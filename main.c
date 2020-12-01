#include <stdio.h>
#include "myBank.h"





int main(){
	char letter;
	double mode, accountNumber,  dep, amount, remain, interes, open;

	initial();
	do{
	printf("\n" );
	printf("\n" );
	printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
	scanf(" %c",&letter);

	switch (letter){

		case 'O':
		printf("Please enter amount for deposit: ");
		if(scanf("%lf", &dep) == 0 ){
			printf("Failed to read the amount");
			break;
		}
		
		if(dep < 0){
			printf("Invalid Amount");
			break;
		}

		accountNumber = openAccount(dep);

		if(accountNumber  == -1){
			printf("No room for new account!");
			break;
		}
		else{
			printf("New account number is: %.0lf", accountNumber);
			break;
		}
		
		case 'B':
		printf("Please enter account number: ");
		if(scanf("%lf", &accountNumber) == 0){
			printf("Failed to read the account number");
			break;
		}
		
		 if(accountNumber < 901 || accountNumber >950){
			printf("Invalid account number");
			break;
		}

		open = isOpen(accountNumber);
		if(open == -1){
			printf("This account is closed");
			break;
		}
	
		amount = accountRemain(accountNumber);
		printf("The balance of account number %.0lf is: %.2lf", accountNumber, amount);
		break;
		
		case 'D':
		printf("Please enter account number: ");
		if(scanf("%lf", &accountNumber) == 0){
			printf("Failed to read the account number");
			break;
		}

		if(accountNumber <901 || accountNumber >950){
			printf("Invalid account number");
			break;
		}

		open = isOpen(accountNumber);
		if(open == -1 ){
			printf("This account is closed");
			break;
		}

		printf("Please enter the amount to deposit: ");
		if(scanf("%lf", &amount) == 0){
			printf("Failed to read the amount");
			break;
		}

		if(amount<0){
			printf("Cannot deposit a negative amount" );
			break;
			}

		dep = deposit(amount, accountNumber);	

		printf("The new balance is: %.2lf", dep);
		break;
		
		case 'W':
		printf("Please enter account number: ");
		if(scanf("%lf", &accountNumber) == 0){
			printf("Failed to read the account number");
			break;
		}
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Invalid account number");
			break;
		}

		open = isOpen(accountNumber);
		if(open == -1 ){
			printf("This account is closed");
			break;
		}

		printf("Please enter the amount to withdraw: ");
		if(scanf("%lf", &amount) == 0){
			printf("Failed to read the amount");
			break;
		}
		if(amount<0){
			printf("\n");
			printf("Cannot withdraw more than the balance" );
			break;
			}

		remain = withdraw(amount,accountNumber);	
		if(remain == -1){
			printf("This account is closed");
			break;
		}

		if(remain == -2){
			printf("Cannot withdraw more than the balance");
			break;
		}

		printf("The new balance is: %.2lf", remain );
		break;

		case 'C':
		printf("Please enter account number: ");
		if(scanf("%lf", &accountNumber) == 0){
			printf("Failed to read the account number");
			break;
		}
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Invalid account number");
			break;
		}

		open = isOpen(accountNumber);
		if(open == -1){
			printf("This account is closed");
			break;
		}

		mode = closeAccount(accountNumber);
		printf("Closed account number %.0lf",mode );
		break;

		case 'I':
		printf("Please enter interest rate: ");
		if(scanf("%lf", &interes) == 0){
			printf("Failed to read the interest rate");
		}
		

		if(interes<-100){
			printf("Invalid interest rate");
			break;
		}

		interest(interes);
		break;

		case 'P':
		printAll();
		break;

		case 'E':
			closeAll();	
			return 0;
		

		default:
		printf("Invalid transaction type");
		break;
		printf("\n");
	}
			

}while(letter!='E');

}



	
