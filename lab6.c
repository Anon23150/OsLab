#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum ; 
int csum ;
void *runner(void *param);

int main (int argc, char*argv[]) {
	pthread_t tid ;
	pthread_attr_t  attr ;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr , runner , argv[1] ) ;

	pthread_join(tid,NULL) ;
	int sum = atoi(argv[1] ); 
	printf("sum = sum %d \n" ,sum );
	for(int i = 0 ; i <= sum ; i++){
		msum += i ; 
	}
	printf("csum - msum = %d\n " , csum-msum) ;
	printf("msum %d , csum %d " , msum , csum  );
	return 0 ; 
}
void *runner (void *param){
	int upper = 2*atoi(param); 
	int i ; 
	csum = 0 ; 
	if(upper > 0 ){
		for(i = 0 ; i<= upper ; i++){
			csum += i ;
		}
	}
	pthread_exit(0);
}

