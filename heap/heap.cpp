#include <iostream>
#include <vector>
#include "heap.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


//private var
template <class T>
void Heap<T>::Sink(std::vector<T> &v, int i)
{
	int lIndex, rIndex, maxIndex, vecSize;
	T temp;
	lIndex = 2 * i + 1;
	rIndex = 2 * i + 2;
	maxIndex = i;
	vecSize = v.size();
	if(rIndex < vecSize && v[lIndex] > v[maxIndex] && v[lIndex] > v[rIndex])
	{
		maxIndex = lIndex;
	}
	
	else if(rIndex < vecSize && v[rIndex] > v[maxIndex] && v[rIndex] >= v[lIndex])
	{
		maxIndex = rIndex;
	}
	
	else if(rIndex == vecSize)
	{
		if(v[lIndex] > v[maxIndex])
		{
			maxIndex = lIndex;
		}
	}
	
	if (maxIndex != i)
	{ 
		temp = v[maxIndex];
		v[maxIndex]= v[i];
		v[i] = temp;
		Sink(v, maxIndex);
	}
}



//constructor
template <class T>
Heap<T>::Heap(std::vector<T> &v)
{
	int vSize = v.size();
	for(int i = vSize/2 ; i >= 0; --i)
	{
		Sink(v, i);
	}
}




//-----------------------inserted function-----------------------
template <class T>
std::vector<T> Heap<T>::heapSort(std::vector<T> &v)
{
	std::vector<T> vecRet;
	T tmp;
	while(v.size() > 0)
	{ 
		
		(Heap(v));
		tmp = v[0];
		v[0] = v.back();
		v.back() = tmp;
		vecRet.insert(vecRet.begin(), v.back());

		v.pop_back();
	}
	return vecRet;
}



template class Heap<char>;
template class Heap<int>;
template class Heap<double>;


