#include <iostream>
#include "UnorderedArray.h"
using namespace std;
int main()
{
	cout << ">>>Unordered array<<<:" << endl;
	UnorderedArray<int> n(1);
	n.push(5);
	n.push(2);
	n.push(8);
	n.push(10);
	n.push(4);

	for (int i = 0; i < n.getSize(); i++)
		cout << n[i] << endl;
}
