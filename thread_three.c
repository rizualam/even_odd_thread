
#include<stdio.h>
#include<pthread.h>

int count=1;
void * even()
{
 while(count<=100)
{	

 	if(count%2==0)
	{
  		printf("even= %d\n",count);
	 	count++;
	}
}
	
}
void * odd()
{	
	while(count<=100)
{
	
	if(count%2!=0)
	{	
		printf("odd=%d\n",count);
		count++;
	}
}

}

int main()
{
	pthread_t thread1,thread2;
	
	
	pthread_create(&thread1,NULL,&even,&count);
	pthread_create(&thread2,NULL,&odd,&count);
	

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
return 0;
}
