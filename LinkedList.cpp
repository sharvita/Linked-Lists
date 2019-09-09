#include<iostream>
using namespace std;
//Sharvita Paithankar 
#include "LinkedList.h"
#include <fstream>
/*
Pre: None 
Post: None 
Description: Default constructor
*/
LinkedList::LinkedList() {
	headPtr = new Node();
}
/*
Pre: None 
Post: None 
Description: Destructor 
*/
LinkedList :: ~LinkedList() {
	clear();
}
/*
Pre: takes in value for new char to be inserted at front of list 
Post: retunrs true if new node is inserted at front
Description: This uses pointers and creates a new Node to 
             plug infront of the list 
*/
bool LinkedList :: insertAtFront(char value) {

	//creates new node
	Node *newPtr = new Node();
	newPtr->data = value;
	if (headPtr == NULL) {
		return false;
	} 
	//if list is empty 
	if (headPtr == nullptr)
		headPtr->nextPtr = newPtr;
    //if list is not empty 
	else if(headPtr != nullptr) 
	{
		Node *tempPtr = headPtr->nextPtr; //uses temporary pointer to save data 
		headPtr->nextPtr = newPtr; //sets head pointer to new data 
		newPtr->nextPtr = tempPtr;//sets new data pointer to previously saved data 
	}
	return true;
}
/*
Pre: takes in the index where the number should be inserted and the new data 
Post: returns true if places in list, false if pos is 0 or out of bounds 
Description: This function takes in an index and data that need to be inserted 
             at a certain index in the list. This function uses pointers and keeps track of 
			 previous and next pointers of the certain position. 
*/
bool LinkedList::insertBeforePosition(char value, int index) {

	if (index <= 0) {
		return false;
    }
	//if out of bounds 
	else if (index > size()) {
		cout << "The linked list's size is " << size() << ".'" << value << "' cannot be added because it is out of bounds." << endl;
		return false;
	}
   else {
	 Node *currentPtr = headPtr->nextPtr;
	 Node *newPtr = new Node();
	 newPtr->data = value;
	 Node *previousPtr = headPtr; //keeps track of pervious pointer 

	 //goes to the specific index 
	 for (int i = 0; i < index-1; i++) {
		 currentPtr = currentPtr->nextPtr;
		 previousPtr = previousPtr->nextPtr;
	 }

	 //sets previous pointer to new and new pointer to the rest of the list 
	 previousPtr->nextPtr = newPtr;
	 newPtr->nextPtr = currentPtr;

	 return true;
 }
}
/*
Pre: takes in value 
Post: returns true if the node is added at the back 
Description: This function takes in new data and creates a new 
             node to add at the back of the list 
*/
bool LinkedList::insertAtBack(char value) {

	Node *newPtr = new Node();
	newPtr->data = value;
	
	Node *currentPtr = headPtr;
	 //goes to last element 
	while (currentPtr->nextPtr != NULL) {
		currentPtr = currentPtr->nextPtr;
	}
	currentPtr->nextPtr = newPtr; //sets new pointer 
	newPtr->nextPtr = nullptr; // this is apparently necessary because it will set it to random data if its not null

	return true;

}
/*
Pre: none 
Post: returns true if stuff is delete at back of the list. returns false if list is empty 
Description: This function uses pointers to delete the first element of the list
*/
bool LinkedList::deleteAtFront() {

	if (headPtr->nextPtr == nullptr)
		return false;

	Node *tempPtr = headPtr->nextPtr ->nextPtr;//goes to the second element of the list 
	Node *deletePtr = headPtr->nextPtr; //first element of list 
	headPtr->nextPtr = tempPtr; //derefrences the front one 

	//clearns memory 
	delete deletePtr;
	deletePtr = nullptr;

	return true;
}
/*
Pre: takes in index which needs to be deleted 
Post: returns false if index is out of bounds or 0, else if index is deleted then its true
Description: This function takes in index that needs to be deleted and uses pointers and delete
             to do so. After deletion, last element needs to be set to nullptr 
*/
bool LinkedList::deletePosition(int index) {

	if (index == 0) {
		return false;
	}
	else if (index == size()) {
		deleteAtBack();
		return true;
	}
	else if (index == 1) {
		deleteAtFront();
	}
	//if out of bounds 
	else if (index > size()) {
		cout << "The linked list's size is " << size() <<  "' cannot be deleted because it is out of bounds." << endl;
		return false;
	}
	else {

		//keeps track of currents and previous pointer 
		Node *currentPtr = headPtr->nextPtr;
		Node *previousPtr = headPtr;

		//gos through loop 
		for (int i = 0; i < index-1; i++) {
			currentPtr = currentPtr->nextPtr;
			previousPtr = previousPtr->nextPtr;
		}

		//deletes pointers 
		Node *tempPtr = currentPtr->nextPtr;
		delete currentPtr;
		currentPtr = nullptr;

		//this is set to the rest of the list 
		previousPtr->nextPtr = tempPtr;

		return true;
	}
}
/*
Pre: none 
Post: deletes the last element of the list 
Description: This function deletes last element of list and uses pointers and delete
             to do so. After deletion, last element needs to be set to nullptr
*/
bool LinkedList::deleteAtBack() {

	//if list is empty 
	if (headPtr->nextPtr == NULL)
		return false;

	Node *currentPtr = headPtr->nextPtr;
	Node *previousPtr = headPtr;
	
	//goes to last element
	while (currentPtr->nextPtr != NULL) {
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	}
    
	//clears memory 
	delete currentPtr;
	previousPtr->nextPtr = nullptr; //needs to be set to nullptr

	return true; 
}
/*
Pre: none 
Post: free up memory for entire list 
Description: This function goes through the end of the list and deletes the last element until the list is cleared.
*/
void LinkedList::clear(){ //frees memory for entire list

	while (headPtr->nextPtr != NULL) {//until head ptr is not null, delete all the elements 
		deleteAtBack(); 
	}
	delete headPtr;
	headPtr = nullptr;//clears up memory for head pointer 

	//cout << "The list is empty" << endl;
	/*while(headPtr->nextPtr == nullptr){
		Node *tempPtr = new Node();
		tempPtr->nextPtr = headPtr->nextPtr;

		delete headPtr;
		headPtr = tempPtr;
	}*/
}
/*
Pre: takes in out operator and the list object 
Post: retunr the ostream object 
Description: this allows the user to print the linked list 
*/
ostream& operator<<  (ostream &out, LinkedList &list) {

	Node *currentPtr = list.headPtr->nextPtr;
	for (int i = 0; i < list.size(); i++) {

		out << currentPtr->data << " ";
		currentPtr = currentPtr->nextPtr;

	}
	return out;
}

/*
Pre: none
Post: none
Description: prints the linked list 

void LinkedList::print() {

	if (headPtr == NULL) {
		cout << "The list is empty " << endl;
	}
	else {
		Node *currentPtr = headPtr->nextPtr;

		cout << "The list has size of " << size() << " and contains :" << endl;

		for (int i = 0; i < size(); i++) {

			cout << currentPtr->data << " ";
			currentPtr = currentPtr->nextPtr;

		}
		cout << endl;
	}
}*/

/*
Pre: none
Post: none
Description: helper function to find the size of the list
*/
int LinkedList::size() {
	int count = 0;

	Node *currentPtr = headPtr;
	if (headPtr == NULL)
		return 0;
	if (headPtr->nextPtr == NULL)
		return 0;
	else {
		while (currentPtr->nextPtr != NULL) {
			count++;
			currentPtr = currentPtr->nextPtr;
		}
	}
	return count;

}