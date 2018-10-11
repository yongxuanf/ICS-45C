#include <iostream>
#include <fstream>
#include <iterator>
#include "MapArray.h"
#include "SetList.h"
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	MapArray <string, int> M;
	SetList <string> S;
	ifstream in_doc("sample_doc.txt");
	ifstream in_stop("stopwords.txt");
	ofstream out_f("frequency.txt");
	for_each( istream_iterator<string>(in_stop),istream_iterator<string>(),[&](string s){S.insert(s);});
	for_each( istream_iterator<string>(in_doc),istream_iterator<string>(),[&](string s){
		string s2(s);
		transform(begin(s),end(s),begin(s2),::tolower);
		if(S.find(s2) == S.end())
		{
			M[s2]++;
		}
		});
	for_each(begin(M),end(M),[&](pair<string, int> p){out_f <<p.first + " : " + to_string(p.second) + "\n";});
	return 0;
}