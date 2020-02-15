#pragma once
#include "tlist.h"
template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T> *pHead;
public:
	//Конструктор
	THeadList() : TList<T>() {
		pHead = new TNode<T>;
		pStop = pHead;
		pHead->pNext = pHead;
		pFirst = pHead;
	}
	//Деструктор
	~THeadList() {
		TList<T> ::DelList();
		delete pHead;
	}
	//Добавить первое звено
	void InsFirst(T el) {
		TList::InsFirst(el);
		pHead->pNext = pFirst;
	}
	//Удаление первого элемента
	void DelFirst() {
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
};