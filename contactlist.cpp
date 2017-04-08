#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<windows.h>
using namespace std;
class ContactList;
class node
{
	string name;
	long long contactno;
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
	void insert();
	void display();
	void sort();
};

void ContactList::create()
{
	string name;
	long long num;
	int ch=1;
	node *temp;
	while(ch==1)
	{
		
	
		cout<<"\nName of Organization : ";
		cin>>name;
		cout<<"\nContact Number :";
		cin>>num;
		node *newnode = new node(name,num);	
		if(start == NULL)
			start = temp = newnode;
		else
		{
			temp -> next = newnode;
			temp = temp -> next ;
		} 
		cout<<"\nEnter 1 to add another contact in the list --------- Enter any other number to exit"<<endl;
		cin>>ch;
	}
}
void ContactList::insert()
{
	system("CLS");
	string name;
	long num;
	cout<<"Enter name of the organization : "<<endl;
	cin>>name;
	cout<<"Enter contact number : "<<endl;
	cin>>num;
	node *newptr = new node(name,num);
	node *temp;
	for(temp=start;temp->next!=NULL;temp=temp->next);
	temp->next = newptr;
}
void ContactList::sort() {
	node *temp = start;
	node *temp2  = new node(name,num);
	while(temp!=null) {
		if(1 == (strcmp(temp->node.s, temp->next -> node.s))) {
			
			strcpy (temp2 -> node(s,num) , temp -> node(s,num));
			strcpy (temp -> node(s,num) , temp->next -> node(s,num));
			strcpy (temp->next -> node(s,num) , temp2 -> node(s,num));
		}
		temp= temp->next;
	}
}
void ContactList::display()
{
	system("CLS");
	node *temp = start;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	cout<<"\tOrganization Name \t\t\t\t Contact Number"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	while(temp!=NULL)
	{
		cout<<"\t\t"<<temp->name;
		cout<<"\t\t\t\t"<<temp->contactno<<endl;
		temp=temp->next;
	}
}

void splashscreen() {
	
	//gotoxy(20,40);
	cout<<"----  EMERGENCY ADDRESS BOOK  ----"<<endl;
	Sleep(1000);
	
}

void horiline(int size) {
	for(int i=0;i<size;i++) {
		cout<<"-";
	}
	cout<<endl;
}
main()
{
	ContactList baner,pashan;
	int choice = 1;
	int ch;
	splashscreen();
	while(1)
	{
		system("CLS");
		cout<<"1. To Create A New Contact List."<<endl;
		cout<<"2. To Add New Contact In The List."<<endl;
		cout<<"3. To Display The Contact List."<<endl;
		cout<<"   Exit"<<endl;
		cout<<"\n";
		cout<<"Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : 	baner.create();
						break;
			case 2 :    baner.insert();
						break;
						baner.sort();
			case 3 :    baner.display();
						cout<<endl;
						horiline(120);
						cout<<"Enter Any Key To Return Back : ";
						char o;
						cin>>o;
						break;
			
			case 4:     exit(0);
			
			default :   cout<<"Enter valid choice ";
						break;
	
		}
	}
	
	getch();
}
