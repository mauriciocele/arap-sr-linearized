/** \file Edge.h Declarations and definitions for the Edge class.
    \author Liliya Kharevych
    \date March 2006
*/


#ifndef EDGE_CM
#define EDGE_CM
#include <Eigen/Core>
#include <Eigen/Dense>

class Vertex;
class Face;

/** Half edge for the mesh datastructure.

In addition to the usual members which edge for the half-edge datastructure has 
(such as pointers to the next and pair edges, pointer to the vertex at the start 
of the edge and pointer to the touching face); 
this edge class has some extra data for circle pattern algorithm. 
The main data is a length of an edge and a theta angle associated with an edge. 
We also store an alpha angle associated with each edge (aplhaOposite). 
This angle is formed by another two edges of the triangle which touches the edge. 
For boundary edges alphaOposite are equal to 0.
Various functions of theta angle are precomputed and stored: 
cos(theta), sin(theta), tan(0.5*(M_PI - theta)),
Cl2(2.0*(M_PI - theta)).


*/
class Edge
{
private:
public:

   // pointers for mesh structure
   Edge * next;
   Edge * pair;
   Vertex * vertex;
   Face * face;

   int	ID;
   /** Check for various iterations*/
   bool check;

   Edge(void) : next(NULL), pair(NULL), vertex(NULL), face(NULL)
   {
	   ID = -1;
   }

   // Assignment (copy only geometrical information)
   void assignData(const Edge& rhs){
      if (this != &rhs) {
      }
   }

   bool isBoundary() const {return !(face && pair->face);}
   Vertex * oppositeVertex() {return next->next->vertex;}
};

#endif

