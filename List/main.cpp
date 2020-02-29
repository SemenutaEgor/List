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
	const int sizem = 3; // Размер массива коэффициентов
	int arr[sizem][2];
	for (int i = 0; i < sizem; i++) {
		cout << "Введите " << i << " коэффициент" << endl;
		cin >> arr[i][0];
		cout << "Введите степени" << endl;
		cin >> arr[i][1];
	}
	/*arr[0][0] = 5;
	arr[0][1] = 222;
	arr[1][0] = 3;
	arr[1][1] = 111;*/
	TPolinom pol(arr, sizem);
	cout << pol;

}