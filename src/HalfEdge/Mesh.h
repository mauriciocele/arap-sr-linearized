/** \file Mesh.h Declarations for the Mesh class.
    \author Liliya Kharevych
    \date March 2006
*/

#ifndef MESH_CM
#define MESH_CM
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>    // std::min

#include "Edge.h"
#include "Face.h"
#include "Vertex.h"

/** 
Implementation of the half edge datastructure.
*/

class Mesh
{
private:
   /** Comparison functions for edge sets

   Lexicographical order by indices of start end end point of the edge
   */
   struct edge_comp {
      edge_comp() {}
      bool operator()( const Edge *e1, const Edge *e2 ) const {
         int b1 = e1->vertex->ID, t1 = e1->pair->vertex->ID;
         int b2 = e2->vertex->ID, t2 = e2->pair->vertex->ID; 

         int min1, min2, max1, max2;
         min1 = std::min(b1, t1); min2 = std::min(b2, t2);
         max1 = std::max(b1, t1); max2 = std::max(b2, t2);
         if (min1 == min2 && max1 == max2){
            if (b1 < b2) return true;
            return (b1 == b2 && t1 < t2);
         }
         if (min1 < min2)     return true;
         return (min1 == min2 && max1 < max2);	
      }
   };


   std::vector<Vertex> vertices;
   std::vector<Face> faces;
   std::multiset<Edge*, Mesh::edge_comp> edges;

public:

   /** Number of vertices (or also edges) at the boundary of the mesh   */
   int numBoundaryVertices;

   /** Number of boundary loops in the mesh */
   int numBoundaryLoops;
   /** Number of connected components */
   int numConnectedComponents;

   /** Genus of the mesh */
   int numGenus;

   typedef std::multiset<Edge*, Mesh::edge_comp>  EdgeSet;
   typedef std::vector<Face> FaceSet;
   typedef std::vector<Vertex> VertexSet;

   Mesh(void);
   ~Mesh(void);
   void clear();

   int addVertex(const Eigen::Vector3d & p);
   void initFace(const std::vector<int>& faceVerts, int faceID);
   Edge * addEdge(int i, int j);
   Edge * addEdge(Edge * e) {
      edges.insert(e);
      return e;
   }

   inline Vertex& vertexAt (int i) {return vertices[i];}
   inline Face& faceAt (int i) {return faces[i];}

   inline int numFaces()     { return (int)faces.size();    }
   inline int numVertices()  { return (int)vertices.size(); }
   inline int numEdges()     { return (int)edges.size()/2;  }
   inline int numBoundary()  { return numBoundaryVertices;  }

   void linkBoundary();
   bool checkManifold();
   bool checkVertexConection();
   void checkGaussianCurvature();

   const std::vector<Vertex>& getVertices() const { return vertices; }
   const std::vector<Face>& getFaces() const { return faces; }
   const std::multiset<Edge*, Mesh::edge_comp>& getEdges() const { return edges; }

   std::vector<Vertex>& getVertices() { return vertices; }
   std::vector<Face>& getFaces() { return faces; }
   std::multiset<Edge*, Mesh::edge_comp>& getEdges() { return edges; }

   /**
   Computes number of connected components, number of boundary loops and genus of the mesh.

   Uses variation of Euler Formula: V - E + F = 2 (c - g)
   Where V - number of vertices.
   E - number of edges.
   F - number of faces.
   c - number of connected components.
   */
   void computeMeshInfo();
   void CenterAndNormalize();

   void readOBJ(const char * obj_file);
   void writeOBJ(const char * obj_file);
   void writeVT(const char * vt_file);

   void computeNormals();

   void finishMesh() {
      linkBoundary();
      checkManifold();
      checkVertexConection();
      std::cout << "*--------------------*" << std::endl;		
      std::cout << "* Faces:    " << numFaces() << std::endl;		
      std::cout << "* Edges:    " << numEdges() << std::endl;		
      std::cout << "* Vertices: " << numVertices() << std::endl;		
      std::cout << "*--------------------*\n" << std::endl;		
   }
};

#endif

