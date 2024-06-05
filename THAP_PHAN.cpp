#include<iostream>
using namespace std;
int thapphan(int n, int cnt = 0)
{
	if (n == 0)
		return 0;
	else
		/*cnt++;*/
		return n % 10 * pow(2, cnt) + thapphan(n / 10, cnt+1);
}
int main()
{
	cout << "1001 = " << thapphan(1001) << endl;
	cout << "1100 = " << thapphan(1100) << endl;
	cout << "11001 = " << thapphan(11001) << endl;
	return 0;
 }