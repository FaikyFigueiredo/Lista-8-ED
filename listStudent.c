#include <stdio.h>
#include <stdlib.h>
#include "listStudent.h"

void criar(Lista *l){
    l->inicio = NULL;
}
int vazia(Lista *l){
    return (l->inicio == NULL);
}
int tamanho(Lista *l){
    int cont = 0;
    No *aux = l->inicio;

    while(aux!=NULL){
        aux=aux->prox;
        cont++;
    }
    return cont;
}
No* searchPosition(Lista *l, int pos){
    No* node = l->inicio;
    for (int i = 0; i != pos; i++){
        if (node->prox != NULL)
            node = node->prox;
        else
            return NULL;
    }
    return node;
}
No* searchName(Lista *l, char name[]){
    No* node = l->inicio;
    while(strcmp(node->student->name, name) != 0){
        if (node->prox != NULL)
            node = node->prox;
        else
            return NULL;
    }
    return node;
}
No* searchMat(Lista *l, int mat){
    No* node = l->inicio;
    while(node->student->mat != mat){
        if (node->prox != NULL)
            node = node->prox;
        else
            return NULL;
    }
    return node;
}
int inserir(Lista *l, Student* stu){
    No *novo = (No *) malloc(sizeof(No));
    novo->student = stu;
    novo->prox = NULL;

    if (vazia(l)){
        l->inicio = novo;
        return 1;
    }

    No *aux = l->inicio;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox = novo;
    return 1;
}
int inserirPos(Lista *l, Student* stu, int pos){
    No *novo = (No *) malloc(sizeof(No));
    novo->student = stu;
    No *past, *searched;
    searched = searchPosition(l,pos);
    if (searched == NULL)
        return 0;
    past = searched->prox;
    searched->prox = novo;
    novo->prox = past;
    return 1;
}
int removeName(Lista *l, char name[]){
    No* searched = searchName(l,name), *past;
    if (searched == NULL)
        return 0;
    searched->student = searched->prox->student;
    past = searched->prox;
    searched->prox = searched->prox->prox;
    free(past->student);
    free(past);
    return 1;
}
int removeMat(Lista *l, int mat){
    No* searched = searchMat(l,mat), *past;
    if (searched == NULL)
        return 0;
    searched->student = searched->prox->student;
    past = searched->prox;
    searched->prox = searched->prox->prox;
    free(past->student);
    free(past);
    return 1;
}
int removeMat(Lista *l, int pos){
    No* searched = searchPosition(l,pos), *past;
    if (searched == NULL)
        return 0;
    searched->student = searched->prox->student;
    past = searched->prox;
    searched->prox = searched->prox->prox;
    free(past->student);
    free(past);
    return 1;
}
void sort(Lista *l){
    No* node, *temp;
    for (int i = tamanho(l); i > 0; i--){
        node = l ->inicio;
        Student* lessMat = node->student;
        for (int j = 0; j < tamanho(l); j++){
            if (lessMat->mat > node->student->mat){
                lessMat = node->student;
                temp = node;
            }
            node = node->prox;
        }
        temp->student = node->student;
        node->student = lessMat;
    }
}
void exibir(Lista *l){
    No *aux = l->inicio;
    while (aux != NULL){
        printf("Aluno %d");
        printf("Nome: %s\nMatricula: %.12d\nNotas: %f %f\n", aux->student->name, aux->student->mat, aux->student->nota1, aux->student->nota2);
        aux=aux->prox;
    }
}