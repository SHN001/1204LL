#include <iostream>
#include "llist.h"
using namespace std;

Linked_list::Linked_list() : m_head(nullptr), m_tail(nullptr) {}
Linked_list::~Linked_list() 
{
	if (m_head) delete_all();
}

void Linked_list::push_front(const int data)
{
	Node* tmp = new Node;
	tmp->data = data;

	if (m_head == nullptr)
	{
		m_head = tmp;
		m_tail = tmp;
		m_tail->next_node = nullptr;
	}
	else
	{
		tmp->next_node = m_head;
		m_head = tmp;
	}
}

bool Linked_list::pop_front()
{

		if (m_head) 
			return true;
		else 
			return false;
}

int Linked_list::front()
{
	if (pop_front()) 
		return m_head->data;
	else
		return 0;
}

void Linked_list::push_back(const int data)
{
	Node* tmp = new Node;

	tmp->data = data;
	if (m_tail == nullptr)
	{
		m_head = tmp;
		m_tail = tmp;
	}
	else
	{
		m_tail->next_node = tmp;
		m_tail = tmp;

	}
	m_tail->next_node = nullptr;
}

bool Linked_list::pop_back() 
{
	
	if (m_tail)
		return true;
	else
		return false;
}

int Linked_list::back()
{
	if (pop_back()) 
		return m_tail->data;
	else
		return 0;
}

bool Linked_list::delete_all()
{
	Node* next;

	if (!m_head)
		return false;

	while (m_head)
	{
		next = m_head->next_node;
		delete m_head;
		m_head = next;
	}

	return true;
}

bool Linked_list::delete_one(const int data)
{
	Node* prev;
	Node* cur;

	if (!m_head)
		return false;

	cur = m_head;
	prev = m_head;

	while ((cur != nullptr) && (cur->data != data))
	{
		prev = cur;
		cur = cur->next_node;
	}

	if (cur == nullptr)
		return false;

	if (cur == m_head)
	{
		m_head = m_head->next_node;
		delete cur;

		return true;
	}

	if (cur == m_tail)
	{
		m_tail = prev;
		m_tail->next_node = nullptr;
		delete cur;

		return true;
	}
	else
	{
		prev->next_node = cur->next_node;
		delete cur;

		return true;
	}

}

void Linked_list::print_list()
{
	Node* tmp;
	tmp = m_head;

	if (!m_head)
		cout << "=====empty list=====" << endl;
	else
	{
		cout << "=====Print List=====" << endl;

		while (m_head)
		{
			cout << m_head->data;
			if (m_head->next_node) cout << " -> ";
			m_head = m_head->next_node;
		}
		cout << "\n=====Print End=====" << endl;
	}
	m_head = tmp;
}