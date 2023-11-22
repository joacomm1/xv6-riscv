#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(void) {

printf("soy yo: %d\n", getancestor(0));
printf("%d\n", getancestor(1));
printf("%d\n", getancestor(2));
printf("%d\n", getancestor(3));
printf("%d\n", getancestor(-1));
exit(0);
}
