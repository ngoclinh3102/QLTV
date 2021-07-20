#pragma once

#include <iostream>
#include <fstream>
#include "DocGia.h"
#include "GiaoDien.h"
using namespace std;

#define nlc 8
#define ESC 27
//===============Ve Khung==============
void KhungTieuDe();
void NhapLuaChon();
void XoaMenuChon();
void MenuQLDG();
void XoaDSDocGia();

//==================Nhap doc gia============
void NhapDG(TREE_DG &tree);

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
	MenuQLDG();
	
	bool kt= true;
	while(kt)
	{
		//system("cls");
		XoaMenuChon();
		NhapLuaChon();
		int chon; cin >> chon;
		switch(chon)
		{
			case 1: //1. Nhap doc gia
			{
				NhapDG(tree);
				cout << "Nhap thanh cong!";
				Sleep(500);
				break;
			}
			case 2: //2. In DS doc gia (Ma the)
			{
				XoaDSDocGia();
				NODE_DG *ds[100];
				int nds=0;
				if(tree==NULL)
				{
					gotoxy(0,nlc+1); cout << " >> Danh sach rong!!";
					Sleep(999); break;
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
					gotoxy(0,nlc+1); cout << " >> Danh sach rong!!";
					Sleep(999); break;
				}
				ChuyenCaySangMang(tree, ds, nds);
				SapXepTheoTen(ds,nds);
				//SapXepTheoMaTheCanBang(ds,nds);
				InDSDG(ds,nds);
				
				GiaiPhongDS(ds,nds);
				break;			
			}
			case 4: //4. Xoa doc gia
			{
				//XoaDSDocGia();
				//Xu li
				int x;
				x= TimDocGia(tree);
				switch(x)
				{
					case -2: //Danh sach rong
					{
						cout << "\n >> Danh sach rong!!";
						Sleep(999); break;
						
					}
					case -1: //Ma doc gia khong ton tai
					{
						cout << "\n >> Ma doc gia khong ton tai!!!";
						Sleep(999); break;
					}
					case 0: //Khong xoa
					{
						cout << "\n >> Khong xoa!!";
						Sleep(999); break;
					}
					default:
					{
						Xoa_DG(x,tree);
						Sleep(999); break;
					}
				}
				
				//In lai ds
				XoaDSDocGia();
				NODE_DG *ds[100];
				int nds=0;
				ChuyenCaySangMang(tree, ds, nds);
				InDSDG(ds,nds);
				
				GiaiPhongDS(ds,nds);
				break;
			}
			case 5: //Hieu chinh
			{
				HieuChinhDG(tree);
				
				//In lai ds
				XoaDSDocGia();
				NODE_DG *ds[100];
				int nds=0;
				ChuyenCaySangMang(tree, ds, nds);
				InDSDG(ds,nds);
				
				GiaiPhongDS(ds,nds);
				break;
			}
			case 0: //0. Thoat
			{
				kt= false;
				break;
			}
			default:
			{
				cout << "Chon sai!";
				Sleep(500);
				break;
			}
		}
	}
	
}

