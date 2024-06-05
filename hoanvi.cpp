#include<iostream>
using namespace std;
int* a;
int* p;
int n;
void xuat()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	cout << endl;
}
void hoanvi(int i)
{
	for (int j = 1; j <= n; j++)
	{
		if (p[j] == 0)
		{
			a[i] = j;
			p[j] = 1;
			if (i == n-1)
				xuat();
			else
				hoanvi(i + 1);
			p[j] = 0;
			
			
		}
	}
}
int main()
{

	cout << "Nhap n:"; cin >> n;
	a = new int[n];
	p = new int[n + 1];

	for (int i = 0; i < n+1; i++)
	{
		p[i] = 0;
	}
	hoanvi(0);
	delete[]p;
	delete[]a;
	return 0;
}