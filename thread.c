
#include<stdio.h>
#include<pthread.h>

int count=1;
pthread_t tmp,tmp2;
void * even(void *b)
{
	tmp2=pthread_self();
	int j= *((int*)b);
 	if(j%2==0)
	{
  		printf("even= %d\n",j);
	 	j++;
	}
	
	
}
void * odd(void *a)
{	
	tmp=pthread_self();
	int k= *((int*)a);
	if(k%2!=0)
	{	
		printf("odd=%d\n",k);
		k++;
	}
}

int main()
{
	pthread_t thread1,thread2;
	for(int i=0;i<=100;i++)
	{
	if(count==100)
	{
	 pthread_cancel(tmp2);
	 pthread_cancel(tmp);
		break;
	}
	pthread_create(&thread1,NULL,&even,&count);
	pthread_create(&thread2,NULL,&odd,&count);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	count++;
	}
return 0;
}
