#ifndef __numerics_h__
#define __numerics_h__

#include <map>
#include <vector>
#include <iostream>
#include <math.h>

namespace numerics {	/*numerics namespace*/

class SparseMatrix
{
public:
	typedef std::map<int,double>		mapVect;
	typedef std::map<int,mapVect>		mapMatrix;

	mapMatrix		matrix;
	int				columns;

	SparseMatrix(int columns)
	{
		this->columns = columns;
	}
	SparseMatrix(int columns, int rows)
	{
		this->columns = columns;
		for(int i = 0 ; i < rows ; ++i)
			matrix.insert(std::pair<int,mapVect>(i, mapVect()));
	}

	int NonZeros() const
	{
		int		nz = 0;
		for(mapMatrix::const_iterator rIter = matrix.begin() ; rIter != matrix.end() ; rIter++)
			for(mapVect::const_iterator cIter = rIter->second.begin() ; cIter != rIter->second.end() ; cIter++)
				nz++;
		return nz;
	}

	int numRows() const
	{
		return this->matrix.size();
	}

	int numColumns() const
	{
		return this->columns;
	}

	class RowIterator
	{
		private:
			mapVect::const_iterator		rIter;
			mapVect::const_iterator		endIter;
			int		rowIndex;
		public:
			RowIterator(const mapMatrix &m, int rowIndex)
			{
				rIter = m.find(rowIndex)->second.begin();
				endIter =  m.find(rowIndex)->second.end();
				this->rowIndex = rowIndex;
			}

			RowIterator& operator++( void )
			{
				rIter++;
				return *this;
			}

			int columnIndex() { return rIter->first; }
			double value() { return rIter->second; }
			bool end(void) { return rIter == endIter;}
	};

	RowIterator iterator(int i) const { return RowIterator(matrix, i); }

	double& operator () (int i, int j) { return matrix[i][j]; }
	const double& operator () (int i, int j) const { return matrix.find(i)->second.find(j)->second; }

	bool isSymmetric()
	{

		for (mapMatrix::iterator it = matrix.begin(); it != matrix.end() ; ++it)
		{
			int		i = it->first;
			for (mapVect::iterator it2 = it->second.begin() ; it2!=it->second.end() ; ++it2)
			{
				int		j = it2->first;
				double	val = it2->second;
				if (!matrix.count(j))
				{
					std::cout << i  << " " << j << " but " << j << " not present"   << std::endl;
					return false;
				}
				else if (!matrix[j].count(i) || abs(matrix[j][i]-matrix[i][j]) > 1e-4 )
				{
					if (matrix[j].count(i))
						std::cout << i  << " " << j << " "<< val << " " << matrix[j][i] << " " <<  matrix[i][j] <<std::endl;
					else 
						std::cout << j << " " << i  << " non present " << "val  " << val << " " << matrix[i][j]  << std::endl;
					return false;
				}
			}
		}
		return true;
	}
};

}; /*numerics namespace*/

#endif