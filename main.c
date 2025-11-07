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
    printf("7-Pesquisar estudante\n");
    printf("8-Organizar lista(ordem crescente de matrícula)\n");
    printf("9-Sair\n");
}
int main(){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    criar(l);
    while(1){
        int opt;
        menu();
        scanf("%d", &opt);
        getchar();
        switch(opt){
            case 1:
                Student* stu1 = (Student*)malloc(sizeof(Student));
                printf("Digite o nome do aluno\n");
                fgets(stu1->name,50,stdin);
                printf("Digite a matricula do aluno\n");
                scanf("%ld", &(stu1->mat));
                printf("Digite as notas(sao duas)\n");
                scanf("%f %f", &(stu1->nota1), &(stu1->nota2));
                int result1 = inserir(l,stu1);
                result1? printf("Aluno inserido com sucesso\n"): printf("Erro ao inserir\n");
                //sort(l);
                break;
            case 2:
                int pos2;
                Student* stu2 = (Student*)malloc(sizeof(Student));
                printf("Insira a posicao a ser inserido o aluno");
                scanf("%d", &pos2);
                getchar();
                printf("Digite o nome do aluno\n");
                fgets(stu2->name,50,stdin);
                printf("Digite a matricula do aluno\n");
                scanf("%ld", &(stu2->mat));
                printf("Digite as notas(sao duas)\n");
                scanf("%f %f", &(stu2->nota1), &(stu2->nota2));
                int result2 = inserirPos(l,stu2,pos2);
                result2? printf("Aluno inserido com sucesso\n") : printf("Erro ao inserir\n");
                //sort(l);
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
                        int result31 = removeName(l,name31);
                        result31? printf("Remocao realizada com sucesso\n") : printf("Erro na remocao\n");
                        break;
                    case 2:
                        long int mat32;
                        printf("Digite a matricula do aluno\n");
                        scanf("%ld", &mat32);
                        getchar();
                        int result32 = removeMat(l,mat32);
                        result32? printf("Remocao realizada com sucesso\n") : printf("Erro na remocao\n");
                        break;
                    case 3:
                        int pos33;
                        printf("Digite a posicao do aluno\n");
                        scanf("%d", &pos33);
                        int result33 = removePos(l,pos33);
                        result33? printf("Remocao realizada com sucesso\n") : printf("Erro na remocao\n");
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
                break;
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
                int opt7;
                printf("Como voce deseja remover\n");
                printf("1-Nome\n2-Matricula\n3-Posicao\n");
                scanf("%d", &opt7);
                getchar();
                switch(opt7){
                    case 1:
                        No* node71;
                        char name71[50];
                        printf("Digite o nome do estudante\n");
                        fgets(name71,50,stdin);
                        node71 = searchName(l,name71);
                        node71==NULL? printf("Aluno nao encontrado\n") : printStudent(node71->student);
                        break;
                    case 2:
                        No* node72;
                        long int mat72;
                        printf("Digite a matricula do aluno\n");
                        scanf("%ld", &mat72);
                        getchar();
                        node72 = searchMat(l,mat72);
                        node72==NULL? printf("Aluno nao encontrado\n") : printStudent(node72->student);
                        break;
                    case 3:
                        No* node73;
                        int pos73;
                        printf("Digite a posicao do aluno\n");
                        scanf("%d", &pos73);
                        node73 = searchPosition(l,pos73);
                        node73==NULL? printf("Aluno nao encontrado\n") : printStudent(node73->student);
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
                break;
            case 8:
                sort(l);
                break;
            case 9:
                return 0;
                break;
        }
    }
}