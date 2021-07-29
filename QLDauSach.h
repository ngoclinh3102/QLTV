#pragma once

#include "GiaoDien.h"

#define MaxOfDauSach 300

char dausach_mang[55]= "C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\dausach_mang.txt";

const int xDS= 3; //ve menu dau sach
const int yDS= 1;
const int xListDS= 32; //ve + in danh sach dau sach
const int yListDS= 0;
const int xListDMS= xListDS; //ve + in danh sach danh muc sach
const int yListDMS= yListDS+5;
const int itemDS= 6;
const int itemDMS= 4;
const int nTheLoai= 13;
const int yNhap= itemDS+3;

char MenuQLDS[itemDS][35]=
{
	"    NHAP DAU SACH         ",
	"    HIEU CHINH DAU SACH   ",
	" IN DS DAU SACH (THELOAI) ",
	"    XOA DAU SACH          ",
	"    QL DANH MUC SACH      ",
	"    THOAT QLDS            "
};

char MenuQLDMS[itemDMS][35]=
{
	"    NHAP                  ",
	"    SUA                   ",
	"    XOA                   ",
	"    THOAT                 "
};

string DSTheLoai[nTheLoai]=
{
	" Van Hoc    ",
	" Toan Hoc   ",
	" Kinh Te    ",
	" Ngoai Ngu  ",
	" Tieu Thuyet",
	" Tam Ly     ",
	" Ton Giao   ",
	" Phap Luat  ",
	" KH - CN    ",
	" Lich Su    ",
	" Thieu Nhi  ",
	" Chinh Tri  ",
	" Triet Hoc  "
};
//==============KHAI BAO CTDL=================//
struct danhmucsach
{
	string masach;
	int trangthai= 0; //0-co the muon, 1-da cho muon, 2-da thanh ly
	string ke;
	int ngan;
};
typedef struct danhmucsach DMS;

struct node_dms
{
	DMS data;
	node_dms* next;
};
//typedef struct node_dms NODE_DMS;
typedef struct node_dms* PTR_DMS;

struct dausach
{
	string ISBM;
	string tensach;
	string tacgia;
	string theloai;
	int namxb;
	int trang;
	int nDMS= 0; //so luong sach trong dau sach
	int luotmuon= 0; //thong ke so luot muon cua dau sach
	PTR_DMS dms;
};
typedef struct dausach* DauSach;

struct danhsach_dausach
{
	int sl=0; //so luong dau sach
	DauSach ds[MaxOfDauSach];
};
typedef struct danhsach_dausach DS_DauSach;
//typedef struct danhsach_dausach* List_DauSach;

//================KHAI BAO NGUYEN MAU HAM==========//
//=========Giao dien======
void VeKhungDauSach();
int MenuDongQLDS(char td [itemDS][35], int x, int y);
void VeKhungMenuQLDS();
void XoaDSDauSach();
void XoaMenuQLDS();

//============Nhap dau sach==========
void NhapDauSach(DS_DauSach &mang);
void ThemDauSach(DS_DauSach &mang, DauSach p);

//Nhap the loai
string NhapTheLoai(int x, int y, string str);

//============In danh sach dau sach===============
void InDSDauSach(DS_DauSach mang);

//=================== QL DANH MUC SACH ===================//
void runQLDMS();
int NhapDeTimChuoiTrongChuoi(int x, int y, DS_DauSach mang);
//======== Ve giao dien========
void VeKhungDS_DMS();
void XoaKhungDS_DMS();

//============Khoi tao===========//
DS_DauSach Mang_DS;

//=================== HAM QL DAU SACH ===================//
void runQLDS()
{
	system("cls");
	Normal();
	VeKhungDauSach();
	KhungThongBao();
	
	int chon;
//	bool kt= true;
	while(true)
	{
		chon= MenuDongQLDS(MenuQLDS,xDS,yDS);
		switch(chon)
		{
			case 1: //Nhap dau sach
			{
				NhapDauSach(Mang_DS);
				break;
			}
			case 2: //Hieu chinh
			{
				break;
			}
			case 3: //In danh sach dau sach
			{
				XoaDSDauSach();
				if(Mang_DS.sl==0) ThongBao("Danh sach rong");
				else InDSDauSach(Mang_DS);
				break;
			}
			case 4: //Xoa dau sach (co dieu kien)
			{
				break;
			}
			case 5: //Quan li Danh muc sach
			{
				gotoxy(0,yNhap); cout << "Nhap ten sach: ";
				int t= NhapDeTimChuoiTrongChuoi(15,yNhap,Mang_DS);
				if(t==-1)
				{
					gotoxy(0,yNhap+1); cout << "ESC";
				}
				else
				{
					runQLDMS();
				}
				break;
			}
			case 6: //Thoat
			{
				return;
			}
		}
	}
}

