#include <iostream>
#include "GiaoDien.h"
#include "QLDG.h"
using namespace std;

int main() {
	
	bool flag= true;
	while(flag)
	{
		SetWindow();
		int chon;
		chon = MenuDong(Menu);
		switch(chon)
		{
			case 1: {
				//cout<<"quan li doc gia";
				runQLDG();
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
				flag= false;
				break;
			}
		}
	system("pause");
	}
	
	return 0;
}
