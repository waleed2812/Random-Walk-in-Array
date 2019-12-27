#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {	
	//Clearing Screen
	system("clear");
	int m = 10;
	int n = 10;
	if(argc>1) {
		m = atoi(argv[1]);
		n = atoi(argv[2]);
	}	
	if(m*n < 26){ printf("Not enough space in 2D array\n(m*n) should be greater than 26\n");return 0;}
//	printf("Rows: %d\nColumns: %d\n",m,n);
	//Initializing Array
	char arr[m][n];
	int i = 0,j=0;
	for(i = 0 ; i < m ; i++){
		for(j = 0 ; j < n ; j++){
			arr[i][j] = '.';		
		}	
	
	}
	srand(time(NULL));
	int posm = rand() % m;
	int posn = rand() % n;	
//	printf("Random Pos m: %d\nRandom Pos n: %d\n",posm,posn);
	i = 65;
	int randm = 0;
	int check = 0;
	while(i <= 90){
		if(randm == 0) { //Move UP 	   
			posm += 1;
			if((int)arr[posm][posn] == '.' && posm < m){
				arr[posm][posn] = (char)i;				
				i += 1;
				randm = rand() % 4;
				check = 0;
				continue; 
			}
			posm -= 1;
			randm = 1;
			check +=1;
//			printf("0check: %d\n",check);					
		}
		if(randm == 1){ //Move Down
			posm -= 1;
			if((int)arr[posm][posn] == '.' && posm >= 0){
				arr[posm][posn] = (char)i;				
				i += 1; 
				randm = rand() % 4;
				check = 0;
				continue;
			}
			posm += 1;
			randm = 2;					
			check += 1;
//			printf("1check: %d\n",check);		
		}
		if(randm == 2){ //Move Left
			posn -= 1;
			
			if((int)arr[posm][posn] == '.' && posn >= 0){
				arr[posm][posn] = (char)i;				
				i += 1;
				randm = rand() % 4;
				check = 0;
				continue; 
			}
			posn += 1;
			randm = 3;			
			check +=1;
//			printf("2check: %d\n",check);		
		}
		if(randm == 3) { //Move Right
			posn += 1;
			
			if((int)arr[posm][posn] == '.' && posn < n) {
				arr[posm][posn] = (char)i;				
				i += 1; 
				randm = rand() % 4;
				check = 0;
				continue;
			}
			posn -= 1;
			randm = 0;			
			check +=1;
//			printf("3check: %d\n",check);		
		}
		if(check >= 4){
			break;
		}
	}
	if(i <= 90){
		printf("%c got trapped\n",(char)i-1);
	}	
	//Printing Array
	for(i = 0 ; i < m ; i++){
		
		for(j = 0 ; j < n ; j++){
			printf("%c",arr[i][j]);		
		}
		printf("\n");	
	
	}


}

/*
int r = rand() % 4;
		if( r == 0 ){
			posm -=1; //Move up
			if(posm < 0){
				posm +=1;
				continue;
			}		
		} else if( r == 1 ) {
			posm +=1; //Move Down
			if(posm >= m){
				posm -=1;
				continue;
			}
		} else if( r == 2 ) {
			posn -=1; //Move Left
			if(posn < 0){
				posn +=1;
				continue;
			}
		} else {
			posn +=1; //Move Right
			if(posn >= n){
				posm -=1;
				continue;
			}
		}
*/
