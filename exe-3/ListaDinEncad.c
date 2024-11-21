#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Prot�tipos

//Defini��o do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in�cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

/* Como pensei para inserir em uma posição específica:

    - Verificar a posição é positiva.
    - Cria o novo elemento.
    - Caso especial: Se a posição for 0, inserir no início da lista (apontar a lista para o novo inicio).
    - Se não, percorrer a lista (mesma lógica de sempre) até encontrar a posição anterior à desejada.
    - Se a posição não for encontrada, o usuário passou uma posição que não existe na lista, então retorno 0.
    - Caso contrário, inserir o aluno na posição correta, atualizando os ponteiros do registro anterior.
*/
int insere_lista_pos(Lista* li, struct aluno al, int pos) {
    if (li == NULL || pos < 0) {
        return 0;
    }

    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if (no == NULL) {
        return 0;
    }

    no->dados = al;

    // Caso seja para inserir no início
    if (pos == 0) { 
        no->prox = *li;
        *li = no;
        return 1;
    }

    int i = 0;
    Elemento* aux = *li;

    while (aux != NULL && i < pos - 1) {
        aux = aux->prox;
        i++;
    }

    if (aux == NULL) {
        free(no);
        return 0;
    }

    no->prox = aux->prox;
    aux->prox = no;

    return 1;
}
