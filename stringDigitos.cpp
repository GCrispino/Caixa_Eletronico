#include <iostream>

using namespace std;

bool stringDigitos(const string &s){
	if (s.empty())
		return false;
	for (unsigned int i = 0;i < s.size();i++)
		if (isdigit(s[i]) == 0)
			return false;
	
	return true;
}