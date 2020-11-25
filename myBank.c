#include <stadio.h>
#include "myBank.h"

#define  R 50
#define  C 3

int openAccount(double arr[][]){
	int ans=-1;

	for (int i = 0; i < R; ++i){
		for(int j=0; j<C; j++){
			if(arr[i][j]==0){
				ans=arr[i][1];// get num of the available account
				break;
			}
		}
	}
	return ans;
	
}

//void closeAccount(double arr[][]);

//void accountRemain(double arr[][]);

//void deposit (double arr[][]);

//void withdraw(double arr[][]);

void interest (double arr[][], double interest){
	for (int i = 0; i < R; ++i){
		if(arr[i][0] != 0){//only if the account is opened
			arr[i][3] *= (100+interest)/100;
		}
	}
}
