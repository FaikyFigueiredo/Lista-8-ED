#ifndef LISTSTUDENT_H
#define LISTSTUDENT_H

typedef struct student{
    int mat;
    char name[50];
    float nota1, nota2;
}Student;
typedef struct no{
    Student *student;
    struct no *prox;
}No;
typedef struct lista{
    No *inicio;
}Lista;

/*Meta - Biblioteca deve conter:
Função de criar
Função de verificar se tá vazias
Função de retornar o tamanho
Função de inserir na posição e no final
Função de remover
Função de exibir*/
void criar(Lista *l);
int vazia(Lista *l);
int tamanho(Lista *l);
int inserir(Lista *l, Student* stu);
int inserirPos(Lista *l, Student* stu, int pos);
int removeName(Lista *l, char name[]);
int removeMat(Lista *l, int mat);
int removePos(Lista *l, int pos);
void sort(Lista *l);
No* searchPosition(Lista *l, int pos);
No* searchName(Lista *l, char name[]);
No* searchMat(Lista *l, int mat);
void exibir(Lista *l);



#endif // LISTSTUDENT_H