#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Heap
{
	private:
		void Sink(std::vector<T> &v, int i);
	public:
		Heap(std::vector<T> &v);

		//----------------inserted function----------------
		std::vector<T> heapSort(std::vector<T> &v);


		//-------------------------------------------------
};

#endif


