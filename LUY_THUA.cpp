#include<iostream>
using namespace std;
int luythua(int n, int m)
{
	if (m == 0)
		return 1;
	else
		return n * luythua(n, m - 1);
 }

int main()
{
	cout << "5^3 = " << luythua(5, 3) << endl;
	cout << "10^2 = " << luythua(10, 2) << endl;
	cout << "8^3 = " << luythua(8, 3) << endl;
	return 0;
}