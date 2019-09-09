#include <iostream>
using namespace std;
#include "LinkedList.h"

int main()
{
	LinkedList list;

	list.insertAtFront('A');
	list.insertAtFront('B');
	list.insertAtFront('C');
	list.insertAtBack('D');
	list.insertAtFront('E');
	list.insertAtBack('F');
	list.insertAtBack('G');
	list.insertAtBack('H');
	list.insertAtFront('I');
	list.insertAtFront('I');

	cout << list << endl;

	list.deleteAtFront();
	cout << list << endl;

	list.deleteAtFront();
	cout << list << endl;
	//list.deleteAtFront();

	//list.deleteAtBack();
	//list.deleteAtBack();
	//list.deleteAtBack();



	

	


	//system("pause");
	return 0;
	//system("pause");
}
