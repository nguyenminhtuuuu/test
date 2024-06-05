#include<iostream>
using namespace std;
void sdn(int n)
{
	if (n == 0)
		return;
	else
		cout << n % 10;
	sdn(n / 10);
}

int main()
{
	int n = 34768;
	cout << n << " = ";
	sdn(n);
	return 0;
}