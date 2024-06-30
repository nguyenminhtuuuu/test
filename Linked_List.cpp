#include<iostream>
using namespace std;
//moi node trong dslk la mot con tro kieu node
struct node
{
	int data;
	node* next;
};
//cap phat node moi
node* makeNode(int x)
{
	node* newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//duyet dslk
void duyet(node* head)
{
	while (head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}
//dem dslk
int size(node* head)
{
	int dem = 0;
	while (head != NULL)
	{
		++dem;
		head = head->next;
	}
	return dem;
}
//them node vao dau dslk
void pushFront(node** head, int x)
{
	node* newNode = makeNode(x);
	newNode->next = *head;//toan tu giai tham chieu, diachi cua node head
	*head = newNode;
}
void pushFront2(node*& head, int x)
{
	node* newNode = makeNode(x);
	newNode->next = head;
	head = newNode;
}
//them node vao cuoi dslk
void pushBack(node **head, int x)
{
	node* newNode = makeNode(x);
	//tim node cuoi trong dslk
	node* tmp = *head;
	if (*head == NULL)
	{
		*head = newNode; return;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	
    tmp->next = newNode;
}
//chen node vao giua
void insert(node** head,int k, int x)
{
	int n = size(*head);
	if (k<1 || k>n + 1) return;
	if (k == 1)
	{
		pushFront(head, x); return;
	}
	node* tmp = *head;
	for (int i = 1; i <= k - 2; i++)
	{
		tmp = tmp->next;
	}
	//tmp : k-1
	node* newNode = makeNode(x);
	newNode->next = tmp->next;
	tmp->next = newNode;
}
//xoa node dau
void popFront(node **head)
{
	if (*head == NULL) return;
	node* tmp = *head;
	*head = (*head)->next;
	delete tmp;
}
void popBack(node** head)
{
	if (*head == NULL) return;
	node* tmp = *head;
	if (tmp->next == NULL)
	{
		*head = NULL; delete tmp;
		return;
	}
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	node* last = tmp->next;//node cuoi can xoa
	tmp->next = NULL;
	delete last;
	
}
//xoa node giua
void popInsert(node** head,int k)
{
	if (k >= 1 || k <= size((*head)))
	{
		node* tmp = *head;
		if (head == NULL)
			return;
		else if ((*head)->next == NULL)
		{
			delete* head;
			return;
		}
		else
		{
			for (int i = 1; i < k - 1; i++)
				tmp = tmp->next;
			node* tem = tmp->next;
			tmp->next = tem->next;
			delete tem;
		}
	}
}
//xoa toan bo
void delAll(node*& head)
{
	while (head != NULL)
		popFront(&head);
}
int main()
{
	node* head = NULL;
	int lc;
	while (1)
	{
		cout << "\n----------------------------\n";
		cout << "1.Them vao dau\n";
		cout << "2.Them vao cuoi\n";
		cout << "3.Them vao giua\n";
		cout << "4.Xoa node khoi dau DSLK\n";
		cout << "5.Xoa node khoi cuoi DSLK\n";
		cout << "6.Xoa node giua DSLk\n";
		cout << "7.Duyet\n";
		cout << "0.Thoat\n";
		cout << "----------------------------\n";
		cout << "lc:";
		cin >> lc;
		if (lc == 1)
		{
			int x;
			cout << "Nhap so:"; cin >> x;
			pushFront(&head, x);
		}
		else if (lc == 2)
		{
			int x;
			cout << "Nhap so:"; cin >> x;
			pushBack(&head, x);
		}
		else if (lc == 3)
		{
			int x; int vt;
			cout << "Nhap so:";
			cin >> x;
			cout << "Vi tri them:";
			cin >> vt;
			insert(&head, vt, x);
		}
		else if (lc == 4)
		{
			popFront(&head);
		}
		else if (lc == 5)
		{
			popBack(&head);
		}
		else if (lc == 6)
		{
			int vt;
			cout << "Vi tri xoa:";
			cin >> vt;
			popInsert(&head, vt);
		}
		else if (lc == 7)
		{
			duyet(head);
		}
		else
			return 0;


	}


	delAll(head);
	return 0;
}