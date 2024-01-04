#include <iostream>
using namespace std;
// Reverse linked list
class Node{
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		this->next=nullptr;
	}
	friend class linkedlist;
};
class linkedlist(){
	Node* head;
	linkedlist(){
		this->head=nullptr;
	}
	void reverse(){
		
	}
};
int main(int argc, char** argv) {
	
	return 0;
}
