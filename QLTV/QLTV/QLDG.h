#pragma once

#include "DocGia.h"
#include "QLDauSach.h"

char docgia_tree[55]= "C:\\Users\\DELL\\Desktop\\QLTV\\docgia_tree.txt";
char docgia_mathe[55]= "C:\\Users\\DELL\\Desktop\\QLTV\\docgia_mathe.txt";
const int quantity= 6;
const int quantityMT= 3;
const int xQLDG= 3;
const int yQLDG= 1;
const int xListDG= 40;
const int yListDG= 0;
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

//them vao cuoi cua danh sach muon tra
void InsertLastMT(PTR_MT &First, MuonTra temp);

//================HAM XU LI QL DOC GIA================//
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
					ThongBao("DANH SACH DG RONG");
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
						ThongBao("DANH SACH DG RONG");
						break;
						
					}
					case -1: //Ma doc gia khong ton tai
					{
						ThongBao("MA KHONG TON TAI");
						break;
					}
					case 0: //Khong xoa
					{
						ThongBao("---");
						break;
					}
					default: //co ma doc gia
					{
						Xoa_DG(x,tree);
						break;
					}
				}
				//In lai
				NODE_DG *ds[100];
				int nds=0;
				if(tree==NULL)
				{
					ThongBao("DANH SACH DG RONG!");
					break;
				}
				ChuyenCaySangMang(tree, ds, nds);
				InDSDG(ds,nds);
				
				GiaiPhongDS(ds,nds);
				break;
			}
			
			case 6: //0. Thoat
			{
				kt = false;
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
	gotoxy(xListDG,yListDG+0);	cout << "+---------------------------------------------------------------------------------------+";
	gotoxy(xListDG,yListDG+1);	cout << "| STT |  MA THE  |      HO      |       TEN       | PHAI |TRANG THAI THE|SL MUON|GHI CHU|";
	gotoxy(xListDG,yListDG+2);	cout << "|-----+----------+--------------+-----------------+------+--------------+-------+-------+";
//								cout << "|     |          |              |                 |      |              |       |       |";
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
		gotoxy(40,j); cout << "                                                                                         ";
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
	if(p->data.ho.compare("")==0) return;
	//gotoxy(10,nlc+3); getline(cin, p->data.ten);
	fflush(stdin); p->data.ten= NhapChuoi(10,nlc+3,p->data.ten);
	//gotoxy(11,nlc+4); getline(cin, p->data.phai);
	fflush(stdin); p->data.phai= NhapGioiTinh(11,nlc+4,p->data.phai);
	p->data.trangthaithe = -1;
	//Muon tra
	p->data.nMT = 0;
	Them_DG(tree,p);
	ThongBao("NHAP THANH CONG!");
	p->data.mt = NULL;
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
	nds=0;
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
		gotoxy(40,3+i);		cout << "|     |          |              |                 |      |              |       |       |";
		gotoxy(42,3+i);		cout << i+1;
		gotoxy(49,3+i);		cout << ds[i]->data.mathe;
		gotoxy(59,3+i);		cout << ds[i]->data.ho;
		gotoxy(75,3+i);		cout << ds[i]->data.ten;
		gotoxy(92,3+i);		cout << ds[i]->data.phai;
		gotoxy(98,3+i); if(ds[i]->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(ds[i]->data.trangthaithe == 0) cout << "  Da bi khoa";
						else if(ds[i]->data.trangthaithe == -1) cout << "  Moi tao";
		gotoxy(116,3+i);	cout << ds[i]->data.nMT;
		Sleep(15);
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
		gotoxy(40,3);	cout << "|  X  |          |              |                 |      |              |       |       |";
		gotoxy(49,3);	cout << tree->data.mathe;
		gotoxy(59,3);	cout << tree->data.ho;
		gotoxy(75,3);	cout << tree->data.ten;
		gotoxy(92,3);	cout << tree->data.phai;
		gotoxy(98,3); if(tree->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(tree->data.trangthaithe == 0) cout << "  Da bi khoa";
						else if(tree->data.trangthaithe == -1) cout << "  Moi tao";
		gotoxy(116,3);	cout << tree->data.nMT;
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

	int x = -3;
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
		gotoxy(40,3); 	cout << "| --> |          |              |                 |      |              |       |       |";
		gotoxy(49,3); 	cout << tree->data.mathe;
		gotoxy(59,3); 	cout << tree->data.ho;
		gotoxy(75,3); 	cout << tree->data.ten;
		gotoxy(92,3); 	cout << tree->data.phai;
		gotoxy(98,3); if(tree->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(tree->data.trangthaithe == 0) cout << "  Da bi khoa ";
						else if(tree->data.trangthaithe == -1) cout << "  Moi tao";
		gotoxy(116,3);	cout << tree->data.nMT;
	}
	return x; //in ra thong tin roi tra ve x
}

void HieuChinhDG(TREE_DG &tree)
{
	int x;
	x= TimMaTheDocGia(tree);
	if(x== -3)
	{
//		ThongBao("Thoat");
		return;
	}
	if(x == -2)
	{
		ThongBao("DANH SACH RONG");
		return;
	}
	if(x == -1)
	{
		ThongBao("MA KHONG TON TAI");
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

//==================== DOC GHI FILE =========================//
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
		FileIn >> node->data.nMT; FileIn.ignore();
		node->data.mt = NULL;
//		PTR_MT pHead = NULL;
		MuonTra temp;
		for(int i=0; i<node->data.nMT; i++)
		{
			getline(FileIn, temp.isbn, '|');
			FileIn >> temp.masach; FileIn.ignore();
			FileIn >> temp.ngayMuon.ngay; FileIn.ignore();
			FileIn >> temp.ngayMuon.thang; FileIn.ignore();
			FileIn >> temp.ngayMuon.nam; FileIn.ignore();
			FileIn >> temp.ngayTra.ngay; FileIn.ignore();
			FileIn >> temp.ngayTra.thang; FileIn.ignore();
			FileIn >> temp.ngayTra.nam; FileIn.ignore();
			FileIn >> temp.trangthai; FileIn.ignore();
			
			InsertLastMT(node->data.mt, temp);
		}
		// them vao cay
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
	FileOut << ds[0]->data.mathe << "|" << ds[0]->data.ho << "|" << ds[0]->data.ten << "|" << ds[0]->data.phai << "|" << ds[0]->data.trangthaithe << "|" << ds[0]->data.nMT;
	PTR_MT p = ds[0]->data.mt;
	for(int j=0; j<ds[0]->data.nMT; j++)
	{
		FileOut << endl << p->data.isbn << "|" << p->data.masach << "|";
		FileOut << p->data.ngayMuon.ngay << "/" << p->data.ngayMuon.thang << "/" << p->data.ngayMuon.nam;
		FileOut << "|";
		FileOut << p->data.ngayTra.ngay << "/" << p->data.ngayTra.thang << "/" << p->data.ngayTra.nam;
		FileOut << "|" << p->data.trangthai;
				
		p = p->next;
	}
	for(int i=1; i<nds; i++)
	{
		//if(i != 0) cout << endl;
		FileOut << "\n" << ds[i]->data.mathe << "|" << ds[i]->data.ho << "|" << ds[i]->data.ten << "|" << ds[i]->data.phai << "|" << ds[i]->data.trangthaithe << "|" << ds[i]->data.nMT;
		//muon tra ??
		if(ds[i]->data.nMT == 0) continue;
		else
		{
			p = ds[i]->data.mt;
			for(int j=0; j<ds[i]->data.nMT; j++)
			{
				FileOut << endl << p->data.isbn << "|" << p->data.masach << "|";
				FileOut << p->data.ngayMuon.ngay << "/" << p->data.ngayMuon.thang << "/" << p->data.ngayMuon.nam;
				FileOut << "|";
				FileOut << p->data.ngayTra.ngay << "/" << p->data.ngayTra.thang << "/" << p->data.ngayTra.nam;
				FileOut << "|" << p->data.trangthai;
				
				p = p->next;
			}
		}
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
// ================================================================================== //
// =============================== PHAN QL MUON TRA ================================= //
// ================================================================================== //
string trangthaiMT[3]=
{
	"DANG MUON",
	"DA TRA",
	"DA LAM MAT"
};
char MenuMT[quantityMT][50]=
{
	"        MUON SACH        ",
	"        TRA SACH         ",
	"         THOAT           "
};
//=========KHAI BAO HAM
//=== ve giao dien
void KhungNhapMaDoGia();
void XoaKhungNhapMaDoGia();
void KhungDSMuonTra();
int MenuDongMT(char td [quantityMT][50], int x, int y);
void KhungMenuMT();
void XoaKhungDSDG();
void XoaNhapMT();
void XoaKhungDSDS();

//=== nhap ma doc gia (f)
void runQLMUONTRA(TREE_DG &dg);
//in danh sach muon tra
void InDSMuonTra(PTR_MT pHead);


// =========== MUON SACH ============ //
void MuonSach(TREE_DG &dg);
int TimSachCoTheMuon(PTR_DMS First);
int DemSachDangMuon(TREE_DG dg);
//void InsertLastMT(PTR_MT &First, MuonTra temp); //dem len dau de dung cho ham doc file
void InsertFirstMT(PTR_MT &First, MuonTra temp);
void LuuDSMuonTra(TREE_DG dg);

// ============= TRA SACH =============== //
void TraSach(TREE_DG &dg);
void XuLiTraSach(TREE_DG &dg, PTR_MT &p);

// ====================== HAM XU LI ============================ //
//Nhap vao ma the doc gia de vao QL MUON TRA(cau f)
void NhapVaoMaDocGia()
{
	system("cls");
	KhungThongBao();
	//in ds doc gia
	if(tree==NULL) ThongBao("DS DOC GIA RONG!");
	else
	{
		KhungTieuDe();
		NODE_DG *ds[100];
		int nds=0;
		ChuyenCaySangMang(tree, ds, nds);
		InDSDG(ds,nds);
		GiaiPhongDS(ds,nds);
	}
	KhungNhapMaDoGia();
	TREE_DG dg;
	int x;
	while(1)
	{
		fflush(stdin);
		x = -3;	x = NhapSo(10,6,x);

		if(x==-3) return; //nguoi dung an ESC
		
		dg = tree;
		while(dg!=NULL)
		{
			if(dg->key == x) break; //tim thay
			else if(dg->key < x) dg = dg->right;
			else if(dg->key > x) dg = dg->left;
		}
		//hoac dg->key==x hoac dg==NULL
		if(dg==NULL)
		{
			ThongBao("MA KHONG TON TAI!");
			//nhap lai
			gotoxy(10,6);	cout << "      ";
			continue;
		}
//		else if(dg->data.trangthaithe == 0)
//		{
//			ThongBao("DOC GIA BI KHOA");
//			gotoxy(10,6);	cout << "      ";
//			continue;
//		}
		else
		{
			XoaDSDocGia();
			gotoxy(40,3); cout << "| --> |          |              |                 |      |              |       |       |";
			gotoxy(49,3); cout << dg->data.mathe;
			gotoxy(59,3); cout << dg->data.ho;
			gotoxy(75,3); cout << dg->data.ten;
			gotoxy(92,3); cout << dg->data.phai;
			gotoxy(98,3);	if(dg->data.trangthaithe == 1) cout << "  Hoat dong";
							else if(dg->data.trangthaithe == 0) cout << "  Da bi khoa ";
							else if(dg->data.trangthaithe == -1) cout << "  Moi tao";
			gotoxy(116,3);	cout << dg->data.nMT;
			
			break;
		}
	}
	XoaKhungNhapMaDoGia();
	runQLMUONTRA(dg);
}
void runQLMUONTRA(TREE_DG &dg)
{
	//in ds muon tra cua doc gia vua tim duoc
	KhungDSMuonTra();
//	PTR_MT pHead = dg->data.mt;
	InDSMuonTra(dg->data.mt);
	//
	int chon;
	while(true)
	{
		chon = MenuDongMT(MenuMT,xQLDG,yQLDG);
		switch(chon)
		{
			case 1: //muon sach
			{
				int b = DemSachDangMuon(dg);
				if(b>=3)
				{
					ThongBao("DA MUON TOI DA 3 CUON");
					break;
				}
				if(dg->data.trangthaithe == 0)
				{
					ThongBao("DOC GIA BI KHOA!");
					gotoxy(10,6);	cout << "      ";
					break;
				}
				MuonSach(dg);
				break;
			}
			case 2: //tra sach
			{
				int b = DemSachDangMuon(dg);
				if(b<1)
				{
					ThongBao("DA MUON TOI DA 3 CUON");
					break;
				}
				TraSach(dg);
				break;
			}
			case 3: //thoat
			{
//				LuuDSMuonTra(dg);
				return;
			}
		}
		//in lai thong tin doc gia
		KhungTieuDe();
		gotoxy(40,3); 	cout << "| --> |          |              |                 |      |              |       |       |";
		gotoxy(49,3); 	cout << dg->data.mathe;
		gotoxy(59,3); 	cout << dg->data.ho;
		gotoxy(75,3); 	cout << dg->data.ten;
		gotoxy(92,3); 	cout << dg->data.phai;
		gotoxy(98,3);	if(dg->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(dg->data.trangthaithe == 0) cout << "  Da bi khoa ";
						else if(dg->data.trangthaithe == -1) cout << "  Moi tao";
		gotoxy(116,3);	cout << dg->data.nMT;
		//in lai ds muon tra
		KhungDSMuonTra();
		InDSMuonTra(dg->data.mt);
	}
}

//=== ve giao dien
void KhungNhapMaDoGia()
{
	gotoxy(2,3);	cout << "+-----------------------+";
	gotoxy(2,4);	cout << "|___ NHAP MA DOC GIA ___|";
	gotoxy(2,5);	cout << "|                       |";
	gotoxy(2,6);	cout << "|    >>                 |";
	gotoxy(2,7);	cout << "|                       |";
	gotoxy(2,8);	cout << "+-----------------------+";
}
void XoaKhungNhapMaDoGia()
{
	gotoxy(2,3);	cout << "                         ";
	gotoxy(2,4);	cout << "                         ";
	gotoxy(2,5);	cout << "                         ";
	gotoxy(2,6);	cout << "                         ";
	gotoxy(2,7);	cout << "                         ";
	gotoxy(2,8);	cout << "                         ";
}
void KhungDSMuonTra()
{
	gotoxy(xListDG,yListDG+5);	cout << "+---------------------------------------------------------------------------------------+";
	gotoxy(xListDG,yListDG+6);	cout << "| STT |     MA SACH     |   NGAY MUON   |   NGAY TRA   |  TRANG THAI  |     GHI CHU     |";
	gotoxy(xListDG,yListDG+7);	cout << "+---------------------------------------------------------------------------------------+";
//	gotoxy(xListDG,yListDG+8);	COUT << "|     |                 |               |              |              |                 |";
}
void XoaKhungDSDG()
{
	for(int j=0; j<28; j++)
	{
		gotoxy(40,j); cout << "                                                                                         ";
	}
}
void XoaKhungDSDS()
{
	for(int j=0; j<37; j++)
	{
		gotoxy(xListDS,j); cout << "                                                                                         ";
	}
	gotoxy(0,0);
}
void XoaNhapMT()
{
	for(int j=5; j<yTB; j++)
	{
		gotoxy(0,j); cout << "                               ";
	}
}
int MenuDongMT(char td [quantityMT][50], int x, int y)
{
	Normal();
	ShowCur(false);
//	XoaMenuQLDG();
	KhungMenuMT();
	//Ve Menu
	for (int i=0; i<quantityMT; i++)
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
  					chon = quantityMT -1;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Down:
				if (chon+1 <quantityMT) {
  		    		
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
void KhungMenuMT()
{
	gotoxy(xQLDG-1,yQLDG-1); cout << "+-------------------------+";
	gotoxy(xQLDG-1,yQLDG);   cout << "|                         |";
	gotoxy(xQLDG-1,yQLDG+1); cout << "|                         |";
	gotoxy(xQLDG-1,yQLDG+2); cout << "|                         |";
	gotoxy(xQLDG-1,yQLDG+3); cout << "+-------------------------+";
}
//in danh sach muon tra
void InDSMuonTra(PTR_MT pHead)
{
	if(pHead==NULL) ThongBao("DS MUON TRA RONG!");
	else
	{
		int i = 0;
		while(pHead!=NULL)
		{
			gotoxy(xListDG,yListDG+8+i);	cout << "|     |                 |               |              |              |                 |";
			gotoxy(xListDG+2,yListDG+8+i);	cout << i+1;
			gotoxy(xListDG+11,yListDG+8+i);	cout << pHead->data.isbn <<  "-" << setw(3) << setfill('0') << pHead->data.masach;
			gotoxy(xListDG+28,yListDG+8+i);	InDate(pHead->data.ngayMuon);
			gotoxy(xListDG+43,yListDG+8+i);	if(pHead->data.ngayTra.thang!=-1) InDate(pHead->data.ngayTra);
											else cout << "--/--/----";
			gotoxy(xListDG+58,yListDG+8+i);	cout << trangthaiMT[pHead->data.trangthai];
				
			pHead = pHead->next;
			i++;
			Sleep(9);
		}
	}
}
// =========== MUON SACH ============ //
void MuonSach(TREE_DG &dg)
{
	bool flag = true;
	XoaKhungDSDG();
	VeKhungDauSach();
	gotoxy(0,7); cout << "Nhap ten sach muon muon:";
	gotoxy(0,8); cout << " >> ";
	int key = NhapDeTimChuoiTrongChuoi(4,8,Mang_DS);
	if(key==-1) //ESC
	{
		XoaNhapMT();
		XoaKhungDSDS();
		return;
	}
	PTR_MT mt = dg->data.mt;
	while(mt!=NULL)
	{
		if(Mang_DS.ds[key]->ISBM.compare(mt->data.isbn)==0 && mt->data.trangthai==0)
		{
			ThongBao("DG DA MUON SACH NAY");
			XoaNhapMT();
			XoaKhungDSDS();
			return;
		}
		mt = mt->next;
	}
	
	VeKhungDS_DMS();
	
	int x = TimSachCoTheMuon(Mang_DS.ds[key]->dms);
	if(x==-1) return; //danh sach rong
	if(x==-2)
	{
		ThongBao("SACH KHONG CO SAN");
		XoaNhapMT();
		XoaKhungDSDS();
		return;
	}
	//co sach de muon
	InDS_DMS(Mang_DS.ds[key]->dms,Mang_DS.ds[key]->ISBM);
	
	gotoxy(0,9);	cout << "Nhap ma sach (number only):";
	gotoxy(0,10);	cout << " >> ";
	do
	{
		x = NhapMaSach(4,10,x);
		
		PTR_DMS p = Mang_DS.ds[key]->dms;
		while(p!=NULL)
		{
			if(p->data.masach==x)
			{
				//xet dieu kien
				if(p->data.trangthai==1 || p->data.trangthai==2)
				{
					ThongBao("SACH KHONG CO SAN!");
					XoaNhapMT();
					XoaKhungDSDS();
					return;
				}
				//else
				//thay doi trang thai sach
				p->data.trangthai = 1;
//				Mang_DS.ds[key]->luotmuon++; //moi muon a, tra sach thi moi tinh
				//them node moi vao danh sach muon tra
				MuonTra temp;
				temp.isbn = Mang_DS.ds[key]->ISBM;
				temp.masach = x;
				today(temp.ngayMuon);
				temp.ngayTra = InitDate();
				temp.trangthai = 0;
				
				InsertFirstMT(dg->data.mt,temp);
				//thay doi thong tin doc gia
				if(dg->data.trangthaithe==-1) dg->data.trangthaithe = 1;
				dg->data.nMT++; //dang muon van tinh 1 luot muon sach
				ThongBao("MUON THANH CONG!");
				
				XoaNhapMT();
				XoaKhungDSDS();
				return;
			}
			else p = p->next;
		}
		if(p==NULL)
		{
			ThongBao("MA THE KHONG TON TAI");
			continue;
		}
		if(x==-1) flag = false;
	}while(flag);
	
	
	
//	Sleep(4444);
	XoaNhapMT();
	XoaKhungDSDS();
}
//tim sach co the muon
int TimSachCoTheMuon(PTR_DMS First)
{
	if(First==NULL) return -1; //danh sach danh muc sach rong
	while(First!=NULL)
	{
		if(First->data.trangthai==0) return First->data.masach;
		else First = First->next;
	}
	return -2; //khong co sach co the cho muon
}
//them vao muon tra
void InsertLastMT(PTR_MT &First, MuonTra temp)
{
	if(First==NULL)
	{
		First = new node_mt;
		First->next = NULL;
		First->data = temp;
	}
	else
	{
		PTR_MT q = First;
		while(q->next!=NULL) q = q->next; // q->next = NULL;
		
		PTR_MT p = new node_mt;
		p->next = NULL;
		p->data = temp;
		q->next = p;
	}
}
void InsertFirstMT(PTR_MT &First, MuonTra temp)
{
	PTR_MT p = new node_mt;
	p->data = temp;
	p->next = First;
	First = p;
}
//luu lai danh sach muon tra
void LuuDSMuonTra(TREE_DG dg)
{
	if(tree==NULL) return;
	
	int x = dg->data.mathe;
	TREE_DG q = tree;
	while(q->data.mathe!=x)
	{
		if(q->data.mathe>x) q = q->right;
		else if(q->data.mathe!=x) q = q->left;
	}
	if(q==NULL) return;
	else
	{
		q->data = dg->data;
	}
}
// =================== TRA SACH ================= //
void TraSach(TREE_DG &dg)
{
	PTR_MT p;
	if(dg->data.mt==NULL)
	{
//		ThongBao("DS MUON TRA RONG");
		return;
	}
	//
	string str;
	while(1)
	{
		p = dg->data.mt;
		gotoxy(0,9);	cout << "Nhap ma sach (text only):";
		gotoxy(0,10);	cout << " >> ";
		str = "";
		str = NhapChuoiHoa(4,10,str);
		//
		if(str.compare("")==0)
		{
			XoaNhapMT();
			return;
		}
		//
		while(p!=NULL)
		{
			if(str.compare(p->data.isbn)==0) break;
			else p = p->next;
		}
		if(p==NULL || p->data.trangthai!=0)
		{
			ThongBao("KHONG TIM THAY");
			Sleep(9);
			ThongBao("NHAP SACH DANG MUON");
			XoaNhapMT();
			continue;
		}
		else
		{
			//TRA SACH
			//thay doi thong tin muon tra
			//thay doi thong tin doc gia
			//thay doi thong tin dau sach va dms
			XuLiTraSach(dg,p);
			XoaNhapMT();
			
			return;
		}
		
	}
	
	
	
	Sleep(9);
}

void XuLiTraSach(TREE_DG &dg, PTR_MT &p)
{
	ShowCur(false);
	gotoxy(0,11);	cout << " >> 1. DOC GIA TRA SACH";
	gotoxy(0,12);	cout << " >> 2. DOC GIA BAO MAT SACH";
	int chon = getch();
	while(chon!=Num1 && chon!=Num2)
	{
		if(chon==ESC)
		{
			ShowCur(true);
			return;
		}
		else chon = getch();
	}
	ShowCur(true);
	switch(chon)
	{
		case Num1: //TRA SACH
		{
			//thay doi thong tin muon tra
			today(p->data.ngayTra);
			p->data.trangthai = 1; //da tra
			//thay doi thong tin doc gia
//			dg->data.nMT++; //da ++ luc muon sach roi
			if(dg->data.trangthaithe = -1) dg->data.trangthaithe = 1;
			//thay doi thong tin dau sach va dms
			int i;
			for(i=0; i<Mang_DS.sl; i++)
			{
				if(Mang_DS.ds[i]->ISBM.compare(p->data.isbn)==0) break;
			}
			Mang_DS.ds[i]->luotmuon++; //hoan thanh 1 luot muon sach
			PTR_DMS q = Mang_DS.ds[i]->dms;
			while(q->data.masach != p->data.masach) q = q->next;
			q->data.trangthai = 0;
			
			ThongBao("TRA SACH THANH CONG");
			break;
		}
		case Num2: //BAO MAT SACH
		{
			//thay doi thong tin muon tra
			today(p->data.ngayTra);
			p->data.trangthai = 2; //lam mat
			//thay doi thong tin doc gia
//			dg->data.nMT++; //nt
			gotoxy(0,13);	cout << "Khoa the doc gia nay?(Y/N): ";
			int k = getch();
			while(k!='Y'&&k!='y'&&k!='N'&&k!='n')
			{
				if(k==ESC) return;
				k = getch();
			}
			if(k!='Y' || k!='y') dg->data.trangthaithe = 0;
			else if(k!='N' || k!='n') dg->data.trangthaithe = 1;
			//thay doi thong tin dau sach va dms
			int i;
			for(i=0; i<Mang_DS.sl; i++)
			{
				if(Mang_DS.ds[i]->ISBM.compare(p->data.isbn)==0) break;
			}
			Mang_DS.ds[i]->luotmuon++;
			PTR_DMS q = Mang_DS.ds[i]->dms;
			while(q->data.masach != p->data.masach) q = q->next;
			q->data.trangthai = 2;
			
			ThongBao("CAP NHAT THANH CONG");
			break;
		}
	}
}

// dem so sach doc gia 'dang muon'
int DemSachDangMuon(TREE_DG dg)
{
	int dem = 0;
	PTR_MT mt = dg->data.mt;
//	if(mt==NULL) return dem;
	while(mt!=NULL)
	{
		if(mt->data.trangthai==0) dem++;
		mt = mt->next;
	}
	return dem;
}






// ================================================================== //
// ================== POWERED BY NGOCLINH =========================== //
// ================================================================== //
