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
	string areaName;

	ContactList()
	{
		areaName = "";
		start = NULL;
	}
	void create();
	void insert();
	void search();
	void display();
	friend class listgraph;
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
void ContactList :: search()
{
	string search_name;
	int flag=0;
	cout<<"Enter name of the organization to be searched : "<<endl;
	cin>>search_name;
	node *temp;
	temp = start;
	while(temp!=NULL)
	{
		if(temp->name==search_name)
		{
			cout<<"Contact number of "<<temp->name<<" is : "<<temp->contactno;
			int flag=1;
		}
		temp = temp->next;
	}
	if(flag==0)
	{
		cout<<"Sorry, number not found"<<endl;
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
	ContactList areas[10];
	int ch,n;
	string name;
							
	cout<<"How many areas do you want to enter?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
			int choice = 1;

		cout<<"Enter name of the area : "<<endl;
		cin>>areas[i].areaName;
		cout<<areas[i].areaName;
		while(choice==1)
		{
			cout<<"Enter 1 to create a new list : "<<endl;
			cout<<"Enter 2 to insert information in the list : "<<endl;
			cout<<"Enter 3 to search the list : "<<endl;
			cout<<"Enter 4 to display the list : "<<endl;
			cin>>ch;
			switch(ch)
			{
				case 1 : 	areas[i].create();
							break;
				case 2 :    cout<<"Enter name of the list in which you want to insert : "<<endl;
							cin>>name;
							for(int j=0;j<n;j++)
							{
								if(name==areas[j].areaName)
								areas[j].insert();
							}
							break;
				case 3 :    cout<<"Enter name of the list in which you want to search : "<<endl;
							cin>>name;
							for(int j=0;j<n;j++)
							{
								if(name==areas[j].areaName)
								areas[j].search();
							}
							break;
				case 4 :	cout<<"Enter name of the list in which you want to display : "<<endl;
							cin>>name;
							for(int j=0;j<n;j++)
							{
								if(name==areas[j].areaName)
								areas[j].display();
							}
							break;
						
				default :   cout<<"Enter valid choice ";
							break;
		
			}
			cout<<"Enter 1 to go back to main menu and 2 to terminate the program : ";
			cin>>choice;
		
		}			
	}
	

	
	getch();
}
