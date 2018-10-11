#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"
#include "IndexOutOfBoundsException.h"
#include <iostream>
#include <iomanip>
using namespace std;

template
< typename Element>

class Matrix
{
private:
  int rows, cols;
  Array< Array < Element > *> m;
public:
  Matrix( int newRows, int newCols )
    : rows( newRows ), cols( newCols ), m( rows )
  {
    for (int i = 0; i < rows; i++ )
    {
      m[i] = new Array < Element >( cols );
	}
  }
  int numRows()
  {
    return rows;
  }
  int numCols()
  {
    return cols;
  }
  Array < Element > & operator [] ( int row )
  {
    if ( 0 <= row && row < rows )
    {
    	return *m[row];
	}
	else
	{
		throw IndexOutOfBoundsException();
	}
  }
  void print( ostream & out)
  {
  	for(int i = 0 ; i < rows; ++i)
  	{
  		out << m[i]<<endl;
  	}
  }
  friend ostream & operator << ( ostream & out, Matrix & m )
  {
    m.print( out );
    return out;
  }
  ~Matrix()
  {
  	for (int i = 0; i < rows; i++)
  	{
  		delete m[i];
  	}
  }
};
#endif