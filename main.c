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
		accouts[i][0]=0;
		accouts[i][1]=accoutNum;
		accouts[i][2]=0;
		accoutNum++;

	}



	printf("Transaction type?:");
	scanf("%c",&letter);
	printf("\n");

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

		case 'D':

		case 'W':

		case 'C':

		case 'I':

		case 'P':

		case 'E':

		default:









	}
}