//==========Ve giao dien========
void VeKhungDauSach()
{
	gotoxy(xListDS,yListDS);	cout << "+---------------------------------------------------------------------------------------+";
	gotoxy(xListDS,yListDS+1);	cout << "|STT| ISBM |        Ten Sach        |     Tac Gia      |  The Loai   |Nam XB|Trang| SL  |";
	gotoxy(xListDS,yListDS+2);	cout << "|---+------+------------------------+------------------+-------------+------+-----+-----|";
//								cout << "|   |      |                        |                  |             |      |     |     |";
//								cout << "                                                                                         ";
}

void VeKhungMenuQLDS()
{
	gotoxy(xQLDG-1,yQLDG-1); cout << "+--------------------------+";
	gotoxy(xQLDG-1,yQLDG);   cout << "|                          |";
	gotoxy(xQLDG-1,yQLDG+1); cout << "|                          |";
	gotoxy(xQLDG-1,yQLDG+2); cout << "|                          |";
	gotoxy(xQLDG-1,yQLDG+3); cout << "|                          |";
	gotoxy(xQLDG-1,yQLDG+4); cout << "|                          |";
	gotoxy(xQLDG-1,yQLDG+5); cout << "|                          |";
	gotoxy(xQLDG-1,yQLDG+6); cout << "+--------------------------+";
}

void XoaDSDauSach()
{
	for(int j=yListDS+3; j<25; j++)
	{
		gotoxy(xListDS,j); cout << "                                                                                         ";
	}
}

void XoaMenuQLDS()
{
	for(int j=0; j<21; j++)
	{
		gotoxy(0,j); cout << "                                ";
	}
}

