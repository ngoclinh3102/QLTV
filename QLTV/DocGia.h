#pragma once 

#include <iostream>
//#include "MuonTra.h"
#include <string>

using namespace std;

//=====DOC GIA=====
struct docgia
{
	int mathe;	//dung lam key trong tree
	string ho;
	string ten;
	string phai;
	int trangthaithe=1; // =0 khoa, =1 hoat dong
//	PTR_MT mt; // con tro se tro den danh sach cac cuon da va dang muon
};
typedef struct docgia DOC_GIA;

struct node_docgia
{
	//int key;
	DOC_GIA data;
	int &key= data.mathe; //dung chung vung nho voi mathe
	node_docgia* left;
	node_docgia* right;
};
typedef struct node_docgia NODE_DG; //???
typedef struct node_docgia* TREE_DG;

//============Khoi trao node Doc Gia
NODE_DG* KhoiTaoNode_DocGia()
{
	NODE_DG *p = new NODE_DG;
	p-> left = NULL;
	p-> right = NULL;
	return p;
}


int DSMaThe[1024]={0,512,768,256,896,640,384,128,192,448,320,832,64,960,704,576,48,32,752,112,736,560,144,688,912,464,208,400,176,304,416,
944,544,224,240,880,976,80,848,672,784,1008,624,496,800,288,992,160,608,656,352,16,96,432,928,336,368,816,528,480,864,272,592,720,152,376,
680,792,872,296,1000,280,520,664,808,456,72,840,200,504,168,728,184,408,600,696,328,952,88,264,776,440,104,888,472,616,424,744,968,136,920,
904,392,536,56,120,584,40,1016,712,216,648,344,552,488,824,568,312,936,360,248,856,8,632,984,760,24,232,852,148,932,868,764,356,692,364,484,
28,788,836,44,516,196,380,636,340,204,860,828,492,988,468,748,84,756,876,20,924,676,52,820,4,500,12,476,428,588,212,508,252,892,332,292,244,
556,684,628,564,612,76,420,596,796,812,572,188,900,68,260,916,652,732,284,108,580,620,236,644,548,36,436,396,956,604,716,116,740,372,460,980,
532,948,780,388,804,404,140,132,228,1012,972,100,276,316,444,124,772,172,300,964,308,324,92,412,996,156,268,1004,1020,724,164,940,220,660,452,
524,908,884,180,540,348,700,708,60,668,844,850,150,810,430,338,926,18,974,330,10,758,98,454,918,570,906,230,914,426,738,518,322,278,294,306,
638,166,822,482,170,966,502,790,62,462,402,446,1018,978,834,986,886,666,634,1014,682,874,190,66,534,910,902,962,114,802,110,326,262,506,242,
998,854,550,698,346,42,982,222,718,290,814,270,694,126,410,90,358,726,686,562,826,258,842,414,622,678,722,510,626,878,930,578,566,646,702,78,
158,1010,770,654,806,450,122,922,762,610,250,70,866,394,22,970,378,458,846,590,214,442,418,6,950,662,586,210,238,830,730,382,1002,50,354,598,
782,794,174,582,554,438,734,898,254,286,714,178,2,246,838,818,546,198,994,30,266,350,594,130,602,618,890,218,194,754,182,650,958,146,274,538,
766,542,422,486,118,862,342,14,310,390,162,154,134,74,670,798,46,954,630,498,58,858,202,642,1022,750,314,226,106,658,234,318,94,34,774,386,
282,558,674,398,1006,490,778,86,302,298,370,206,706,142,690,514,522,526,786,406,938,942,362,946,470,574,186,494,870,54,934,474,82,710,366,
990,742,38,434,478,374,26,746,530,334,466,138,614,882,606,894,102,873,865,877,1021,591,665,507,911,721,245,753,279,551,925,895,577,907,455,
883,487,757,79,579,13,497,545,295,781,409,133,853,511,681,141,207,559,77,495,377,523,97,271,945,401,87,543,49,149,333,705,427,647,537,605,
503,711,379,549,351,745,987,659,969,991,641,533,953,165,267,255,663,973,475,143,493,169,567,771,229,399,5,541,569,181,123,827,121,289,903,
309,67,951,521,319,985,467,381,393,799,251,999,73,595,923,861,7,119,655,759,365,445,671,171,673,211,329,237,287,283,941,691,1,281,889,849,
439,339,695,815,499,265,621,459,239,609,217,311,617,939,963,307,115,469,831,773,857,161,179,535,501,177,227,17,955,163,749,47,465,871,901,
933,419,107,441,573,1001,25,639,411,789,763,743,43,437,1005,971,69,613,685,3,297,719,707,643,529,407,693,627,867,41,1003,83,1009,995,779,
893,943,139,299,739,457,649,777,109,453,99,983,23,257,327,447,201,183,313,667,761,801,231,59,323,803,95,513,371,481,199,527,715,395,259,213,
509,71,851,185,243,471,651,219,981,785,887,581,797,997,975,197,391,337,125,187,361,561,65,285,89,839,959,373,101,443,937,81,135,1007,725,699,
93,795,203,1023,599,15,435,917,273,811,723,91,317,367,967,709,539,249,791,27,633,689,175,629,1011,751,961,817,449,727,637,103,885,325,583,
821,429,131,703,39,241,807,189,359,863,935,697,741,157,159,9,947,587,589,113,675,11,565,363,767,525,291,331,345,117,717,461,755,375,477,977,
793,53,603,479,355,21,843,623,729,303,881,491,129,45,855,431,383,747,225,825,735,417,557,31,531,593,55,63,423,661,657,1013,517,625,575,713,
897,679,645,485,731,921,193,385,683,859,85,989,147,875,269,1017,809,473,597,553,463,293,19,415,155,571,505,879,845,929,235,413,563,519,787,
931,405,891,669,515,173,253,57,805,823,555,979,357,631,369,489,111,635,223,677,601,837,687,433,167,483,829,61,233,607,209,51,263,653,615,
701,1015,993,899,965,277,905,949,35,421,915,195,37,737,927,847,547,215,151,191,403,353,387,335,869,835,29,769,425,913,349,275,347,389,315,
909,127,733,841,451,105,75,585,783,957,341,619,919,145,765,153,221,305,1019,33,301,819,775,813,321,833,137,397,205,611,247,343,261};

