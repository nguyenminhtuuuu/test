#include<iostream>
using namespace std;
#define MAX 8
int b[MAX] = {-1,-1,-1,-1,-1,-1,-1,-1};//luu chi so j da dat
int mang[MAX][MAX];
int cnt;
bool check( int j)
{
	for (int k = 0; k < MAX; k++)
	{
		if (j == b[k])
			return false;
	}
	return true;
}
void xuatkq()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << mang[i][j] << " ";
		}
		cout << endl;
	}
}
void putQueen(int i)
{
	for (int j = 0; j < MAX; j++)
	{
		if (check(j))
		{
			
			b[cnt++] = j;
			mang[i][j] = 2;
			if (i == MAX - 1)
			{
				xuatkq();
			
			}
			else
				putQueen(i + 1);
		}
		
		mang[i][j] = 0;
	}
}

int main()
{
	
	putQueen(0);
 	return 0;
}