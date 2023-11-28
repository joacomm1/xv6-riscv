#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    // Obtiene la dirección actual del puntero de instrucción.
    int *ip = (int*)main;

    // Intenta sobrescribir el código en memoria.
    *ip = 13;

    // Si no hay fallos, imprime un mensaje.
    printf("¡No hubo fallos!\n");

    exit(0);
}
