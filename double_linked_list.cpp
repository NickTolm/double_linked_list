#include <iostream>

using namespace std;

struct Node 
{
	int x; 
	Node *next, *prev; 
};

class List{ 
	Node *Head, *Tail; 
public:
	List() :Head(NULL), Tail(NULL){};
	~List(); 
	void Show();
	void Add(int x);
};

List::~List(){
	while (Head){ 
		Tail = Head->next; 
		delete Head;
		Head = Tail; 
	}
}

void List::Add(int x){
	Node *temp = new Node; 
	temp->next = NULL;
	temp->x = x; 

	if (Head != NULL){
		temp->prev = Tail;
		Tail->next = temp; 
		Tail = temp;
	}
	else
	{
		temp->prev = NULL; 
		Head = Tail = temp;
	}
}

void List::Show(){
	
	Node *temp = Head;
	while (temp != NULL){ 
		cout << temp->x << " "; 
		temp = temp->next;
	}
	cout << "\n";

	/* 
	Node *temp = Tail;
	while (temp != NULL) 
	{
		cout << temp->x << " "; 
		temp = temp->prev; 
	}
	cout << "\n";
	*/
}


int main(){

	List lst;
	lst.Add(100);
	lst.Add(200);
	lst.Add(900);
	lst.Add(888);

	lst.Show();

	system("pause");
	return 0;
}