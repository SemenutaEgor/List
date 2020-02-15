#include <iostream>
#include "tlist.h"
#include "theadlist.h"

using namespace std;

void main() {
	/*TList<int> l;
	for (int i = 0; i < 10; i++) {
		l.InsCurr(i);
	}
	for (l.Reset(); !l.IsEnd(); l.GoNext())
		cout << l.GetCurrEl() << "\n";*/
	THeadList<int> l;
	l.InsFirst(5);
	l.Reset();
	cout << l.GetCurrEl() << endl;
}