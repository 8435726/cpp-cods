#include <iostream>
using namespace std;
//node yapýsý
class Node{
	public:
		int data;
		Node* next;
		Node(int data){         //constracter
			this->data=data;
			this->next=0;       
		}
		~Node(){    //deconstracter
			cout<<data<<"dugumu silindi"<<endl;
		}
   	friend class LinkedList; 
};
//linked list yapýsý
class LinkedList{
	private:
		Node* head;
	public:
		LinkedList(){     //constracter		
			head=0;
		}
		~LinkedList(){     //decontracter   hepsini siliyo
		    Node*temp=head;
		    while(temp!=0){
		        Node*del=temp;  //geçici atama 1. düðümü gösteriyo
		        temp=temp->next;   //2.düðümü gösteriyo
		        delete del; // 1. düðüm silindi
		    }
		}
		
 		void insertAtBeginning(int data) { // to insert a front node
  			Node *newNode = new Node(data);   //create a new node with data
    		newNode->next = head;   // head now follows newNode
   			head = newNode;// newNode is now the head
		 }
  
   		void deleteAtBeginning() {  // to remove front node
    		if (head == 0) {  // if there is no node in the list
    		  return;     
   		}
   			Node *temp = head; // save the current head
    		head = head->next;  // skip over old head
    		delete temp;  // delete the old head
  		}
  //insert at end
		void add(int data){
			Node* newNode =new Node(data);    //create a new node
			if(head==0){
				head=newNode;
			}
			else{
				Node* temp=head;
				while(temp->next!=0)
					temp=temp->next;
				temp->next=newNode;
			}
		}
		void deleteAtEnd(){
		    if(head==0) return;
		    if(head->next==0){
		        delete head;
		        head=0;  //unutma önemli
		    }
		    else{
		 		Node* temp=head;
                while(temp->next->next!=0)  // sondan bir öncekini güsterir
		            temp=temp->next;
		        delete temp->next;   //son düðümü sildik
		        temp->next=0;   //baðý koparttýk
		    }
		    cout<<"son dugum silindi"<<endl;

		}
		void print(){
		
			Node* temp=head;
			while(temp!=0)  //son dögüde de düðümün içine girilir
			{
			    cout<<temp->data<<" ";
			    //cout<<temp->next<<" "; düðümün içindeki nexti yazdýrýr
				temp=temp->next;
			}
			cout<<endl;
	    }
};
// main kod örneði
int main(){
	LinkedList*  b=new LinkedList();

	b->add(1);
	b->add(2);
	b->add(3);
	b->add(4);
	b->add(5);
	cout<<"original list: ";
	b->print();
	cout<<endl;
	b->deleteAtEnd();   
	cout<<endl;
	b->print();
	delete b;    //hepsini sildi

}
