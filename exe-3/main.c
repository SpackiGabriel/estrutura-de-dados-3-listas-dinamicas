#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncad.h"

int main() {
    Lista* li = cria_lista();
    if (li == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    struct aluno al1 = {1, "João", 8.0, 7.5, 9.0};
    struct aluno al2 = {2, "Maria", 7.0, 6.5, 8.5};
    struct aluno al3 = {3, "Ana", 9.5, 8.0, 10.0};

    if (insere_lista_pos(li, al1, 0)) {
        printf("Aluno João inserido na posição 0.\n");
    }
    if (insere_lista_pos(li, al2, 1)) {
        printf("Aluno Maria inserido na posição 1.\n");
    }

    if (insere_lista_pos(li, al3, 1)){
        printf("Aluno Ana inserido na posição 1.\n");
    }

    imprime_lista(li);

    libera_lista(li);
    return 0;
}
