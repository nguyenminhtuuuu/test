#include<iostream>
#include<ctime>
using namespace std;

void sinhmang(int *&a, int n)
{
	a = new int[n];
	srand((int)time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
	}
}
void xuatmang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void nhapmang(int*& a, int n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
int tongmang(int*& a, int n, int cnt = 0, int tong = 0)
{
	if (cnt == n )
		return tong;
	else
	{
		tong = tong + a[cnt];
		cnt++;
		return tongmang(a, n, cnt, tong);
	}
}

int main()
{
	int n;
	int* a;
	do
	{
		cout << "Nhap so phan tu cho mang: ";
		cin >> n;
		if (n <= 0)
			cout << "Moi nhap lai!\n";
	} while (n <= 0);
	int chon;
	while(true)
	{
	cout << "1.Sinh mang ngau nhien\n"
		<< "2.Nhap phan tu cho mang\n"
		<< "0.Thoat!\n";
	cin >> chon;
	switch (chon)
	{
	case 1:
	{
		sinhmang(a, n);
		cout << "------------------\n";
		xuatmang(a, n);
		cout << endl;
		cout << "------------------\n";
		cout << "Tong mang = " << tongmang(a, n) << endl;
		break;
	}
	case 2:
	{
		nhapmang(a, n);
		cout << endl;
		cout << "--------------------\n";
		xuatmang(a, n);
		cout << endl;
		cout << "--------------------\n";
		cout << "Tong mang = " << tongmang(a, n) << endl;
		break;
	}
	case 0:
	{
		return 0;
	}
	default:
	{
		cout << "Du lieu khong hop le!\n";
	}

	}
}
	return 0;

}