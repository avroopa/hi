#include<stdio.h>
#include<string.h>
struct air
{ 
  int phno;
  char address[50];
  int ticketno;
  char name[30],pass[30];

  }s[99];
  void menu();
  void view();
  void cancel();
  void reserve();
  void read();
  int i;
void menu()
{ int ch;
printf("\n\n1.VIEW ALL TRAINS");
printf("\n\n2.RESERVE A TICKET");
printf("\n\n3.CANCEL A TICKET");
printf("\n\n4.VIEW TICKETS");
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
  case 4:read();
  menu();
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
int n,i=0;
FILE *fp;
  
  if(reserved<total_seats)
  {  reserved++;
   printf("\nEnter the train code");
   scanf("%d",&code);
   if(code==1021||code==1024||code==1098||code==1987||code==1576)
    { 
     printf("\n1.first class(fare Rs1500 )");
     printf("\n2.second class(fare Rs1000)");
     printf("\n3.sleeper class(fare Rs500)");
     scanf("%d",&class);
     printf("\nEnter number of tickets to be booked");
     scanf("%d",&s[i].ticketno);
       if(class==1)
       {
       	
		a = 1500 * s[i].ticketno;
 printf("\nYour fare is Rs.%d",a);
 
       }
       else if(class==2)
       {
 
		a = 1000 * s[i].ticketno;
 printf("\nYour fare is Rs.%d",a);
       }
       else if(class==3)
       {
       	
		a = 500 * s[i].ticketno;
 printf("\nYour fare is Rs.%d",a);
       }
       else
       {
	     printf("\nEnter valid choice(1,2or 3)");
       }
fp=fopen("stu.dat","wb");
if(fp==NULL)
{
printf("can't create file");

}
n=1+i;
for(i=0;i<n;i++)
{
 printf("\nEnter your name");
 scanf("%[^\n]s",&s[i].name);
 printf("\nEnter the phone number");
 scanf("%d",&s[i].phno);
 printf("\n Enter the address");
 scanf("%[^\n]s",&s[i].address);
 printf("\nEnter number of tickets to be booked");
  scanf("%d",&s[i].ticketno);
 printf("\nYour ticket is confirmed");
fwrite(&s,sizeof(s),1,fp);
}
fclose(fp);
}
 
 printf("\nHere is your ticket\n");
 printf("-----------------------------------------------------------------------------------------------\n");
 printf("                             APOORVA'S RAILWAY NETWORK                                        \n");
 printf(" Name: %c                                                                                     \n",s[i].name);
 printf(" Phone Number: %d                                                                             \n",s[i].phno);
 printf(" Address: %c                                                                                  \n",s[i].address);                   
 printf(" Tickets Booked: %d                                                                           \n",s[i].ticketno);
 printf("                               HAVE A NICE JOURNEY!                                          \n");
 printf("-----------------------------------------------------------------------------------------------\n");

}
else
 printf("Error");

}

void cancel()
{int ticket;
 char ch;
 
printf("enter the ticket no");
scanf("%d",&ticket);
 if(ticket==s[i].ticketno)
  {    printf("your ticket is cancelled");

   }
 else
 {printf("ticket no is invalid");
  
 menu();
}}
void read()
{
FILE *fp;
fp=fopen("stu.dat","rb");
if(fp==NULL)
{
printf("can't read file");
}
while(fread(&s,sizeof(s),1,fp)==1)
{
 printf("\nEnter your name",s[i].name);
 printf("\nEnter the phone number",s[i].phno);
 printf("\n Enter the address",s[i].address);
 printf("\nEnter number of tickets to be booked",s[i].ticketno);
}
fclose(fp);
}
void main(){
	int n;
	printf("***********************************************************");
	printf("\n         Welcome to Apoorva's Railway Network              ");
	printf("\n***********************************************************");
 menu();
}

