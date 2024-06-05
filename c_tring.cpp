#include<iostream>
using namespace std;
 
//c_string

void nhapChuoi(char cstring[])
{
	cout << "Chuoi ki tu:";
	cin.get(cstring, 50);

}
void xuatChuoi(char cstring[])
{
	cout << cstring << endl;
}
//void huyChuoi(char*& cstring)
//{
//	delete cstring;
//}


//Cac ham check
bool isSpace(char x)
{
	if (x == ' ')
		return true;
	return false;
}

//Cac ham xu ly cstring
void earseSpace(char cstring[])
{
	for (int i = 0; i < strlen(cstring); i++)
	{
		if (isSpace(cstring[i]) && isSpace(cstring[i + 1])|| isSpace(cstring[0]))
		{
			//doi chuoi tu phai sang trai
			while (isSpace(cstring[i])&& isSpace(cstring[i + 1]) || isSpace(cstring[0]))
			{
				for (int j = i; j < strlen(cstring); j++)
				{
					cstring[j] = cstring[j + 1];
				}
			}
		}
	}
}

int main()
{
	char chuoi[50];
	nhapChuoi(chuoi);
	xuatChuoi(chuoi);
	earseSpace(chuoi);
	xuatChuoi(chuoi);
	/*huyChuoi(chuoi);*/
	return 0;
}
