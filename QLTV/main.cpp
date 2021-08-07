
#include "ThongKe.h"

using namespace std;

int main()
{
	SetConsoleTitle("Quan Ly Thu Vien - Nhom 53");
	resizeConsole(1200,675);
	//===DOC FILE
	DocDSMaThe();
	DocDSDocGia();
	DocDSDauSach();
	//===THONG KE DG MUON QUA HAN
	ThongKeQuaHan(tree);
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
			case 4: //thong ke
			{
				runThongKe();
				break;
			}
			case 5: {
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
