#include <iostream>
#include "tlist.h"
#include "theadlist.h"
#include "tpolinom.h"

using namespace std;

void main() {
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
	int arr[2][2];
	arr[0][0] = 5;
	arr[0][1] = 222;
	arr[1][0] = 3;
	arr[1][1] = 111;
	TPolinom pol(arr, 2);
	cout << pol;

}