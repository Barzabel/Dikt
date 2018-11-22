#include<iostream>

#include"dict.h"

#include<string>

using namespace std;



int main() {


	NativeDict<int> a;
	a.put("a", 21);
	a.put("b", 22);
	a.put("c", 23);
	a.put("d", 24);

	cout << a.get("a")<<endl;
	a.put("a", 23);
	a["a"]=13;
	cout << a["a"] << endl;

	return 0;
}