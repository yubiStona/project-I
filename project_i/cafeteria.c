#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>

void generatebills();
void viewbills();
void editbills();
void deletebills();

// THIS STUCTURE IS FOR MULTIPLE ITEMS

struct items
{
	char items[50];
	int price;
	int quantity;
	// float total;
};

// creating structure for storing details:
struct details
{

	char name[50];

	char address[50];

	char contact[50];
	int numofitems;
	char time[50];
	struct items itm[50];
};

// MAIN FUNCTIION IS DEFINED AS BELOW:
void main()
{
	// THIS IS LOGIN PART OF PROGRAM:

	char username[50];
	char password[50];

	char defpassword[50] = "passport";
	char ask[50];

login:
	system("cls");

	printf("\t\t\t       _______________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t\t  cafeteria invoice management system\n");

	printf("\n\t\t\t       _______________________________________________________________________________\n");

	printf("\n\n\t\t\t\t\t\t    Please enter username and password to login: \n\n");

	printf("\t\t\t               \t\t-------------------------------------------------\n");
	fflush(stdin);

	printf("\n\t\t\t\t\t\t    please  Enter your username     :  ");
	fgets(username,50,stdin);
	// scanf("%s", &username);
	username[strlen(username)-1]=0;

	/* By default fgets takes next line value and after we print data taken in by fgets,
	 there will be akward next linee which ruins design so above technique is used to avoid it by reducing one character at end*/

	
	

	printf("\t\t\t               \t\t-------------------------------------------------\n");

repeat:
	printf("\n\t\t\t\t\t\t    please  Enter your password     :  ");
	fgets(password,50,stdin);
	password[strlen(password)-1]=0;
	// scanf("%s", &password);


	if (strcmp(password, defpassword) == 0)
	{
	menu:

		system("cls");
		
		printf("\t\t\t       _______________________________________________________________________________\n");
		printf("\n\t\t\t\t\t\t\t  cafeteria invoice management system\n");

		printf("\n\t\t\t\t\t\t\t\twelcome  %s", username);
		printf("\n\t\t\t       _______________________________________________________________________________\n");

		printf("\n\n\n\t\t\t\t\t\t   please select desired operation from below ");

		printf("\n\n\n\t\t\t\t\t\t\t   1. Generate bills/invoices ");
		printf("\n\n\n\t\t\t\t\t\t\t   2. View bills/invoices ");
		printf("\n\n\n\t\t\t\t\t\t\t   3. modify bills/invoices ");
		printf("\n\n\n\t\t\t\t\t\t\t   4. Delete bills/invoices ");
		printf("\n\n\n\t\t\t\t\t\t\t   5. About system");
		printf("\n\n\n\t\t\t\t\t\t\t   6. logout from system ");

		printf("\n\n\n\t\t\t\t\t\tplease Enter an option you want to perforfm  :\t");

		fflush(stdin);

		char option;
		scanf("%c", &option);

		switch (option)
		{
			// FIRST CASE IS TO SELECT OPTION FOR  GENERATING BILLS:

		case '1':
			// system("color 07");
			generatebills();

			// GOTO MENU1 : WILL REDIRECT USER TO MAIN MENU,IF HE PRESS OTHER THEN DEFINED KEY TO REPEAT TASK:

			goto menu;
			break;

			// THIS CASE IS TO VIEW BILLS FROM MAIN MENU:

		case '2':
			// system("color B0");
			viewbills();

			// GOTO MENU2 : USER CAN GO BACK TO MAIN MENU AFTER VIEWING THE BILLS:
			goto menu;
			break;

		case '3':
			editbills();

			goto menu;

			break;

		case '4':
			deletebills();
			goto menu;
			break;

			// IF USER WILL Enter ANY NON DEFINED VALU FOR  CASE,  HE WILL BE REDIRECTED TO MAIN MENU WITH SUGGESTION:

		case '5':
			system("cls");

			printf("\t\t\t       _______________________________________________________________________________\n");
			printf("\n\t\t\t\t\t\t\t  cafeteria invoice management system\n");

			printf("\n\t\t\t\t\t\t\t\tAbout System");
			printf("\n\t\t\t       _______________________________________________________________________________\n");

			printf("\n\n\t\t\t\t\t       This is demo of cafeteria invoice management system,\n\n \t\t\t\t\t       which have been designed using various reference\n");
			printf("\n\t\t\t\t\t\t\t      project Members  \n");
			printf("\n\t\t\t\t\t\t\t      1. Ankit Belal  \n");
			printf("\n\t\t\t\t\t\t\t      1. Yubraj Dhungana  \n");
			printf("\n\t\t\t\t\t\t\t      1. Dinesh Nath  \n");
			printf("\n\n\t\t\t\t\t\t\tsSubmitted to: ER-Pusp Raj Joshi  \n");

			printf("\n\n\n\t\t\t \t\t       Press any key to go to main menu  :    ");
			char ask1;

			scanf("%s", &ask1);
			goto menu;
			break;

		case '6':
			system("cls");

			printf("\t\t\t       _______________________________________________________________________________\n");
			printf("\n\t\t\t\t\t\t\t  cafeteria invoice management system\n");

			printf("\n\t\t\t\t\t\t\t\twelcome  %s", username);
			printf("\n\t\t\t       _______________________________________________________________________________\n");

			printf("\n\n\t\t\t\t\t\t\t  Are you sure to logout ?\t");
			scanf("%s", ask);

			if (strcmp(ask, "Y") == 0 || strcmp(ask, "y") == 0)
			{
				goto login;
			}
			else
			{
				goto menu;
			}
			break;

		default:
			system("cls");
			printf("\t\t\t       _______________________________________________________________________________\n");
			printf("\n\t\t\t\t\t\t\t  cafeteria invoice management system\n");

			printf("\n\t\t\t       _______________________________________________________________________________\n");

			printf("\n\n\t\t\t\t\t\t\t     Please Enter valid option\n\n ");
			printf("\t\t\t\t\t\t\t    ");
			system("pause");
			// program  wait for terminate until any key is pressed.
			goto menu;
			break;
		}

		// END OF SWITCH CASE
	}

	// BELOW PART IS TO SUGGEST USER TO REEnter PASSWORD IF THE Enter WORNG ONE:

	else

	{
		system("cls");

		printf("\t\t\t       _______________________________________________________________________________\n");
		printf("\n\t\t\t\t\t\t\t  cafeteria invoice management system\n");

		printf("\n\t\t\t\t\t\t\t\t welcome mr.%s", username);
		printf("\n\t\t\t       _______________________________________________________________________________\n");
		printf("\n\n\t\t\t\t\t\t     sorry you have Entered wrong password\n");
		printf("\n\n\t\t\t\t\t\t\t   please Enter correct one\n");

		// GOTO REPEAT: WILL REDIRECT TO LOGIN PAGE UNTIL HE Enter WORNG PASSWORD WITH SUGGESTION:

		goto repeat;
	}
	// END OF ELSE STATEMENT OF LOGIN PART:
}
// END OF  MAIN FUUNCTION:

