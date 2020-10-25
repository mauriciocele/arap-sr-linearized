/** \file Vertex.h Declarations and definitions for the Vertex class.
    \author Liliya Kharevych
    \date March 2006
*/
#ifndef VERTEX_CM
#define VERTEX_CM
#include "Edge.h"

/** Vertex for the mesh datastructure.
*/
class Vertex
{
private:
   const Vertex& operator=(const Vertex& rhs){ return *this;}
public:

   // pointers for mesh structure
   Edge * edge;

   // geometry data
   Eigen::Vector3d p;
   Eigen::Vector3d n;
   Eigen::Vector3d uv;

   // distinct id
   int ID;

   // to check various iterations
   bool check;

   Vertex (const Eigen::Vector3d & _pos = Eigen::Vector3d(0,0,0)): 
   edge(NULL), p(_pos), uv(0,0,0)
   {
   }

   // Assignment (copy only geometrical information)
   void assignData(const Vertex& rhs){
      if (this != &rhs) {
         p = rhs.p;
         uv = rhs.uv;
      }
   }


   bool isBoundary() {
      return (edge && !edge->face);
   }

  /** The iterator that visits edges or vertices in one ring of the current face in order. */
  class EdgeAroundIterator {
   private:
      Edge * endI;
      Edge * run;

   public:
      EdgeAroundIterator(Edge * e) {
         endI = NULL;
         run = e;
      }
      EdgeAroundIterator& operator++( void ){
         if (!endI) endI = run;
         run = run->pair->next;
         return *this;
      }
      EdgeAroundIterator operator++( int ){
      	 EdgeAroundIterator r = *this; ++*this; return r;
      }

      Edge * edge_out( void ) const { return run; }
      Edge * & edge_out( void )     { return run; }

      Vertex * vertex( void ) const { return run->vertex; }
      Vertex * & vertex( void )     { return run->vertex; }

      bool end(void) { return endI == run;}
   };

   EdgeAroundIterator iterator() {return EdgeAroundIterator(edge);}
   EdgeAroundIterator iterator(Edge * eFrom) {return EdgeAroundIterator(eFrom);}

   int getValence() {
      Vertex::EdgeAroundIterator iter = iterator();
      int res = 0;
      for (; !iter.end(); iter++)
	      res++;
      return res;
   }
};
#endif

