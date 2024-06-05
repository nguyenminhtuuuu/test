#include<iostream>
using namespace std;
void nhiphan(int n)
{
	if (n == 0)
		return;
	else
	nhiphan(n / 2);
	cout << n % 2;
 }
int main()
{
	nhiphan(9);
	cout << endl;
	nhiphan(12);
	return 0;
}