// DIFINITION OF FUNCTION TO GENERATE BILSS:

void generatebills()
{
	int i;
	system("cls");
	printf("\t\t\t   _______________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t       generating bills/invoice\n");
	printf("\t\t\t   _______________________________________________________________________________\n");

	char ask[9];
	do
	{
		FILE *fp;
		fp = fopen("cafeteria.dat", "ab+");
		struct details customer;

		strcpy(customer.time, __DATE__);

		fflush(stdin);
		printf("\n\t\t\t\t\t\t  Enter customer name      :\t");
		fgets(customer.name,50,stdin);
		customer.name[strlen(customer.name)-1]=0;
		// scanf("%s", &customer.name);

		printf("\n\t\t\t\t\t\t  Enter an address         :\t");
		fgets(customer.address,50,stdin);
		customer.address[strlen(customer.address)-1]=0;

		//scanf("%s", &customer.address);

		printf("\n\t\t\t\t\t\t  Enter  contact no        :\t");
		fgets(customer.contact,50,stdin);
		customer.contact[strlen(customer.contact)-1]=0;
		// scanf("%d", &customer.contact);

		fflush(stdin);

		printf("\n\t\t\t\t\t\t  Enter number of item     :\t");
		scanf("%d", &customer.numofitems);
		printf("\t\t\t      \t\t------------------------------------------------------\n");
		for (i = 0; i < customer.numofitems; i++)
		{
			fflush(stdin);

			printf("\n\t\t\t\t\t\t  Enter an item[%d]         :    ", i + 1);
			fgets(customer.itm[i].items,50,stdin);
			customer.itm[i].items[strlen(customer.itm[i].items)-1]=0;
			
			//scanf("%s", &customer.itm[i].items);
		
			fflush(stdin);
			printf("\n\t\t\t\t\t\t  Enter price              :    Rs ");
			scanf("%d", &customer.itm[i].price);

			printf("\n\t\t\t\t\t\t  Enter quantity           :    ");
			scanf("%d", &customer.itm[i].quantity);
			printf("\t\t\t \t\t------------------------------------------------------\n");
		}

		fwrite(&customer, sizeof(struct details), 1, fp);
		fclose(fp);

		if (fp == NULL)
		{
			printf("\n\t\t\t\t\t\t can't save file");
		}
		else
		{
			printf("\n\n\n\t\t\t\t\t\t       file saved successfully\n\n");
		}

		printf("\n\t\t\t\t\t      Do you want to generate bills again [Y/N]:\t ");
		scanf("%s", &ask);
		fflush(stdin);

		system("cls");
		printf("\t\t\t   _______________________________________________________________________________\n");
		printf("\n\t\t\t\t\t\t       generating new bills/invoice\n");
		printf("\t\t\t   _______________________________________________________________________________\n");

	} while (strcmp(ask, "y") == 0 || strcmp(ask, "Y") == 0|| strcmp(ask, "Yes") == 0|| strcmp(ask, "yes") == 0);
}