int MenuDongQLDS(char td [itemDS][35], int x, int y)
{
	//Co the sua
	Normal();
	ShowCur(false);
	XoaThongBao();
	XoaMenuQLDS();
	VeKhungMenuQLDS();
	
	//Khong duoc sua
	for (int i=0; i<itemDS; i++)
	{
		gotoxy(x, y +i); cout << td[i];
	}
  	HighLight();
  	int chon =0;
  	gotoxy(x,y+chon);
  	cout << td[chon];
  	Normal();
  	int kytu;
	do {
  		kytu = getch();
  		if (kytu==0) kytu = getch();
  		switch (kytu) {
    		case Up:
				if (chon+1 >1) {
  		        	
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon --;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
  					
              		gotoxy(x,y+chon);
              		cout << td[chon];
  					chon = itemDS -1;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Down:
				if (chon+1 <itemDS) {
  		    		
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon ++;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
					
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon = 0;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Enter:
  				ShowCur(true);
				return chon+1;
		}
  	} while (1);
}

//================Nhap dau sach=================//
void NhapDauSach(DS_DauSach &mang)
{
	gotoxy(0,yNhap);	cout << "Nhap ma ISBM: ";
	gotoxy(0,yNhap+1);	cout << "Nhap ten sach: ";
	gotoxy(0,yNhap+2);	cout << "Nhap tac gia: ";
	gotoxy(0,yNhap+3);	cout << "Nhap the loai: ";
	gotoxy(0,yNhap+4);	cout << "Nhap nam xuat ban: ";
	gotoxy(0,yNhap+5);	cout << "Nhap so trang: ";
	
	DauSach p = new dausach;
	
	fflush(stdin); p->ISBM= NhapChuoiHoa(14,yNhap,p->ISBM);
	fflush(stdin); p->tensach= NhapTenSach(15,yNhap+1,p->tensach);
	fflush(stdin); p->tacgia= NhapChuoi(14,yNhap+2,p->tacgia);
	//Nhap the loai
	fflush(stdin); p->theloai= NhapTheLoai(15,yNhap+3,p->theloai);
	fflush(stdin); p->namxb= NhapNam(19,yNhap+4,p->namxb);
	fflush(stdin); p->trang= NhapSo(15,yNhap+5,p->trang);
	
	ThemDauSach(mang,p);
	delete p;
	ThongBao("Nhap thanh cong!");
}

void ThemDauSach(DS_DauSach &mang, DauSach p)
{
	mang.ds[mang.sl]= new dausach;
	mang.ds[mang.sl]->ISBM = p->ISBM;
	mang.ds[mang.sl]->tensach = p->tensach;
	mang.ds[mang.sl]->tacgia = p->tacgia;
	mang.ds[mang.sl]->theloai = p->theloai;
	mang.ds[mang.sl]->namxb = p->namxb;
	mang.ds[mang.sl]->trang = p->trang;
	mang.sl++; //1
	
	int i=mang.sl-1;
	while(i>0 && mang.ds[i]->theloai.compare(mang.ds[i-1]->theloai) <= 0)
	{
		if(mang.ds[i]->theloai.compare(mang.ds[i-1]->theloai) == 0 )
		{
			if(mang.ds[i]->tensach.compare(mang.ds[i-1]->tensach) >= 0 ) continue;
		}

		DauSach temp = new dausach;
		temp= mang.ds[i];
		mang.ds[i] = mang.ds[i-1];
		mang.ds[i-1] = temp;
//		delete mang.ds[i-1];
		i--;

	}
}

//====================In danh sach dau sach========================//
void InDSDauSach(DS_DauSach mang)
{
	for(int i=0; i<mang.sl; i++)
	{
		gotoxy(xListDS,yListDS+3+i);		cout << "|   |      |                        |                  |             |      |     |     |";
		gotoxy(xListDS+2,yListDS+3+i);	cout << i+1;
		gotoxy(xListDS+6,yListDS+3+i);	cout << mang.ds[i]->ISBM;
		gotoxy(xListDS+13,yListDS+3+i);	cout << mang.ds[i]->tensach;
		gotoxy(xListDS+38,yListDS+3+i);	cout << mang.ds[i]->tacgia;
		gotoxy(xListDS+56,yListDS+3+i);	cout << mang.ds[i]->theloai;
		gotoxy(xListDS+71,yListDS+3+i);	cout << mang.ds[i]->namxb;
		gotoxy(xListDS+78,yListDS+3+i);	cout << mang.ds[i]->trang;
		gotoxy(xListDS+84,yListDS+3+i);	cout << mang.ds[i]->nDMS;
		Sleep(25);
	}
}

//================Nhap the loai=================
string NhapTheLoai(int x, int y, string str)
{
	int i=0;
	
	int chr;
	do
	{
		gotoxy(x,y);	cout << "< " << DSTheLoai[i] << " >";
		fflush(stdin);
		chr= getch();
		if(chr==Enter)
		{
			return DSTheLoai[i];
		}
		else if(chr==Left)
				{
					if(i==0) i=nTheLoai-1;
					else i--;
				}
		else if(chr==Right)
				{
					if(i== (nTheLoai-1)) i=0;
					else i++;
				}
	} while(chr!=ESC);
	return "tba";
}

//================= QL Danh muc sach =========================//
//==== Tim chuoi trong chuoi ===//
int NhapDeTimChuoiTrongChuoi(int x, int y, DS_DauSach mang)
{
	string str;
	char* c = new char[10];
	
	int vitri= 0;
	int n; //kiem tra so luong dau sach dang hien thi
	int key; //bien luu gia tri thu i thoa dieu kien
	int chr;
    do
	{
		gotoxy(x + vitri, y);
        fflush(stdin);
        chr = getch();
        if (chr == Enter && vitri != 0 && n==1)
        {
        	delete[] c;
            return key;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || chr == ' ' || chr>='0' && chr <= '9') && vitri < nameMAX)
        {
            if ( chr== ' ' && ( vitri==0 || c[vitri - 1]==' ')) continue;
			if ( vitri==0 || c[vitri - 1]==' ')	c[vitri] = char(toupper(chr));
            else c[vitri] = char(tolower(chr));
            cout << c[vitri];
            vitri++;
        }
        
        c[vitri]='\0';
        str=c;
        n=0;
        XoaDSDauSach();
        
        for(int i=0; i<mang.sl; i++)
        {
        	if(TimChuoiCon(str,mang.ds[i]->tensach)==1)
        	{
        		key++;
        		gotoxy(xListDS,yListDS+3+n);	cout << "|   |      |                        |                  |             |      |     |     |";
				gotoxy(xListDS+2,yListDS+3+n);	cout << n+1;
				gotoxy(xListDS+6,yListDS+3+n);	cout << mang.ds[i]->ISBM;
				gotoxy(xListDS+13,yListDS+3+n);	cout << mang.ds[i]->tensach;
				gotoxy(xListDS+38,yListDS+3+n);	cout << mang.ds[i]->tacgia;
				gotoxy(xListDS+56,yListDS+3+n);	cout << mang.ds[i]->theloai;
				gotoxy(xListDS+71,yListDS+3+n);	cout << mang.ds[i]->namxb;
				gotoxy(xListDS+78,yListDS+3+n);	cout << mang.ds[i]->trang;
				gotoxy(xListDS+84,yListDS+3+n);	cout << mang.ds[i]->nDMS;
				
				n++;
				key=i;
				Sleep(9);
			}
		}
    } while (chr != ESC);
    
    delete[] c;
    return -1;
}

//====
void runQLDMS()
{
	MenuDongQLDS(MenuQLDMS,xDS,yDS);
	
	getch();
}

//======= Ve giao dien ====
void VeKhungDS_DMS()
{
	gotoxy(xListDMS,yListDMS);		cout << "+---------------------------------------------------------------------------------------+";
	gotoxy(xListDMS,yListDMS+1);	cout << "| STT |   Ma Sach   |  Vi Tri  |    Trang Thai    |                Ghi Chu              |";
	gotoxy(xListDMS,yListDMS+2);	cout << "|-----+-------------+----------+------------------+-------------------------------------|";
//									cout << "|     |             |          |                  |                                     |";
//									cout << "                                                                                         ";
}
void XoaKhungDS_DMS()
{
	for(int j=yListDMS+3; j<25; j++)
	{
		gotoxy(xListDMS,j);
		cout << "                                                                                         ";
	}
}

//========================== DOC / GHI FILE ===============================//
void GhiDSDauSach()
{
	clearFileContent(dausach_mang);
	//mo file
	ofstream FileOut;
	FileOut.open(dausach_mang, ios_base::out);
	if(FileOut.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file dausach_mang de ghi!" << endl;
		system("pause");
		return;
	}
	//ghi file
	int n= Mang_DS.sl;
	FileOut << n;
//	FileOut << Mang_DS.ds[0]->ISBM << "|" << Mang_DS.ds[0]->tensach << "|" << Mang_DS.ds[0]->tacgia << "|" << Mang_DS.ds[0]->theloai << "|" << Mang_DS.ds[0]->namxb << "|" << Mang_DS.ds[0]->trang << "|" << Mang_DS.ds[0]->nDMS;                          //
	for(int i=0; i<n; i++)
	{
	FileOut << endl << Mang_DS.ds[i]->ISBM << "|" << Mang_DS.ds[i]->tensach << "|" << Mang_DS.ds[i]->tacgia << "|" << Mang_DS.ds[i]->theloai << "|" << Mang_DS.ds[i]->namxb << "|" << Mang_DS.ds[i]->trang << "|" << Mang_DS.ds[i]->luotmuon << "|" << Mang_DS.ds[i]->nDMS;                   //
	//danh muc sach??
	}
	
	//dong file
	FileOut.close();
	cout << "Ghi file dausach_mang thanh cong!" << endl;
	Sleep(500);
	//system("pause");
}

void DocDSDauSach()
{
	//
	ifstream FileIn;
	FileIn.open(dausach_mang, ios_base::in);
	if(FileIn.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file dausach_mang de doc!!" << endl;
		system("pause");
		return;
	}
	//
	FileIn >> Mang_DS.sl;
	for(int i=0; i<Mang_DS.sl; i++)
	{
		Mang_DS.ds[i] = new dausach;
		FileIn.ignore();
		getline(FileIn, Mang_DS.ds[i]->ISBM, '|');
		getline(FileIn, Mang_DS.ds[i]->tensach, '|');
		getline(FileIn, Mang_DS.ds[i]->tacgia, '|');
		getline(FileIn, Mang_DS.ds[i]->theloai, '|');
		FileIn >> Mang_DS.ds[i]->namxb;
		FileIn.ignore();
		FileIn >> Mang_DS.ds[i]->trang;
		FileIn.ignore();
		FileIn >> Mang_DS.ds[i]->luotmuon;
		FileIn.ignore();
		FileIn >> Mang_DS.ds[i]->nDMS;
		//ghi danh muc sach ??
	}
	//
	FileIn.close();
	cout << "Doc file dausach_mang thanh cong!" << endl;
	Sleep(500);
}




//===== de day va khong noi gi =====//
