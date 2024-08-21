#include<stdio.h>
int main(){
	int a = 0x810003bf;
	unsigned long map = 0x0- 0xffffffff80000000;
	long b = a;
	b+=map;
	unsigned long ptr = (unsigned long )b;
	printf("map is %#lx\n",map);
	printf("(long)map is %#lx\n",(long)map);
	printf("b is %#lx\n",b);
	printf("ptr is %#lx\n",ptr);
}
