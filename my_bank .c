#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account
{
  int acc;//to store the account no.
  char fname[100];//to store the first name of the customer
  char lname[100];//to store the last name
  long int pan;//to store the PAN no. of the customer
  long int aadhar;//to store the aadhar no.
  long int phone;//to store the phone no.
  char email[50];//to store the email id
  char district[50];//to store the district 
  long int balance;//to store the balance 

};

void account_info(struct account *);
//case 1: Function to open the account in the bank
int open_account (struct account *a,int i)
{
	char ch;
	int x=0,check=0,check1=0;// variables to check and ask the input again;

	printf("Do you have pan card press: 'Y' for yes, 'N' for no:\t");
	scanf(" %c",&ch);
	
	if(ch=='Y' || ch=='y')//check if the pan card is there or not if pan card is not there then no account is opened
	{
	long int num;
	/*if pan card is there then taking the details of the customer 
	 and then checking if phone no. or rest other details are appropriate or not */
	
	//Name of the Customer ...........................
       	printf("Enter the First name: \t");
	 scanf("%s",(a+i)->fname);
	
	printf("Enter the Last name: \t");
	scanf("%s",(a+i)->lname);
	
	//PAN card no. ........................
	do
	{
		long int num2,remainder,count=0;
		printf ("Enter the 10 digit PAN card no.: \t");
		printf("\tNOTE:- THE PAN CARD NO. SHOULD NOT START WITH '0'\n");
		scanf ("%ld", &num);
		num2=num;
		// To check if the PAN card no. is 10 digits or not ..........
		 while(num2>0)
	         {
	             remainder=num2%10;
	             count++;
        	     num2/=10;
	 	}
		 if(count==10)// if PAN card is 10 digit then store it in pan structure member......
	 	{
	    	  (a+i)->pan = num;
		  x=1;
	 	}
	}while(x!=1);
	// aadhar no. ........................
	do
	{
		long int Aadhar,num3;
		int remainder1,cmt=0;
		printf("Enter the 12 digit aadhar no.: \t");
		printf("\tNOTE:- THE AADHAR CARD NO. SHOULD NOT START WITH '0'\n");
		scanf("%ld",&Aadhar);
		num3=Aadhar;
		// To check if Aadhar card no. is 12 digits or not
		while(Aadhar>0)
		{
			remainder1=Aadhar%10;
			cmt++;
			Aadhar=Aadhar/10;
		}
		if(cmt==12)//to check if the Aadhar card no. is 12 digits or not
		{
			(a+i)->aadhar=num3;
			check=1;
		}
	}
	while(check!=1);
	// phone no. .........................
	do
	{
		long int num1,digit,remain,cnt=0;
		printf("Enter the 10 digit Phone no.:\t");
		printf("\tNOTE:- THE PHONE NO SHOULD NOT START WITH '0'\n");
		scanf("%ld",&num1);
		digit=num1;
		//counting if the phone no. is 10 digit or not;
		while(num1>0)
		{
			remain=num1%10;
			cnt++;
			num1/=10;
		}
		//if phone no. is 10 digits store it in the phone structure member
		if(cnt==10)
		{
		(a+i)->phone=digit;
		check1=1;
		}
	}
	while(check1!=1);

	//Email id .....................................
	printf("enter the Email id:\t");
	scanf("%s",(a+i)->email);

	//District .....................................
	char add[100];
	printf("Enter the district: \t");
	scanf("%s",add);
	strcpy((a+i)->district,add);
	
	//Balance is initiated to 500 
	(a+i)->balance=500;
	return 1;
	}
	else
	{
		printf("\tGet the pan card\n");
		printf("\n");
	return -1;
	}
}

// case 5: printing the details of the specific account 
void account_info(struct account a[10])
{
	int search,i,flag=0;
        printf("Enter the account no.\n");
	scanf("%d",&search);
	for(i=0;i<10;i++)
	{
		if(a[i].acc==search)//to search the account in the array if that account no. is present or not in the bank
		{
		 printf("\n");
        	 printf("details of the customers\n");
       		 printf ("PAN card no.= %ld\nName=%s  %s\nPhone no.= %ld\n Email_id= %s\n ", (a+i)->pan,(a+i)->fname,(a+i)->lname,(a+i)->phone,(a+i)->email);
		 printf("Aadhar no= %ld\n",(a+i)->aadhar);
		 printf("District= %s\n",(a+i)->district);
        	 printf("\n");
		 flag=1;
		}
	}
	if(flag!=1)
	   printf("\tno such account\n");
	printf("\n");
}

