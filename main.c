#include <stadio.h>
#include "myBank.h"
#define  R 50
#define  C 3




int main{


	char letter;
	double  dep;
	int accouts[R][C];
	int accoutNum=901;



// initial array to 0 

	for( int i=0; i<R; i++){
		accouts[i][0]=0;//closed or opened - first initiation to close
		accouts[i][1]=accoutNum;//the account number
		accouts[i][2]=0;//remained cash
		accoutNum++;

	}



	printf("Transaction type?:");
	scanf("%c",&letter);
	printf("\n");
	while(letter=='O' || letter=='B' || letter=='D' || letter=='W' || letter=='C' || letter=='I' ||letter=='P' || letter=='E'){
	switch (letter){
		case 'O':
		int getAccountNum=0;

		printf("Initial deposit?:");
		scanf("%lf", &dep);

		getAccountNum= openAccount(accouts);
		if( getAccountNum== -1){
			printf("No account available!\n");
			break;
		}

		if(dep<0){
			printf("Deposit can not be negetive!");
		}

		else{
			accouts[getAccountNum-901][2]=dep;
		}
		return getAccountNum;
		break;


		case 'B':
		double accountNumber;
		printf("Account number?:");
		scanf("%lf", &accountNumber);
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Account number must be between 901 - 950!");
			break;
		}
		else{
			if(accouts[accountNumber-901][0] == 0){
				printf("The given account is closed!");
				break;
			}
			printf("%lf", accouts[accountNumber-901][2]);
			break;
		}

		case 'D':
		double accountNumber, amount;
		printf("Account number?");
		scanf("%lf", &accountNumber);
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Account number must be between 901 - 950!");
			break;
		}
		else{
			if(accouts[accountNumber-901][0] == 0){
				printf("The given account is closed!");
				break;
			}
			printf("Amount?:");
			scanf("%lf", &amount);

			if(amount<0){
				printf("Cann't deposit a negative amount of money!" );
				break;
			}
			accouts[accountNumber-901][2] += amount;

			printf("%lf",accouts[accountNumber-901][2]);
			break;

		case 'W':
		double accountNumber, amount;
		printf("Account number?");
		scanf("%lf", &accountNumber);
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Account number must be between 901 - 950!");
			break;
		}
		else{
			if(accouts[accountNumber-901][0] == 0){
				printf("The given account is closed!");
				break;
			}
			printf("Amount?:");
			scanf("%lf", &amount);

			if(amount>accouts[accountNumber-901][2]){
				printf("Not enough money at the account!");
				break;
			}

			accouts[accountNumber-901][3]-= amount;
			printf("%lf",accouts[accountNumber-901][2]);
			break;
			


		case 'C':
		double accountNumber;
		printf("Account number?");
		scanf("%lf", &accountNumber);
		
		if(accountNumber < 901 || accountNumber >950){
			printf("Account number must be between 901 - 950!");
			break;
		}

		if(accouts[accountNumber-901][0]==0){
			printf("The account is already closed!");
			break;
		}

		accounts[accountNumber-901][0] = 0;
		accounts[accountNumber-901][2] = 0;
		break;

		case 'I':
		double positive_interest;
		printf("Interest rate?:");
		scanf("%lf", &positive_interest);

		if(interest < 0 ){
			printf("Interest cann't be negative!");
			break;
		}

		interest(accounts, positive_interest);
		break;

		case 'P':
		for (int i = 0; i < R; ++i)
		{
			if(accounts[i][0] != 0){
				printf("Account number: %d, Account remain: %lf", accounts[i][1], accounts[i][2]);
				printf("\n" );
			}
		}
		break;

		case 'E':
		for(int i = 0; i<R; i++){
			if(accounts[i][0] != 0){
				accounts[i][0] = 0;
				accounts[i][2] = 0;
			}
			break;
		}
		default:
	}








	}
}
