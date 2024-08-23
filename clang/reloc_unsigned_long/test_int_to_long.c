#include<stdio.h>
#include<string.h>
void itoc(unsigned long);
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

	unsigned long  p = 0x0000000002814067;
	p = p - (unsigned long)0xffffffff80000000;
	printf("test =  %#lx\n",p);
	
	printf("a is %d\n",a);
	itoc(0xffffffff80000000);
}
void itoc(unsigned long n){
	char s[100] = {0};
	int i = 0, j, flag = 0;
	char temp;
	if(n < 0)//为负数
	{
		n = -n;
		flag = 1;
	}
	if(n == 0)//数字为0
	{
		s[i++] = '0';
	}
	while(n)
	{
		s[i++] = n % 10 +'0'; //取出每一位数字
		n = n/10;
	}
	if(flag)
	{
		s[i++] = '-';
	}
	j = strlen(s);
	for(i = 0; i < j/2; i++)  //顺序调换
	{
		temp = s[i];
		s[i] = s[j-i-1];
		s[j-i-1] = temp;
	}
	printf("number is %s\n",s);
}
