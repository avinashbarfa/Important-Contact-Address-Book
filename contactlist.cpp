#include<iostream>
#include<conio.h>
using namespace std;
class ContactList;
class node
{
	string name;
	long contactno;
	node *next;
	public :
	node(string s,long num)
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
	void display();
};

void ContactList::create()
{
	string name;
	long num;
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
		cout<<"Enter 1 to add another contact in the list --------- Enter any other number to go back to main menu"<<endl;
		cin>>ch;
	}
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
	baner.create();
	baner.display();
	getch();
}
