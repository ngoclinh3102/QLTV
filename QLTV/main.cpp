
#include "QLDG.h"
#include "QLDauSach.h"

using namespace std;

int main()
{
	SetConsoleTitle("Quan Ly Thu Vien - Nhom 53");
	resizeConsole(1200,675);
	//===DOC FILE
	DocDSMaThe();
	DocDSDocGia();
	DocDSDauSach();
	
	//===XU LI
	bool flag= true;
	while(flag)
	{
//		SetWindow();
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
//				cout<<"quan li dau sach";
				runQLDS();
				break;
			}
			case 3: {
				NhapVaoMaDocGia();
//				system("pause");
				break;
			}
			case 4: {
				cout<<"good bye\n\n";
				flag= false;
				break;
			}
		}
//	system("pause");
	}
	system("cls");
	//ghi file
	GhiDSDocGia();
	GhiDSMaThe();
	GhiDSDauSach();
	
//	system("pause");
	return 0;
}
