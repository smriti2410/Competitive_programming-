#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	//member initialiseer list , more efficient than full constructor function
	node(int val): data(val), next(nullptr){}
};

class LinkedList{
public:
	//head always points to the begining of Linked list
	node* head;
	LinkedList() : head(nullptr){};

	//insertion of element at front of linked list => push function

	void push(int data){
		node* newNode = new node(data);
		newNode->next=head; // new node points to the rest of the list that was previously headed by head.
		head= newNode; //places the new node at the beginning of the list.

	}

	//append function add a node at the end /tail of the linked list

	void append(int data){
		node* newNode =new node(data);
		if(head==nullptr){
			head=newNode;
			return; // breaks out of append function
		}

		node* temp= head;
		while(temp->next!=nullptr){
			temp=temp->next;

		}
		temp->next=newNode;

	}

	//reverse the linked list

	void reverse(){
		node* prev= nullptr;
		node* current =head;
		node* next=nullptr;

		//traversing the linked list 
		while(current!=nullptr){
			next=current->next;//do not lose the reference to the rest of the list.
			current->next=prev;// reverses the direction of the pointer for the current node.
			prev=current;
			current=next;
		}

		head=prev;
	}


	void printList(){
		node* temp=head;
		while(temp!=nullptr){
			cout<<temp->data<<" ";
			temp=temp->next;
		}

		cout<<endl;

	}
};



int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);


	LinkedList list;
	list.push(1);
	list.append(2);
	list.append(3);

	list.printList();
	list.reverse();

	list.printList();

}