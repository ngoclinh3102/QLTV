#pragma once

#include "essential.h"

struct date
{
	int ngay;
	int thang;
	int nam;
};
// lay ngay hien tai
void today(date &d)
{
	time_t now = time(NULL);
	tm *t = localtime(&now);
	d.ngay = t->tm_mday;
	d.thang = t->tm_mon + 1;
	d.nam = t->tm_year + 1900;
}
// dem so ngay muon->tra
int CountDay(date muon)
{
	date tra;
	today(tra);
	int dem = 0;
	
	while(muon.nam <= tra.nam)
	{
		if(tra.nam == muon.nam && tra.thang == muon.thang)
		{
			dem += tra.ngay - muon.ngay;
			return  dem;
		}
		else
		{
			//thang 1,3,5,7,8,10,12
			if(muon.thang==1||muon.thang==3||muon.thang==5||muon.thang==7||muon.thang==8||muon.thang==10||muon.thang==12)
			{
				dem += 31 - muon.ngay;
			}
			//thang 4,6,9,11
			if(muon.thang==4||muon.thang==6||muon.thang==9||muon.thang==11)
			{
				dem += 30 - muon.ngay;
			}
			//thang 2
			if(muon.thang==2)
			{
				if(muon.nam % 4 == 0) dem += 29 - muon.ngay;
				else dem += 28 - muon.ngay;
			}
			muon.thang++;
			muon.ngay = 0;
			//thang 13
			if(muon.thang == 13)
			{
				muon.nam++;
				muon.thang = 1;
			}
		}
	}

}
// khoi tao ngay
date InitDate()
{
	date d;
	{
		d.ngay = -1;
		d.thang = -1;
		d.nam  = -1;
	}
	return d;
}
// xuat ngay theo dinh dang: dd/mm/yyyy
void InDate(date d)
{
	cout << setfill('0') << setw(2) << d.ngay << "/" << setw(2) << d.thang << "/" << d.nam;
}









// ============================= !@#^*&$%^@# ================================= //
