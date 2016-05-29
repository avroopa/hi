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
  void login();
  void reg();
  int i;
  
  void reg()
  {
    FILE *fp;
    char c,checker[30]; int i,n,z=0;
    fp=fopen("Web_reg.txt","ab+");
    for(i=0;i<100;i++)
    {
      printf("\n ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&s[i],sizeof(s[i]),1,fp);
          if(strcmp(checker,s[i].name)==0)
            {
            printf("\nUSERNAME ALREADY EXISTS");
           
            reg();
            }
          else
          {
            strcpy(s[i].name,checker);
            break;
          }
        }
      printf("\n  ENTER PASSWORD: ");
      while((c=getch())!=13)
        {
          s[i].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&s[i],sizeof(s[i]),1,fp);
      fclose(fp);
      printf("\nPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
      
        printf("\nYou are successfully registered");
        printf("\nTry login your account??");
        printf("> PRESS 1 FOR YES\n > PRESS 2 FOR NO");
        scanf("%d",&n);
        switch(n)
          {
              case 1: 
                    login();
                    break;
              case 2: 
                    printf("\nTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        break;
      }

  }
  void login()
    {
      FILE *fp;
      char c,name[30],pass[30]; int i,z=0,y;
      int checku,checkp;
      fp=fopen("Web_reg.txt","rb");
      for(i=0;i<1000;i++)
      {
        printf("\nENTER USERNAME: ");
        scanf("%s",name);
        printf("\nENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&s[i],sizeof(s[i]),1,fp);
          checku=strcmp(name,s[i].name);
          checkp=strcmp(pass,s[i].pass);
          if(checku==0&&checkp==0)
          {

            printf("\nYOU HAVE LOGGED IN SUCCESSFULLY!!");
            
            break;
          }
        if(checku==0&&checkp!=0)
          {
            printf("\nWRONG PASSWORD!! Not %s??",name);
            printf("\n(Press 'Y' to re-login)");
            scanf("%s",&y);
            if(y=='y'||y=='Y')
              login();
          }
        if(checku!=0)
          {
            printf("\nYou are not a Registered User\n Press enter to register yourself");
            reg();
          }
        }
        break;
      }
    }
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
    
 printf("\nEnter the phone number");
 scanf("%d",&s[i].phno);
 printf("\n Enter the address");
 scanf("%s",&s[i].address);
 printf("\nYour ticket is confirmed");
 
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
void main(){
	int n;
	printf("***********************************************************");
	printf("\n         Welcome to Apoorva's Railway Network              ");
	printf("\n***********************************************************");
	printf("\n1. LOGIN \n2. REGISTER");
scanf("%d",&n);
switch(n)
  {
    case 1: 
	       login();
        break;
    case 2: 
        reg();
        break;
    default: printf("\nNO MATCH FOUND");
        printf("\nPress Enter to re-Enter the choice");
        
  }
	
 menu();
}

