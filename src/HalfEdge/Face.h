/** \file Face.h Declarations and definitions for the Face class.
    \author Liliya Kharevych
    \date March 2006
*/

#ifndef FACE_CM
#define FACE_CM
#include <iostream>
#include "Edge.h"
#include "Vertex.h"
#include <Eigen/Core>
#include <Eigen/Dense>

/** Face for the mesh datastructure.

Faces are always assumed to be triangles. Although circle pattern algorithm can be extended to 
polygonal meshes, we currently limit it to triangular meshes only. In addition to standard 
data members, radius of the circum circle is stored for each edge.
*/
class Face
{
public:

   // pointers for mesh structure
   Edge * edge;

   // distinct id
   int ID;

   // to check various iterations
   bool check;

   Face(void): edge(NULL), ID(-1) 
   { 
   }

   /** The iterator that visits edges, vertices, or faces around the current face in order. */
   class EdgeAroundIterator {
   private:
      Edge * endI;
      Edge * run;
      Edge * _e;
   public:

      EdgeAroundIterator(Edge * e) {
         endI = NULL;
         run = e;
         _e = e;
      }

      void reset() {
         endI = NULL;
         run = _e;
      }

      EdgeAroundIterator& operator++( void ){
         if (!endI) endI = run;
         run = run->next;
         return *this;
      }
      EdgeAroundIterator operator++( int ){
      	 EdgeAroundIterator r = *this; ++*this; return r;
      }

      Edge * edge( void ) const { return run; }
      Edge * & edge( void )     { return run; }

      Vertex * vertex( void ) const { return run->vertex; }
      Vertex * & vertex( void )     { return run->vertex; }

      Face * face( void ) const { return run->pair->face; }
      Face * & face( void )     { return run->pair->face; }

      bool end(void) { return endI == run;}
   };

   EdgeAroundIterator iterator() {return EdgeAroundIterator(edge);}
   EdgeAroundIterator iterator(Edge * myE) {return EdgeAroundIterator(myE);}

};
#endif

