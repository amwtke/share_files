#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#define BUFFER_SIZE 256
int main(){
        sleep(30);
        int fd;
         void *buffer = malloc(BUFFER_SIZE);
         if(buffer == NULL){
                 return 0;
         }
        //create or open f.txt
        fd = open("./f.txt",O_CREAT|O_RDWR,S_IRWXU);
        int size = read(fd,buffer,BUFFER_SIZE);
        if(size == 0){
                int tmp = sprintf(buffer,"xiaojin is here!");
                //write some words to f.txt
                size = write(fd,buffer,tmp);
                printf("write %d bytes!\n",size);
                //写入磁盘
                if(fsync(fd)<0){
                        printf("failed fsync!\n");
                        return 0;
                }
                //写入后pos移动到文件最后，所以读的时候需要重新移动到开头。
                lseek(fd,0,SEEK_SET);
                size = read(fd,buffer,BUFFER_SIZE);
                printf("read size = %d\n",size);
                if(size!=0){
                        printf("ok");
                        printf("\n%s\n",(char*)buffer);
                }
        }else{
                printf("\n%s\n",(char*)buffer);
        }
        close(fd);


        //mmap
        fd = open("./f.txt",O_RDWR);
        char* addr = mmap(0,BUFFER_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
        if(MAP_FAILED == addr){
                return 0;
        }
        for(int i=0;i<15;i++){
                *(addr+i) = 'b';
                sleep(5);
                printf("i = %d\n",i);
                fsync(0);
        }
        //sleep(30);
        lseek(fd,0,SEEK_SET);
        size = read(fd,buffer,BUFFER_SIZE);
        printf("read size = %d\n",size);
        if(size!=0){
                printf("ok");
                printf("\n%s\n",(char*)buffer);
        }
        close(fd);
        return 0;
}
