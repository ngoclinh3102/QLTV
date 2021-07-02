#include <iostream>
#include "GiaoDien.h"
using namespace std;

int main() {
	SetWindow();
	int chon;
	chon = MenuDong(Menu);
	switch(chon) {
		case 1: {
			cout<<"quan li doc gia";
			break;
		}
		case 2: {
			cout<<"quan li dau sach";
			break;
		}
		case 3: {
			cout<<"muon/tra sach";
			break;
		}
		case 4: {
			cout<<"good bye\n\n";
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}
