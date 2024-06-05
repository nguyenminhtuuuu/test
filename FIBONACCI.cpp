#include<iostream>
using namespace std;
int fibo(int n)
{
	if (n == 0)
	{
		
		return 0;
		
	}
	else if (n == 1)
	{

		return 1;
		
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	
	}
}
void xuatfibo(int n)
{
	for (int i = 0; i <= n; i++)
	{
		cout << fibo(i) << " ";
	}
	cout << endl;
}



int main()
{
	cout << fibo(5) << endl;
	cout << fibo(7) << endl;
	cout << fibo(8) << endl;
	cout << "Day fibo la : ";
	xuatfibo(9);

	return 0;
}