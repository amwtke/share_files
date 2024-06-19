#include<stdio.h>
int a[1024];
int main(){
	a[100] = 100;
	getchar();
	printf("a[100] is:%d\n",a[100]);
	printf("a[100] at:%p\n",&a[100]);
}
