#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> split(string input, string delimeter){
	vector<string> ret;
	size_t start=0;
	size_t end=input.find(delimeter);

	while(end!=string::npos){
		ret.push_back(input.substr(start,end-start));
		start=end+delimeter.size();
		end=input.find(delimeter,start);
	}
	ret.push_back(input.substr(start,end));
	return ret;
}
int main(){
	string s("hi bye hello");
	vector<string> v=split(s," ");
	for(auto i: v){
		cout<<i<<" ";
	}
	cout<<v.size();
}