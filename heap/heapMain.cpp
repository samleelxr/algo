#include <iostream>
#include <string>
#include <vector>
#include "heap.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;



int main()
{
	std::vector<int> vInput, vSorted;
	int ele;
	cout << "please input the value : ";
	while(cin >> ele)
	{
		vInput.push_back(ele);
		if(cin.get() == '\n')
		{
			break;
		}
	}	
	Heap<int> myHeap(vInput);
	for(int i = 0; i < vInput.size(); i++)
	{
		cout << vInput[i] << " ";
	}
	
	cout << endl;	
	vSorted = myHeap.heapSort(vInput);
	for(auto &c : vSorted)
	{
		cout << c << " ";
	}
	cout << endl;
	return 0;
}


/*


*/

