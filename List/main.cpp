#include <iostream>
#include "tlist.h"
#include "theadlist.h"
#include "tpolinom.h"

using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");
	/*TList<int> l;
	for (int i = 0; i < 10; i++) {
		l.InsCurr(i);
	}
	for (l.Reset(); !l.IsEnd(); l.GoNext())
		cout << l.GetCurrEl() << "\n";*/
		/*THeadList<int> l;
		l.InsFirst(5);
		l.Reset();
		cout << l.GetCurrEl() << endl;*/
	/************************************************************/
		int sizem; // ������ ������� �������������
		int column = 2;
		int** arr;
		cout << "������� ������ ����������" << endl;
		cin >> sizem;
		arr = new int*[sizem];
		for (int i = 0; i < sizem; i++)
			arr[i] = new int[column];

		for (int i = 0; i < sizem; i++) {
			cout << "������� " << i << " �����������" << endl;
			cin >> arr[i][0];
			cout << "������� �������" << endl;
			cin >> arr[i][1];
		}
		TPolinom pol(arr, sizem);
		cout << pol;
		int sizem1; // ������ ������� �������������
		int column1 = 2;
		int** arr1;
		cout << "������� ������ ����������" << endl;
		cin >> sizem1;
		arr1 = new int*[sizem1];
		for (int i = 0; i < sizem1; i++)
			arr1[i] = new int[column1];

		for (int i = 0; i < sizem1; i++) {
			cout << "������� " << i << " �����������" << endl;
			cin >> arr1[i][0];
			cout << "������� �������" << endl;
			cin >> arr1[i][1];
		}
		TPolinom pol1(arr1, sizem1);
		cout << pol1;
		/************************************************************************************/
		/*int arrm[1][2];
		cout << "������� ����������� ������" << endl;
		cin >> arrm[0][0];
		cout << "������� �������" << endl;
		cin >> arrm[0][1];
		TMonom monom(arrm);
		pol.InsMonom(monom);
		cout << pol << endl;*/
		//pol += pol1;
		//cout << pol;
		/*******************************************************************/
	int f = 0, c = 0, a = 0;
	int arrm[1][2];
	while (true) {
		cout << "��������� �� ����� ��������� - 1" << endl;
		cout << "��������� �� ����� - 2" << endl;
		cout << "�������� � ������� ����� - 3" << endl;
		cout << "������� ��� �������� - 4" << endl;
		cout << "������� �������� - 5" << endl;
		cout << "������� f" << endl;
		cin >> f;
		switch (f) {
		case 1:
			cout << "�������� ������� 1 ��� 2" << endl;
			cin >> c;
			cout << "������� ����� ���������" << endl;
			cin >> a;
			if (c == 1) {
				pol *= a;
				cout << pol;
			}
			else
			{
				pol1 *= a;
				cout << pol1;
			}
			break;
		case 2: {
			cout << "�������� ������� 1 ��� 2" << endl;
			cin >> c;
			cout << "������� ����������� ������" << endl;
			cin >> arrm[0][0];
			cout << "������� �������" << endl;
			cin >> arrm[0][1];
			TMonom monom(arrm);
			if (c == 1) {
				pol *= monom;
				cout << pol << endl;
			}
			else {
				pol1 *= monom;
				cout << pol1 << endl;
			}
			break;
		}
		case 3: {
			cout << "�������� ������� 1 ��� 2" << endl;
			cin >> c;
			cout << "������� ����������� ������" << endl;
			cin >> arrm[0][0];
			cout << "������� �������" << endl;
			cin >> arrm[0][1];
			TMonom monom1(arrm);
			if (c == 1) {
				pol.InsMonom(monom1);
				cout << pol << endl;
			}
			else {
				pol1.InsMonom(monom1);
				cout << pol1 << endl;
			}
			break;
		}
		case 4:
			cout << pol + pol1 << endl;
			break;
		case 5:
			cout << "1)" << pol << endl;
			cout << "2)" << pol1 << endl;
			break;
		case 0:
			return;
		default:
			continue;
		}
	}
}