// this part is for function to view the record:
void viewbills()

{
	system("cls");
	printf("\t\t\t   _______________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t          viewing bills/invoice\n");
	printf("\t\t\t   _______________________________________________________________________________\n");

	FILE *fp;

	struct details customer;
	int i;
	float total;
	fp = fopen("cafeteria.dat", "rb+");

	if (fp != NULL)
	{
		while (fread(&customer, sizeof(struct details), 1, fp) == 1)
		{
			printf("\n\n\t\t\t\t       %s", customer.time);
			printf("\n\n\t\t\t\t\t\t          Invoice to : %s", customer.name);
			printf("\n\t \t\t\t      __________________________________________________________\n");
			printf("\n\n\t\t\t\t\t\t     Name            :       %s", customer.name);

			printf("\n\n\t\t\t\t\t\t     Address         :       %s", customer.address);

			printf("\n\n\t\t\t\t\t\t     contact         :       %s", customer.contact);
			printf("\n\t\t\t\t\t--------------------------------------------------------\n");
			total = 0;

			for (i = 0; i < customer.numofitems; i++)
			{
				printf("\n\n\t\t\t\t\t\t     Item name[%d]    :       %s", i + 1, customer.itm[i].items);

				printf("\n\n\t\t\t\t\t\t     Price           :       Rs.%d", customer.itm[i].price);

				printf("\n\n\t\t\t\t\t\t     Quantity        :       %d", customer.itm[i].quantity);

				total += customer.itm[i].price * customer.itm[i].quantity;
				printf("\n\t\t\t\t\t-------------------------------------------------------\n");
			}

			printf("\n\t \t\t\t      __________________________________________________________\n");

			printf("\n\t\t\t\t\t\t     Total           :    Rs %f", total);
			printf("\n\t \t\t\t      __________________________________________________________");
			printf("\n\n\n");
		}
		printf("\n\t\t\t \t\t       Enter any key to go to main menu  :    ");
		getch();
	}
	else
	{
		printf("\n\n\n\t\t\t\t\t\t          sorry, No file present\n");
		printf("\n\t\t\t\t\t\t  Enter any key to go to main menu :\t");
		
		getch();
	}

	fclose(fp);
	system("cls");
}

// This part is for function to edit bills.

void editbills()

