#include<iostream>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
void entry_menu(); void result();
void class_result(); void delete_student();
void modify_student(); void display_sp(int n);
void write_student();
int  retid(); void show_tabular();
void showdata(); void calculate();
void getdata(); int id = 1;
char name[50]; int phno;
char address[50]; int tickets;
int code,total_seats=100,reserved=0,cl,no=0,cost;
int i =0;
class student
{
	
	void calculate()
	{
  if(reserved<total_seats)
  {  reserved++;
   printf("\nEnter the train code");
   scanf("%d",&code);
   if(code==1021||code==1024||code==1098||code==1987||code==1576)
    { 
     printf("\n1.first class(fare Rs1500 )");
     printf("\n2.second class(fare Rs1000)");
     printf("\n3.sleeper class(fare Rs500)");
     scanf("%d",&cl);
       if(cl==1)
       {
       	
		cost = 1500 * tickets;
 printf("\nYour fare is Rs.%d",cost);
 
       }
       else if(cl==2)
       {
 
		cost = 1000 * tickets;
 printf("\nYour fare is Rs.%d",cost);
       }
       else if(cl==3)
       {
       	
		cost = 500 * tickets;
 printf("\nYour fare is Rs.%d",cost);
       }
       else
       {
	     printf("\nEnter valid choice(1,2or 3)");
       }
	}}
showdata();}
 public:
	void getdata()
	{    cout<<"enter your id "; 
		cin>>id;
		cout<<"\n\nEnter your Name";
		cin>>name;
		cout<<"\nEnter your phone number : ";
		cin>>phno;
		cout<<"\nEnter your address : ";
		cin>>address;
		cout<<"\nEnter the number of ticket you wish to buy ";
		cin>>tickets;
		calculate();
	}
	
	void showdata()
	{
		cout<<("\nHere is your ticket\n");
 cout<<"-----------------------------------------------------------------------------------------------\n";
 cout<<"                             APOORVA'S RAILWAY NETWORK                                        \n";
 cout<<" ID : "<<id<<endl;
 cout<<" Name: "<<name<<endl;
 cout<<" Phone Number: "<<phno<<endl;
 cout<<" Address: "<<address<<endl;                   
 cout<<" Tickets Booked: "<<tickets<<endl;
 cout<<" Tickets Cost: "<<cost<<endl;
 cout<<"                               HAVE A NICE JOURNEY!                                          \n";
 cout<<"-----------------------------------------------------------------------------------------------\n";
 
	}

	void show_tabular()
	{
	cout<<id<<setw(12)<<name<<setw(10)<<phno<<setw(10)<<address<<setw(10)<<tickets<<setw(3)<<"   "<<cost<<endl;
	}

	int  retid()
	{	return id;	}

};         
 fstream fp;
 student st;
void write_student()
{
	fp.open("student.dat",ios::out|ios::app);
	st.getdata();
	fp.write((char*)&st,sizeof(student));
	fp.close();
	cout<<"\n\nYour Data Has been saved ";
	
}

void display_sp(int n)
{
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retid()==n)
		{
		
			st.showdata();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\nrecord does not exist";

}
void modify_student()
{
	int no,found=0;
	
	cout<<"\n\n\tTo Modify ";
	cout<<"\n\n\tPlease Enter your id";
	cin>>no;	
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	{
		if(st.retid()==no)
		{
			st.showdata();
			cout<<"\nPlease Enter The New Details"<<endl;
			st.getdata();
			int pos = static_cast<int>(-1 * sizeof(st));
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";}
void delete_student()
{
	int no;

    	cout<<"\n\n\n\tDelete Record";
    	cout<<"\n\nPlease Enter the id number of person whose data you want to delete";
    	cin>>no;
    	fp.open("student.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retid()!=no)
		{
			fp2.write((char*)&st,sizeof(student));
		}
	}
    	fp2.close();
    	fp.close();
    	remove("student.dat");
    	rename("Temp.dat","student.dat");
    	cout<<"\n\n\tRecord Deleted ..";
    	
}
void class_result()
{
	
	fp.open("student.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
       		cout<<"\n\n\n Program is closing ....";
       		
       		exit(0);
     	}
	cout<<"\n\n\t\tALL RECORDS \n\n";
	cout<<"====================================================\n";
	cout<<"ID. Name          Phone Number  Address  Ticket booked  Cost\n";
	cout<<"====================================================\n";
	while(fp.read((char*)&st,sizeof(student)))
	{
		st.show_tabular();
	}
     	fp.close();
     	
}
void result()
{
	int ans,rno;
    	char ch;
    	
    	cout<<"\n\n\nBOOKING MENU";
    	cout<<"\n\n\n1. View all bookings\n\n2. View your Ticket\n\n3.Back to Main Menu";
    	cout<<"\n\n\nEnter Choice (1/2)? ";
    	cin>>ans;
    	switch(ans)
    	{
     		case 1 : class_result();break;
     		case 2 : {
			   char ans;
				cout<<"\n\nEnter Roll Number Of Student : ";
				cin>>rno;
				display_sp(rno);
			    break;
	       		}
     		case 3 :break;
     		default:  cout<<"\a";
 	   	}
 }
void entry_menu()
{
  	
  	char ch2;
  	cout<<"\n\n\n\tENTRY MENU";
  	cout<<"\n\n\t1.CREATE  RECORD";
  	cout<<"\n\n\t2.MODIFY YOUR RECORD";
  	cout<<"\n\n\t3.DELETE YOUR RECORD";
  	cout<<"\n\n\t4.BACK TO MAIN MENU";
  	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
  	cin>>ch2;
  	switch(ch2)
  	{
    		case '1': 
	      		write_student();
	      		break;
      		case '2': modify_student();break;
      		case '3': delete_student();break;
      		case '4': break;
      		default:cout<<"\a";entry_menu();
   	}
}
int main()
{
  	char ch;
  	
  	do
    	{
		
	  	cout<<"\n\n\n\tMAIN MENU";
	  	cout<<"\n\n\t01. BOOK";
	  	cout<<"\n\n\t02. LOGIN/REGISTER";
	  	cout<<"\n\n\t03. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-3) ";
	  	cin>>ch;
	  	switch(ch)
	  	{
			case '1': 
				result();
			   	break;
		  	case '2': entry_menu();
			    	break;
		  	case '3':exit(0);
		  	default :cout<<"\a";
		}
    	}while(ch!='3');
return 0;
}
