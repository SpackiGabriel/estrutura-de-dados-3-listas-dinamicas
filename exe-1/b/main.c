#include <stdio.h>
#include "ListaDinEncad.h"

int main() {
    Lista* li = cria_lista();

    struct aluno al1 = {1, "João", 8.0, 7.5, 9.0};
    struct aluno al2 = {2, "Maria", 7.0, 6.5, 8.5};

    insere_lista_final(li, al1);
    insere_lista_final(li, al2);

    struct aluno aluno_encontrado = busca_lista_pos(li, 1);

    if (aluno_encontrado.matricula != -1) {
        printf("Aluno encontrado: %s, Matrícula: %d\n",
               aluno_encontrado.nome,
               aluno_encontrado.matricula);
    } else {
        printf("Aluno não encontrado na posição informada.\n");
    }

    libera_lista(li);

    return 0;
}
