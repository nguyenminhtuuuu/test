#include<iostream>
using namespace std;


class Gio
{
private:
	int gio, phut, giay;
public:
	//constructor
	Gio()
	{
		gio = NULL;
		phut = NULL;
		giay = NULL;
	}
	Gio(int x, int y, int z)
	{
		gio = x;
		phut = y;
		giay = z;
	}

	//set
	void setGio(int gio1)
	{
		gio = gio1;
	}
	void setPhut(int phut1)
	{
		phut = phut1;
	}
	void setGiay(int giay1)
	{
		giay = giay1;
	}
	//get
	int getGio()
	{
		return gio;
	}
	int getPhut()
	{
		return phut;
	}
	int getGiay()
	{
		return giay;
	}
	//show
	void show()
	{
		cout << gio << ":" << phut << ":" << giay << "s ";
	
	}
	//nhap
	void nhapGio()
	{
		cout << "Gio:";
		cin >> gio;
		cout << "Phut:";
		cin >> phut;
		cout << "Giay:";
		cin >> giay;
	}



	//huy
	~Gio(){};
};
//Cac ham danh cho Gio
bool check(Gio a)
{
	if (a.getGio() < 0 || a.getGio() > 24)
		return false;
	if (a.getPhut() < 0 || a.getPhut() > 60)
		return false;
	if (a.getGiay() < 0 || a.getGiay() > 60)
		return false;
	return true;
}
Gio traGiaTri(long long x)
{
	Gio tam;
	int g=0, p, s;
	long long a = x / 1000;
	int tmp = a;
	p = a / 60; int ptmp = 0;
	s = a % 60; int stmp = 0;
	while(tmp>0)
	{
		if (p >= 60)
		{
			g += 1;
			p = p - 60;
			ptmp = 60;
		}
		if (s >= 60)
		{
				p += 1;
				s = s - 60;
				stmp = 60;
		}
		tmp = tmp - (ptmp * 60) -stmp ;
	}
	tam.setGio(g);
	tam.setPhut(p);
	tam.setGiay(s);
	return tam;
}
bool trans(int gio)
{
	for (int i = 0; i <= 12; i++)
	{
		if (gio == i)
			return true;
	}
	return false;
}
int main()
{
	int a = 15, b = 30, c = 44;
	/*Gio gps1;*/
	Gio gps2;
	/*gps1.show();
	gps2.show();*/
	/*gps2.nhapGio();
	gps2.show();
	if (trans(gps2.getGio()))
		cout << "AM\n";
	else
		cout << "PM\n";*/
	
	//Nhan vao ml tra ve Gio
	Gio the=traGiaTri(35876000);
	the.show();
	
	return 0;
}