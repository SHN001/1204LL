#ifndef LLST_H
#define LLST_H

struct Node {
	int data;
	Node* next_node;
};

class Linked_list {
	Node* m_head;
	Node* m_tail;
public:
	// const Mat& input, Mat& ouput
	void push_front(const int data);
	bool pop_front();
	int front();
	void push_back(const int data);
	bool pop_back();
	int back();
	bool delete_all();
	bool delete_one(const int data);
	void print_list();
	
	Linked_list();
	~Linked_list();
};

#endif