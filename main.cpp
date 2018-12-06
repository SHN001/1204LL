#include <iostream>
#include "llist.h"
using namespace std;

int main() {

	Linked_list lst;

	lst.push_front(3);
	lst.push_front(2);
	lst.push_front(1);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);

	lst.print_list();

	cout << boolalpha << "7 deleted? : " << lst.delete_one(7) << endl;
	
	lst.delete_one(1);
	lst.print_list();

	lst.delete_one(6);

	lst.print_list();

	lst.delete_one(3);
	lst.print_list();

	cout << "first node : " << lst.front() << endl;
	cout << "last node : " << lst.back() << endl;

	lst.delete_all();
	lst.print_list();
	
	system("pause");
	return 0;
}