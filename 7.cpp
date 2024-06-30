#include<iostream>
using namespace std;

//Cau truc dslk vong
struct node
{
	int info;
	node* next;
};
//Khoi tao dslk vong
void init(node*& head)
{
	head = NULL;
}
//Duyet phan tu dslk vong
void out(node* head)
{
	if (head == NULL)
		return;
	node* tmp = head;
	do
	{
		cout << tmp->info << ' ';
		tmp = tmp->next;
	} while (tmp != head);
	cout << endl;
}
//Tao node moi
node* createNode(int x)
{
	node* newNode = new node();
	newNode->info = x;
	newNode->next = NULL;
	return newNode;
}
//Them phan tu vao dau dslk vong
void pushFront(node*& head, int x)
{
	node* newNode = createNode(x);
	if (head == NULL)
	{
		head = newNode;
		head->next = head;
		return;
	}
	node* tmp = head;
	
	while (tmp->next != head)
	{
		tmp = tmp->next;

	}
	tmp->next = newNode;
	newNode->next = head;
	head = newNode;
	
}
//Xoa phan tu dau dslk vong
void popFront(node*& head)
{
	if (head == NULL)
		return;
	if (head->next == head)
	{
		delete head;
		head = NULL;
		return;
	}
	node* tmp = head;
	while (tmp->next != head)
	{
		tmp = tmp->next;
	}
	tmp->next = head->next;
	tmp = head;
	head = tmp->next;
	delete tmp;
}
//Them phan tu cuoi dslk vong
void pushBack(node*& head, int x)
{
	if (head == NULL)
	{
		pushFront(head, x);
		return;
	}
	node* newNode = createNode(x);
	/*if (head->next == head)
	{
		head->next = newNode;
		newNode->next = head;
		return;
	}*/
	node* tmp = head;
	while (tmp->next != head)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->next = head;
	
}
//Xoa phan tu cuoi dslk vong
void popBack(node*& head)
{
	if (head == NULL)
		return;
	if (head->next == head)
	{
		popFront(head);
		return;
	}
	node* tmp = head;
	while (tmp->next->next!= head)
	{
		tmp = tmp->next;
	}
	node* p = tmp->next;
	tmp->next =head;
	delete p;
}
//Tim kiem node
node* search(node* head, int x)
{
	if (head == NULL)
		return NULL;
	node* tmp = head;
	do
	{
		if (tmp->info == x)
			return tmp;
		tmp = tmp -> next;

	} while (tmp != head);
	return NULL;
}
//Tim va xoa trong  dslk vong
void seekAndPop(node*& head, int x)
{
	if (head == NULL)
		return;
	node* tmp = search(head, x);
	if(tmp!=NULL)
	{
		if (tmp == head)
		{
			popFront(head);
			return;
		}
		if (tmp->next == head)
		{
			popBack(head);
			return;
		}
		node* p = head;
		while (p->next != tmp)
		{
			p = p->next;

		}
		p->next = tmp->next;
		delete tmp;
	}
}

//Huy dslk
void delAll(node*& head)
{
	while (head != NULL)
		popFront(head);
}
int main()
{
	node* head;
	init(head);
	pushFront(head,5);
	out(head);
	pushFront(head, 7);
	pushFront(head, 8);//8 7 5
	out(head);

	popFront(head);//7 5;
	out(head);
	
	popBack(head);//7
	out(head);

	seekAndPop(head, 7);
	cout << "sau khi tim va xoa\n";
	out(head);
	
	delAll(head);
	return 0;
}