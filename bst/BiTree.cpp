#include <iostream>
#include <vector>
#include "BiTree.h"

using namespace std;

template <class T>
void BiTree<T>::Create(BiNode<T>* &R, vector<T> &v, int i, int n)
{
	if(i <= n && v[i - 1] != '0')
	{
		R = new BiNode<T>;
		R -> data = v[i - 1];
		Create(R->lchild, v, i * 2, n);
		Create(R->rchild, v, i * 2 + 1, n);	
	}
	else
		R = NULL;

}

template <class T>
void BiTree<T>::Release(BiNode<T>* R)
{
	if(R != NULL)
	{	
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}

template <class T>
BiTree<T>::BiTree(vector<T>& v, int n)
{
	Create(root, v, 1, n);
}


//----------------inserted function----------------

template <class T>
void BiTree<T>::PreOrder(BiNode<T>* R)
{
	if(R != NULL)
	{
		cout << R->data << " ";
		PreOrder(R->lchild);
		PreOrder(R->rchild);
	}
}


template <class T>
void BiTree<T>::PostOrder(BiNode<T>* R)
{
	if(R != NULL)
	{
		PostOrder(R->lchild);
		PostOrder(R->rchild);
		cout << R->data << " ";
	}
}


//------------------------------------------------



template <class T>
BiTree<T>::~BiTree()
{
	Release(root);
}






template class BiTree<char>;
template class BiTree<int>;
template class BiTree<double>;
template class BiNode<char>;








