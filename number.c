#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>


void decTobin(int);
void binTodec(char[]);
void decTooct(int);
void octTodec(char[]);
void decTohex(int);
void hexTodec(char[]);


void decTobin(int number)
{
    int     cnt,i;
    int     bin[32];
    cnt=0;             				 /*initialize index to zero*/
    while(number>0)
    {
        bin[cnt]=number%2;
        number=number/2;
        cnt++;
    }					 /*print value in reverse order*/
    printf("Binary value is: ");
    for(i=(cnt-1); i>=0;i--)
    printf("%d",bin[i]);
}
void decTooct(int number)
{
    int     cnt,i;
    int     oct[32];
    cnt=0;            			  /*initialize index to zero*/
    while(number>0)
    {
        oct[cnt]=number%8;
        number=number/8;
        cnt++;
    }
/*print value in reverse order*/
    printf("Octal value is: ");
    for(i=(cnt-1); i>=0;i--)
        printf("%d",oct[i]);
 }
void decTohex(int number)
{
    int cnt,i;
    char    hex[32];   			 /*as it contains characters A to F*/
    cnt=0;             					 /*initialize index to zero*/
    while(number>0)
    {
        switch(number%16)
        {
            case 10:
                hex[cnt]='A'; break;
            case 11:
                hex[cnt]='B'; break;
            case 12:
                hex[cnt]='C'; break;
            case 13:
                hex[cnt]='D'; break;
            case 14:
                hex[cnt]='E'; break;
            case 15:
                hex[cnt]='F'; break;
            default:
                hex[cnt]=(number%16)+0x30;  /*converted into char value*/
        }
        number=number/16;
        cnt++;
    }							/*print value in reverse order*/
    printf("Hexadecimal value is: ");
    for(i=(cnt-1); i>=0;i--)
        printf("%c",hex[i]);
 }
void binTodec(char bin[])
{
    int  dec,i;
    int  cnt;   					/*for power index*/
    cnt=0;
    dec=0;
    for(i=(strlen(bin)-1);i>=0;i--)
    {
        dec=dec+(bin[i]-0x30)*pow((double)2,(double)cnt);
        cnt++;
    }
    printf("DECIMAL value is: %d",dec);
}
void octTodec(char oct[])
{
    int  dec,i;
    int  cnt;   					/*for power index*/
    cnt=0;
    dec=0;
    for(i=(strlen(oct)-1);i>=0;i--)
    {
        dec= dec+ (oct[i]-0x30)*pow((double)8,(double)cnt);
        cnt++;
    }
    printf("DECIMAL value is: %d",dec);
}
void hexTodec(char hex[])
{
    int  dec,i;
    int  cnt;   						/*for power index*/
    int  dig;  							 /*to store digit*/

    cnt=0;
    dec=0;
    for(i=(strlen(hex)-1);i>=0;i--)
    {
        switch(hex[i])
        {
            case 'A':
                dig=10;
                break;
            case 'B':
               	 dig=11;
                break;
            case 'C':
                dig=12;
                break;
            case 'D':
                dig=13;
                break;
            case 'E':
                dig=14;
                break;
            case 'F':
                dig=15;
                break;
            default:
               	 dig=hex[i]-0x30;
        }
        dec= dec+ (dig)*pow((double)16,(double)cnt);
        cnt++;
    }
    printf("DECIMAL value is: %d",dec);
}
int main()
{
    int choice,number;
    char oct[30],bin[30],hex[30];
    do
    {
         printf("\nEnter choice : \n1- Decimal To Binary\n2- Decimal To Octal\n3- Decimal To Hexadecimal\n4- Binary To Decimal\n5- Octal To Decimal\n6- Hexadecimal To Decimal\n7- Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:
                printf("Enter decimal number: \n");
                scanf("%d",&number);
                decTobin(number);
                break;
            case 2:
                printf("Enter decimal number: \n");
                scanf("%d",&number);
                decTooct(number);
                break;
            case 3:
                printf("Enter decimal number: \n");
                scanf("%d",&number);
                decTohex(number);
                break;
            case 4:
                printf("Enter binary value: ");
                scanf(" %[^\n]",bin);
                binTodec(bin);
                break;
            case 5:
                printf("Enter octal value: ");
                scanf(" %[^\n]",oct);
                octTodec(oct);
                break;
            case 6:
                printf("Enter hex value: ");
                scanf(" %[^\n]",hex);
                hexTodec(hex);
                break;
            case 7:
                break;
          	default:
            		printf("\n INVALID CHOICE ! ");
            }
   }while(choice!=7);
   return 0;
}
