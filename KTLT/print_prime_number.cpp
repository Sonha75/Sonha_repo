#include<stdio.h>

int checkprimenumber(int n){
	int flag=0;
	for(int i=2;i<=n/2;i++){
		if(n%i==0){
			flag=1;
			break;
		}
	}
	return flag;
}
int main(){
	int number;
	scanf("%d",&number);
	
	if(number==2)
	printf("%d",number);
	
	if(number>2){
		for(int i=2;i<=number;i++){
			if( checkprimenumber(i) == 0 )
			printf("\t%d",i);
		}
	}
	else
	printf("\nNo primenumber!");
	
}
