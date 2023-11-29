#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"

void child_process(char *num) {
    printf("Está protegido con un valor de = %d\n", *num);   
    munprotect(num, 1) ;  
    *num=10;
    printf("Está desprotegido con un valor de = %d\n", *num); 
    exit(0);
}

int main(int argc, char *argv[]) {
    char *num = sbrk(0);
    sbrk(PGSIZE);
    *num=1;
    mprotect(num, 1) ;
    int pid=fork();

    if(pid==0){
        child_process(num);
    }
    return 0;
}

