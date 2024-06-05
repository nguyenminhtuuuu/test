#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

bool isNguyenAm(char x)
{
	if (x == 'a' || x == 'A' ||
		x == 'o' || x == 'O' || x == 'e' || x == 'E'
		|| x == 'u' || x == 'U' || x == 'i' || x == 'I')
		return true;
	else
		return false;
}
float transDoub(float num)
{
	 num = (int)(num * 100 + .5);
	return num / 100;
}


using namespace std;
int main()
{
	/*int a, b, c;*/
	//ghi ra file
	/*ofstream myfile("BT3.txt");
	if (myfile.is_open())
	{
		myfile << a << '#' << b << '#' << c;
		myfile.close();
	}*/

	//doc tu file len chuong trinh
	/*ifstream myfile("BT3.txt");
	if (myfile.is_open())
	{
		myfile >> a;
		myfile.ignore(1);
		myfile >> b;
		myfile.ignore(1);
		myfile >> c;
		myfile.close();
	}
	cout << a << b << c << endl;*/

	//char str[21];//mang kt toi da 20 k
	//char* str1;//contro tinh tro den chuoi nhap vao
	//cout << "Chuoi ki tu bat ki:";
	//cin.get(str, 21);
	//str1 = str;//str o dang mang nen contro co the tro truc tiep toi
	//for (int i = 0; i < strlen(str1); i++)
	//{
	//	*(str1 + i) = toupper(*(str1 + i));
	//}

	//ofstream myfile("BT4.txt");
	//if (myfile.is_open())
	//{
	//	/*myfile << str1;*/
	//	for (int i = 0; i < strlen(str1); i++)
	//	{
	//		myfile << *(str1 + i) << " ";
	//	}
	//	myfile.close();
	//}
	//str1 = nullptr;
	/*char str[50];
	ifstream myfile("BT4.txt");
	if (myfile.is_open())
	{
		myfile.get(str, 50);
		myfile.close();*/
	/*}*/
	/*cout << str; int cnt = 0;
	char* str1;
	str1 = str;
	while (*str1)
	{
		if (isalnum(*str1))
			cnt++;
		str1++;
	}
	cout << "So ki tu trong chuoi la " << cnt << endl;*/

	
	/*char* str1 = str;
	cout << str1;
	ofstream myfile1("BT6.txt");
	if (myfile1.is_open())
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (isNguyenAm(*(str1 + i)))
				myfile1 << *(str + i) << " ";
		}
		
		
		myfile1.close();
	}*/


	/*float luong[1000];*/
	//float luong;
	//int tmp=0; int cnt = 0;
	//ofstream myfile2("BT7.txt");
	//while (tmp != -1)
	//{
	//	/*cin >> luong[cnt];
	//	tmp = luong[cnt];
	//	luong[cnt] = transDoub(luong[cnt]);
	//	cnt++;*/
	//	cin >> luong;
	//	tmp = luong;
	//	if(luong !=-1)
	//		myfile2 << transDoub(luong) << " ";
	//	
	//}
	//myfile2.close();
	

	/*string str;
	cout << "Chuoi:";
	getline(cin, str);*/
	/*ofstream myfile9("BT9.txt");;
	if (myfile9.is_open())
	{
		myfile9 << str;
		myfile9.close();
	}*/
	string tmp;
	ifstream myfile91("BT9.txt");
	if (myfile91.is_open())
	{
		getline(myfile91, tmp);
		myfile91.close();
	}
	/*if (str == tmp)
		cout << "Y\n";
	else
		cout << "N\n";*/
	/*string noi = str + tmp;
	cout << noi;*/
	int word = 1;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == ' ')
			word++;
	}
	cout << word;
	
	
	return 0;
}