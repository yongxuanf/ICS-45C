#include <iostream>
using namespace std;

#define STACK_CAPACITY 1000
class Stack
{
	char s [STACK_CAPACITY];
	int index;
	void error(string message)
                {
                        cerr << "Error: " << message << endl;
                }

	public:
 		 Stack():index(0)
		{	


		}
		void push( char c)
		{
			if (isFull())
			{
				error("Push() on an full stack");
			}
			else
			{
				s [index++] = c;
			}
		}	
 
		char pop()
		{
			if (isEmpty())
			{ 
				error("Pop() on an empty stack");
			}
			else
			{
				return s[--index];
			}
		}
		char top()
		{
			if (isEmpty())
			{
				error("Top() on an empty stack");
			}
			return s[index - 1];
		}
		bool isEmpty()
		{
			return index <= 0;
		}
		bool isFull()
		{
			return index >= STACK_CAPACITY;
		}		
		~Stack()
		{
		}
};
