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
			}
		}
	}
	return ans;
	
}

void closeAccount(double arr[][]);

void accountRemain(double arr[][]);

void deposit (double arr[][]);

void withdraw(double arr[][]);

void interest (double arr[][]);