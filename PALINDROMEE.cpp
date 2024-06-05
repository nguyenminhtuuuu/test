#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
bool isPalindrome(char* x)
{
	for (int i = 0; i < strlen(x) / 2; i++)
	{
		if (x[i] != x[strlen(x) - i - 1])
			return false;
	}
}
int main()
{
	char hoten[50];
	cout << "ho, ten: ";
	cin.get(hoten, 49);
	if (isPalindrome(hoten))
		cout << "Y\n";
	else
		cout << "N\n";
	return 0;
}