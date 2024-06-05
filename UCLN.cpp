#include<iostream>
using namespace std;
int UCLN(int a, int b)
{
	if (b == 0)
		return a;
	else
	{
		int du = a % b;
		a = b;
		b = du;
		return UCLN(a, b);
	}
}

int main()
{
	int a, b;
	while (true)
	{
		do
		{
			cout << "Nhap a > b:";
			cin >> a;
			cout << "Nhap b:";
			cin >> b;
			if (a < b)
			{
				cout << "Moi nhap lai!\n";
			}
		} while (a < b);
		cout << "UCLL(" << a << "," << b << ") = " << UCLN(a, b) << endl;
	}
	return 0;
}