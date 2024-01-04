#include <iostream>
using namespace std;
#define SPACE 10
class TreeNode{
	public:
		int value;             //key or data
		TreeNode* left;
		TreeNode* right;
		TreeNode()
		{
			value=0;
			left=NULL;
			right=NULL;
		}
		TreeNode(int v)
		{
			value=v;
			left=NULL;
			right=NULL;
		}
};
class BST{
	public:
		TreeNode* root;
		BST(){
			root=NULL;
		}
		bool isTreeEmpty()
		{
			if(root==NULL)
				return true;
			else
				return false;
		}
		void insertNode(TreeNode* new_node)
		{
			if(root==NULL)
			{
				root==new_node;
				cout<<"value Inserted as root node!"<<endl;
			}
			else{
				TreeNode* temp=root;
				while(temp!=NULL)
				{
					if(new_node->value==temp->value)
					{
						cout<<"Value Already exist, Insert another value!"<<endl;
						return;
					}
					else if((new_node->value<temp->value)&&(temp->left==NULL)){
						temp->left=new_node;
						cout<<"Value Inserted to the left!"<<endl;
						break;
					}
					else if(new_node->value<temp->value){
						temp=temp->left;
					}
					else if((new_node->value>temp->value)&&(temp->right==NULL)){
						temp->right=new_node;
						cout<<"Value Inserted to the right!"<<endl;
						break;
					}
					else{
						temp=temp->right;
					}
				}
			}
			
		}
		void print2D(TreeNode* r,int space)
		{
			if(r==NULL)            //Base case
				return;
			space +=SPACE;
			print2D(r->right,space);
			cout<<endl;
			for(int i=SPACE; i<space;i++)
				cout<<" ";
			cout<<r->value<<"\n";
			print2D(r->left,space);
		}
		

};
int main() 
{
	BST obj;
	int option,val;
	do
	{
		cout<<"what operation do you want to perform? ";
		cout<<"Select option number. Enter 0 to exit."<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print BST Values"<<endl;
		cout<<"5. Clear Screen"<<endl;
		cout<<"0. Exit Program"<<endl;
		
		cin>>option;
		TreeNode*new_node=new TreeNode();
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"INSERT"<<endl;
				cout<<"Enter value of tree node to ýnsert in BST:";
				cin>>val;
				new_node->value=val;
				obj.insertNode(new_node);
				cout<<endl;
				break;
			case 2:
				cout<<"SEARCH"<<endl;
				
				break;
			case 3:
				cout<<"DELETE"<<endl;
				
				break;
			case 4:
				cout<<"PRINT ant TRAVERSE"<<endl;
				obj.print2D(obj.root,5);
				
				break;
			case 5:
				//cout<<"CLEAR SCREEN"<<endl;
				system("cls");
				break;
			default:
				cout<<"Enter Proper Option number"<<endl;
		}
	}
	while(option!=0);
	
	return 0;
}
