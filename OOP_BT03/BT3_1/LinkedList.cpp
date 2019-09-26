#include "LinkedList.h"
LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
LinkedList::~LinkedList()
{
}
int LinkedList::IsEmpty()
{
	return (this->head == nullptr);
}
Node* LinkedList::Create(NhanVien data)
{
	Node *temp = new Node(data);
	if (temp)
	{
		temp->data = data;
		temp->prev = temp->next = nullptr;
	}
	return temp;
}
void LinkedList::Print()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		temp->print();
		temp = temp->next;
	}
}
void LinkedList::AddTail(NhanVien data)
{
	Node *temp = new Node(data);
	if (this->head == nullptr)
	{
		this->head = this->tail = temp;
		return;
	}
	temp->prev = this->tail;
	this->tail->next = temp;
	this->tail = temp;
	this->size++;
}
void LinkedList::AddFirst()
{
	NVBC r;
	NVHD s;
	bool sign;
	Node *P;
	cout << "La nhan vien bien che?(1/0) "; cin >> sign;
	if (sign == 1)
	{
		cin >> r;
		P = Create(r);
	}
	else
	{
		cin >> s;
		P = Create(s);
	}
	if (IsEmpty())
	{
		this->head = P;
		this->tail = P;
	}
	else
	{
		P->next = this->head;
		this->head->prev = P;
		this->head = P;
	}
	this->size++;
}
void LinkedList::AddLast()
{
	NVBC r;
	NVHD s;
	bool sign;
	Node *P;
	cout << "La nhan vien bien che?(1/0) "; cin >> sign;
	if (sign == 1)
	{
		cin >> r;
		P = Create(r);
	}
	else
	{
		cin >> s;
		P = Create(s);
	}
	if (IsEmpty())
	{
		this->head = P;
		this->tail = P;
	}
	else
	{
		this->tail->next = P;
		P->prev = this->tail;
		this->tail = P;
	}
	this->size++;
}
void LinkedList::Add(const int& legth)
{
	NVBC r;
	NVHD s;
	bool sign;
	Node *P;
	if ((legth > this->size + 1) || (legth < 1)) cout << "---illegal---" << endl;
	else
	{
		cout << "Input data of objective add:" << endl;
		cout << "La nhan vien bien che?(1/0) "; cin >> sign;
		if (sign == 1)
		{
			cin >> r;
			P = Create(r);
		}
		else
		{
			cin >> s;
			P = Create(s);
		}
		Node *PT1 = this->head, *PT2;
		int i = 1;
		while (PT1 != nullptr && i != legth - 1)
		{
			i++;
			PT1 = PT1->next;
		}
		PT2 = PT1->next;
		P->next = PT2;
		P->prev = PT1;
		PT1->next = P;
		PT2->prev = P;
		this->size++;
	}
}
void LinkedList::Update(NhanVien &p)
{
	NVBC r;
	NVHD s;
	bool sign;
	cout << "La nhan vien bien che?(1/0) "; cin >> sign;
	if (sign == 1)
	{
		cin >> r;
		p = r;
	}
	else
	{
		cin >> s;
		p = s;
	}
}
void LinkedList::DeleteFirst()
{
	if (!IsEmpty())
	{
		this->head = this->head->next;
		this->size--;
	}
}
void LinkedList::DeleteLast()
{
	if (!IsEmpty())
	{
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
		this->size--;
	}
}
void LinkedList::Delete(const int& legth)
{
	Node *PT1 = this->head, *PT2;
	int i = 1;
	if ((legth < 1) || (legth > this->size)) cout << "---illegal---" << endl;
	else
	{
		while (PT1 != nullptr && i != legth - 1)
		{
			i++;
			PT1 = PT1->next;
		}
		PT2 = PT1->next->next;
		PT1->next = PT2;
		PT2->prev = PT1;
		this->size--;
	}
}
void LinkedList::Sort()
{
	Node *temp;
	NhanVien info;
	bool Cond = false;
	while (!Cond)
	{
		Cond = true;
		for (temp = this->head; temp->next != nullptr; temp = temp->next)
			if (temp->data.Salary < temp->next->data.Salary)
			{
				info = temp->data;
				temp->data = temp->next->data;
				temp->next->data = info;
				Cond = false;
			}
	}
}
Node* LinkedList::Search(double Salary)
{
	Node *i = this->head;
	while (i && i->data.Salary != Salary)
		i = i->next;
	return i;
}
