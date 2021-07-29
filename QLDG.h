#pragma once

#include "DocGia.h"

using namespace std;

char docgia_tree[55]= "C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_tree.txt";
char docgia_mathe[55]= "C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_mathe.txt";
const int quantity= 6;
const int xQLDG= 3;
const int yQLDG= 1;
const int nGioiTinh= 2;

#define nlc 8

string GioiTinh[nGioiTinh]=
{
	"Nam",
	"Nu ",
};

//===============Ve Khung==============
void KhungTieuDe();
void VeKhungMenu();
void XoaMenuQLDG();
void XoaDSDocGia();
int MenuDongQLDG(char td [items][50], int x, int y);
char MenuQLDG[quantity][50]=
{
	"  NHAP DOC GIA         ",
	"  DS DOC GIA (MA THE)  ",
	"  DS DOC GIA (HO TEN)  ",
	"  HIEU CHINH           ",
	"  XOA DOC GIA          ",
	"  THOAT QLDG           "
};

//==================Nhap doc gia============
void NhapDG(TREE_DG &tree);
// Nhap gioi tinh ? ? ?
string NhapGioiTinh(int x, int y, string str);


//===============Xuat danh sach doc gia====
void ChuyenCaySangMang(TREE_DG tree, NODE_DG *ds[], int &nds); //InOrder: list theo thu tu mathe tang dan
void XuatDSDG(NODE_DG *ds[], int &nds);
void InDSDG(NODE_DG *ds[], int &nds);
void GiaiPhongDS(NODE_DG *ds[], int &nds);

//========================Sap xep theo ten==
void SapXepTheoTen(NODE_DG *ds[], int &nds); //Sap xep mang theo ten (ho) tang dan
void HoanViDG(NODE_DG *a, NODE_DG *b);

//===============Xoa doc gia theo ma the===========
int TimDocGia(TREE_DG tree);

//================HIEU CHINH DOC GIA=====================
int TimMaTheDocGia(TREE_DG tree);
void HieuChinhDG(TREE_DG &tree);

//=================DOC GHI FILE==============
int DSMaThe[1024];
void DocDSMaThe();
TREE_DG tree = NULL;
void DocDSDocGia();
//==ghi file==
void GhiDSDocGia();
void SapXepTheoMaTheCanBang(NODE_DG *ds[], int &nds);
void GhiDSMaThe();

//================HAM XU LI================
void runQLDG() {
	system("cls");
	Normal();
	KhungTieuDe();
	if(tree!=NULL)
	{
		NODE_DG *ds[100];
		int nds=0;
		ChuyenCaySangMang(tree, ds, nds);
		InDSDG(ds,nds);
		GiaiPhongDS(ds,nds);
	}
	KhungThongBao();
	int chon;
	bool kt= true;
	while(kt)
	{
		//system("cls");
		//XoaMenuChon();
		//NhapLuaChon();
		
		chon= MenuDongQLDG(MenuQLDG,xQLDG,yQLDG);
		switch(chon)
		{
			case 1: //1. Nhap doc gia
			{
				NhapDG(tree);
				break;
			}
			case 2: //2. In DS doc gia (Ma the)
			{
				XoaDSDocGia();
				NODE_DG *ds[100];
				int nds=0;
				if(tree==NULL)
				{
					ThongBao("Danh sach rong");
					break;
				}
				ChuyenCaySangMang(tree, ds, nds);
				InDSDG(ds,nds);
				
				GiaiPhongDS(ds,nds);
				break;
			}
			case 3: //3. In DS doc gia (Ten)
			{
				XoaDSDocGia();
				NODE_DG *ds[100];
				int nds=0;
				if(tree==NULL)
				{
					ThongBao("Danh sach rong");
					break;
				}
				ChuyenCaySangMang(tree, ds, nds);
				SapXepTheoTen(ds,nds);
				//SapXepTheoMaTheCanBang(ds,nds);
				InDSDG(ds,nds);
				
				GiaiPhongDS(ds,nds);
				break;			
			}
			case 4: //Hieu chinh
			{
				HieuChinhDG(tree);
				
				//In lai DS
				NODE_DG *ds[100];
				int nds=0;
				ChuyenCaySangMang(tree, ds, nds);
				InDSDG(ds,nds);
				GiaiPhongDS(ds,nds);
				
				break;
			}
			case 5: //4. Xoa doc gia
			{
				//XoaDSDocGia();
				//Xu li
				int x;
				x= TimDocGia(tree);
				switch(x)
				{
					case -3: //Doc gia da muon/tra, khong the xoa
					{
						Sleep(999);
						break;
					}
					case -2: //Danh sach rong
					{
						ThongBao("Danh sach rong");
						break;
						
					}
					case -1: //Ma doc gia khong ton tai
					{
						ThongBao("Ma khong ton tai");
						break;
					}
					case 0: //Khong xoa
					{
						ThongBao("Khong xoa");
						break;
					}
					default:
					{
						Xoa_DG(x,tree);
						
						//In lai
						NODE_DG *ds[100];
						int nds=0;
						if(tree==NULL)
						{
							ThongBao("Danh sach rong");
							break;
						}
						ChuyenCaySangMang(tree, ds, nds);
						InDSDG(ds,nds);
				
						GiaiPhongDS(ds,nds);
						break;
					}
				}

				break;
			}
			
			case 6: //0. Thoat
			{
				kt= false;
				break;
			}
			default:
			{
				cout << "Chon sai!";
				Sleep(999);
				break;
			}
		}
	}
}

