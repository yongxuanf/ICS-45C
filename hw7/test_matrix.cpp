#include <iostream>
using namespace std;
#include "Array.h"
#include "Matrix.h"
#include "IndexOutOfBoundsException.h"

template
  < typename T >
void fillMatrix( Matrix <T> & m )
{
  int i, j;
  for ( i = 0; i < m.numRows(); i++ )
    m[i][0] = T();
  for ( j = 0; j < m.numCols(); j++ )
    m[0][j] = T();
  for ( i = 1; i < m.numRows(); i++ )
    for ( j = 1; j < m.numCols(); j++ )
    {
      m[i][j] = T(i * j);
    }
}
template
  < typename T >
void generate_exception( Matrix < T > &m)
{
	for(int row = 0; row >=0;row++)
	{
		for(int col = 0; col >=0;col++)
		{
			m[row][col];
		}
	}
}
void test_int_matrix()
{
	cout << "----------start test int matrix--------------"<< endl;
	cout << "Matrix [10] [5] :\n";
    Matrix < int > m(10,5);
    fillMatrix( m );
    cout << m;
    cout << "Done"<<endl;
}
void test_double_matrix()
{
	cout << "----------start test double matrix--------------"<< endl;
	cout << "Matrix [8] [10] : \n";
	Matrix < double > M(8,10);
    fillMatrix( M );
    cout << M;
    cout << "Done"<<endl;
}
void test_double_matrix_exceptions()
{
	cout << "----------start test double matrix exception --------------"<< endl;
    Matrix < double > M(8,10);
    fillMatrix( M );
    cout << M;
    cout << "Test 1: Matrix[8][11]   ----> should: out of bounds\n\t";
    try
	{
		generate_exception ( M );
	}
	catch ( IndexOutOfBoundsException & e)
	{
		cout << "Error: out of bounds" << endl;
	}
    cout << "Done" << endl;
}
int main()
{
   for (int i=0; i<3; ++i)
   {
       test_int_matrix();
       test_double_matrix();
       test_double_matrix_exceptions();
   }
   return 0;
}
