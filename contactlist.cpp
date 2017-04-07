#include<iostream>
#include<conio.h>
using namespace std;
class ContactList;
class node
{
	string name;
	long long contactno;
	node *next;
	public :
	node(string s,long long num)
	{
		name = s;
		contactno = num;
		next = NULL;
	}
	friend class ContactList;
};
class ContactList
{
	node *start;
	public :
	ContactList()
	{
		start = NULL;
	}
	void create();
	void insert();
	void display();
};

void ContactList::create()
{
	string name;
	long long num;
	int ch=1;
	node *temp;	
	while(ch==1)
	{
		
	
		cout<<"\nEnter the  name of organization : ";
		cin>>name;
		cout<<"\nEnter Contact Number :";
		cin>>num;
		node *newnode = new node(name,num);	
		if(start == NULL)
			start = temp = newnode;
		else
		{
			temp -> next = newnode;
			temp = temp -> next ;
		} 
		cout<<"Enter 1 to add another contact in the list --------- Enter any other number to exit"<<endl;
		cin>>ch;
	}
}
void ContactList :: insert()
{
	string name;
	long long num;
	cout<<"Enter name of the organization : "<<endl;
	cin>>name;
	cout<<"Enter contact number : "<<endl;
	cin>>num;
	node *newptr = new node(name,num);
	node *temp;
	for(temp=start;temp->next!=NULL;temp=temp->next);
	temp->next = newptr;
}
void ContactList :: display()
{
	node *temp = start;
	while(temp!=NULL)
	{
		cout<<"Name of the organization : "<<temp->name<<endl;
		cout<<"Contact number : "<<temp->contactno<<endl;
		temp=temp->next;
	}
}
main()
{
	ContactList baner;
	int choice = 1;
	int ch;
	while(choice==1)
	{
		cout<<"Enter 1 to create a new list : "<<endl;
		cout<<"Enter 2 to insert information in the list : "<<endl;
		cout<<"Enter 3 to display the list : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1 : 	baner.create();
						break;
			case 2 :    baner.insert();
						break;
			case 3 :    baner.display();
						break;
			default :   cout<<"Enter valid choice ";
						break;
	
		}
		cout<<"Enter 1 to go back to main menu and 2 to terminate the program : ";
		cin>>choice;
	
	}
	
	getch();
}