//them doc gia vao cay
void Them_DG(TREE_DG &t, NODE_DG *p) {
	if(t==NULL) {
		t=p;
	}
	else
		if(p->key < t->key) Them_DG(t->left, p);
		else
			if(p->key > t->key) Them_DG(t->right, p);
}

//Xoa doc gia khoi cay
TREE_DG rp;

void Xoa_DG_3(TREE_DG &r)
{
	if(r->left != NULL) Xoa_DG_3(r->left);
	else
	{
		rp->key= r->key;
		rp->data= r->data;
		rp= r;
		r= rp->right;
	}
}

void Xoa_DG(int x, TREE_DG &p)
{
	if(p== NULL) cout << "\nKhong tim thay!!";
	else
		if(x < p->key) Xoa_DG(x, p->left);
		else
			if(x > p->key) Xoa_DG(x, p->right);
			else
			{
				rp=p;
				if(rp->right == NULL)  p= rp->left;
				else
					if(rp->left == NULL) p= rp->right;
					else
						Xoa_DG_3(rp->right);
				delete rp;
			}
}



























struct QuaHan
{
	int MADG;
	int songayquahan;
};
//// khoi tao
//void initTREE_DG(TREE_DG &t);
//
//// kiem tra rong
//bool IsEmpty(TREE_DG t);
//
//// get node bat ki
//NODE_DG* GetNode_DG(DOC_GIA dg);
//
////  them node vao tree DG
//void InsertDTtoTree(TREE_DG &t, DOC_GIA dg);
//
//// dem so luong doc gia
//int countDG(TREE_DG tree);
//
//// kiem tra MSDG co ton tai hay khong.
//bool Check_MADG(TREE_DG  t, uint MADG);
//
//// tra ve 1 so nguyen ngau nhien tu dong;
//uint Random();
//
//// Ham tra ve  MSDG la so nguyen ngau nhien tu dong va khong trung.
//uint Random_MADG(TREE_DG t);
//
//// find Min
//NODE_DG* FindMin(TREE_DG t);
//
//// tim doc gia bang ma doc gia, co tra ve dia chi , khong tra ve NULL
//NODE_DG* Find_DG(TREE_DG t, uint MADG);
//
//// neu xoa dc, thuc hien xoa roi tra ve true , khong tra ve false
//bool IsDeleted_DG(TREE_DG &t, DOC_GIA dg);
