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
	int len; //�����
	int pos;//���� ���������� pCurr
public:
	//�����������
	TList() {
		pFirst = NULL;
		pLast = NULL;
		pCurr = NULL;
		pPrev = NULL;
		pStop = NULL;
		len = 0;
		pos = 0;
	}
	//����������
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
	//�������� � ������
	void InsFirst(const T& a) {
		TNode<T> *tmp;
		tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		pFirst = tmp;
		len++;
	}
	//�������� � �����
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
	//�������� ��������� �� ���������
	TNode<T>* GetNext() {
		return pCurr->pNext;
	}
	//������� ������ �����
	void DelFirst() {
		T res = pFirst->val;
		TNode<T> *tmp;
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		len--;
	}
	//�������� ������� �� ������� �������
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
				len++; // ������ ��� �������� 1 �����
			//}
		}
	}
	//������� ������� �������
	void DelCurr() {
		//if (pCurr == pStop)
			//throw - 1;
		if (pCurr == pFirst)
			DelFirst();
		else {
			TNode<T> *tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			pCurr = pCurr->pNext;
			/*pCurr = GetNext();
			pPrev->SetNext(pCurr);*/
			delete tmp;
			len--;//��������� �����, �.�. ���� ������� �������
		}
	}
	//���������� ������� �������
	T GetCurrEl() {
		return pCurr->val;
	}
	//���������� pCurr �� ������
	void Reset() {
		pCurr = pFirst;
		pPrev = pStop;
		pos = 0;
	}
	//������� �� ��������� �������
	void GoNext() {
		//if (IsEnd()) throw - 1;
		//else {
			pPrev = pCurr;
			pCurr = pCurr->pNext;
			pos++;
		//}
	}
	//��������, �� ����� �� ����� ��� �� �����
	bool IsEnd() {
		return (pCurr == pStop);
	}
    //��������, ��� �� ����� �� ��������������
	bool IsNextEnd() {
		return (pCurr->pNext == pStop);
	}
	//�������� �� �������
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
	//�������� ����� ������
	void DelList() {
		for (Reset(); !IsEnd(); GoNext()) {
			DelCurr();
		}
		DelCurr();
	}
};