//============Ve khung de xuat danh sach======
void KhungTieuDe()
{
	gotoxy(40,0); cout << "+-------------------------------------------------------------------------------+";
	gotoxy(40,1); cout << "| STT |  Ma The  |      Ho      |       Ten       | Phai |Trang thai the|Ghi chu|";
	gotoxy(40,2); cout << "|-----+----------+--------------+-----------------+------+--------------+-------|";
//	              cout << "|     |          |              |                 |      |              |       |";
}

void VeKhungMenu()
{
	gotoxy(xQLDG-1,yQLDG-1); cout << "+-----------------------+";
	gotoxy(xQLDG-1,yQLDG);   cout << "|                       |";
	gotoxy(xQLDG-1,yQLDG+1); cout << "|                       |";
	gotoxy(xQLDG-1,yQLDG+2); cout << "|                       |";
	gotoxy(xQLDG-1,yQLDG+3); cout << "|                       |";
	gotoxy(xQLDG-1,yQLDG+4); cout << "|                       |";
	gotoxy(xQLDG-1,yQLDG+5); cout << "|                       |";
	gotoxy(xQLDG-1,yQLDG+6); cout << "+-----------------------+";
	
}

void XoaMenuQLDG()
{
	for(int i=0; i<21; i++)
	{
		gotoxy(0,i); cout << "                                        ";
	}
}
void XoaDSDocGia()
{
	for(int j=3; j<25; j++)
	{
		gotoxy(40,j); cout << "                                                                                 ";
	}
}

