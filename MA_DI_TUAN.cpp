#include<iostream>
using namespace std;

#define MAX 5
int dd[] = { -2, -1,1,2,2,1,-1,-2 };
int dc[] = { 1,2,2,1,-1,-2,-2,-1 };
int a[MAX][MAX] = { 0 };
 
void xuatKQ()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void nuocDi(int cnt, int vtDong, int vtCot)
{
	for (int i = 0; i < 8; i++)
	{
		int dmoi = vtDong + dd[i];
		int cmoi = vtCot + dc[i];
		if (dmoi >= 0 && dmoi < MAX && cmoi >= 0 && cmoi < MAX && a[dmoi][cmoi] == 0)
		{
			a[dmoi][cmoi] = cnt;
			if (cnt == MAX * MAX)
			{
				xuatKQ();
				char c;
				cout << "Nhap ki tu bat ky de tiep tuc:";
				cin >> c;
			}
			else
			{
				nuocDi(cnt + 1, dmoi, cmoi);
			}
			a[dmoi][cmoi] = 0;
		}
		
		
	}
	
}

int main()
{
	int vtDong, vtCot;
	cout << "Nhap vi tri bat dau:\n";
	cout << "Vi tri dong:";
	cin >> vtDong;
	cout << "Vi tri cot:";
	cin >> vtCot;
	nuocDi(0, vtDong,vtCot);
	cout << "Khong tim thay duong di\n";
	return 0;
}