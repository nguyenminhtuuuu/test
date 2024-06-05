#include<iostream>
using namespace std;

void menu()
{
	cout << "Ban can nhap chuoi gi?\n";
	cout << "--------M E N U--------\n";
	cout << "1.Loi bai hat\n"
		<< "2.Ho va ten\n"
		<< "0.Thoat\n";
}
int main()
{
	
		char s[50],*p,*q; int chon;
		menu();
		
			cout << ">>Chon:";
			cin >> chon;
			cin.ignore();
			switch (chon)
			{
			case 1:

				cout << "---Loi bai hat---\n";
				cout << "Moi nhap:";
				cin.get(s, 50);
				p = s;
				if (islower(*(p + 0)))
					*(p + 0) = toupper(*(p + 0));
				cout << p << endl;
				break;

			case 2:
				cout << "---Ho va ten---\n";
				cout << "Moi nhap:";
				cin.get(s, 50);
				q = s;
				for (int i = 0; i < 15; i++)
				{
					if (islower(*(q + 0)))
						*(q + 0) = toupper(*(q + 0));
					if (isspace(*(q + i)) && islower(*(q + i + 1)))
						*(q + i + 1) = toupper(*(q + i + 1));
					if (i != 0)
					{
						if (isspace(*(q + i - 1)) == false && isupper(*(q + i)))
							*(q + i) = tolower(*(q + i));
					}
				}
				cout << q << endl;
				break;
			case 0:
			{
				cout << "Ket thuc!\n";
				return 0;
			}
			default:
				cout << "Du lieu khong hop le!\n";
			}
		


	return 0;
}