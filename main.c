#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listStudent.h"

void menu(){
    printf("O que voce gostaria de fazer?\n");
    printf("1-Inserir aluno no final da lista\n");
    printf("2-Inserir aluno em certa posicao da lista\n");
    printf("3-Remover aluno\n");
    printf("4-Verificar lista vazia\n");
    printf("5-Tamanho da lista\n");
    printf("6-Exibir lista\n");
    printf("7-Sair\n");
}
int main(){
    Lista* l;
    criar(l);
    while(1){
        int opt;
        menu();
        scanf("%d", &opt);
        getchar();
        switch(opt){
            case 1:
                Student* stu1;
                printf("Digite o nome do aluno\n");
                fgets(stu1->name,50,stdin);
                printf("Digite a matricula do aluno\n");
                scanf("%d", &(stu1->mat));
                printf("Digite as notas(sao duas)\n");
                scanf("%f %f", &(stu1->nota1), &(stu1->nota2));
                int result = inserir(l,stu1);
                if (result)
                    printf("Aluno inserido com sucesso\n");
                else
                    printf("Erro ao inserir\n");
                sort(l);
                break;
            case 2:
                int pos2;
                Student* stu2;
                printf("Insira a posicao a ser inserido o aluno");
                scanf("%d", &pos2);
                getchar();
                printf("Digite o nome do aluno\n");
                fgets(stu2->name,50,stdin);
                printf("Digite a matricula do aluno\n");
                scanf("%d", &(stu2->mat));
                printf("Digite as notas(sao duas)\n");
                scanf("%f %f", &(stu2->nota1), &(stu2->nota2));
                int result = inserirPos(l,stu2,pos2);
                result? printf("Aluno inserido com sucesso\n") : printf("Erro ao inserir\n");
                sort(l);
                break;
            case 3:
                int opt3;
                printf("Como voce deseja remover\n");
                printf("1-Nome\n2-Matricula\n3-Posicao\n");
                scanf("%d", & opt3);
                getchar();
                switch(opt3){
                    case 1:
                        char name31[50];
                        printf("Digite o nome do estudante\n");
                        fgets(name31,50,stdin);
                        int result = removeName(l,name31);
                        result? printf("Remocao realizada com sucesso\n") : printf("Erro na remocao\n");
                        break;
                    case 2:
                        int mat32;
                        printf("Digite a matricula do aluno\n");
                        scanf("%d", &mat32);
                        getchar();
                        int result = removeMat(l,mat32);
                        result? printf("Remocao realizada com sucesso\n") : printf("Erro na remocao\n");
                        break;
                    case 3:
                        int pos33;
                        printf("Digite a posicao do aluno\n");
                        scanf("%d", &pos33);
                        int result = removePos(l,pos33);
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
            case 4:
                vazia(l)?printf("Lista esta vazia\n"):printf("Lista nao esta vazia\n");
                break;
            case 5:
                printf("A lista possui o tamanho %d", tamanho(l));
                exibir(l);
                break;
            case 6:
                exibir(l);
                break;
            case 7:
                return 0;
        }
    }
}