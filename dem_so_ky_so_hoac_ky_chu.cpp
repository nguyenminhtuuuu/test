#include<iostream>
#include<string>
using namespace std;

int main()
{
	
	char s[50];
	cout << "Nhap chuoi:";
	cin.get(s, 50);
	char* contro;
	//dem ky tu chu hoac so
	int dem = 0;
	int demchuhoacso = 0;
	int demchu = 0;
	int demso = 0;
	contro = s;

	while (*contro != NULL)
	{
		if (isspace(*contro))
			dem++;
		if (isalnum(*contro))
			demchuhoacso++;
		if (isalpha(*contro))
			demchu++;
		if (isdigit(*contro))
			demso++;
		contro++;

	}
	cout << "So ky tu khoang trang la: " << dem << endl;
	cout << "So ky tu chu la: " << demchu << endl;
	cout << "So ky tu so la: " << demso << endl;
	cout << "So ky tu chu hoac so la: " << demchuhoacso << endl;
	return 0;
}
