#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include "IndexOutOfBoundsException.h"
using namespace std;

template
< typename T>
class Array
{
private:
  int len;
  T * buf;
public:
  Array( int newLen ): len( newLen ), buf( new T[newLen] ){}
  Array( const Array<T> & l ): len( l.len ), buf( new T[l.len] )
  {
  		 for ( int i = 0; i < l.len; i++ )
      	buf[i] = l.buf[i];
  }
  Array operator = ( const Array<T> & l )
  {
  	return *this;
  }
  	
  int length()
  {
    return len;
  }
  T & operator [] ( int i )
  {
    if ( 0 <= i && i < len )
    {
    	return buf[i];
	}
	else
	{
		throw IndexOutOfBoundsException();
	}
  }
  void print( ostream & out )
  {
    for (int i = 0; i < len; ++i)
      out << setw(8) << setprecision(2) << fixed << right << buf[i];
  }
  friend ostream & operator << ( ostream & out, Array & a )
  {
    a.print( out );
    return out;
  }
  friend ostream & operator << ( ostream & out, Array * ap )
  {
    ap->print( out );
    return out;
  }
  ~Array()
  {
  	delete[] buf;
  }
};
#endif