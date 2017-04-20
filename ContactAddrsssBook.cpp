// Contact Management System
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<iostream>
#include<process.h>
#include<windows.h>
using namespace std;

fstream baner;
fstream aundh;
fstream pashan;
fstream file;
char found;


class contactbook
{
		
	public:
	    char orgname[20];
		long contact;
		char category[10];
		char address[20];
		string passwd;
		
		
		void getdata();
		void display();
		void display1();
		void display2();
		void condition();
		void pass();
		void end();
		
		void gotoxy(short x,short y);
		void horiline(int size);
		void garea();
		void adminarea();
		
		void banerdata();
		void baneropen();
		void banerread();
		void banersearch();
		void banermodify();
		void banerdeleted();
		
		void aundhdata();
		void aundhopen();
		void aundhread();
		void aundhsearch();
		void aundhmodify();
		void aundhdeleted();
		
		void pashandata();
		void pashanopen();
		void pashanread();
		void pashansearch();
		void pashanmodify();
		void pashandeleted();
		
		void optionmenu();
		void login();
		void choice();
}c;

void contactbook::gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void contactbook::horiline(int size) {
	for (int i=0 ;i<size;i++) {
		cout<<"~";
	}
}
void contactbook::getdata()
{
	system("cls");
	//textcolor(YELLOW);
	gotoxy(33,2);
	cout<<" $ CITY Contact Management System $ ";
	gotoxy(30,3);
	cout<<"* Register Organisation * ";
	gotoxy(1,4);
	horiline(85);
	//textcolor(WHITE);
	gotoxy(14,6);
	cout<<"Ogransiation Name : ";
	gotoxy(14,8);
	cout<<"Contact Number :";
	gotoxy(14,10);
	cout<<"Category ";
	gotoxy(14,12);
	cout<<"Address : ";
	gotoxy(50,6);
	cin>>orgname;
	gotoxy(50,8);
	cin>>contact;
	gotoxy(50,10);
	cin>>category;
	gotoxy(50,12);
	cin>>address;
	gotoxy(20,18);
	cout<<"YOUR DATA HAS BEEN SUCCESFULLY CREATED"<<endl;
	getch();
}
void contactbook::display()
{

	system("cls");
	gotoxy(17,12);
	//textcolor(YELLOW);
	horiline(85);
	gotoxy(38,14);
	//textcolor(RED);
	cout<<" * CITY CONTACT ADDRESS BOOK * ";
	gotoxy(17,16);
	//textcolor(YELLOW);
	horiline(85);
	getch();
}
void contactbook::display1()
{
	cout<<"\t"<<contact<<"\t\t\t"<<orgname<<"\t\t\t\t"<<category<<"\t\t\t\t"<<address<<endl;
}
void contactbook::display2()
{
	gotoxy(15,8);
	//textcolor(YELLOW);
	cout<<"* Organisation Detail *";
	gotoxy(1,9);
	horiline(82);
	cout<<endl;
	cout<<"Emergency Contact No. : "<<contact<<endl;
	cout<<"Org Name : "<<orgname<<endl;
	cout<<"Category : "<<category<<endl;
	cout<<"Address : "<<address<<endl;
	getch();


}

/************************************* BANER DATA FUNCTIONS **************************************************************/

