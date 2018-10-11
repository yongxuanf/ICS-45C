#include <iostream>
#include "stack.h"
using namespace std;

void pushAll(Stack & stk, string str)
{
	for(int i = 0; i< str.length();++i)
	{
		stk.push(str[i]);
	}
}
void popAll(Stack & stk)
{
        while(stk.isEmpty() == 0)
        {
                cout << stk.pop();
        }
	cout << endl;
}

int main()
{
	Stack astk;
	std:: string ain;
	cout << "Please enter a string for reversing (^D for quit)"<< endl;
	while (getline(cin, ain))
	{
		pushAll(astk,ain);
		cout << "The reserved string is: ";
		popAll(astk);
		cout << "Please enter a string for reversing (^D for quit)"<< endl;
	}
        return 0;
}