{
	char ask2[20];
	int i;
	do
	{
		system("cls");

		printf("\t\t\t   _______________________________________________________________________________\n");
		printf("\n\t\t\t\t\t\t       Modifying bills/invoice\n");
		printf("\t\t\t   _______________________________________________________________________________\n");

		char cname[50];
		char confirm[50];
		
		float total;
		struct details customer;
		long int size = sizeof(struct details);

		FILE *fp;
		fp = fopen("cafeteria.dat", "rb+");

		if (fp != NULL)
		{
			fflush(stdin);
			printf("\n\t\t\t\t\t\tEnter customer name  : \t");
			fgets(cname,50,stdin);
			cname[strlen(cname)-1]=0;

			

			rewind(fp);

			while (fread(&customer, sizeof(struct details), 1, fp) == 1)
			{
				if (strcmp(customer.name, cname) == 0 )
				{

					// this part is for viewing detail for editing/modifying
					printf("\n\n\t\t\t\t     %s", customer.time);
					printf("\n\n\n\t\t\t\t\t\t          Invoice to : %s", customer.name);
					printf("\n\t \t\t\t      __________________________________________________________\n");
					printf("\n\t\t\t\t\t\t     Name            :       %s", customer.name);

					printf("\n\n\t\t\t\t\t\t     Address         :       %s", customer.address);

					printf("\n\n\t\t\t\t\t\t     contact         :       %s", customer.contact);
					printf("\n\t\t\t\t\t--------------------------------------------------------\n");

					total = 0;
					for (i = 0; i < customer.numofitems; i++)
					{

						printf("\n\n\t\t\t\t\t\t     Item name [%d]   :       %s", i + 1, customer.itm[i].items);

						printf("\n\n\t\t\t\t\t\t     Price           :       Rs.%d", customer.itm[i].price);

						printf("\n\n\t\t\t\t\t\t     Quantity        :       %d", customer.itm[i].quantity);
						printf("\n\t\t\t\t\t--------------------------------------------------------\n");
						total += customer.itm[i].price * customer.itm[i].quantity;
					}

					printf("\n\t \t\t\t      __________________________________________________________\n");

					printf("\n\t\t\t\t\t\t     Total           :    Rs %f", total);
					printf("\n\t \t\t\t      __________________________________________________________\n\n");

					// editing part
					fflush(stdin);
					printf("\n\t\t\t\t\t\tIs this bill, that you want to edit?[Y/N] : ");
					scanf("%s",confirm);
					fflush(stdin);
					printf("\n\t\t\t\t\t-------------------------------------------------------\n");
					if(strcmp(confirm,"Y")==0 || strcmp(confirm,"y")==0 || strcmp(confirm,"Yes")==0 || strcmp(confirm,"yes")==0 )
					{
						printf("\n\t\t\t\t\t\t  Enter name               :\t");
						fgets(customer.name,50,stdin);
							customer.name[strlen(customer.name)-1]=0;
						// scanf("%s", &customer.name);

						printf("\n\t\t\t\t\t\t  Enter an address         :\t");
						fgets(customer.address,50,stdin);
						customer.address[strlen(customer.address)-1]=0;

						//scanf("%s", &customer.address);

						printf("\n\t\t\t\t\t\t  Enter  contact no        :\t");
						fgets(customer.contact,50,stdin);
						customer.contact[strlen(customer.contact)-1]=0;
						// scanf("%d", &customer.contact);

						fflush(stdin);

						printf("\n\t\t\t\t\t\t  Enter number of item     :\t");
						scanf("%d", &customer.numofitems);
						printf("\t\t\t      \t\t------------------------------------------------------\n");

						for (i = 0; i < customer.numofitems; i++)
						{
							fflush(stdin);

							printf("\n\t\t\t\t\t\t  Enter an item[%d]         :    ", i + 1);
							fgets(customer.itm[i].items,50,stdin);
							customer.itm[i].items[strlen(customer.itm[i].items)-1]=0;
					
							//scanf("%s", &customer.itm[i].items);
				
							fflush(stdin);
							printf("\n\t\t\t\t\t\t  Enter price              :    Rs ");
							scanf("%d", &customer.itm[i].price);

							printf("\n\t\t\t\t\t\t  Enter quantity           :    ");
							scanf("%d", &customer.itm[i].quantity);
							printf("\t\t\t \t\t------------------------------------------------------\n");

						}

						fseek(fp, -size, SEEK_CUR);
						fwrite(&customer, size, 1, fp);
						goto close;
						//jump to close file
					
					}
					else
					{
						goto close;
					}
				}
				
				// else{
				// 	printf("\n\n\t\t\t\t\t\t  Sorry, No record found to this name\n");
				// 	fclose(fp);
				// 	goto exit;
				// }
			}
			printf("\n\n\n\t\t\t\t\t\t       sorry, No Record found\n");
			

			// PROGRAM WILL EXIT WHEN THERE IS MO FILE SAVED
			close:
			fclose(fp);
			 
			printf("\n\t\t\t\t\t    Do you want to continue modifying bills agan [Y/N] ?\t ");
			printf("\n\n\t\t\t\t\t       Press [Y] to continue and other for main menu:  ");
			scanf("%s", &ask2);
			fflush(stdin);
		}

		else

		{
			
			printf("\n\n\n\t\t\t\t\t\t       sorry, No any file present\n");
			exit:
			printf("\n\t\t\t\t\t\t  Press any key to go to main menu :\t");
			
			
			getch();
			break;
			// char exit[20];
			// scanf("%s",exit);
		}

	} while (strcmp(ask2, "Y") == 0 || strcmp(ask2, "y") == 0|| strcmp(ask2, "yes") == 0 || strcmp(ask2, "Yes") == 0);
}

