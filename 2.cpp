#include<iostream>
#define MAX 100
using namespace std;
//nhap
void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "]=";
		cin >> a[i];
	}
}
//xuat
void output(int a[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//them mot phan tu
void pushElement(int a[], int& n,int x)
{
	if (n < MAX)
	{
		n++;
		a[n-1] = x;
	}
	return;
}
//kiem tra day
bool isFull(int a[], int n)
{
	if (n < MAX)
		return true;
	return false;
}
//xoa tai vi tri bat ki
void popMid(int a[], int& n, int vt)
{
	if (isFull(a, n))
	{
		for (int i = vt; i < n - 1; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
	}
	return;
}

//tim phan tut tuan tu
int search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return i;
	}
	return -1;
}
//tim phan tu nhi phan (truong hop mang sap tang dan)
int searchBinary(int a[], const int n, int x)
{
	bool flag = false, flag2 = false;
	int cnt = 0;
	int tmp = 0, trungvi = 0, sophantu = n;
	if (a[n - 1] == x)
		return n;
	while (a[tmp]!=x)
	{
		if (sophantu % 2 != 0)
			trungvi = trungvi + sophantu / 2;
		else
		{
			if (sophantu == 2)
				trungvi = trungvi + sophantu / 2;
			else
				trungvi = trungvi + sophantu / 2 - 1;
		}
		tmp = trungvi;
		if (a[tmp] < x)
		{
			sophantu = n - trungvi - 1;
			if (sophantu == 2 && trungvi + 1 == n - 1 || sophantu == 1 && trungvi + 1== x)
				return trungvi + 1;
		}
		cnt++;
		if (cnt > n)
			return -1;
			
	}
	return trungvi+1;
}
 
 

//tim va xoa
void seekAndPop(int a[], int& n, int x)
{
	if (search(a, n, x)!=-1)
		popMid(a, n, search(a,n,x));
}
//gop 2mang
void merge(int c[MAX], int a[],int sl, int b[],int sl1,int &dem)
{
	int cnt = 0;
	for (int i = 0; i < sl; i++)
	{
		c[cnt] = a[i];
		cnt++;
	}
	for (int i = 0; i <sl1; i++)
	{
		c[cnt] = b[i];
		cnt++;
	}
	dem = cnt;
}
int main()
{
	int a[MAX],sophantu,choice;
	int b[MAX];
	int c[MAX];
	bool flag = false;
	while (1)
	{
		cout << "-----------------------\n";
		cout << "1.Nhap mang\n";
		cout << "2.Xuat\n";
		cout << "3.Tim phan tu tuan tu\n";
		cout << "4.Tim phan tu nhi phan\n";
		cout << "5.Tim phan tu va xoa\n";
		cout << "6.Gop 2 mang\n";
		cout << "0.Thoat!\n";
		cout << "-----------------------\n";
		cout << "Moi chon:";
		cin >> choice;
		system("cls");

		if (choice == 1)
		{
			do
			{
				cout << "So phan tu:";
				cin >> sophantu;
				if (sophantu <= 0 || sophantu > MAX)
					cout << "Vui long nhap lai!\n";
			} while (sophantu <= 0 || sophantu > MAX);
			input(a, sophantu);
			flag = true;
		}
		else if (choice == 2)
		{
			if (flag)
				output(a, sophantu);
			else
				cout << "Mang chua duoc nhap\n";
		}
		else if (choice == 3)
		{
			if (flag)
			{
				int x;
				cout << "Phan tu tim:";
				cin >> x;
				if (search(a, sophantu, x))
					cout << x << " co trong mang\n";
				else
					cout << "Khong tim thay\n";
			}
			else
				cout << "Mang chua duoc nhap\n";
		}
		else if (choice == 4)
		{
			if (flag)
			{
				int x,kq;
				cout << "Phan tu tim:";
				cin >> x;
				kq = searchBinary(a, sophantu, x);
				if (kq == -1)
				{
					cout << x << " khong co trong mang!\n";
				}
				else
					cout << x << " o tri vi thu: " << kq << endl;
				
			}
			else
				cout << "Mang chua duoc nhap\n";
		}

		else if (choice == 5)
		{
			if (flag)
			{
				int x;
				cout << "Phan tu tim va xoa:";
				cin >> x;
				seekAndPop(a, sophantu, x);
			}
			else
				cout << "Mang chua duoc nhap\n";
		}
		else if (choice == 6)
		{
			int sl, sl1;
			int dem;
			do
			{
				cout << "So luong mang a:";
				cin >> sl;
				cout << "So luong mang b:";
				cin >> sl1;
				if (sl + sl1 > MAX||sl+sl1 <=0)
					cout << "Vui long 0 < tong so luong 2 mang < 100\n";
			} while (sl + sl1 > MAX|| sl+sl1 <=0);
			cout << "\n------Nhap mang a-----\n";
			input(a, sl);
			cout << "\n------Nhap mang b-----\n";
			input(b, sl1);
			merge(c, a,sl,b,sl1,dem);
			cout << "\n------Mang sau khi gop--------\n";
			output(c, dem);
		}
		else
			break;
	}


	return 0;
}