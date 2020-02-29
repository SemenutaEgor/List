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
		int sizem; // Размер массива коэффициентов
		int column = 2;
		int** arr;
		cout << "Введите размер многочлена" << endl;
		cin >> sizem;
		arr = new int*[sizem];
		for (int i = 0; i < sizem; i++)
			arr[i] = new int[column];

		for (int i = 0; i < sizem; i++) {
			cout << "Введите " << i << " коэффициент" << endl;
			cin >> arr[i][0];
			cout << "Введите степени" << endl;
			cin >> arr[i][1];
		}
		TPolinom pol(arr, sizem);
		cout << pol;
		int sizem1; // Размер массива коэффициентов
		int column1 = 2;
		int** arr1;
		cout << "Введите размер многочлена" << endl;
		cin >> sizem1;
		arr1 = new int*[sizem1];
		for (int i = 0; i < sizem1; i++)
			arr1[i] = new int[column1];

		for (int i = 0; i < sizem1; i++) {
			cout << "Введите " << i << " коэффициент" << endl;
			cin >> arr1[i][0];
			cout << "Введите степени" << endl;
			cin >> arr1[i][1];
		}
		TPolinom pol1(arr1, sizem1);
		cout << pol1;
		pol += pol1;
		cout << pol;
}