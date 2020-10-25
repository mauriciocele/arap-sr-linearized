/** \file Mesh.cpp Definitions for the Mesh class.
    \author Liliya Kharevych
    \date March 2006
*/

#include "Mesh.h"
#include <iostream>
#include <fstream>
#include "util.h"
#include <stack>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <assert.h>

using namespace std;

Mesh::Mesh(void)
{
   numBoundaryVertices = 0;
}

Mesh::~Mesh(void)
{
   clear();
}

void Mesh::clear() {
   for (Edge* e : edges) { delete e; }
   vertices.clear();
   faces.clear();
   edges.clear();
}

int Mesh::addVertex(const Eigen::Vector3d & _p) {
   Vertex v;
   v.p = _p;
   v.ID = (int)vertices.size();
   vertices.push_back(v);
   return v.ID;
}

void Mesh::initFace(const std::vector<int>& faceVerts, int faceID) {
   Face* f = &faces[faceID];
   f->ID = faceID;

   Edge * firstEdge = NULL;
   Edge * last = NULL;
   Edge * current = NULL;

   unsigned int i;

   for (i = 0; i < faceVerts.size()-1; i++) {
      current = addEdge(faceVerts[i], faceVerts[i+1]);
   
      check_error (!current, "Problem while parsing mesh faces.");

      current->face = f;

      if (last)
	      last->next = current;
      else
	      firstEdge = current;
      last = current;
   }

   current = addEdge (faceVerts[i], faceVerts[0]);
   check_error (!current, "Problem while parsing mesh faces.");
   
   current->face = f;

   last->next = current;
   current->next = firstEdge;

   f->edge = firstEdge;
}

Edge * Mesh::addEdge (int i, int j) {
   Edge eTmp;
   eTmp.vertex = &vertices[i];

   Edge eTmpPair;
   eTmpPair.vertex = &vertices[j];
   eTmp.pair = &eTmpPair;

   Mesh::EdgeSet::iterator eIn = edges.find(&eTmp);
   Edge * e;

   if (eIn != edges.end()){
      e = *eIn;
      if (e->face != NULL)
	      return NULL;
   }
   else {
      e = new Edge();
      Edge * pair = new Edge();

      e->vertex = &vertices[i];
      pair->vertex = &vertices[j];

      pair->pair = e;
      e->pair = pair;

      edges.insert(e);
      edges.insert(pair);

      pair->vertex->edge = pair;
   }   
   return e;
}

void Mesh::computeNormals()
{
	map< int, Eigen::Vector3d >					normals;

	for (Face& face : faces) {
		Eigen::Vector3d		u = face.edge->next->vertex->p - face.edge->vertex->p;
		Eigen::Vector3d		v = face.edge->next->next->vertex->p - face.edge->vertex->p;
		Eigen::Vector3d		n = u.cross(v).normalized();
		normals.insert( pair<int, Eigen::Vector3d>(face.ID, n) );
	}

	for (Vertex& vertex : vertices) {
		int		valence = 0;
		vertex.n = Eigen::Vector3d(0,0,0);

		for( Vertex::EdgeAroundIterator	around = vertex.iterator(); !around.end(); around++ )
		{
			if(around.edge_out()->face)
			{
				int		faceId = around.edge_out()->face->ID;
				vertex.n += normals[faceId];
				valence++;
			}
		}

		vertex.n /= (double)valence;
		vertex.n.normalize();
	}
}


/** Called after the mesh is created to link boundary edges */
void Mesh::linkBoundary() {
   for (Edge* edge : edges) {
      if (!edge->face) 
	      edge->vertex->edge = edge;
   }

   Edge *next, *beg;
   for (Vertex& vertex : vertices) {
      if (vertex.isBoundary()) {
         beg = vertex.edge;
         next = beg;
         while (beg->pair->face)
            beg = beg->pair->next;
         beg = beg->pair;
         beg->next = next;
         numBoundaryVertices++;
      }
   }

}

