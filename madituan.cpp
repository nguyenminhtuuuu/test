
// bo ngo

#include<iostream>
using namespace std;
int X[8] = {-1,-1, 1, 2, 1, -2,2, -2 };
int Y[8] = { 2,-2,-2, 1, 2,  1,-1 -1};
int A[8][8] = { 0 };
int cnt = 1;
int n;

int main()
{

	int x, y;
	cout << "Nhap ma tran cap: "; cin >> n;
	cout << "Nhap vi tri muon bat dau (x,y)\n";
	cout << "Nhap x:"; cin >> x;
	cout << "Nhap y:"; cin >> y;
	A[x][y] = cnt;
	int tam = x, ho = y;
	for (int dk = 0; dk < 8 ; dk++)
	{
		cnt++;
		x = x + X[dk];
		y = y + Y[dk];
		A[x][y] = cnt;
		while (true)
		{
			bool kiemtra = false;
			int biendem = 0;
			for (int i = 0; i < 8; i++)
			{
				if (cnt == n * n)
				{

					for (int t = 0; i < n; i++)
					{
						for (int u = 0; i < n; i++)
						{
							cout << A[t][u] << " ";
						}
						cout << endl;
					}
				}
				int u = x + X[i];
				int v = y + Y[i];
				if (u >= 0 && u < n && v >= 0 && v < n && A[u][v] == 0)
				{
					cnt++;
					A[u][v] = cnt;
					x = u;
					y = v;
					kiemtra = true;
					break;
				}
				biendem++;
			}
			cout << "===========================\n";
			for (int h = 0; h < n; h++)
			{
				for (int k = 0; k < n; k++)
				{
					cout << A[h][k] << " ";
				}
				cout << endl;
			}
			cout << "Kiemtra = " << kiemtra << endl;
			cout << "Biendem = " << biendem << endl;

			if (kiemtra == false && biendem == 8)
			{
				cnt = 1;
				for (int h = 0; h < n; h++)
				{
					for (int k = 0; k < n; k++)
					{
						A[h][k] = 0;
					}
				}
				x = tam;
				y = ho;
				A[x][y] = cnt;
				break;
			}

		}
	
	}



	return 3;
}