//case 2; deposite money in the specific account
void deposit_money(struct account a[10])
{
	int search,i,flag=0,amt;
	printf("\tEnter the account to which money is to be deposited\n");
	scanf("%d",&search);
	for(i=0;i<10;i++)
	{
		if(a[i].acc==search)
		{
			printf("\tEnter the amount to be deposited\n");
			scanf("%d",&amt);
			a[i].balance+=amt;
			printf("\n");
			printf("\tThe new balance is: Rs %ld\n",a[i].balance);
			flag=1;
		}
	}
		if(flag!=1)
		printf("\t No such account\n");
		printf("\n");
}

//case 3: withdraw money from the account
void withdraw_money(struct account a[10])
{
	int search,i,flag=0,amt;
	printf("Enter the account no. \n");
	scanf("%d",&search);
	for(i=0;i<10;i++)
	{
		if(a[i].acc==search)// search the acount from which customer wants to withdraw
		{
			printf("Enter the amount to be withdrawn\n");//taking the amount to be withdrawn
			scanf("%d",&amt);
			if(a[i].balance<amt)
				printf("\tNot sufficient balance\n");
			else
			{
				a[i].balance=a[i].balance-amt;
				printf("The remaining balance is: Rs %ld\n",a[i].balance);
			}
			flag=1;
		}
	}
	if(flag!=1)// if the account is not found
		printf("No such account\n");
}

//case 4: checking the balance of the specific account
void check_balance(struct account a[10])
{
	int search,i,flag=0;
	printf("Enter the Account no.\n ");
	scanf("%d",&search);
	for(i=0;i<10;i++)
	{
		if(a[i].acc==search)
		{
			printf("Your current Account balance is:  Rs %ld\n",a[i].balance);
			flag=1;
		}
	}
	if(flag!=1)
		printf("There is no such account\n");
	printf("\n");
}
//case 6:ordering the card if customer wants
void card_order(struct account a[10])
{
	int search,flag=0,i;
	char ch;
	printf("Enter the Account no.\n");
	scanf("%d",&search);
	for(i=0;i<10;i++)
	{
		if(a[i].acc==search)
		{
		 flag=1;
		 printf("\tDo you want to order ATM card  Press 'Y' to order and 'N' for declining\n");
		 scanf(" %c",&ch);
		 if(ch=='y' || ch=='Y')
			printf("\tYour ATM will be posted to your district's %s post office\n",a[i].district);
		}
	}
	if(flag!=1)
		printf("\tThe Account no. is incorrect\n");
}
//main function : asking for options to the customers
int main ()
{
  int option,cnt=0,x;
  struct account a[10];

  for (;;)// for continuously asking of the options
    {
      printf("Press\n\t1 for open bank account: \n\t2 for deposit money: \n\t3 for withdraw money: \n\t4 for check balance: \n\t5 for Account info:\n\t6 for ordering ATM card\n\t7 for exiting\n");
      scanf ("%d", &option);

      switch (option)
	{
	case 1: if(cnt<10)
		{
			x=open_account (a,cnt);
			if(x==1)
			{
			  a[cnt].acc=100+cnt;
			  printf("\n");
			  printf("\tYour account is opened with Rs500\n");
			  printf("\tYour Account No is %d\n",a[cnt].acc);
			  cnt++;
			  printf("\n");
			}
			else
				printf("\tEnter the details properly\n");
		}
		else
			printf("\tNo more customers today\n");
	 	 break;
	case 2: deposit_money(a);
	   	 break;
	case 3: withdraw_money(a);
		   break;
       	case 4: check_balance(a);
		   break;
	case 5: account_info(a);
		break;
	case 6:card_order(a);
	       break;
	case 7: exit(0);

	default:{
		  printf ("Invalid Option\n");
	 	  exit(0);
		}
	}
    }
  return 0;
}
