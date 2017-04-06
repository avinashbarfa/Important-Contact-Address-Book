#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
#include<graphics.h>
struct entry
{
char name[50];
char nick[50];
char email[50];
char address[50];
char city[50];
char cont[50];
char pin[50];
struct entry *lptr;
struct entry *rptr;
}*temp,*newe,*l,*r;
typedef struct entry *list;
void newentry();
void display(char n[50]);
void deletentry(char n[50]);
void displayall();
void makempty();
int isempty();
void saventry();
void loadentry();
void deleteall();
void newentry()
{
char a[50],b[50],f[50],g[50],c[50],d[50],e[50];
int i,k=0;
printf("Enter the Datas for the New Entry:
");
printf("Name      :");
scanf("%s",a);
printf("Nick name :");
scanf("%s",b);
printf("E-mail ID :");
scanf("%s",c);
printf("Address   :");
scanf("%s",d);
printf("City      :");
scanf("%s",e);
printf("Contact No:");
scanf("%s",f);
printf("Pincode   :");
scanf("%s",g);
newe=(struct entry*)malloc(sizeof(struct entry));
for(i=0;i<50;i++)
{
newe->name[i]=' ';
newe->nick[i]=' ';
newe->email[i]=' ';
newe->address[i]=' ';
newe->city[i]=' ';
newe->cont[i]=' ';
newe->pin[i]=' ';
}
for(i=0;i<50;i++)
{
newe->name[i]=a[i];
newe->nick[i]=b[i];
newe->email[i]=c[i];
newe->address[i]=d[i];
newe->city[i]=e[i];
newe->cont[i]=f[i];
newe->pin[i]=g[i];
}
if(isempty())
{
newe->lptr=newe->rptr=NULL;
l=r=newe;
printf("Your Entry is Added
");
}
else
 {
	 temp=l;
	 while(temp!=NULL)
  {
	  i=stricmp(newe->name,temp->name);
	 if(i<0)
	 break;
	 else if(i>0)
	  temp=temp->rptr;
	  else if(i==0)
	 {
		printf("Name Already Exists.Entry cannot be Added
");
	  k=1;
	  break;
	 }
	}
	 if(k!=1)
	 {
		if(temp==l)
	{
	  newe->lptr=NULL;
	  newe->rptr=l;
	  l->lptr=newe;
	  l=newe;
	  printf("Your Entry is Added
");
	 }
	 else if(temp==NULL)
	{
	  newe->rptr=NULL;
	  newe->lptr=r;
	  r->rptr=newe;
	  r=newe;
	  printf("Your Entry is Added
");
	 }
	 else
	{
	newe->rptr=temp;
	newe->lptr=temp->lptr;
	temp->lptr=newe;
	(newe->lptr)->rptr=newe;
	printf("Your Entry is Added
");
	}
  }
  }
}

void displayall()
{       int n=1;
if(!isempty())
{
temp=l;
while(temp!=NULL)
{
printf("[%d]	Name      :%s
	Nick Name :%s
	E-mail ID 
:%s
	address
:%s
	City      :%s
	Contact.No:%s
	Pin code
:%s

",n,temp->name,temp->nick,temp->email,temp->address,temp->city,temp
->cont,temp->pin);
temp=temp->rptr;
n++;
}
}
else
printf("Address Book is Empty
");
}

void deletentry(char n[50])
{
int i;
if(isempty())
printf("Address  Book is Empty 
");
else{
temp=l;
while(temp!=NULL)
{
i=stricmp(temp->name,n);
if(i==NULL)
{
if(l==r)
{
l=r=NULL;
printf("Entry deleted
");
break;
}
else if(temp==l)
  {
  l=l->rptr;
  l->lptr=NULL;
  printf("Entry deleted
");
  break;
  }
else if(temp==r)
{
r=r->lptr;
r->rptr=NULL;
printf("Entry deleted
");
break;
}
else{
(temp->lptr)->rptr=temp->rptr;
(temp->rptr)->lptr=temp->lptr;
printf("Entry deleted
");
break;
}
}
temp=temp->rptr;

}
if(temp==NULL)
printf("Not Found
");
}
}
int isempty()
{
return l==NULL;
}

void makempty()
{
l=r=NULL;
printf("Address Book is Emptied
");
}





void display(char n[50])
{
int i,p=1;
if(isempty())
printf("Address Book is Empty
");
else
{
temp=l;
while(temp!=NULL)
{
i=stricmp(temp->name,n);
if(i==NULL)
{if(p==1)
printf("Entry is found in %dst position
",p);
 else if(p==2)
 printf("Entry is found in %dnd position
",p);
 else if (p==3)
 printf("Entry is found in %drd position
",p);
 else
printf("Entry is found in %dth position
",p);
printf("Name      :%s
Nick Name :%s
E-mail ID :%s
address   
:%s
City
 :%s
Contact.No:%s
Pin code
:%s
",temp->name,temp->nick,temp->email,temp->address,temp->city,temp->co
nt,temp->pin);
break;
}
temp=temp->rptr;
p++;
}
if(temp==NULL)
printf("Entry Not Found
");

}
}






void main()
{
int l=1,m;
int gd=DETECT,gm;
char n[50];
initgraph(&gd,&gm,"c:\tc\bgi");
while(l!=8)
{
clrscr();
textmode(C80);
textcolor(4);
cprintf("*****************************************************************
***************#------------------------MINI PROJECT-SIMPLE ADDRESS
BOOK----------------------#***********************************************
*********************************");
cprintf("Enter Your Choice");
printf("
");
cprintf("(1)-New Entry");
printf("
");
cprintf("(2)-Display an Entry");
printf("
");
cprintf("(3)-Delete an Entry");
printf("
");
cprintf("(4)-Display all Entries");
printf("
");
cprintf("(5)-Empty the book");
printf("
");
cprintf("(6)-Save Entry");
printf("
");
cprintf("(7)-Load Entries");
printf("
");
cprintf("(8)-Delete All Saved Files");
printf("
");
cprintf("(9)-End");
printf("
");
cprintf("*****************************************************************
***************");
printf("
");
scanf("%d",&l);
switch(l)
{
case 1:
textcolor(2);
newentry();
getch();
break;
case 2:
textcolor(2);
cprintf("Enter the Name of the Person to Display");
printf("
");
scanf("%s",&n);
display(n);
getch();
break;
case 3:
textcolor(2);
cprintf("Enter the Name of the Person to Delete");
printf("
");
scanf("%s",&n);
deletentry(n);
getch();
break;
case 4:
textcolor(2);
displayall();
getch();
break;
case 5:
textcolor(2);
makempty();
getch();
break;
case 6:
textcolor(2);
saventry();
getch();
break;
case 7:
textcolor(2);
loadentry();
getch();
break;
case 8:
textcolor(2);
deleteall();
getch();
break;
case 9:
textcolor(2);
printf("Program Ends Here.Thank You!!!");
printf("
");
getch();
break;
default:
textcolor(2);
printf("Enter a Valid Choice from 1-9 only");
printf("
");
getch();
break;
}
}
getch();
}
void saventry()
{
char n[50];
int c;
printf("Enter the Name of the Person
");
scanf("%s",n);
list t;
if(isempty())
printf("Address Book is Empty
");
else
{
FILE *f;
f=fopen("entry.c","a");
int i;t=l;
while(t!=NULL)
{
i=stricmp(t->name,n);
if(i==0)
{
fprintf(f," 
%s %s %s %s %s %s %s
",t->name,t->nick,t->email,t->address,t->city,t->cont,t->pin);
printf("Your Entry Saved
");
printf("Add Another Entry?
 (1-yes/2-no)
");
scanf("%d",&c);
if(c==1)
saventry();
else if(c==2)
break;
}
t=t->rptr;

}
fclose(f);
if(t==NULL)
printf("Entry Not Found
");
}

}
void loadentry()
{
int i=1;
list t;
FILE *f;
       f=fopen("entry.c","r");
	if(f==NULL)
	{
	printf("Cannot Open
");
	exit(1);
	}
	while(fscanf(f," %s %s %s %s %s %s %s
",t->name,t->nick,t->email,t->address,t->city,t->cont,t->pin)!=EOF)
       {	printf("[%d]	Name      :%s
	Nick Name :%s
	E-mail ID
:%s
	address   :%s
	City      :%s
	Contact.No:%s
	Pin code
:%s
",i,t->name,t->nick,t->email,t->address,t->city,t->cont,t->pin);
	i++;}
	fclose(f);
	}


	void deleteall()
	{
	FILE *f;
	f=fopen("entry.c","w");
	fclose(f);
	printf("all saved files were delete
");
	}

