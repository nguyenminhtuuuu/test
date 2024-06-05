#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Cac kieu du lieu tu dinh nghia
struct SV
{
	long long mssv;
	string hoten;
	int namsinh;
};

struct DSSV
{
	int sl;
	SV* ds;
};
//Cac ham danh cho SV
void nhapSV(SV& sv)
{
	cout << "MSSV:";
	cin >> sv.mssv;
	cin.ignore(1);
	cout << "Ho ten:";
	getline(cin, sv.hoten);
	cout << "Nam sinh:";
	cin >> sv.namsinh;
}
void xuatSV(SV sv)
{
	    cout << "========================\n";
		         cout << "MSSV:";
		         cout << sv.mssv << endl;
		         cout << "Ho ten:";
		         cout << sv.hoten << endl;
		         cout << "Nam sinh:";
		         cout << sv.namsinh << endl;
		cout << "========================\n";
}
//Cac ham danh cho DSSV
void nhapDSSV(DSSV& dssv)
{
	do
	{
		cout << "So luong < 10 sinh vien:";
		cin >> dssv.sl;
		if (dssv.sl < 0 || dssv.sl>10)
			cout << "Sai yeu cau!\n";
	} while (dssv.sl < 0 || dssv.sl>10);
	dssv.ds = new SV[dssv.sl];//Xin vung nho trong Heap
	for (int i = 0; i < dssv.sl; i++)
	{
		cout << i + 1 << ".\n";;
		nhapSV(dssv.ds[i]);//ham truyen vao mot SV trong danh sach thu i

	}
}
void xuatDSSV(DSSV dssv)
{
	for (int i = 0; i < dssv.sl; i++)
	{
		xuatSV(dssv.ds[i]);
	}
}
void huyDSSV(DSSV& dssv)
{
	delete[]dssv.ds;
	dssv.ds = nullptr;
}
int main()
{
	DSSV OU;
	OU.ds = NULL;
	OU.sl = 0;
	/*nhapDSSV(OU);
	xuatDSSV(OU);*/
	/*ofstream myfile10("BT10.txt");
	if (myfile10.is_open())
	{
		for (int i = 0; i < OU.sl; i++)
		{
			myfile10 << "======================\n";
			myfile10 << "MSSV:";
			myfile10 << OU.ds[i].mssv << endl;
			myfile10 << "Ho ten:";
			myfile10 << OU.ds[i].hoten << endl;
			myfile10 << "Nam sinh:";
			myfile10 << OU.ds[i].namsinh << endl;
			myfile10 << "======================\n";
		}

		myfile10.close();
	}*/
	ifstream myfile10("BT10.txt");
	OU.sl = 2;
	OU.ds = new SV[OU.sl];
	if (myfile10.is_open())
	{
		cout << "Mo file thanh cong!\n";
		
		for (int i = 0; i < OU.sl; i++)
		{
			myfile10 >> OU.ds[i].mssv;
			myfile10.ignore();
			getline(myfile10, OU.ds[i].hoten);
			myfile10 >> OU.ds[i].namsinh;
		}
		myfile10.close();
	}
	long long mssv;
	cout << "MSSV can tim:";
	cin >> mssv;
	bool check = false;
	for (int i = 0; i < OU.sl; i++)
	{
		if (OU.ds[i].mssv == mssv)
		{
			xuatSV(OU.ds[i]);
			check = true;
		}

	}
	if (check != true)
		cout << "Sinh vien khong ton tai hoac nhap sai ma so sinh vien\n";

	/*xuatDSSV(OU);*/
	huyDSSV(OU);
	return 0;
}