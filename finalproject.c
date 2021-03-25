#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

// fuction for string encryption and decryption using caesar cipher
void enc_str()
{
   int i;
   char str[100];

   printf("\nPlease enter a string(<100) to be encrypted:");
   fflush(stdin);
   gets(str);
   
   for(i = 0; (i < 100 && str[i] != '\0'); i++)
   {     
   		str[i] = str[i] + 5; //the key for encryption is 5 that is added to ASCII value
   }
   printf("\nENCRYPTED STRING: %s\n", str);
   for( i = 0; (i < 100 && str[i] != '\0'); i++)
   {    
		str[i] = str[i] - 5; //the key for decryption is 5 that is subtracted from ASCII value
   } 
   printf("\nDECRYPTED STRING: %s\n", str);
   printf("\n\n    PRESS ANY KEY TO GO BACK TO MAIN MENU  \n\n   ");
   getch();
   display();   
}
// function for string encryption and decryption (selfmade method)//
int enc_rev()
{
	char str[100];
	int i;
	int len=0;
	printf("\nEnter the string(<100 ) you want to encrypt:");
	fflush(stdin);
	gets(str);
	len=strlen(str);
	printf("\nlength of entered string is %d",len);
	strrev(str); // reverse the string
	for(i=0;(i<100 && str[i]!='\0');i++)
	{
		str[i]=str[i]+5;   //using 5 as key for encryption
	}
	printf("\nENCRYPTED STRING IS:%s",str);

	for(i=0;(i<100 && str[i]!='\0');i++)
	{
		str[i]=str[i]-5;  // using 5 as key to decrypt
	
	}
	strrev(str); // revresal of string for decryption
	printf("\nDECRYPTED STRING IS :%s",str);
	printf("\n\n    PRESS ANY KEY TO GO BACK TO MAIN MENU  \n\n   ");
   	getch();
   	display();   
}
	
//  function to choose whether to encrypt or decrypt files //
int enc_file()
{
	void encryption();
	void decryption();
	int choice;
	printf("\n\n Press\n");
	printf("1- For file encryption:\n");
	printf("2- For file decryption:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		encryption();
		break;
	case 2:
		decryption();
		break;
	default:
		printf("sorry wrong choice");
	}
	return 0;
}
// function to encrypt the file
void encryption()
{

	char fname[20], ch;
	FILE *fps, *fpt;
	printf("\n******FILE ENCRYPTION******\n\n");
	// file to be encrypted is named project.txt//
	printf("Enter file name (with extension like file.txt) to encrypt : ");
	fflush(stdin);
	gets(fname);
	fps=fopen(fname, "r");
	if(fps==NULL)
	{
		printf("Error in opening file..!!");
		printf("\nPress any key to exit...");
		exit(1);
	}
	fpt=fopen("temp.txt", "w");
	if(fpt==NULL)
	{
		printf("Error in creating temp.txt file..!!");
		fclose(fps);
		printf("\nPress any key to exit...");
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fps);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100; // key used to encrypt the data is 100
			fputc(ch, fpt); // temp.txt file contains encrypted data
		}
	}
	fclose(fps);
	fclose(fpt);
	fps=fopen("temp.txt", "r");
	if(fps==NULL)
	{
		printf("error in opening temp.txt file");
		printf("press any key to exit");
		exit(3);
	}
	fpt=fopen(fname, "w");
	if(fpt==NULL)
	{
		printf("error in opening source file");
		printf("enter any key to exit");
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fps);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch,fpt);
		}
	}
	printf("file encrypted successfully"); // file project.txt too contains the encrypted data now
	fclose(fps);
	fclose(fpt);
	printf("\n\n    PRESS ANY KEY TO GO BACK TO MAIN MENU \n\n   ");
	getch();
	display();
}
// function to decrypt files
void decryption()
{
	char ch, choice, fname[20];
	FILE *fps, *fpt;
	printf("\n*********FILE DECRYPTION*********\n");
	// file name is project.txt which was earlier encrypted
	printf("Enter file name (with extension like file.txt) to be decrypted which you have encrypted earlier  : ");
	fflush(stdin);
	gets(fname);
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file..!!");
		printf("\nPress any key to exit...");
		getch();
		exit(7);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file..!!");
		fclose(fps);
		printf("\nPress any key to exit...");
		getch();
		exit(9);
	}
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-100;
			fputc(ch, fps); // project.txt decrypted
		}
	}
	printf("File %s decrypted successfully..!!",fname);
	printf("\nPress any key to exit...");
	fclose(fps);
	fclose(fpt);
	printf("\n\n    PRESS ANY KEY TO GO BACK TO MAIN MENU \n\n   ");
	getch();
	display();
}

// function for first screen 
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// fuction to display main menu
int display()
{
	int opt;
	printf("\n\n");
	printf("                     MAIN MENU\n                  ");
	printf("      ............................\n          ");
	printf("            ............................\n          ");
	printf("\n\n                Press:\n");
	printf("                1- For string encryption or decryption using caesar cipher\n");
	printf("                2- For string encryption and decryption using selfmade method\n");
	printf("                3- For file encryption or decryption\n");
	printf("                4- To exit: ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			enc_str();
			break;
		case 2:
			enc_rev();
			break;
		case 3:
			enc_file();
			break;
		case 4:
			exit(0);
			break;
		default :
			printf("\nsorry camnot help it,wrong choice");
			break;
	}
	return 0;
}

//main function
int main()
{
	int r,q;
	system("color 3F");
	gotoxy(0,0);
	printf("\n\n****************PROJECT FOR DATA ENCRYPTION AND DECRYPTION******************");
	gotoxy(2,10);
	printf("                          BY: ISHITA \n");
	gotoxy(10,14);
	printf("\n\tLOADING...");
	gotoxy(10,16);
	for(r=1;r<=20;r++)
	{
		for(q=1;q<=100000000;q++);
		printf("%c",177);
	}
	system("cls");
	system("color 3F");
	display();
	return 0;
}
