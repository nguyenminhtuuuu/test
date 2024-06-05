#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;



//Cac ham dung chung
bool isNamNhuan(int nam)
{
	if (nam % 400 == 0 || nam % 4 == 0 && nam % 100 != 0)
		return true;
	return false;
}

bool checkDDMMYYYY(int ngay, int thang, int nam)
{
	if (ngay > 0 && thang > 0 && thang <= 12 && nam <= 2024 && nam > 0)
	{
		switch (thang)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			if (ngay <= 31)
				return true;
		case 4:case 6:case 9: case 11:
			if (ngay <= 30)
				return true;
		case 2:
			if (isNamNhuan(nam))
			{
				if (ngay <= 29)
					return true;
			}
			else
			{
				if (ngay <= 28)
					return true;
			}
		}
		return false;
	}
	return false;
}
//Kieu du lieu tu dinh nghia
struct ngaythangnam
{
	int dd, mm, yyyy;
};
struct Lop
{
	char malop[5];//CS31
	char tenlop[9];//DH23CS02
	string tenkhoa;
	int sosv;
	ngaythangnam ngaykhaigiang;
};
struct DSL
{
	vector<Lop>ds; //mang kieu vector luu tru kieu Lop
};


//Cac ham danh cho Lop
void xuatLop(Lop* lop)
{
	cout << "=====================\n";
	cout << "Ma lop:";
	cout << lop->malop << endl;
	cout << "Ten lop:";
	cout << lop->tenlop << endl;
	cout << "Ten khoa:";
	cout << lop->tenkhoa << endl;
	cout << "So luong sinh vien:";
	cout << lop->sosv << endl;
	
	if (checkDDMMYYYY(lop->ngaykhaigiang.dd, lop->ngaykhaigiang.mm, lop->ngaykhaigiang.yyyy))
	{
		cout << "Ngay khai giang:";
		cout << lop->ngaykhaigiang.dd << "/" << lop->ngaykhaigiang.mm << "/" << lop->ngaykhaigiang.yyyy << endl;
	}
	else
		cout << "Ngay nhap khong hop le!\n";
	cout << "=====================\n";
}
//Cac ham cho DSL
void nhapDSLTuFile(DSL& dsl,string fileName)
{
	ifstream infile(fileName);
	if (infile.is_open())
	{
		while (infile.eof()==false)
		{
			Lop lop;
			infile.getline(lop.malop, 5, '#');
			infile.getline(lop.tenlop, 9, '#');
			
			getline(infile, lop.tenkhoa, '#');
			infile >> lop.sosv;
			infile.ignore(1);
			//Nhap ngay thang nam khai giang
			ngaythangnam ngay;
			infile >> ngay.dd;
			infile.ignore(1);//bo qua ki tu /
			infile >> ngay.mm;
			infile.ignore(1);
			infile >> ngay.yyyy;
			infile.ignore(1);
			if (checkDDMMYYYY(ngay.dd, ngay.mm, ngay.yyyy))
			{
				lop.ngaykhaigiang = ngay;
				dsl.ds.push_back(lop);
			}
			else
				cout << "Ngay khong hop le!\n";
			
		}

		infile.close();
	}
}

void xuatDSL( DSL dsl)
{
	for (int i = 0; i < dsl.ds.size(); i++)
	{
		xuatLop(&dsl.ds[i]);
	}
}

int trangay(int thang, int nam)
{
	switch(thang)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		return 31;
	case 4:case 6:case 9:case 11:
		return 30;
	case 2:
		if (isNamNhuan(nam))
			return 29;
		else
			return 28;
	}
}



ngaythangnam ngaycapnhat(ngaythangnam ngaybaygio,int tongngay)
{
	ngaythangnam ngayKiemTra;
	int ngayhientai, ngaysequathangmoi,thang,nam; 
	thang = ngaybaygio.mm;
	nam = ngaybaygio.yyyy;
	ngayhientai = ngaybaygio.dd;
	
	while (tongngay != 0)
	{
		ngaysequathangmoi = trangay(thang, nam) - ngayhientai;//trangay() = ngay toi da trong thang
		if (tongngay - ngaysequathangmoi > 0)
		{
			tongngay = tongngay - ngaysequathangmoi;
			if (thang == 12 && tongngay != 0)
			{
				nam = nam + 1;
				thang = 1;
			}
			else
			{
				thang = thang + 1;
			}
			ngayhientai = 1;
		}
		else
		{
			ngayhientai = ngayhientai + tongngay;
			tongngay = 0;
		}
		
	}
	ngayKiemTra.dd = ngayhientai;
	ngayKiemTra.mm = thang;
	ngayKiemTra.yyyy = nam;
	return ngayKiemTra;
}
bool checkNgay(ngaythangnam ngaydukien, ngaythangnam ngaybaygio)
{
	if (ngaydukien.yyyy == ngaybaygio.yyyy)
	{
		if (ngaydukien.mm == ngaybaygio.mm)
			if (ngaydukien.dd > ngaybaygio.dd)
				return true;
		if (ngaydukien.mm > ngaybaygio.mm)
			return true;
	}
	return false;
}
void xuatFileKiemTra(DSL dsl,ngaythangnam ngayhientai)
{
	ngaythangnam ngaydukien;
	
	ofstream outfile("fileName.txt");
	if (outfile.is_open())
	{
		outfile << dsl.ds.size() << endl;
		
			for (int i = 0; i < dsl.ds.size(); i++)
			{
				ngaydukien = ngaycapnhat(dsl.ds[i].ngaykhaigiang, 90);
				if (checkNgay(ngaydukien, ngayhientai))
				{
					outfile << dsl.ds[i].malop << '#'
						<< dsl.ds[i].tenlop << '#'
						<< dsl.ds[i].tenkhoa << '#'
						<< dsl.ds[i].sosv << '#'
						<< ngaydukien.dd << "/"
						<< ngaydukien.mm << "/"
						<< ngaydukien.yyyy;
					outfile << endl;
				}
			}
			outfile.close();
	}
	
}



int main()
{
	DSL ou;
	nhapDSLTuFile(ou, "BT5.txt");
	xuatDSL(ou);

	/*ngaythangnam ngaybaygio;
	ngaythangnam res;
	int date = 90;
	ngaybaygio.dd = 17;
	ngaybaygio.mm = 3;
	ngaybaygio.yyyy = 2024;
	res = ngaycapnhat(ngaybaygio, date);
	cout << res.dd << "/" << res.mm << "/" << res.yyyy << endl;*/

	ngaythangnam ngayhomnay;
	ngayhomnay.dd = 30;
	ngayhomnay.mm = 5;
	ngayhomnay.yyyy = 2024;

	xuatFileKiemTra
	(ou, ngayhomnay);

	return 0;
}