void contactbook::baneropen()
{
	char ans;
	baner.open("banerfile.txt",ios::in | ios::out | ios::app);
	ans='y';
	while(ans=='y')
	{
		c.getdata();
		baner.write((char*)&c,sizeof(c));
		//textcolor(WHITE);
		gotoxy(20,21);
		cout<<"DO you want to enter more record(y/n) : ";
		cin>>ans;
	}
	baner.close();
}
void contactbook::banerread()
{
	system("cls");
	gotoxy(24,8);
	cout<<"Please Wait...File Is Loading ";
//	delay(700);
	system("cls");
	baner.open("banerfile.txt",ios::in);
	baner.seekg(0);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* Details *";
	gotoxy(2,3);
	//textcolor(GREEN);
	horiline(110);
	gotoxy(2,4);
	cout<<"   Contact No. \t\t Organisation Name    \t\t Category\t\t\t Address";
	gotoxy(2,5);
    horiline(110);
    cout<<endl;
	while(baner.read((char*)&c,sizeof(c)))
	{
		if(baner.eof())
		break;
		c.display1();
	}
	baner.close();
	getch();
}
void contactbook::banersearch()
{
	long temp;
	int found='n';
	system("cls");
	gotoxy(30,1);
	//textcolor(YELLOW);
	cout<<"* CITY CONATACT ADDRESS BOOK *";
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* SEARCH *";
	gotoxy(1,3);
	horiline(80);
	gotoxy(15,7);
	cout<<"Enter the Contact No to be searched : "<<endl;
	baner.open("banerfile.txt",ios::out | ios::in);
	gotoxy(55,7);
	cin>>temp;
	gotoxy(15,8);
	cout<<"Searching...";
	//delay(1000);
	while(!baner.eof())
	{
		baner.read((char*)&c,sizeof(c));
		if(contact==temp)
		{
			c.display2();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Contact Does Not Exist"<<endl;
	baner.close();
	getch();
}
void contactbook::banermodify()
{
	found='n';
	int pos;
	long temp;
	system("cls");
	baner.open("banerfile.txt",ios::out | ios::in | ios::app);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* MODIFICATION *";
	gotoxy(14,6);
	cout<<"Enter the Contact No to be searched :"<<endl;
	gotoxy(53,6);
	cin>>temp;
	gotoxy(15,8);
	cout<<"  Searching..";
	//delay(700);
	while(!baner.eof())
	{
		pos=baner.tellg();
		baner.read((char*)&c,sizeof(c));
		if(contact==temp)
		{
			c.getdata();
			baner.seekg(pos);
			baner.write((char*)&c,sizeof(c));
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Contact Does Not Exist"<<endl;
	baner.close();
	getch();
}
void contactbook::banerdeleted()
{
	long temp;
	system("cls");
	baner.open("banerfile.txt",ios::in);
	file.open("temp.txt",ios::out);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* DELETE ORGANISATION DETAIL *";
	gotoxy(12,4);
	cout<<"Enter the contactbook No to be searched : "<<endl;
	gotoxy(55,4);
	cin>>temp;
	gotoxy(15,8);
	cout<<"   Searching..";
	//delay(700);
	found='n';
	char confirm='n';
	while(baner.read((char*)&c,sizeof(c)))
	{
		if(contact==temp)
		{
			display2();
			found='y';
			cout<<"\n\nAre you sure you want to delete record(y/n) :";
			cin>>confirm;
			if(confirm=='n')
				file.write((char*)&c,sizeof(c));

		}
		else
				file.write((char*)&c,sizeof(c));
	}
	if(found=='n')
	cout<<"DATA Does Not Exist"<<endl;
	baner.close();
	file.close();
	remove("banerfile.txt");
	rename("temp.txt","banerfile.txt");
	getch();
}


/************************************* AUNDH DATA FUNCTIONS **************************************************************/

void contactbook::aundhopen()
{
	char ans;
	aundh.open("aundhfile.txt",ios::in | ios::out | ios::app);
	ans='y';
	while(ans=='y')
	{
		c.getdata();
		aundh.write((char*)&c,sizeof(c));
		//textcolor(WHITE);
		gotoxy(20,21);
		cout<<"DO you want to enter more record(y/n) : ";
		cin>>ans;
	}
	aundh.close();
}
void contactbook::aundhread()
{
	system("cls");
	gotoxy(24,8);
	cout<<"Please Wait...File Is Loading ";
//	delay(700);
	system("cls");
	aundh.open("aundhfile.txt",ios::in);
	aundh.seekg(0);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* Details *";
	gotoxy(2,3);
	//textcolor(GREEN);
	horiline(110);
	gotoxy(2,4);
	cout<<"   Contact No. \t\t Organisation Name    \t\t Category\t\t\t Address";
	gotoxy(2,5);
    horiline(110);
    cout<<endl;
	while(aundh.read((char*)&c,sizeof(c)))
	{
		if(aundh.eof())
		break;
		c.display1();
	}
	aundh.close();
	getch();
}
void contactbook::aundhsearch()
{
	long temp;
	int found='n';
	system("cls");
	gotoxy(30,1);
	//textcolor(YELLOW);
	cout<<"* CITY CONATACT ADDRESS BOOK *";
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* SEARCH *";
	gotoxy(1,3);
	horiline(80);
	gotoxy(15,7);
	cout<<"Enter the Contact No to be searched : "<<endl;
	aundh.open("aundhfile.txt",ios::out | ios::in);
	gotoxy(55,7);
	cin>>temp;
	gotoxy(15,8);
	cout<<"Searching...";
	//delay(1000);
	while(!aundh.eof())
	{
		aundh.read((char*)&c,sizeof(c));
		if(contact==temp)
		{
			c.display2();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Contact Does Not Exist"<<endl;
	aundh.close();
	getch();
}
void contactbook::aundhmodify()
{
	found='n';
	int pos;
	long temp;
	system("cls");
	aundh.open("aundhfile.txt",ios::out | ios::in);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* MODIFICATION *";
	gotoxy(14,6);
	cout<<"Enter the Contact No to be searched :"<<endl;
	gotoxy(53,6);
	cin>>temp;
	gotoxy(15,8);
	cout<<"  Searching..";
	//delay(700);
	while(!aundh.eof())
	{
		pos=aundh.tellg();
		aundh.read((char*)&c,sizeof(c));
		if(contact==temp)
		{
			c.getdata();
			aundh.seekg(pos);
			aundh.write((char*)&c,sizeof(c));
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Contact Does Not Exist"<<endl;
	aundh.close();
	getch();
}
void contactbook::aundhdeleted()
{
	long temp;
	system("cls");
	aundh.open("aundhfile.txt",ios::in);
	file.open("temp.txt",ios::out);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* DELETE ORGANISATION DETAIL *";
	gotoxy(12,4);
	cout<<"Enter the contactbook No to be searched : "<<endl;
	gotoxy(55,4);
	cin>>temp;
	gotoxy(15,8);
	cout<<"   Searching..";
	//delay(700);
	found='n';
	char confirm='n';
	while(aundh.read((char*)&c,sizeof(c)))
	{
		if(contact==temp)
		{
			display2();
			found='y';
			cout<<"\n\nAre you sure you want to delete record(y/n) :";
			cin>>confirm;
			if(confirm=='n')
				file.write((char*)&c,sizeof(c));

		}
		else
				file.write((char*)&c,sizeof(c));
	}
	if(found=='n')
	cout<<"DATA Does Not Exist"<<endl;
	aundh.close();
	file.close();
	remove("aundhfile.txt");
	rename("temp.txt","aundhfile.txt");
	getch();
}

/************************************* PASHAN DATA FUNCTIONS **************************************************************/

void contactbook::pashanopen()
{
	char ans;
	pashan.open("pashanfile.txt",ios::in | ios::out | ios::app);
	ans='y';
	while(ans=='y')
	{
		c.getdata();
		pashan.write((char*)&c,sizeof(c));
		//textcolor(WHITE);
		gotoxy(20,21);
		cout<<"DO you want to enter more record(y/n) : ";
		cin>>ans;
	}
	pashan.close();
}
void contactbook::pashanread()
{
	system("cls");
	gotoxy(24,8);
	cout<<"Please Wait...File Is Loading ";
//	delay(700);
	system("cls");
	pashan.open("pashanfile.txt",ios::in);
	pashan.seekg(0);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* Details *";
	gotoxy(2,3);
	//textcolor(GREEN);
	horiline(110);
	gotoxy(2,4);
	cout<<"   Contact No. \t\t Organisation Name    \t\t Category\t\t\t Address";
	gotoxy(2,5);
    horiline(110);
    cout<<endl;
	while(pashan.read((char*)&c,sizeof(c)))
	{
		if(pashan.eof())
		break;
		c.display1();
	}
	pashan.close();
	getch();
}
void contactbook::pashansearch()
{
	long temp;
	int found='n';
	system("cls");
	gotoxy(30,1);
	//textcolor(YELLOW);
	cout<<"* CITY CONATACT ADDRESS BOOK *";
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* SEARCH *";
	gotoxy(1,3);
	horiline(80);
	gotoxy(15,7);
	cout<<"Enter the Contact No to be searched : "<<endl;
	pashan.open("pashanfile.txt",ios::out | ios::in);
	gotoxy(55,7);
	cin>>temp;
	gotoxy(15,8);
	cout<<"Searching...";
	//delay(1000);
	while(!pashan.eof())
	{
		pashan.read((char*)&c,sizeof(c));
		if(contact==temp)
		{
			c.display2();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Contact Does Not Exist"<<endl;
	pashan.close();
	getch();
}
void contactbook::pashanmodify()
{
	found='n';
	int pos;
	long temp;
	system("cls");
	pashan.open("pashanfile.txt",ios::out | ios::in);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* MODIFICATION *";
	gotoxy(14,6);
	cout<<"Enter the Contact No to be searched :"<<endl;
	gotoxy(53,6);
	cin>>temp;
	gotoxy(15,8);
	cout<<"  Searching..";
	//delay(700);
	while(!pashan.eof())
	{
		pos=pashan.tellg();
		pashan.read((char*)&c,sizeof(c));
		if(contact==temp)
		{
			c.getdata();
			pashan.seekg(pos);
			pashan.write((char*)&c,sizeof(c));
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Contact Does Not Exist"<<endl;
	pashan.close();
	getch();
}
void contactbook::pashandeleted()
{
	long temp;
	system("cls");
	pashan.open("pashanfile.txt",ios::in);
	file.open("temp.txt",ios::out);
	gotoxy(30,2);
	//textcolor(YELLOW);
	cout<<"* DELETE ORGANISATION DETAIL *";
	gotoxy(12,4);
	cout<<"Enter the contactbook No to be searched : "<<endl;
	gotoxy(55,4);
	cin>>temp;
	gotoxy(15,8);
	cout<<"   Searching..";
	//delay(700);
	found='n';
	char confirm='n';
	while(pashan.read((char*)&c,sizeof(c)))
	{
		if(contact==temp)
		{
			display2();
			found='y';
			cout<<"\n\nAre you sure you want to delete record(y/n) :";
			cin>>confirm;
			if(confirm=='n')
				file.write((char*)&c,sizeof(c));

		}
		else
				file.write((char*)&c,sizeof(c));
	}
	if(found=='n')
	cout<<"DATA Does Not Exist"<<endl;
	pashan.close();
	file.close();
	remove("pashanfile.txt");
	rename("temp.txt","pashanfile.txt");
	getch();
}


/***********************************      OTHER GUEST/ADMIN FUNCTIONS          ******************************************/

void contactbook::garea() 
{
	int ara;
	system("cls");
	gotoxy(20,4);
	horiline(80);
	gotoxy(33,6);
	cout<<" CITY CONTACT DATA BOOK ";
	gotoxy(36,7);
	cout<<"$$ CONTACT MANAGMENT $$";
	gotoxy(20,8);
	horiline(80);
	gotoxy(26,12);
	cout<<"1. BANER"<<endl;
	gotoxy(26,14);
	cout<<"2. AUNDH"<<endl;
	gotoxy(26,16);
	cout<<"3. PASHAN"<<endl;
	gotoxy(26,18);
	cout<<"4. Exit From Area List"<<endl;
	gotoxy(26,20);
	cout<<"Enter Choice :";
	gotoxy(20,26);
	horiline(80);
	gotoxy(45,20);
	cin>>ara;
	switch(ara) 
	{
		case 1: c.banerread();
				break;
		
		case 2: c.aundhread();
				break;
				
		case 3: c.pashanread();
				break;
		
		case 4: break;				
	}
		
}

void contactbook::optionmenu() 
{
	system("cls"); 
 	gotoxy(15,6);
	gotoxy(20,8);
	cout<<" 1. TO ADD contactbook HOLDER.";
	gotoxy(20,10);
	cout<<" 2. TO DISPLAY DATA OF ALL ACCOUNT HOLDERS.";
	gotoxy(20,12);
	cout<<" 3. MODIFY ORGANISATION DETAIL.";
	gotoxy(20,14);
	cout<<" 4. SEARCH ORGANISATION.";
	gotoxy(20,16);
	cout<<" 5. DELETE DATA.";
	gotoxy(20,18);
	cout<<" 6. Exit";
	gotoxy(36,24);
	cout<<"ENTER CHOOSE : ";
}
void contactbook::banerdata()
{
		int opt;
		c.optionmenu();
		cin>>opt;
			switch(opt)
			{
				case 1: c.baneropen();
						break;

				case 2: c.banerread();
						break;

				case 3:	c.banermodify();
						break;

				case 4: c.banersearch();
						break;

				case 5: c.banerdeleted();
						break;

				case 6: c.end();
			}
}

void contactbook::aundhdata()
{
		int opt;
		c.optionmenu();
		cin>>opt;
			switch(opt)
			{
				case 1: c.aundhopen();
						break;

				case 2: c.aundhread();
						break;

				case 3:	c.aundhmodify();
						break;

				case 4: c.aundhsearch();
						break;

				case 5: c.aundhdeleted();
						break;

				case 6: c.end();
			}
}

void contactbook::pashandata()
{
		int opt;
		c.optionmenu();
		cin>>opt;
			switch(opt)
			{
				case 1: c.pashanopen();
						break;

				case 2: c.pashanread();
						break;

				case 3:	c.pashanmodify();
						break;

				case 4: c.pashansearch();
						break;

				case 5: c.pashandeleted();
						break;

				case 6: c.end();
			}
}
void contactbook::login()
{
	passwd="";
	char ch;
	system("cls");
	gotoxy(37,10);
	cout<<"** WELCOME TO ADMIN PANEL **";
	gotoxy(20,11);
	horiline(80);
	gotoxy(40,13);
	cout<<"USERNAME :";
	gotoxy(53,13);
	cout<<"admin";
	gotoxy(40,15);
	cout<<"PASSWORD";
	gotoxy(20,16);
	horiline(80);
	gotoxy(53,15);
	ch= _getch();
	while(ch!=13)
	{
		passwd.push_back(ch);
		cout<<"*";
		ch= _getch();
	}
}
void contactbook::choice()
{
	int z;
	if(passwd.compare("admin")!=0)
	{
		gotoxy(40,18);
		cout<<"Wrong Login Credentials! :P";
		gotoxy(40,20);
		cout<<"Press Enter To Retry";
		getch();
		c.login();
		c.choice();
	}
	else
	{
		system("cls");
		if(passwd.compare("admin")==0)
		{
			gotoxy(55,2);
			cout<<"Welcome Administrator ! ";			
		}
	}
}
	

void contactbook::adminarea() 
{
	c.login();
	c.choice();
	int ara;
	gotoxy(20,4);
	horiline(80);
	gotoxy(33,6);
	cout<<" CITY CONTACT DATA BOOK ";
	gotoxy(36,7);
	cout<<"$$ CONTACT MANAGMENT $$";
	gotoxy(20,8);
	horiline(80);
	gotoxy(26,12);
	cout<<"1. BANER"<<endl;
	gotoxy(26,14);
	cout<<"2. AUNDH"<<endl;
	gotoxy(26,16);
	cout<<"3. PASHAN"<<endl;
	gotoxy(26,18);
	cout<<"4. Exit From Area List"<<endl;
	gotoxy(26,20);
	cout<<"Enter Choice :";
	gotoxy(20,26);
	horiline(80);
	gotoxy(45,20);
	cin>>ara;
	switch(ara) 
	{
		case 1: c.banerdata();
				break;
		
		case 2: c.aundhdata();
				break;
				
		case 3: c.pashandata();
				break;
		
		case 4: break;				
	}
		
}


void contactbook::condition()
{
    while(2)
	{
		int opt;
		while(2)
		{
			int pos1;
			system("cls");
			gotoxy(20,4);
			horiline(80);
			gotoxy(33,6);
			cout<<" CITY CONTACT DATA BOOK ";
			gotoxy(36,7);
			cout<<"$$ CONTACT MANAGMENT $$";
			gotoxy(20,8);
			horiline(80);
			gotoxy(34,12);
			cout<<"1. LOGIN AS GUEST";
			gotoxy(34,14);
			cout<<"2. LOGIN AS ADMINISTATOR";
			gotoxy(34,16);
			cout<<"3. Exit"<<endl;
			gotoxy(34,18);
			cout<<"Enter Choice :";
			gotoxy(50,18);
			cin>>pos1;
			switch(pos1)	
			{
				case 1: c.garea();
						break;
						
				case 2:	c.adminarea();
						break;
				
				case 3: exit(0);			
			}	
		
		}
	}
}

void contactbook::end()
{
 system("cls");
 gotoxy(34,14);
 cout<<"--- * THANK YOU * ---";
 gotoxy(32,16);
 cout<<"     SEE YOU AGAIN  ";
 getch();
 exit(0);
}
main()
{
	c.display();
    c.condition();
}
