#include<iostream>
using namespace std;

long m = 0;
bool nguyento(int x)
{
	if (x < 2)
	{
		return false;
	}
	else
	{
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void luumangnguyento(long arr[])
{
	
	for (int i = 0; i < 100; i++)

	{
		if (nguyento(i))
		{
			arr[m] = i;
			m++;
		}
	}
}
int main()
{
	long arr[50];//mang luu cac so nguyen to tu 1 den 100;
	long x; // so can phan tich thua so nguyen to
	luumangnguyento(arr);
	do
	{
		cout << "Nhap x:";
		cin >> x;
		if (x <= 0)
			cout << "Vui long nhap lai!\n";
	} while (x <= 0);

	cout << x << " = ";
	for (int i = 0; i < m; i++)
	{
		
		while (x % arr[i] == 0)
		{
			x = x / arr[i];
			cout << arr[i];
			if ( x > 1)
			{
				cout << "*";
			}
			else
			{
				break;
			}
			

		}
	}
	
	return 0;
}

		