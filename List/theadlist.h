#pragma once
#include "tlist.h"
template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T> *pHead;
public:
	//�����������
	THeadList() : TList<T>() {
		pHead = new TNode<T>;
		pStop = pHead;
		pHead->pNext = pHead;
		pFirst = pHead;
	}
	//����������
	~THeadList() {
		TList<T> ::DelList();
		delete pHead;
	}
	//�������� ������ �����
	void InsFirst(T el) {
		TList::InsFirst(el);
		pHead->pNext = pFirst;
	}
	//�������� ������� ��������
	void DelFirst() {
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
};