//============Ve khung de xuat danh sach======
void KhungTieuDe()
{
	gotoxy(40,0); cout << "+-------------------------------------------------------------------------------+";
	gotoxy(40,1); cout << "| STT |  Ma The  |        Ho        |     Ten     | Phai |Trang thai the|Ghi chu|";
	gotoxy(40,2); cout << "+-----+----------+------------------+-------------+------+--------------+-------+";
//	gotoxy(40,3); cout << "|     |          |                  |             |      |              |       |";
}
void MenuQLDG()
{
	gotoxy(0,0);
	cout << "+-----------------------------+" << endl;
	cout << "|      1. Nhap doc gia        |" << endl;
	cout << "|    2. DS doc gia (Ma the)   |" << endl;
	cout << "|     3. DS doc gia (Ten)     |" << endl;
	cout << "|        4. Xoa doc gia       |" << endl;
	cout << "|        5. Hieu chinh        |" << endl;
	cout << "|         0. Thoat            |" << endl;
	cout << "+-----------------------------+" << endl;
	
	
}
void NhapLuaChon()
{
	gotoxy(0,nlc); cout << " >>> Nhap lua chon: ";
}
void XoaMenuChon()
{
	for(int i=nlc; i<30; i++)
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


//================Nhap doc gia================
void NhapDG(TREE_DG &tree)
{
//	system("cls");
	NODE_DG *p = KhoiTaoNode_DocGia();
	cin.ignore();
	DSMaThe[0]++;
	int i= DSMaThe[0];
	p->data.mathe= DSMaThe[i];
	gotoxy(0,nlc+1); cout << "Ma the: " << p->key;
	gotoxy(0,nlc+2); cout << "Nhap ho: ";
	gotoxy(0,nlc+3); cout << "Nhap ten: ";
	gotoxy(0,nlc+4); cout << "Nhap phai: ";
	
	gotoxy(9,nlc+2); getline(cin, p->data.ho);
	gotoxy(10,nlc+3); getline(cin, p->data.ten);
	gotoxy(11,nlc+4); getline(cin, p->data.phai);
	
	Them_DG(tree,p);
	
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
void XuatDSDG(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds; i++)
	{
		cout << "\t===Nhan vien " << i+1 << ":" << endl;
		cout << "Ma the: " << ds[i]->data.mathe << endl;
		cout << "Ho: " << ds[i]->data.ho << endl;
		cout << "Ten: " << ds[i]->data.ten << endl;
		cout << "Phai: " << ds[i]->data.phai << endl;
		cout << "Trang thai the: ";
			if(ds[i]->data.trangthaithe == 1) cout << "Dang hoat dong" << endl;
			else if(ds[i]->data.trangthaithe == 0) cout << "Da bi khoa" << endl;
		
	}
	//system("pause");
}
void InDSDG(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds; i++)
	{
		gotoxy(40,3+i); cout << "|     |          |                  |             |      |              |       |";
		gotoxy(42,3+i); cout << i+1;
		gotoxy(49,3+i); cout << ds[i]->data.mathe;
		gotoxy(61,3+i); cout << ds[i]->data.ho;
		gotoxy(79,3+i); cout << ds[i]->data.ten;
		gotoxy(92,3+i); cout << ds[i]->data.phai;
		gotoxy(98,3+i); if(ds[i]->data.trangthaithe == 1) cout << "  Hoat dong" << endl;
						else if(ds[i]->data.trangthaithe == 0) cout << "  Da bi khoa" << endl;
		Sleep(50);
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
	int x; cin >> x;
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
		gotoxy(40,3); cout << "|     |          |                  |             |      |              |       |";
		gotoxy(42,3); cout << " X ";
		gotoxy(49,3); cout << tree->data.mathe;
		gotoxy(61,3); cout << tree->data.ho;
		gotoxy(79,3); cout << tree->data.ten;
		gotoxy(92,3); cout << tree->data.phai;
		gotoxy(98,3); if(tree->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(tree->data.trangthaithe == 0) cout << "  Da bi khoa";
	}
	
	gotoxy(0,9); cout << "Nhap lai ma doc gia neu ban muon xoa: ";
	int kt; cin >> kt;
	if(kt == x) return x;
	return 0;
}
//================HIEU CHINH DOC GIA=====================
int TimMaTheDocGia(TREE_DG tree)
{
	if(tree==NULL) return -2; //danh sach rong
	gotoxy(0,nlc+1); cout << " >> Nhap ma doc gia: ";
	int x; cin >> x;
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
		gotoxy(40,3); cout << "|     |          |                  |             |      |              |       |";
		gotoxy(42,3); cout << " X ";
		gotoxy(49,3); cout << tree->data.mathe;
		gotoxy(61,3); cout << tree->data.ho;
		gotoxy(79,3); cout << tree->data.ten;
		gotoxy(92,3); cout << tree->data.phai;
		gotoxy(98,3); if(tree->data.trangthaithe == 1) cout << "  Hoat dong";
						else if(tree->data.trangthaithe == 0) cout << "  Da bi khoa ";
	}
	return x; //in ra thong tin roi tra ve x
}
void HieuChinhDG(TREE_DG &tree)
{
	int x;
	x= TimMaTheDocGia(tree);
	if(x == -2)
	{
		cout << "\n >> Danh sach rong!!";
		Sleep(999); return;
	}
	if(x == -1)
	{
		cout << "\n >> Khong ton tai ma doc gia!!!";
		Sleep(999); return;
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
	gotoxy(0,nlc+4); cout << " >> "; int ch; cin >> ch;
	switch(ch)
	{
		case 1: //hieu chinh
		{
			cin.ignore();
			gotoxy(0,nlc+5); cout << "Ma the: " << t->key;
			gotoxy(0,nlc+6); cout << "Nhap ho: ";
			gotoxy(0,nlc+7); cout << "Nhap ten: ";
			gotoxy(0,nlc+8); cout << "Nhap phai: ";
	
			gotoxy(9,nlc+6); getline(cin, t->data.ho);
			gotoxy(10,nlc+7); getline(cin, t->data.ten);
			gotoxy(11,nlc+8); getline(cin, t->data.phai);
			
			break;
		}
		case 2: //Khoa the, Mo khoa the
		{
			if(t->data.trangthaithe == 1) t->data.trangthaithe= 0;
			else if(t->data.trangthaithe == 0) t->data.trangthaithe= 1;
			
			break;
		}
	}
	cout << " >> Cap nhat thanh cong!";
	Sleep(999);
}
//=================DOC GHI FILE==============
void DocDSMaThe()
{
	ifstream FileIn;
	FileIn.open("C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_mathe.txt", ios_base::in);
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
	FileIn.open("C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_tree.txt", ios_base::in);
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
	clearFileContent("C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_tree.txt");
	//mo file
	ofstream FileOut;
	FileOut.open("C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_tree.txt", ios_base::out);
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
	clearFileContent("C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_mathe.txt");
	ofstream FileOut;
	FileOut.open("C:\\Users\\DELL\\Desktop\\QLTV\\QLTV\\docgia_mathe.txt", ios_base::out);
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

