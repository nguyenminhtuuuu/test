#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	char passwrd[] = "SinhVienCQ";
	char passwrd1[10]; char c = 0;
	int cnt = 0, re;
	cout << "Nhap password:";
	do
	{
		int i = 0;
		while (true)
		{
			c = getch();
			if (i == 10)
				break;
			else
			{
				passwrd1[i++] = c;
				cout << "*";
			}
		}
		cout << endl;
		cout << passwrd1 << endl;

		re = strcmp(passwrd, passwrd1);
		if (re != 0)
		{
			if (re != 0 && cnt == 2)
			{
				cout << "Qua so lan nhap!\n";
				return 0;
			}
			cout << "Nhap sai! Nhap lai!\n";
			cnt++;
		}
	} while (re != 0 && cnt != 3);
	if (cnt != 3)
	{
		cout << "Dang nhap thanh cong!\n";
	}
	return 0;
}