/** Computes information about the mesh:

Number of boundary loops,
Number of connected components,
Genus of the mesh.

Only one connected compoment with 0 or 1 boundary loops can be parameterize.
Singularities should be assigned in such a way that Gauss-Bonet theorem is satisfied.
*/
void Mesh::computeMeshInfo() {
   cout << "Topological information about the mesh:" << endl;
   // Number of boundary loops
   for (Edge* edge : edges) {
      edge->check = false;
   }
   numBoundaryLoops = 0;
   for (Edge* edge : edges) {
      Edge * e = edge;
      if (e->face)
	      e->check = true;
      else if (!e->check) {
	      Edge * beg = NULL;
         while (e != beg) {
            if (!beg) beg = e;
            check_error(!e, "Building the mesh failed, probem with input format.");
            e->check = true;
            e = e->next;
         }
         numBoundaryLoops++;
      }
   }
   cout << "Mesh has " << numBoundaryLoops << " boundary loops." << endl;
   // Number of connected components
   numConnectedComponents = 0;
   for (Face& face : faces) {
      face.check = false;
   }
   stack<Edge *> toVisit;
   for (Face& face : faces) {
      if (!face.check) {
         numConnectedComponents++;
         toVisit.push(face.edge);
         while (!toVisit.empty()) {
            Face * fIn = toVisit.top()->face; 
            toVisit.pop();
            fIn->check = true;     
            Face::EdgeAroundIterator iter = fIn->iterator();
            for (; !iter.end(); iter++) 
               if (iter.edge()->pair->face && !iter.edge()->pair->face->check)
            toVisit.push(iter.edge()->pair);
         }
      }
   }
   cout << "Mesh has " << numConnectedComponents << " connected components." << endl;
   // Genus number
   check_error(numConnectedComponents == 0, "The mesh read is empty.");
   numGenus = 
      (1 - (numVertices() - numEdges() + numFaces() + numBoundaryLoops ) / 2) / numConnectedComponents;
   cout << "Mesh is genus " << numGenus << "." << endl;
}

/** Check if all the vertices in the mesh have at least on edge coming out of them */
bool Mesh::checkVertexConection() {
   bool conectedVert = true;

   for (Vertex& vertex : vertices)
      vertex.check = false;

   for (Face& face : faces) {
      Face::EdgeAroundIterator around = face.iterator();
      for (;!around.end();around++)
      	 around.vertex()->check = true;
   }
   for (Vertex& vertex : vertices) {
      if (!vertex.check) {
	      cerr << "Vertex " << vertex.ID << " is not connected." << endl;
	      conectedVert = false;
      }
   }

   return conectedVert;
}

/** Manifoldness check: only one disk should be adjusted on any vertex */
bool Mesh::checkManifold() {
   bool manifold = true;

   for (Edge* edge : edges)
      edge->check = false;

   for (Vertex& vertex : vertices) {
      Vertex::EdgeAroundIterator around = vertex.iterator();
      for (;!around.end();around++)
	      around.edge_out()->check = true;
   }

   for (Edge* edge : edges) {
      if (!edge->check) {
	      cerr << "Mesh is not manifold - more then one disk at vertex " 
	            << edge->vertex->ID << endl;
	      manifold = false;
	      break;
      }
   }

   return manifold;
}

void Mesh::CenterAndNormalize()
{
	double maxX, maxY, maxZ, minX, minY, minZ;
	maxX = maxY = maxZ = -1e38;
	minX = minY = minZ = 1e38;

	for (Vertex& vertex : vertices)
	{
		if(vertex.p.x() > maxX) maxX = vertex.p.x();
		if(vertex.p.y() > maxY) maxY = vertex.p.y();
		if(vertex.p.z() > maxZ) maxZ = vertex.p.z();
		if(vertex.p.x() < minX) minX = vertex.p.x();
		if(vertex.p.y() < minY) minY = vertex.p.y();
		if(vertex.p.z() < minZ) minZ = vertex.p.z();
	}

	Eigen::Vector3d min(minX,minY,minZ);
	Eigen::Vector3d max(maxX,maxY,maxZ);

	Eigen::Vector3d center = min + (max - min) * 0.5;

	for (Vertex& vertex : vertices) {
		vertex.p -= center;
	}

	double diag = (max - min).norm() / 2.0;
	double scale = 1.0 / diag;
	for (Vertex& vertex : vertices) {
		vertex.p *= scale;
	}
}


