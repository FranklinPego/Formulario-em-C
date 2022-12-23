#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100


int main() {
    char namefunc[MAX][30], cpf[MAX][11], pesq[11];
    float salario[MAX], totalsalario=0;
    int age[MAX], option, i, qtde = 0, found;

    do {
        printf("\n=========Empresa PP==========\n\n");
        printf("\n1. Novo Funcionario\n2. Listar todos os funcionarios\n3. Pesquisar um funcionario pelo CPF\n4. Excluir um funcionario\n5. Media dos salarios dos funcionarios\n6. Sair do sistema\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &option);
        printf("\n");
        switch(option){
            case 1:
                printf("Digite o nome Do Funcionario: ");
                fflush(stdin);
                gets(namefunc[qtde]);
                printf("Digite o CPF Do Funcionario: ");
                fflush(stdin);
                gets(cpf[qtde]);
                printf("Digite o Salario Do Funcionario: ");
                scanf("%f",&salario[qtde]);
                totalsalario+=salario[qtde];
                printf("Digite a Idade do Funcionario: ");
                scanf("%d",&age[qtde]);
                printf("\nSeu cadastro foi cadastrado! ;) ᵇʸ:ᴬʸʳᵗᵒⁿ\n");
                qtde++;
            break;


            case 2:
            if (qtde > 0) {
                for (i=0; i<qtde; i++) {
                        printf("Nome: %s\n", namefunc[i]);
                        printf("CPF: %s\n", cpf[i]);
                        printf("Salario: R$ %.3f\n", salario[i]);
                        printf("Idade: %d\n\n", age[i]);
                        found = 1;
                   
                }
            } else {
                printf("\nNenhum Funcionario foi Encontrado no nosso Banco de dados!!!!\n");
            }
            break;

            case 3:
                printf("Informe o CPF do Funcionario para pesquisarmos no nosso banco de dados: ");
                fflush(stdin);
                gets(pesq);
                found = 0;
                for (i=0; i<qtde; i++) {
                    if (strcmp(cpf[i], pesq) == 0) {
                        printf("Nome: %s\n", namefunc[i]);
                        printf("CPF: %.3f\n", cpf[i]);
                        printf("Salario: %.3f\n", salario[i]);
                        printf("Idade: %d\n\n", age[i]);
                        found = 1;
                        
                    }
                }
                if (found == 0) {
                    printf("\nNenhum Funcionario com esse CPF Encontrado\n");
                }
            break;

            case 4:
                 printf("\nInforme o CPF do Funcionario para removermos do nosso banco de dados: ");
                fflush(stdin);
                gets(pesq);
                found = 0;
                for (i=0; i<qtde; i++) {
                    if (strcmp(cpf[i], pesq) == 0) {
                        for (int j = i; j < (qtde-1); j++) {
                            strcpy(namefunc[j], namefunc[j+1]);
                            strcpy(cpf[j], cpf[j+1]);
                            salario[j] = salario[j+1];
                            age[j] = age[j+1];
                        }
                        printf("\nFuncionario Removido com sucesso!!");
                        found = 1;
                    }
                }
                if (found == 0) {
                    printf("Nenhum Funcionario com esse CPF Encontrado\n");
                } else {
                    qtde--;
                }
            break;
            case 5:
            printf("media: %.3f", totalsalario);
            break;
            case 6:
                printf("Voce saiu do sistema com exito.\n");
                sleep(2);
            break;

            default:
                printf("Opcao invalida\n");
        }

    } while(option != 6);

}