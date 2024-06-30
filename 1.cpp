#include<iostream>
#define MAX 100
using namespace std;
//kiem tra day
bool isFull(int a[], int n)
{
	if (n < MAX)
		return true;
	return false;
}
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
//tim phan tu
bool search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return true;
	}
	return false;
}
//them vao cuoi ds
void pushBack(int a[], int& n,int x)
{
	if (isFull(a,n))
	{
		a[n] = x;
		n++;
	}
	return;
}
//xoa cuoi ds
void popBack(int a[], int& n)
{
	a[n - 1] = NULL;
	n--;
	return;
}
//xoa tai vi tri bat ki
void popMid(int a[], int& n, int vt)
{
	if (isFull(a,n))
	{
		for (int i = vt; i < n - 1; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
	}
	return;
}
//them tai vi tri bat ki
void pushMid(int a[], int& n,int vt ,int x)
{
	
	if (isFull(a, n))
	{
		for (int i = n; i >= vt; i--)
			a[i] = a[i - 1];
		a[vt] = x;
		n++;
	}
}
//tim va xoa
void seekAndPop(int a[], int& n, int x)
{
	if (search(a, n, x))
		popMid(a, n, x);
}



int main()
{
	int mang1chieu[MAX];
	int sophantu;
	int choice;
	bool flag = false;
	while (1)
	{
		cout << "-----------------------\n";
		cout << "1.Nhap mang\n";
		cout << "2.Xuat\n";
		cout << "3.Tim phan tu\n";
		cout << "4.Them phan tu cuoi\n";
		cout << "5.Xoa phan tu cuoi\n";
		cout << "6.Xoa phan tu vi tri bat ky\n";
		cout << "7.Them phan tu vi tri bat ky\n";
		cout << "8.Tim phan tu va xoa\n";
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
			input(mang1chieu, sophantu);
			flag = true;
		}
		else if (choice == 2)
		{
			if (flag)
				output(mang1chieu, sophantu);
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
				if (search(mang1chieu, sophantu, x))
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
				int x;
				cout << "Phan tu them:";
				cin >> x;
				pushBack(mang1chieu, sophantu, x);
			}
			else
				cout << "Mang chua duoc nhap\n";
		}
		else if (choice == 5)
		{
			if (flag)
			{
				popBack(mang1chieu, sophantu);
			}
			else
				cout << "Mang chua duoc nhap\n";
		}
		else if (choice == 6)
		{
			if (flag)
			{
				int vt;
				do
				{
					cout << "Vi tri xoa:";
					cin >> vt;
					if (vt <= 0 || vt > sophantu)
						cout << "Vui long nhap lai!\n";
				} while (vt <= 0 || vt >sophantu);
				popMid(mang1chieu, sophantu, vt-1);
			}
			else
				cout << "Mang chua duoc nhap\n";
		}
		else if (choice == 7)
		{
			if (flag)
			{
				int x,vt;
				cout << "Phan tu them:";
				cin >> x;
				do
				{
					cout << "Vi tri:";
					cin >> vt;
					if (vt <= 0 || vt > MAX)
						cout << "Vui long nhap lai!\n";
				} while (vt <= 0 || vt > MAX);
				pushMid(mang1chieu, sophantu, vt-1, x);
			}
			else
				cout << "Mang chua duoc nhap\n";
		}
		else if (choice == 8)
		{
			if (flag)
			{
				int x;
				cout << "Phan tu tim va xoa:";
				cin >> x;
				seekAndPop(mang1chieu, sophantu, x);
			}
			else
				cout << "Mang chua duoc nhap\n";
		}
		else
			break;
	}


	return 0;
}