/** Loads mesh from obj file

Standard format for OBJ file is

v double double double

v double double double

f int int int

f int int int

Files with vt tags also can be parsed
*/
void Mesh::readOBJ(const char * obj_file) {
   string front;
   string v = "v", vt = "vt", f = "f";
   Eigen::Vector3d vert;
   vector<Eigen::Vector3d> uvVec;
   char etc;
   int id;

   struct TempFace {
      vector<int> verts;
      vector<int> uvs;
      int ID;
   };
   vector<TempFace> tempFaces;

   ifstream in(obj_file);

   check_error(!in, "Cannot find input obj file.");

   bool hasUV = false;

   while(!in.eof() || in.peek() != EOF) {
      in >> ws; //extract whitespaces
      if (in.eof() || in.peek() == EOF)
	      break;
      if (in.peek() == '#') {
	      in.ignore(300, '\n');
      }
      else {
         in >> front;
         if (front == v) {
            in >> vert.x() >> vert.y() >> vert.z();
            addVertex(vert);
         }
         else if (front == vt){
            in >> vert.x() >> vert.y();
            vert.z() = 0;
            uvVec.push_back(vert);
            hasUV = true;
         }
         else if (front == f) {
            TempFace tempFace;
            while (in >> id) {

               check_error(id > numVertices(), "Problem with input OBJ file.");

               tempFace.verts.push_back(id-1);
               bool vtNow = true;
               if (in.peek() == '/'){
                  in >> etc;
                  if (in.peek() != '/') {
                     in >> id;
                     check_warn(id > numVertices(), "Texture coordinate index is greater then number of vertices.");
                     if (id < numVertices() && hasUV) {
                        tempFace.uvs.push_back(id-1);
                        vtNow = false;
                     }
                  }
               }
               if (in.peek() == '/'){
                  int tmp;
                  in >> etc;
                  in >> tmp;
               }
               if (hasUV && vtNow) {
                  tempFace.uvs.push_back(id-1);
               }
            }
            in.clear(in.rdstate() & ~ios::failbit);
            tempFace.ID = tempFaces.size();
            tempFaces.push_back(tempFace);
         }
         else {
            string line;
            getline(in, line);
            cout << "Warning, line: " << line << " ignored." << endl;	
         }
      }
   }

   in.close();

   faces.resize(tempFaces.size());
   for(TempFace& tempFace : tempFaces) {
      initFace(tempFace.verts, tempFace.ID);

      if (hasUV && tempFace.uvs.size() != 0){
         int k = 0;
         for (Face::EdgeAroundIterator e = faces[tempFace.ID].iterator(); !e.end(); e++, k++)
            e.vertex()->uv = uvVec[tempFace.uvs[k]];
      }
   }
   tempFaces.clear();
   // Finnish building the mesh, should be called after each parse.
   finishMesh();
}

/* Write mesh in OBJ format to obj_file parameter */
void Mesh::writeOBJ(const char * obj_file) {
   ofstream out(obj_file);
   check_error (!out, "Cannot find output file.");

   for (Vertex& vertex : vertices)
      out << "v " << vertex.p << endl;

   for (Vertex& vertex : vertices)
      out << "vt " << vertex.uv.x() << " " << vertex.uv.y() << endl;

   for (Face& face : faces) {
      Face::EdgeAroundIterator around = face.iterator();
      out << "f";
      for ( ; !around.end(); around++)
	      out << " " << (around.vertex()->ID + 1) << "/" << (around.vertex()->ID + 1);
      out << endl;
   }
}

/* Write mesh in VT format (only text coodrinates) to vt_file parameter */
void Mesh::writeVT(const char * vt_file) {
   ofstream out(vt_file);
   check_error (!out, "Cannot find output file.");

   for (Vertex& vertex : vertices)
      out << "vt " << vertex.uv.x() << " " << vertex.uv.y() << endl;
}
