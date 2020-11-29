#include <stdio.h>
#include "myBank.h"





int main(){
	char letter;
	double mode, accountNumber,  dep, amount, remain, interes;

	initial();
	do{
	printf("\n");
	printf("Transaction type?: ");
	scanf(" %c",&letter);
	printf("\n");

	switch (letter){

		case 'O':
		printf("Initial deposit?:");
		scanf("%lf", &dep);
		if(dep < 0){
			printf("Deposit cann't be negative!");
			break;
		}

		accountNumber = openAccount(dep);

		if(accountNumber  == -1){
			printf("No room for new account!");
			break;
		}
		else{
			printf("%.0lf", accountNumber);
			break;
		}

		case 'B':
		printf("Account number?:");
		scanf("%lf", &accountNumber);
		printf("\n");
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Account number must be between 901 - 950!\n");
			break;
		}

		amount = accountRemain(accountNumber);

		if(amount == -1){
			printf("Given account number is closed!");
			break;
		}

		printf("%.2lf", amount);
		break;

		case 'D':
		printf("Account number?");
		scanf("%lf", &accountNumber);
		printf("\n");
		
		if(accountNumber <901 || accountNumber >950){
			printf("Account number must be between 901 - 950!\n");
			break;
		}
		printf("Amount?:");
		scanf("%lf", &amount);
		if(amount<0){
			printf("\n");
			printf("Cann't deposit a negative amount of money!\n" );
			break;
			}

		dep = deposit(amount, accountNumber);	
		if(dep == -1){
			printf("Given account number is closed!");
			break;
		}

		printf("%.2lf", dep);
		break;
		
		case 'W':
		printf("Account number?");
		scanf("%lf", &accountNumber);
		printf("\n");
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Account number must be between 901 - 950!\n");
			break;
		}

		printf("Amount?:");
		scanf("%lf", &amount);
		if(amount<0){
			printf("\n");
			printf("Can not withdraw a negative amount of money!\n" );
			break;
			}

		remain = withdraw(amount,accountNumber);	
		if(remain == -1){
			printf("Given account number is closed!");
			break;
		}

		if(remain == -2){
			printf("Not enough money at the account!\n");
			break;
		}

		printf("%.2lf", remain );
		break;

		case 'C':
		printf("Account number?");
		scanf("%lf", &accountNumber);
		printf("\n");
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Account number must be between 901 - 950!");
			break;
		}

		mode = closeAccount(accountNumber);
		if(mode == -1){
			printf("Account is already closed!");
			break;
		}

		break;

		case 'I':
		printf("Interest rate?:");
		scanf("%lf", &interes);
		printf("\n");

		if(interes<-100){
			printf("Interest can not be below -100!");
			break;
		}

		interest(interes);
		break;

		case 'P':
		printAll();
		break;

		case 'E':
			closeAll();
			printf("All the accounts have been closed. bye-bye!\n");		
			return 0;
		

		default:
			printf("Enter a valid character!");
			break;
		}
			

}while(letter!='E');

}



	
