#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if (pos == 0){
        return l->inicio;
    }for (int i = 0; i != pos; i++){
        node = node->prox;
        if (node == NULL)
            return NULL;
    }
    return node;
}
No* searchName(Lista *l, char name[]){
    No* node = l->inicio;
    if (vazia(l))
        return NULL;
    while (strcmp(node->student->name,name) != 0){
        node = node->prox;
        if (node == NULL)
            return NULL;
    }
    return node;
}
No* searchMat(Lista *l, long int mat){
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
        novo->pre = NULL;
        return 1;
    }

    No *aux = l->inicio;
    for (;aux->prox!=NULL;aux=aux->prox);
    aux->prox = novo;
    novo->pre = aux;
    return 1;
}
int inserirPos(Lista *l, Student* stu, int pos){
    No *novo = (No *) malloc(sizeof(No));
    novo->student = stu;
    No *past, *searched;
    if(pos == 0){
        past = l->inicio;
        l->inicio = novo;
        novo->prox = past;
        novo->pre = NULL;
        return 1;
    }
    searched = searchPosition(l,pos-1);
    if (searched == NULL)
        return 0;
    else{
        past = searched->prox;
        searched->prox = novo;
        novo->prox = past;
        novo->pre = searched;
    }
    return 1;
}
int removeName(Lista *l, char name[]){
    No* searched = searchName(l,name), *past;
    if (searched == NULL)
        return 0;
    if (searched == l->inicio){
        l->inicio = NULL;
        free(searched);
    }else if (searched->prox ==NULL){
        if (searched->pre != NULL)
            searched->pre->prox = NULL;
        free(searched->student);
        free(searched);
    }else{
        searched->pre->prox = searched->prox;
        free(searched->student);
        free (searched);
    }
    return 1;
}
int removeMat(Lista *l, long int mat){
    No* searched = searchMat(l,mat), *past;
    if (searched == NULL)
        return 0;
    else if(searched == l->inicio){
        l->inicio = l->inicio->prox;
    }else{
        past = searched->pre;
        past->prox = searched->prox;
    }
    free(searched->student);
    free(searched);
    return 1;
}
int removePos(Lista *l, int pos){
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
    No* node, *temp,*lessMat;
    Student *tempSt;
    int count = 0;
    for (count = 0; count < tamanho(l);count++){
        lessMat = l->inicio;
        for(int i = 0; i < count; i++)
            lessMat = lessMat->prox;
        for(node = lessMat ;node != NULL; node = node->prox){
            if (lessMat->student->mat > node->student->mat)
                lessMat = node;
        }
        temp = l->inicio;
        for(int i = 0; i < count; i++)
            temp = temp->prox;
        tempSt = temp->student;
        temp->student = lessMat->student;
        lessMat->student = tempSt;
    }
}
void printStudent(Student* st){
    printf("Nome: %sMatricula: %.12ld\nNotas: %.2f %.2f\n", st->name, st->mat, st->nota1, st->nota2);
}
void exibir(Lista *l){
    No *aux = l->inicio;
    for (int i = 0;aux != NULL;aux = aux->prox){
        printf("Aluno %d\n", ++i);
        printStudent(aux->student);
    }
}