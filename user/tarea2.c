#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero_hijos>\n", argv[0]);
        exit(1);
    }

    int num_children = atoi(argv[1]);
    int pids[num_children];

    for (int i = 0; i < num_children; i++) {
        int pid = fork();
        if (pid < 0) {
            printf("fork failed\n");
            exit(1);
        } else if (pid == 0) {
            set_priority(i, getpid());
            exit(0);
        }
        pids[i] = pid;
        wait(0);
    }

    for (int i = num_children - 1; i >= 0; i--) {
        for (int j = 1; j <= 60; j++) {
            printf("%d %d\n", pids[i], j);
            sleep(1);
        }
    }
    for (int j = 1; j <= 60; j++) {
        printf("%d %d\n", getpid(), j);
        sleep(1);

    } 
    exit(0);
}