int MenuDongQLDG(char td [quantity][50], int x, int y)
{
	Normal();
	ShowCur(false);
	XoaThongBao();
	XoaMenuQLDG();
	VeKhungMenu();
	//Ve Menu
	for (int i=0; i<quantity; i++)
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
  					chon = quantity -1;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Down:
				if (chon+1 <quantity) {
  		    		
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


//================Nhap doc gia================
void NhapDG(TREE_DG &tree)
{
//	system("cls");
	NODE_DG *p = KhoiTaoNode_DocGia();
	DSMaThe[0]++;
	int i= DSMaThe[0];
	p->data.mathe= DSMaThe[i];
	gotoxy(0,nlc+1); cout << "Ma the: " << p->key;
	gotoxy(0,nlc+2); cout << "Nhap ho: ";
	gotoxy(0,nlc+3); cout << "Nhap ten: ";
	gotoxy(0,nlc+4); cout << "Nhap phai: ";
	
	//gotoxy(9,nlc+2); getline(cin, p->data.ho);
	fflush(stdin); p->data.ho= NhapChuoi(9,nlc+2,p->data.ho);
	//gotoxy(10,nlc+3); getline(cin, p->data.ten);
	fflush(stdin); p->data.ten= NhapChuoi(10,nlc+3,p->data.ten);
	//gotoxy(11,nlc+4); getline(cin, p->data.phai);
	fflush(stdin); p->data.phai= NhapGioiTinh(11,nlc+4,p->data.phai);
	
	Them_DG(tree,p);
	ThongBao("Nhap thanh cong!");
	
//	delete p;
}
//==============Xuat danh sach doc gia===========
void ChuyenCaySangMang(TREE_DG tree, NODE_DG *ds[], int &nds)
{
	if(tree != NULL)
	{
		ChuyenCaySangMang(tree->left,ds,nds);
		
		ds[nds] = new NODE_DG;
		ds[nds]->key = tree->key;
		ds[nds]->data = tree->data;
		nds++;
		
		ChuyenCaySangMang(tree->right,ds,nds);
	}
}
//====Giai phong mang tam====
void GiaiPhongDS(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds; i++) delete ds[i];

}
//void XuatDSDG(NODE_DG *ds[], int &nds)
//{
//	for(int i=0; i<nds; i++)
//	{
//		cout << "\t===Nhan vien " << i+1 << ":" << endl;
//		cout << "Ma the: " << ds[i]->data.mathe << endl;
//		cout << "Ho: " << ds[i]->data.ho << endl;
//		cout << "Ten: " << ds[i]->data.ten << endl;
//		cout << "Phai: " << ds[i]->data.phai << endl;
//		cout << "Trang thai the: ";
//			if(ds[i]->data.trangthaithe == 1) cout << "Dang hoat dong" << endl;
//			else if(ds[i]->data.trangthaithe == 0) cout << "Da bi khoa" << endl;
//		
//	}
//	//system("pause");
//}
void InDSDG(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds; i++)
	{
		gotoxy(40,3+i); cout << "|     |          |              |                 |      |              |       |";
		gotoxy(42,3+i); cout << i+1;
		gotoxy(49,3+i); cout << ds[i]->data.mathe;
		gotoxy(59,3+i); cout << ds[i]->data.ho;
		gotoxy(75,3+i); cout << ds[i]->data.ten;
		gotoxy(92,3+i); cout << ds[i]->data.phai;
		gotoxy(98,3+i); if(ds[i]->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(ds[i]->data.trangthaithe == 0) cout << "  Da bi khoa";
						else if(ds[i]->data.trangthaithe == -1) cout << "  Moi tao";
		Sleep(25);
	}
}

void SapXepTheoTen(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds-1; i++)
	{
		for(int j=i+1; j<nds; j++)
		{
			if(ds[i]->data.ten > ds[j]->data.ten) HoanViDG(ds[i],ds[j]);
			else if(ds[i]->data.ten == ds[j]->data.ten)
					if(ds[i]->data.ho > ds[j]->data.ho) HoanViDG(ds[i],ds[j]);
		}
	}
}
//===Hoan vi 2 doc gia trong mang tam=====
void HoanViDG(NODE_DG *a, NODE_DG *b)
{
	NODE_DG *temp = new NODE_DG;
	
	temp->data = a->data;
	a->data = b->data;
	b->data = temp->data;
	
	delete temp;
}
//===============Xoa doc gia theo ma the===========
int TimDocGia(TREE_DG tree) //tim + in + xac nhan xoa
{
	if(tree==NULL) return -2; //danh sach rong
	gotoxy(0,8); cout << " >>> Nhap ma doc gia: ";
	fflush(stdin);
	int x= NhapSo(22,8,x);
	while(tree!=NULL)
	{
		if(x == tree->key) break; //tim thay
		else if(x > tree->key) tree= tree->right;
			 else if(x < tree->key) tree= tree->left;
	}
	if(tree==NULL) return -1; //khong ton tai
	else
	{
		XoaDSDocGia();
		gotoxy(40,3); cout << "|  X  |          |              |                 |      |              |       |";
		gotoxy(49,3); cout << tree->data.mathe;
		gotoxy(59,3); cout << tree->data.ho;
		gotoxy(75,3); cout << tree->data.ten;
		gotoxy(92,3); cout << tree->data.phai;
		gotoxy(98,3); if(tree->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(tree->data.trangthaithe == 0) cout << "  Da bi khoa";
						else if(tree->data.trangthaithe == -1) cout << "  Moi tao";
	}
	if(tree->data.trangthaithe == 1 || tree->data.trangthaithe == 0)
	{
		gotoxy(0,9); cout << "Ban khong the xoa doc gia nay";
		return -3;
	}
	gotoxy(0,9); cout << "Nhap lai chinh xac ma doc gia de xoa: ";
	int kt; cin >> kt;
	if(kt == x) return x; //Xoa
	return 0; //Nhap xac nhan bi sai, khong xoa
}
//================HIEU CHINH DOC GIA=====================
int TimMaTheDocGia(TREE_DG tree)
{
	if(tree==NULL) return -2; //danh sach rong
	
	gotoxy(0,nlc+1); cout << " >> Nhap ma doc gia: ";

	int x;
//	fflush(stdin); x= getch();
//	if(x==ESC) return -3; //thoat // tam thoi bo vi khong can thiet
	
	fflush(stdin); x= NhapSo(21,nlc+1,x);
//	int x; cin >> x;
	while(tree!=NULL)
	{
		if(x == tree->key) break; //tim thay
		else if(x > tree->key) tree= tree->right;
			 else if(x < tree->key) tree= tree->left;
	}
	if(tree==NULL) return -1; //khong ton tai
	else
	{
		XoaDSDocGia();
		gotoxy(40,3); cout << "| --> |          |              |                 |      |              |       |";
		gotoxy(49,3); cout << tree->data.mathe;
		gotoxy(59,3); cout << tree->data.ho;
		gotoxy(75,3); cout << tree->data.ten;
		gotoxy(92,3); cout << tree->data.phai;
		gotoxy(98,3); if(tree->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(tree->data.trangthaithe == 0) cout << "  Da bi khoa ";
						else if(tree->data.trangthaithe == -1) cout << "  Moi tao";
	}
	return x; //in ra thong tin roi tra ve x
}

void HieuChinhDG(TREE_DG &tree)
{
	int x;
	x= TimMaTheDocGia(tree);
	if(x== -3)
	{
		ThongBao("Thoat");
		return;
	}
	if(x == -2)
	{
		ThongBao("Danh sach rong");
		return;
	}
	if(x == -1)
	{
		ThongBao("Ma khong ton tai");
		return;
	}
	//NODE_DG *p = KhoiTaoNode_DocGia();
	TREE_DG t= tree;
	while(t!=NULL)
	{
		if(x == t->key) break; //tim thay
		else if(x > t->key) t= t->right;
			 else if(x < t->key) t= t->left;
	}
	gotoxy(0,nlc+2); cout << "1. Thay doi thong tin";
	gotoxy(0,nlc+3); if(t->data.trangthaithe == 1) cout << "2. Khoa the";
					 else if(t->data.trangthaithe == 0) cout << "2. Mo khoa the";
	gotoxy(0,nlc+4); cout << " >> "; 
	int ch;
	do
	{
		ch= getch();
		if(ch==ESC) return;
		else if(ch==Num1)
			{
				cout << "CHINH SUA THONG TIN:";
				gotoxy(0,nlc+5); cout << "Ma the: " << t->key;
				gotoxy(0,nlc+6); cout << "Nhap ho: " << t->data.ho;
				gotoxy(0,nlc+7); cout << "Nhap ten: " << t->data.ten;
				gotoxy(0,nlc+8); cout << "Nhap phai: " << t->data.phai;
			
				fflush(stdin); t->data.ho= NhapChuoi(9,nlc+6,t->data.ho);
				fflush(stdin); t->data.ten= NhapChuoi(10,nlc+7,t->data.ten);
				fflush(stdin); t->data.phai= NhapGioiTinh(11,nlc+8,t->data.phai);
				
				ThongBao("Cap nhat thanh cong");
				return;
			}
		else if(ch==Num2)
			{
				cout << "THAY DOI TRANG THAI THE:"; Sleep(99);
				if(t->data.trangthaithe == 1) t->data.trangthaithe= 0;
				else if(t->data.trangthaithe == 0) t->data.trangthaithe= 1;
				
				ThongBao("Cap nhat thanh cong");
				return;
			}
	} while(1);
	
}

//=================DOC GHI FILE==============//
void DocDSMaThe()
{
	ifstream FileIn;
	FileIn.open(docgia_mathe, ios_base::in);
	if(FileIn.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file docgia_mathe de doc!" << endl;
		system("pause");
		return;
	}
	for(int i=0; i<1024; i++)
	{
		FileIn >> DSMaThe[i];
	}
	FileIn.close();
	cout << "Doc file docgia_mathe thanh cong!" << endl;
	Sleep(500);
	//system("pause");
}
void DocDSDocGia()
{
	ifstream FileIn;
	FileIn.open(docgia_tree, ios_base::in);
	if(FileIn.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file docgia_tree de doc!!" << endl;
		system("pause");
		return;
	}
	while(FileIn.eof() != true)
	{
		NODE_DG *node = KhoiTaoNode_DocGia();
		FileIn >> node->data.mathe; FileIn.ignore();
		getline(FileIn, node->data.ho, '|');
		getline(FileIn, node->data.ten, '|');
		getline(FileIn, node->data.phai, '|');
		FileIn >> node->data.trangthaithe; FileIn.ignore();
		//? con tro muon tra ?
		
		Them_DG(tree,node);
	}
	FileIn.close();
	cout << "Doc file docgia_tree thanh cong!" << endl;
	Sleep(500);
}
//==ghi file==
void GhiDSDocGia()
{
	//Dua danh sach doc gia vao mang tam
	NODE_DG *ds[100];
	int nds=0;
	ChuyenCaySangMang(tree,ds,nds);
	//Sap xep dac biet
	SapXepTheoMaTheCanBang(ds,nds);
	//don sach file
	clearFileContent(docgia_tree);
	//mo file
	ofstream FileOut;
	FileOut.open(docgia_tree, ios_base::out);
	if(FileOut.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file docgia_tree de ghi!" << endl;
		system("pause");
		return;
	}
	//ghi file
	FileOut << ds[0]->data.mathe << "|" << ds[0]->data.ho << "|" << ds[0]->data.ten << "|" << ds[0]->data.phai << "|" << ds[0]->data.trangthaithe;
	for(int i=1; i<nds; i++)
	{
		//if(i != 0) cout << endl;
		FileOut << "\n" << ds[i]->data.mathe << "|" << ds[i]->data.ho << "|" << ds[i]->data.ten << "|" << ds[i]->data.phai << "|" << ds[i]->data.trangthaithe;
	}
	//dong file
	FileOut.close();
	cout << "Ghi file docgia_tree thanh cong!" << endl;
	Sleep(500);
	//system("pause");	
}
void SapXepTheoMaTheCanBang(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds-1; i++)
	{
		if(ds[i]->data.mathe == DSMaThe[i+1]) continue;
		int j=i+1;
		for( ; j<nds; j++)
		{
			if(ds[j]->data.mathe == DSMaThe[i+1]) break;
		}
		HoanViDG(ds[i],ds[j]);
	}
}
void GhiDSMaThe()
{
	clearFileContent(docgia_mathe);
	ofstream FileOut;
	FileOut.open(docgia_mathe, ios_base::out);
	if(FileOut.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file docgia_mathe de ghi!" << endl;
		system("pause");
		return;
	}
	
	FileOut << DSMaThe[0];
	for(int i=1; i<1024; i++)
	{
		FileOut << "\n" << DSMaThe[i];
	}
	
	FileOut.close();
	cout << "Ghi file docgia_mathe thanh cong!" << endl;
	Sleep(500);
	//system("pause");
}

//================ Nhap gioi tinh sinh hoc ? ================
string NhapGioiTinh(int x, int y, string str)
{
	int i=0;
	gotoxy(x,y);	cout << "< " << str << " >";
	int chr;
	do
	{
		
		fflush(stdin);
		chr= getch();
		if(chr==Enter)
		{
			return GioiTinh[i];
		}
		else if(chr==Left)
				{
					if(i==0) i= nGioiTinh-1;
					else i--;
					gotoxy(x,y);	cout << "< " << GioiTinh[i] << " >";
				}
		else if(chr==Right)
				{
					if(i== (nGioiTinh-1)) i=0;
					else i++;
					gotoxy(x,y);	cout << "< " << GioiTinh[i] << " >";
				}
	} while(chr!=ESC);
	return "tba";
}







//===== de day va khong noi gi =====//
