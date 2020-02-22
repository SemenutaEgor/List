#pragma once
#include "tlist.h"
#include "theadlist.h"
struct TMonom {
	double coeff;
	int px, py, pz;
	//конструктор
	TMonom() {
		coeff = 0;
		px = py = pz = 0;
	}
	//операторы сравнения
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
	bool operator== (TMonom& mon) {
		if (*this == mon)
			return false;
		else
			return true;
	}
};