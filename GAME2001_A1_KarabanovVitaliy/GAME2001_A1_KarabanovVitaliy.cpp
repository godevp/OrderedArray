#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"
using namespace std;
int main()
{
	cout << ">>>Unordered array<<<:" << endl;
	UnorderedArray<int> n(1);
	cout << endl << "Max size on start : " << n.getMaxSize() << endl;
	cout << "Number of elements on start :" << n.getSize() << endl;
	n.push(5);
	n.push(2);
	n.push(8);
	n.push(10);
	n.push(4);
	cout << "Max size now : " << n.getMaxSize() << endl;
	cout << "Number of elements now :" << n.getSize() << endl;
	for (int i = 0; i < n.getSize(); i++)
		cout << n[i] << endl;

	cout << endl << ">>>Ordered array with duplicates<<<:" << endl;

	OrderedArray<int> n2(1,true);
	cout << endl << "Max size on start : " << n2.getMaxSize() << endl;
	cout << "Number of elements on start :" << n2.getSize() << endl;
	n2.push(5);
	n2.push(2);
	n2.push(7);
	n2.push(3);
	n2.push(3);
	n2.push(9);
	n2.push(10);
	n2.push(10);
	n2.push(11);
	n2.push(12);
	n2.push(13);

	cout << "Max size now : " << n2.getMaxSize() << endl;
	cout << "Number of elements now :" << n2.getSize() << endl;

	for (int i = 0; i < n2.getSize(); i++)
		cout << n2[i] << endl;
	cout << endl << ">>>Ordered array without duplicates<<<:" << endl;

	OrderedArray<int> n3(1, false);
	cout << endl << "Max size on start : " << n3.getMaxSize() << endl;
	cout << "Number of elements on start :" << n3.getSize() << endl;
	n3.push(5);
	n3.push(2);
	n3.push(7);
	n3.push(3);
	n3.push(3);
	n3.push(9);
	n3.push(10);
	n3.push(10);
	n3.push(11);
	n3.push(12);
	n3.push(13);

	cout << "Max size now : " << n3.getMaxSize() << endl;
	cout << "Number of elements now :" << n3.getSize() << endl;

	for (int i = 0; i < n3.getSize(); i++)
		cout << n3[i] << endl;

	return 0;
}