// THIS IS DEFINITION OF FUNCTION TO DELETEBCUSTOMER DETAILS

void deletebills()

{
	char askey[20];
	do
	{
		// again:
		system("cls");

		printf("\t\t\t   _______________________________________________________________________________\n");
		printf("\n\t\t\t\t\t\t       Deleting  bills/invoice\n");
		printf("\t\t\t   _______________________________________________________________________________\n");

		int f=0;
		int i;
		float total;
		char cname[50];
		
		char ask[10];

		struct details customer;
		long int size = sizeof(struct details);
		FILE *fp1;
		FILE *fp2;

		fp1 = fopen("cafeteria.dat", "rb");
		fp2 = fopen("fakecafe.dat", "wb");
		fflush(stdin);
		printf("\n\t\t\t\t\t\t  Enter costumer name     :\t");

		fgets(cname,50,stdin);
		cname[strlen(cname)-1]=0;
	

		if (fp1 != NULL)
		{
			while (fread(&customer, sizeof(struct details), 1, fp1) == 1)
			{
				
				if (strcmp(cname, customer.name) == 0)
				{
					f = 1;
					printf("\n\n\t\t\t\t     %s", customer.time);
					printf("\n\n\t\t\t\t\t\t          Invoice to : %s", customer.name);
					printf("\n\t \t\t\t      __________________________________________________________\n");
					printf("\n\n\t\t\t\t\t\t     Name           :       %s", customer.name);

					printf("\n\n\t\t\t\t\t\t     Address        :       %s", customer.address);

					printf("\n\n\t\t\t\t\t\t     contact        :       %s", customer.contact);
					printf("\n\t\t\t\t\t--------------------------------------------------------\n");

					total = 0;
					for (i = 0; i < customer.numofitems; i++)
					{

						printf("\n\n\t\t\t\t\t\t     Item name [%d]  :       %s", i + 1, customer.itm[i].items);

						printf("\n\n\t\t\t\t\t\t     Price          :       Rs.%d", customer.itm[i].price);

						printf("\n\n\t\t\t\t\t\t     Quantity       :       %d", customer.itm[i].quantity);
						printf("\n\t\t\t\t\t--------------------------------------------------------\n");
						total += customer.itm[i].price * customer.itm[i].quantity;
					}

					printf("\n\t \t\t\t      __________________________________________________________\n");

					printf("\n\t\t\t\t\t\t     Total          :    Rs %f", total);
					printf("\n\t \t\t\t      __________________________________________________________\n\n");
					break;
				}
				else
				{
					fwrite(&customer, sizeof(struct details), 1, fp2);
					
				}
			}

			if (f == 1)

			{
				printf("\n\n\t\t\t\t\t\t Are you sure to delete this bill?[Y/N]:  ");
				scanf("%s", &ask);
				fflush(stdin);

				if (strcmp(ask, "Y") == 0 || strcmp(ask, "y") == 0|| strcmp(ask, "yes") == 0|| strcmp(ask, "Yes") == 0)
				{

					goto delete;
				}

				else
				{

					goto exit;
				}
			}

			else
			{
				printf("\n\n\n\t\t\t\t\t\t  sorry, There is no file to this name\n");
				
				goto exit;
			}

			delete : 
			fclose(fp1);
			fclose(fp2);
			remove("cafeteria.dat");
			rename("fakecafe.dat", "cafeteria.dat");

			printf("\n\n\t\t\t\t\t\t       Bills deleted succesfully\n");
		}
		else
		{
			
			printf("\n\n\t\t\t\t\t\t       Sorry, no record found \n");
		}

	exit:
		printf("\n\t\t\t\t\t\t   do you want to continue [Y/N]:\t");
		fclose(fp1);
		fclose(fp2);

		// printf("\n\t\t\t\t\t\t   Else press any key to go to main menu:\t");
		// getch();
		scanf("%s", askey);
		// while(strcmp(ask,"Y")==0 && strcmp(ask,"y")==0)
		// {
		// 	goto again;
		// 	}

	} while (strcmp(askey, "Y") == 0 || strcmp(askey, "y") == 0|| strcmp(askey, "yes") == 0|| strcmp(askey, "Yes") == 0);
}
