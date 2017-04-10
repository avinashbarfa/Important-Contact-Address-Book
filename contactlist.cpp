#include <iostream>
#include<conio.h>
#include <iomanip>
#include <limits>
#include <string.h>
#include <Windows.h>
using namespace std;
//bool check(string);

bool check(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=48 && a[i]<=57)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}

bool check_alphabet(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=65 && a[i]<=122)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}


void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}	

void horiline(int size) {
	for(int i=0;i<size;i++) {
		cout<<"-";
	}
	cout<<endl;
}	
	
class ContactList;

bool check(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=48 && a[i]<=57)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}

bool check_alphabet(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=65 && a[i]<=122)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}


void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}	

void horiline(int size) {
	for(int i=0;i<size;i++) {
		cout<<"-";
	}
	cout<<endl;
}	
	


class node
{
	string name;
	string contactno;
	node *next;
	public :
<<<<<<< HEAD
	node(string s,string num)
=======
	node(string s,long num)
>>>>>>> origin/master
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
	void search();
};

void ContactList::create()
{
	string name;
	string num;
	int ch=1;
	node *temp;
	while(ch==1)
	{
		system("CLS");
<<<<<<< HEAD
		gotoxy(20,3);
		cout<<"Name of Organization : ";
		gotoxy(43,3);
		cin>>name;
		while(check(name)==false)
			{
				gotoxy(43,3);
				cout<<"                                  ";
				gotoxy(43,3);
				cin>>name;
			}
		gotoxy(20,5);
		cout<<"Contact Number :";
		gotoxy(43,5);
=======
		cout<<"\nName of Organization : ";
		cin>>name;
		while(check(name)==false)
		{
			gotoxy(42,3);
			cout<<"                       ";
			gotoxy(42,3);
			cin>>name;
		}
		cout<<"\nContact Number :";
>>>>>>> origin/master
		cin>>num;
		while(check_alphabet(num) == false)
			{
				gotoxy(43,5);
				cout<<"                              ";
				gotoxy(43,5);
				cin>>num;
			}
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
<<<<<<< HEAD
	string num;
=======
	long num;
>>>>>>> origin/master
	cout<<"Enter name of the organization : "<<endl;
	cin>>name;
	cout<<"Enter contact number : "<<endl;
	cin>>num;
	node *newptr = new node(name,num);
	node *temp;
	for(temp=start;temp->next!=NULL;temp=temp->next);
	temp->next = newptr;
}
/*void ContactList::sort() {
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
}*/

void ContactList::search()
{
	string search_name;
	int flag=0;
	system("CLS");
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
		cout<<"Sorry, Contact Details Not Found."<<endl;
	}
}

void ContactList::display()
{
	system("CLS");
	node *temp = start;
<<<<<<< HEAD
	horiline(120);
	cout<<"\tOrganization Name \t\t\t\t Contact Number"<<endl;
	horiline(120);
=======
	horiline(125);
	cout<<"\tOrganization Name \t\t\t\t Contact Number"<<endl;
	horiline(125);
>>>>>>> origin/master
	while(temp!=NULL)
	{
		cout<<"\t\t"<<temp->name;
		cout<<"\t\t\t\t"<<temp->contactno<<endl;
		temp=temp->next;
	}
}

void splashscreen() {
	
	system("CLS");
<<<<<<< HEAD
	gotoxy(5,7);
	horiline(112);
	cout<<endl;
	gotoxy(40,10);
	cout<<"----  EMERGENCY ADDRESS BOOK  ----"<<endl;
	cout<<endl;
	gotoxy(5,13);
	horiline(112);
	Sleep(0000);
=======
	horiline(125);
	cout<<endl;
	gotoxy(20,20);
	cout<<"----  EMERGENCY ADDRESS BOOK  ----"<<endl;
	cout<<endl;
	horiline(125);
	Sleep(1000);
>>>>>>> origin/master
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
		gotoxy(12,7);
		horiline(100);
		gotoxy(16,10);
		cout<<"1. To Create A New Contact List."<<endl;
		gotoxy(16,12);
		cout<<"2. To Add New Contact In The List."<<endl;
		gotoxy(16,14);
		cout<<"3. To Display The Contact List."<<endl;
		gotoxy(16,16);
		cout<<"4. Search Contact."<<endl;
		gotoxy(16,24);
		cout<<"   Quit Address Book."<<endl;
		gotoxy(16,26);
		cout<<"Enter Your Choice : ";
		gotoxy(12,28);
<<<<<<< HEAD
		horiline(100);
=======
		horiline(124);
>>>>>>> origin/master
		gotoxy(36,26);
		cin>>ch;
		cout<<endl;
		
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
			case 4 :    baner.search();
						break;
			
			case 5:     exit(0);
			
			default :   cout<<"Enter valid choice ";
						break;
	
		}
	}
	
	getch();
}
