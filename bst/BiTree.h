#ifndef TEMP_H
#define TEMP_H
#include <iostream>
#include <vector>

using namespace std;


template <class T>
class BiNode
{
	public:
		T data;
		BiNode<T>* lchild;
		BiNode<T>* rchild;
};




template <class T>
class BiTree
{
	private:
		void Create(BiNode<T>* &R, vector<T> &v, int i, int n);
		void Release(BiNode<T>* R);
	public:
		//----------initialization-------------
		BiNode<T>* root;
		BiTree()
		{
			root = NULL;
		}
		BiTree(vector<T>& v, int n);
			
		//the function insertion
		void PreOrder(BiNode<T>* R);
		void InOrder(BiNode<T>* R);
		void PostOrder(BiNode<T>* R);
		~BiTree();	
};




//#include "temp.tpp"

#endif










