#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

void hello_world(void)
{
    printf("Hello world!!!!\r\n");
}

int main(void)
{

        struct  timeval   tv_begin,tv_end;
        
        gettimeofday(&tv_begin,NULL);
        
        hello_world();

        gettimeofday(&tv_end,NULL);
    
        printf("tv_begin_sec:%ld\n",tv_begin.tv_sec);

        printf("tv_begin_usec:%ld\n",tv_begin.tv_usec);

        printf("tv_end_sec:%ld\n",tv_end.tv_sec);

        printf("tv_end_usec:%ld\n",tv_end.tv_usec);

        return 0;

}        
