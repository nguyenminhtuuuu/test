#include<iostream>
using namespace std;

//cau truc danh sach lien ket
struct Node
{
	int info;
	Node* next;
};
//khoi tao danh sach rong
void init(Node** first)
{
	*first = NULL;
}
//tao ra Node moi -> ham tra ve kieu Node
Node* makeNode(int x)
{
	Node *newNode = new Node();
	newNode->info = x;
	newNode->next = NULL;
	return newNode;
}
//duyet phan tu dslk
void output(Node* head)
{
	
	while (head != NULL)
	{
			cout << head->info << " ";
		head = head->next;
	}
	cout << endl;
	return;
}
//tim phan tu trong dslk
Node* search(Node* head, int x)
{
	if (head == NULL)
		return NULL;
	Node *tmp = head;
	while (tmp != NULL)
	{
		if (tmp->info == x)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}
//them mot phan tu vao dau danh sach
void pushFront(Node** head, int x)
{
	Node* newHead = makeNode(x);
	if (*head == NULL) //*head: giai tham chieu
	{
		*head = newHead;
	}
	else
	{
		newHead->next = *head;
		*head = newHead;
	}
	return;
}
//xoa phan tu dau dslk
void popFront(Node** head)
{
	if (*head == NULL)
		return;
		Node* tmp = *head;
		*head = (*head)->next;
		delete tmp;
		return;
		
}
//them phan tu cuoi dslk
void pushBack(Node** head,int x)
{
	Node* newNode = makeNode(x);
	Node* last;
	last = *head;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = newNode;
}
//xoa phan tu cuoi dslk
void popBack(Node** head)
{
	if (*head == NULL)
		return;
	Node* tmp = *head;
		if (tmp->next == NULL)
		{
			*head = NULL;
			delete tmp;
			return;
		}
		Node* last, * nearlast;
		last;
		nearlast = *head;
		while (nearlast->next->next != NULL)
		{
			nearlast = nearlast->next;
		}
		last = nearlast->next;
		nearlast->next = NULL;
		delete last;
	
}
//tim va xoa trong dslk
void seekAndPop(Node** head, int x)
{
	if (*head == NULL)
		return;
		Node* neartmp;
		neartmp = *head;
		//Tim Node cuoi
		Node* last=*head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		//Truong hop la Node dau
		if ((*head)->info == x)
		{
			popFront(head);
			return;
		}
		//Truong hop la Node cuoi
		if (last->info == x)
			popBack(head);
		//Truong hop con lai
		while (1)
		{
			Node* tmp;
			
			if (neartmp->next->info == x)
			{
				tmp = neartmp->next;
				neartmp->next =tmp->next;
				delete tmp;
			}
			neartmp = neartmp->next;
			if (neartmp->next == NULL && neartmp->info != x)
				return;
		}

}
//doi cho 2 Node
void swap(Node** first, Node** second)
{
	auto third = (*first)->info;
	(*first)->info = (*second)->info;
	(*second)->info = third;
}
//so sanh lon hon
bool isLarger(int x, int y)
{
	return x > y ? true : false;
}
//so sanh nho hon
bool isSmaller(int x, int y)
{
	return x < y ? true : false;
}
//chuyen thanh danh sach co thu tu
void change(Node** head,bool condition(int x,int y))
{
	if (*head != NULL)
	{
		Node* headtmp;
		headtmp = *head;
		while (headtmp != NULL)
		{
			Node* tmp = headtmp->next;
			while (tmp!= NULL)
			{
				if (condition(headtmp->info, tmp->info))
					swap(&headtmp, &tmp);
				tmp = tmp->next;
			}
			headtmp = headtmp->next;
		}
	}
}

int main()
{
	Node* head;
	init(&head);
	while (1)
	{
		int lc;
		cout << "------------------------------\n";
		cout << "1.Xuat dslk\n";
		cout << "2.Tim mot phan tu dslk\n";
		cout << "3.Them phan tu dau dslk\n";
		cout << "4.Them phan tu cuoi dslk\n";
		cout << "5.Xoa phan tu dau dslk\n";
		cout << "6.Xoa phan tu cuoi dslk\n";
		cout << "7.Tim phan tu va xoa trong dslk\n";
		cout << "8.Sap danh sach tang dan\n";
		cout << "9.Sap danh sach giam dan\n";
		cout << "0.Thoat\n";
		cout << "------------------------------\n";
		cout << "Chon:";
		cin >> lc;
		system("cls");
		if (lc == 1)
		{
			if (head == NULL)
				cout << "DSLK dang trong!\n";
			else
				output(head);
		}
		else if (lc == 2)
		{
			if (head != NULL)
			{
				int x;
				cout << "Phan tu tim:";
				cin >> x;
				if (search(head, x) == NULL)
					cout << "Khong tim thay!\n";
				else 
					cout << "Tim thay " << search(head, x)->info << " trong DSLK!\n";
			}
			else
				cout << "DSLK dang trong!\n";
		}
		else if (lc == 3)
		{
				int x;
				cout << "Phan tu them:";
				cin >> x;
				pushFront(&head, x);
		}
		else if (lc == 4)
		{
				int x;
				cout << "Phan tu them:";
				cin >> x;
				pushBack(&head, x);
		}
		else if (lc == 5)
		{
			if (head != NULL)
			{
				popFront(&head);
			}
			else
				cout << "DSLK dang trong!\n";
		}
		else if (lc == 6)
		{
			if (head != NULL)
			{
				popBack(&head);
			}
			else
				cout << "DSLK dang trong!\n";
		}
		else if (lc == 7)
		{
			if (head != NULL)
			{
				int x;
				cout << "Phan tu tim va xoa:";
				cin >> x;
				if (search(head, x) != NULL)
				{
					seekAndPop(&head, x);
				}
				else
					cout << "Phan tu khong co trong mang\n";
			}
			else
				cout << "DSLK dang trong!\n";
		}
		else if (lc == 8)
		{
			if (head != NULL)
			{
				change(&head,isLarger);
			}
			else
				cout << "DSLK dang trong!\n";
		}
		else if (lc == 9)
		{
			if (head != NULL)
			{
				change(&head, isSmaller);
			}
			else
				cout << "DSLK dang trong!\n";
		}
		else
			return 0;
	}



	return 0;
}