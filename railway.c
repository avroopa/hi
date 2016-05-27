#include<stdio.h>
struct air
{ char name[20];
  int phno;
  char address[50];
  int ticketno;

  }s;
  void menu();
  void view();
  void cancel();
  void reserve();
  
void menu()
{ int ch;
printf("\n\n1.VIEW ALL TRAINS");
printf("\n\n2.RESERVE A TICKET");
printf("\n\n3.CANCEL A TICKET");
printf("\nEnter your choice(1,2 or 3)");
scanf("%d",&ch);
switch(ch)
{ case 1: view();
   menu();
   break;
  case 2: reserve();
    menu();
    break;
  case 3: cancel();
  
  menu();
  break;
  default:printf("\nenter a valid choice");
}}
void view()
{ 
  printf("CODE      ROUTE  TIMINGS    ");
  printf("\n1021 Delhi to Mumbai                 06:30      ");
  printf("\n1024    Delhi to kolkata             12:00      ");
  printf("\n1098 Delhi to Amritsar               14:30      ");
  printf("\n1987 Delhi to Banglore               18:00      ");
  printf("\n1576 Delhi to chennai                20:00      ");

  

}
void reserve()
{ int code,total_seats=100,reserved=0,class,no=0,a=0;
  
  if(reserved<total_seats)
  {  reserved++;
   printf("Enter the train code");
   scanf("%d",&code);
   if(code==1021||code==1024||code==1098||code==1987||code==1576)
    { 
     printf("\n 1.first class(fare Rs1500 )");
     printf("\n 2.second class(fare Rs1000)");
     printf("\n 3.sleeper class(fare Rs500)");
     scanf("%d",&class);
     printf("Enter number of tickets to be booked");
     scanf("%d",&no);
       if(class==1)
       {
       	
		a = 1500*no;
 printf("Your fare is Rs.%d",&a);
 
       }
       else if(class==2)
       {
 
		a = no*1000;
 printf("Your fare is Rs.%d",&a);
       }
       else if(class==3)
       {
       	
		a = 500*no;
 printf("Your fare is Rs.%d",&a);
       }
       else
       {
	     printf("Enter valid choice(1,2or 3)");
       }
    
 printf("\nEnter the name");
 scanf("%s",&s.name);
 printf("\nEnter the phone number");
 scanf("%d",&s.phno);
 printf("\n Enter the address");
 scanf("%s",&s.address);
  printf("Number of tickets");
  scanf("%d",&s.ticketno);
 printf("Your ticket is confirmed");
 
 printf("\nHere is your ticket\n");
 printf("-----------------------------------------------------------------------------------------------\n");
 printf("                             APOORVA'S RAILWAY NETWORK                                        \n");
 printf(" Name: %c                                                                                     \n",&s.name);
 printf(" Phone Number: %d                                                                             \n",&s.phno);
 printf(" Address: %c                                                                                  \n",&s.address);                   
 printf(" Tickets Booked: %d                                                                           \n",&s.ticketno);
 printf("                               HAVE A NICE JOURNEY!                                          \n");
 printf("-----------------------------------------------------------------------------------------------\n");

}
else
 printf("Error");

}
}
void cancel()
{int ticket;
 char ch;
 
printf("enter the ticket no");
scanf("%d",&ticket);
 if(ticket==s.ticketno)
  {    printf("your ticket is cancelled");

   }
 else
 {printf("ticket no is invalid");
  
 menu();
}}
void main(){
	printf("***********************************************************");
	printf("\n         Welcome to Apoorva's Railway Network              ");
	printf("\n***********************************************************");
	
 menu();
}

