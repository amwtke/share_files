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

	printf("now for testing....\n");

	unsigned long load_physical_addr = 0x1000000;
	unsigned long start_kernel_map = 0xffffffff80000000;

	unsigned long output = 201326592;
	unsigned long virt_addr = 452984832;
	unsigned long delta = virt_addr - load_physical_addr;
	unsigned long _text = start_kernel_map +load_physical_addr + delta;
	unsigned long load_delta = output - (_text - start_kernel_map);
	printf("virt_addr delta is %#lx\n",delta);
	printf("virt_addr delta is %lu\n",delta);
	printf("load delta is %#lx\n",load_delta);
	printf("load delta is %lu\n",load_delta);

	unsigned long orig_addr = 42025063;
	printf("virt_delta 0x2814067 is %lu\n",orig_addr + delta);
	printf("final of 0x2814067 is %lu\n",orig_addr + delta + load_delta);
	printf("final of 0x2814067 is %#lx\n",orig_addr + delta + load_delta);

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
