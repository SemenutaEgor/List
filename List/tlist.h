#pragma once
template <class T>
struct TNode {
	T val;
	TNode<T> *pNext;
	/*void SetNext(TNode<T>* el) {
		pNext = el;
	}*/
};
template <class T>
class TList {
protected:
	TNode <T> *pFirst, *pLast, *pCurr, *pPrev, *pStop;
	int len; //lenght
	int pos;//where pCurr shows
public:
	//constructor
	TList() {
		pFirst = NULL;
		pLast = NULL;
		pCurr = NULL;
		pPrev = NULL;
		pStop = NULL;
		len = 0;
		pos = 0;
	}
	//destructor
	~TList() {
		TNode<T> *tmp = pFirst;
		//if (tmp == pStop)
			//delete tmp;
		while (pFirst != pStop) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	//insert at the beginning
	void InsFirst(const T& a) {
		TNode<T> *tmp;
		tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		pFirst = tmp;
		len++;
	}
	//insert at end
	void InsLast(const T& a) {
		if (pFirst == pStop)
			InsFirst(a);
		else {
			TNode<T> *p = pFirst;
			while (p->pNext != pStop)
				p = p->pNext;
			TNode<T> *tmp;
			tmp = new TNode<T>;
			tmp->val = a;
			tmp->pNext = pStop;
			p->pNext = tmp;
			pLast = tmp;
		}
	}
	//get a pointer pNext
	TNode<T>* GetNext() {
		return pCurr->pNext;
	}
	//delete first link
	void DelFirst() {
		if (pFirst == pStop)
			return;
		if (pCurr == pFirst)
			pCurr = pFirst->pNext;
		T res = pFirst->val;
		TNode<T> *tmp;
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		len--;
	}
	//insert to current poisition
	void InsCurr(const T& a) {
		if (pCurr == pFirst) {
			InsFirst(a);
			pCurr = pFirst;
		}
		else {
			//if (pCurr == pStop)
				//throw - 1;
			//else {
				TNode<T> *tmp = new TNode<T>;
				tmp->val = a;
				pPrev->pNext = tmp;
				tmp->pNext = pCurr;
				pCurr = tmp;
				len++; 
			//}
		}
	}
	//delete current link
	void DelCurr() {
		if (pCurr == pStop)
			return;
		if (pCurr == pFirst)
			DelFirst();
		else {
			TNode<T> *tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			pCurr = pCurr->pNext;
			/*pCurr = GetNext();
			pPrev->SetNext(pCurr);*/
			delete tmp;
			len--;
		}
	}
	//get current link
	T GetCurrEl() {
		return pCurr->val;
	}
	//set pCurr to the beginning
	void Reset() {
		pCurr = pFirst;
		pPrev = pStop;
		pos = 0;
	}
	//go to the next link
	void GoNext() {
		//if (IsEnd()) throw - 1;
		//else {
			pPrev = pCurr;
			pCurr = pCurr->pNext;
			pos++;
		//}
	}
	//end check
	bool IsEnd() {
		return (pCurr == pStop);
	}
    //penultimate check
	bool IsNextEnd() {
		return (pCurr->pNext == pStop);
	}
	//add in order
	void InsOnOrder(const T& el) {
		if ((pFirst == pStop) || (el > pFirst->val))
			InsFirst(el);
		else
			if (pLast->val > el)
				InsLast(el);
			else
				for (Reset(); !IsEnd(); GoNext()) {
					if (el > pCurr->val) {
						InsCurr(el);
						break;
					}
				}
	}
	//delete the whole list
	void DelList() {
		for (Reset(); !IsEnd(); GoNext()) {
			DelCurr();
		}
		DelCurr();
	}
};
