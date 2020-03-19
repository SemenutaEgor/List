#pragma once
#include "tlist.h"
template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T> *pHead;
public:
	//constructor
	THeadList() : TList<T>() {
		pHead = new TNode<T>;
		pStop = pHead;
		pHead->pNext = pHead;
		pFirst = pHead;
	}
	//destructor
	~THeadList() {
		TList<T> ::DelList();
		delete pHead;
	}
	//add first link
	void InsFirst(T el) {
		TList::InsFirst(el);
		pHead->pNext = pFirst;
	}
	// add last link
	void InsLast(T el) {
		TList::InsLast(el);
	}
	//add current link
	void InsCurr(T el) {
		TList::InsCurr(el);
	}
	// delete first link
	void DelFirst() {
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
};