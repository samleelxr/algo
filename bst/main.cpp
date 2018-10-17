#include <iostream>
#include <vector>
#include "BiTree.h"

using namespace std;

int main()
{
	vector <char> A;
	char ele;
	cout << "please input the value: ";
	do
	{
		cin >> ele;
		A.push_back(ele);
	}
	while(getchar() != '\n');
	int n = A.size();
	BiTree <char> MyTree(A, n);
	cout << "the normal traversal: " << endl;
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	MyTree.PreOrder(MyTree.root);

	cout << " " << endl;
	return 0;



}









