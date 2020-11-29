#include <stdio.h>
#include "myBank.h"
#define  R 50
#define  C 3

double accounts [R][C] ={0};
char letter;
double  dep, getAccountNum, accountNumber, amount, interes;
int accoutNum = 901;


//initial array to 0 
void initial(){
	for(int i=0; i < R; i++){
		accounts[i][0]=0;//closed or opened - first initiation to close
		accounts[i][1]=accoutNum;//the account number
		accounts[i][2]=0;//remained cash
		accoutNum++;
	}
}	



double openAccount(double amount){
	getAccountNum = -1;
	for (int i = 0; i < R; ++i){
			if(accounts[i][0] == 0){
				getAccountNum = accounts[i][1];
				accounts[i][2] = amount;
				accounts[i][0] = 1;
				break;
			}
		}
		return getAccountNum;
	}

double accountRemain(double accountNumber){
	if(accounts[(int)accountNumber-901][0] == 0){
		return -1;
	}
	return accounts[(int)accountNumber-901][2];
}

double deposit (double amount, double accountNumber){
	if(accounts[(int)accountNumber-901][0] == 0){
		return -1;
		}
	accounts[(int)accountNumber-901][2] += amount;	
	return accounts[(int)accountNumber-901][2];	
}

double withdraw(double amount, double accountNumber){
	if(accounts[(int)accountNumber-901][0] == 0){
		return -1;
		}
	if(accounts[(int)accountNumber-901][2] < amount){
		return -2;
	}

	accounts[(int)accountNumber-901][2] -= amount;
	return accounts[(int)accountNumber-901][2];
}

double closeAccount(double accountNumber){
	if(accounts[(int)accountNumber-901][0]==0){
		return -1;
		}
	accounts[(int)accountNumber-901][2] = 0;
	accounts[(int)accountNumber-901][0] = 0;
	return 0;	
}

void interest (double interes){
	for (int i = 0; i < R; ++i){
		if(accounts[i][0] != 0){//only if the account is opened
			accounts[i][2] *= (100+interes)/100;
		}
	}
}

void printAll(){
	for (int i = 0; i < R; ++i){
			if(accounts[i][0] != 0){
				printf("Account number: %.0lf, Account remain: %.2lf", accounts[i][1], accounts[i][2]);
				printf("\n" );
			}
		}
}

void closeAll(){
	for(int i = 0; i<R; i++){
			if(accounts[i][0] != 0){
				accounts[i][0] = 0;
				accounts[i][2] = 0;
			}
		}
}
