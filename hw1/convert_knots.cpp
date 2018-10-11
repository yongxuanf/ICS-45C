#include <iostream>
using namespace std;

double convert(int knot)
{
  return knot*6076.0/5280.0/60.0;
}

int main()
{
  int i;
  cout <<"Please enter a integer for convert"<<endl;
  cin >> i;
  cout << "The number convert to miles per minute is: "<<convert(i) << endl;
  return 0;
}
