#include<iostream>
using namespace std;

//Cau truc dslk kep
struct node
{
	int info;
	node* next;
	node* prev;
};
//khoi tao dslk
void init(node*& head)
{
	head = NULL;
}
//Xuat phan tu dslk kep
void out(node* head)
{
	while (head != NULL)
	{
		cout << head->info << " ";
		head = head->next;
	}
	cout << endl;
}
//Tao node moi
node* createNode(int x)
{
	node* newNode = new node();
	newNode->info = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//Them phan tu vao dau dslk kep
void pushFront(node*& head, int x)
{
	node* newNode = createNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}
//Them phan tu vao cuoi dslk kep
void pushBack(node*& head, int x)
{
	node* newNode = createNode(x);
	node* tmp = head;
	if (tmp == NULL)
	{
		head = newNode;
		return;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->prev = tmp;
}
//Xoa phan tu dau dslk kep
void popFront(node*& head)
{
	if (head == NULL)
	{
		return;
	}
	node* tmp = head;
	head = head->next;
	delete tmp;
}
//Xoa phan tu cuoi dslk kep
void popBack(node*& head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		delete head;
		return;
	}
	node* tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	node* last = tmp;
	tmp = tmp->prev;
	tmp->next = NULL;
	last->prev = NULL;
	delete last;
	return;
}
//Tim phan tu
node* search(node* head,int x)
{
	if (head == NULL)
		return NULL;
	node* tmp = head;
	while (tmp != NULL)
	{
		if (tmp->info == x)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}
//Tim phan tu va xoa
void seekAndPop(node*& head, int x)
{
	node* tmp = search(head, x);
	if (tmp!= NULL)
	{
		if (tmp->prev == NULL)
			popFront(tmp);
		else if (tmp->next == NULL)
			popBack(tmp);
		else
		{
			node* prevTmp = tmp->prev;
			prevTmp->next = tmp->next;
			tmp->next->prev = prevTmp;
			delete tmp;
		}
	}
}
//Ham huy dslk kep
void delAll(node*& head)
{
	while (head != NULL)
	{
		popFront(head);
	}
}
//Doi cho node
void swap(node*& a, node*& b)
{
	auto c = a->info;
	a->info = b->info;
	b->info = c;
}
//Sap xep mang
void changeHead(node*& head, bool funct(node* a, node* b))
{
	node* tmp = head;
	node* lastTmp;
	if (tmp == NULL)
		return;
	while (tmp != NULL)
	{
		lastTmp = tmp->next;
		while (lastTmp != NULL)
		{
			if (funct(tmp, lastTmp))
				swap(tmp, lastTmp);
			lastTmp = lastTmp->next;
		}
		tmp = tmp->next;
	}
}

bool isIncre(node* a, node* b)
{
	return a->info > b->info ? true : false;
}
bool isDecre(node* a, node* b)
{
	return a->info < b->info ? true : false;
}
//Them phan tu vao giua dslk kep
void pushMid(node*& head, int tmp, int x)
{
	if (head == NULL)
		return;
	node* p = head;
	node* newNode = createNode(x);
	if (head->info == tmp)
	{
		pushFront(head, x);
		return;
	}
	while (p != NULL)
	{
		if (p->info == tmp)
		{
			
			newNode->next = p;
			newNode->prev = p->prev;
			p->prev->next = newNode;
			p->prev = newNode;
			return;
			
		}
		p = p->next;
	}
}
//Tim phan tu gan x nhap vao va chen node vao truoc phan tu do
void seekAndInsert(node*& head, int x, int xchen)
{
	if (head != NULL)
	{
		//sap xep tang dan
		changeHead(head, isIncre);
		node* tmp = head;
		while (tmp != NULL)
		{
			if (tmp->info>x || tmp->info == x)
			{
				break;
			}
			tmp = tmp->next;
		}
		pushMid(head, tmp->info, xchen);
	}
}
int main()
{
	node* head;
	init(head);
	pushFront(head, 10);
	pushFront(head, 9);

	

	pushFront(head, 8);
	pushFront(head, 7);
	pushBack(head, 5);//7 8 9 10 5
	out(head);
	
	
	popFront(head);//8 9 10  5
	out(head);
	
	seekAndInsert(head, 3, 7);//7 5 8 9 10
	out(head);
	
	//popBack(head);//8 9 10
	//out(head);
	//
	//seekAndPop(head, 9);//8 10
	//out(head);

	//seekAndInsert(head, 8, 7);//7 8 10
	//out(head);
	
	

	delAll(head);
	return 0;
}