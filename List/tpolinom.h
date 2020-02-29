#pragma once
#include <iostream>
#include "tlist.h"
#include "theadlist.h"

struct TMonom {
	double coeff;
	int px, py, pz;
	//�����������
	TMonom() {
		coeff = 0;
		px = py = pz = 0;
	}
	//��������� ���������
	bool operator< (TMonom& mon) {
		if (px < mon.px)
			return true;
		else
			if (py < mon.py)
				return true;
			else
				if (pz < mon.pz)
					return true;
				else
					false;
	}
	bool operator> (TMonom& mon) {
		if (px > mon.px)
			return true;
		else
			if (py > mon.py)
				return true;
			else
				if (pz > mon.pz)
					return true;
				else
					false;
	}
	bool operator== (TMonom& mon) {
		if ((px == mon.px) && (py == mon.py) && (pz == mon.pz))
			return true;
	}
	bool operator!= (TMonom& mon) {
		if (*this == mon)
			return false;
		else
			return true;
	}
};
class TPolinom : public THeadList<TMonom> {
public:
	//�����������
	TPolinom() : THeadList<TMonom>() {
		pHead->val.pz = -1;
	}
	//����������� ��� ������� (����������� ��������� ������ � �������)
	TPolinom(int arr[][2], int sizep) : THeadList<TMonom>() {          //sizep - ������ ������� � ���������
		pHead->val.pz = -1;
		for (int i = 0; i < sizep; i++) {
			TMonom mon;
			mon.coeff = arr[i][0];
			mon.px = arr[i][1] / 100;
			mon.py = arr[i][1] / 10 % 10;
			mon.pz = arr[i][1] % 10;
			InsLast(mon);
		}
	}
	//����������� �����������
	TPolinom(TPolinom &p) : THeadList<TMonom>() {
		pHead->val.pz = -1;
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			TMonom mon = p.pCurr->val;
			InsLast(mon);
		}
	}
	//�������� ������������
	void operator= (TPolinom &p) {
		///
	}
	//�������� �����
	TMonom& GetMonom() {
		return pCurr->val;
	}
	//�������� �����
	void InsMonom(TMonom mon) {
		for (Reset(); !IsEnd(); GoNext()) {
			if (mon == GetMonom()){
				double tmp = mon.coeff + GetMonom().coeff;
				if (tmp)
					//GetMonom().coeff = tmp;
					pCurr->val.coeff = tmp;
				else
					DelCurr();
				return;
			}
			if (mon > GetMonom()) {
				InsCurr(mon);
				return;
			}
			InsLast(mon);
		}
	}
	//��������� �� �����
	void operator*= (TMonom mon) {
		for (Reset(); !IsEnd(); GoNext()) {
			pCurr->val.coeff *= mon.coeff;
			pCurr->val.px += mon.px;
			pCurr->val.py += mon.py;
			pCurr->val.pz += mon.pz;
		}
		return;
	}
	//�������� ������
	TPolinom operator* (TMonom mon) {
		TPolinom res = *this;
		res *= mon;
		return res;
	}
	//����� ��������
	friend std::ostream& operator<<( std::ostream &os, TPolinom &p) {
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			std::cout << p.pCurr->val.coeff << "x^" << p.pCurr->val.px << "y^" << p.pCurr->val.py << "z^" << p.pCurr->val.pz << " + ";//<<  std::endl;
		}
		return os;
	}
};