#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int main(){

    struct aluno al, a[4] = {
        {1,"Andre",9.5,7.8,8.5},
        {2,"Ricardo",7.5,8.7,6.8},
        {3,"Bianca",9.7,6.7,8.4},
        {4,"Ana",5.7,6.1,7.4}
    };

    Lista* li = cria_lista();

    for (int i = 0; i < 4; i++) {
        insere_lista_ordenada(li, a[i]);
    }

    imprime_lista(li);

    troca(li, 1);
    troca(li, 3);

    printf("\n\n\n\n");

    imprime_lista(li);

    libera_lista(li);

    return 0;
}

