//Trabalho final de AP1
//Assunto: Organizador de tabelas de campeonatos de futebol
//Alunos: Victor Gabriel Caldas, Renan Oliveira, Batley Abreu, Pedro
//Curso: Engenharia de Computação - Noturno 2017/1

#include <stdio.h>
#include <string.h>
void introducao(void)
{
    printf("\t\t\tBem vindo ao tabela maker de futebol!!\n\n");
    printf("Primeiramente precisamos saber quantos times participarao do campeonato\n\n");
    printf("Digite o numero: ");
    return;
}
void escreveMenu(void)
{
    system("cls");
    printf("Escolha uma opcao:\n\n");
    printf("1 - Cadastro de times\n");
    printf("2 - Cadastro de resultados\n");
    printf("3 - Tabela\n");
    printf("0 - Sair");
    printf("\n\nEscolha sua opcao: ");
    return;
}
int main()
{
    int menu, nTimes, l, c, i, j, golsM=0, golsV=0, flagNomeM=0, flagNomeV=0, flagCadastro=0, numTimeM=0, numTimeV=0;
    int auxTabela[5];
    char auxNomeTimes[20], nomeM[20], nomeV[20];
    introducao();
    scanf("%d", &nTimes);
    int tabela[nTimes][5];
    char nomeTimes[nTimes][20];
    do
    {
        escreveMenu();
        scanf("%d", &menu);
        if (menu == 1)
        {
            if (flagCadastro == 1)
            {
                printf("Voce ja realizou cadastro, tem certeza que deseja zerar os dados??\n");
                printf("Caso sim digite 0, caso nao digite 1: ");
                scanf("%d", &flagCadastro);
            }
            else
            {
                for (l = 0; l < nTimes; l++)
                {
                    for (c = 0;c < 5; c++)
                    {
                        tabela[l][c]=0;
                    }
                }
                system("cls");
                printf("Agora digite o nome dos times...\n\n");
                for (l = 0;l < nTimes;l++)
                {
                    printf("Nome do time %d: ", l+1);
                    fflush(stdin);
                    scanf("%s",&nomeTimes[l]);
                }
                printf("\n\n");
                flagCadastro=1;
                system("pause");
            }
        }
        else
        {
            if (menu == 2)
            {
                system("cls");
                if(flagCadastro=0)
                {
                    printf("Times nao cadastrados, por favor cadastre no menu!\n\n");
                    system("pause");
                }
                else
                {
                    do
                    {
                        printf("Digite o nome do time mandante: ");
                        fflush(stdin);
                        scanf("%s", &nomeM);
                        for (l=0;l<nTimes;l++)
                        {
                            if(strcmp(nomeM, nomeTimes[l])==0)
                            {
                                flagNomeM=1;
                                numTimeM=l;
                            }
                        }
                        if (flagNomeM==0)
                        {
                            system("cls");
                            printf("Time nao encontrado, digite novamente \n\n");
                            system("pause");
                        }
                    } while (flagNomeM != 1);
                    do
                    {
                        printf("Digite o nome do time visitante: ");
                        fflush(stdin);
                        scanf("%s", &nomeV);
                        for (l=0;l<nTimes;l++)
                        {
                            if(strcmp(nomeV, nomeTimes[l])==0)
                            {
                                flagNomeV=1;
                                numTimeV=l;
                            }
                        }
                        if (flagNomeV==0)
                        {
                            system("cls");
                            printf("Time nao encontrado, digite novamente\n\n ");
                            system("pause");
                        }
                    } while (flagNomeV != 1);
                    printf("Digite o numero de gols marcados pelo mandante: ");
                    scanf("%d",&golsM);
                    printf("Digite o numero de gols marcados pelo visitante: ");
                    scanf("%d",&golsV);
                    tabela[numTimeM][1]=tabela[numTimeM][1]+1;
                    tabela[numTimeV][1]=tabela[numTimeV][1]+1;
                    tabela[numTimeM][3]=tabela[numTimeM][3]+(golsM-golsV);
                    tabela[numTimeV][3]=tabela[numTimeV][3]+(golsV-golsM);
                    tabela[numTimeM][4]=tabela[numTimeM][4]+golsM;
                    tabela[numTimeV][4]=tabela[numTimeV][4]+golsV;
                    if (golsM>golsV)
                    {
                        tabela[numTimeM][0]=tabela[numTimeM][0]+3;
                        tabela[numTimeM][2]=tabela[numTimeM][2]+1;
                    }
                    else
                    {
                        if (golsM<golsV)
                        {
                            tabela[numTimeV][0]=tabela[numTimeV][0]+3;
                            tabela[numTimeV][2]=tabela[numTimeV][2]+1;
                        }
                        else
                        {
                            tabela[numTimeM][0]=tabela[numTimeM][0]+1;
                            tabela[numTimeV][0]=tabela[numTimeV][0]+1;
                        }
                    }
                }
            }
            else
            {
                if (menu == 3)
                {
                    system("cls");
                    for (l=0;l<nTimes-1;l++)
                    {
                        for (c=0;c<nTimes-1;c++)
                        {
                            if(tabela[c][0]<tabela[c+1][0])
                            {
                                strcpy(auxNomeTimes, nomeTimes[c]);
                                strcpy(nomeTimes[c], nomeTimes[c+1]);
                                strcpy(nomeTimes[c+1], auxNomeTimes);
                                for (i=0; i<5; i++)
                                {
                                    auxTabela[i]=tabela[c][i];
                                }
                                for (i=0; i<5; i++)
                                {
                                    tabela[c][i]=tabela[c+1][i];
                                }
                                    for (i=0; i<5; i++)
                                {
                                    tabela[c+1][i]=auxTabela[i];
                                }
                            }
                            else
                            {
                                if (tabela[c][0] == tabela[c+1][0] && tabela[c][2] < tabela [c+1][2])
                                {
                                    strcpy(auxNomeTimes, nomeTimes[c]);
                                    strcpy(nomeTimes[c], nomeTimes[c+1]);
                                    strcpy(nomeTimes[c+1], auxNomeTimes);
                                    for (i=0; i<5; i++)
                                    {
                                        auxTabela[i]=tabela[c][i];
                                    }
                                    for (i=0; i<5; i++)
                                    {
                                        tabela[c][i]=tabela[c+1][i];
                                    }
                                        for (i=0; i<5; i++)
                                    {
                                        tabela[c+1][i]=auxTabela[i];
                                    }
                                }
                                else
                                {
                                    if (tabela[c][2] == tabela[c+1][2] && tabela[c][3] < tabela[c+1][3])
                                    {
                                        strcpy(auxNomeTimes, nomeTimes[c]);
                                        strcpy(nomeTimes[c], nomeTimes[c+1]);
                                        strcpy(nomeTimes[c+1], auxNomeTimes);
                                        for (i=0; i<5; i++)
                                        {
                                            auxTabela[i]=tabela[c][i];
                                        }
                                        for (i=0; i<5; i++)
                                        {
                                            tabela[c][i]=tabela[c+1][i];
                                        }
                                            for (i=0; i<5; i++)
                                        {
                                            tabela[c+1][i]=auxTabela[i];
                                        }
                                    }
                                    else
                                    {
                                        if (tabela[c][3] == tabela[c+1][3] && tabela[c][4] < tabela[c+1][4])
                                        {
                                            strcpy(auxNomeTimes, nomeTimes[c]);
                                            strcpy(nomeTimes[c], nomeTimes[c+1]);
                                            strcpy(nomeTimes[c+1], auxNomeTimes);
                                            for (i=0; i<5; i++)
                                            {
                                                auxTabela[i]=tabela[c][i];
                                            }
                                            for (i=0; i<5; i++)
                                            {
                                                tabela[c][i]=tabela[c+1][i];
                                            }
                                                for (i=0; i<5; i++)
                                            {
                                                tabela[c+1][i]=auxTabela[i];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    system("cls");
                    printf("Tabela:\n\n");
                    printf("%20s%4s%4s%4s%4s%4s\n", "Nome dos times", "Pts", "J", "V", "SG", "GM");
                    for (l=0;l<nTimes;l++)
                    {
                        printf("%20s", nomeTimes[l]);
                        for (c=0; c<5; c++)
                        {
                            printf("%4d", tabela[l][c]);
                        }
                        printf("\n");
                    }
                    printf("\n\n");
                    system("pause");
                }
                else
                {
                    if (menu == 4)
                    {
                        system("cls");
                        printf("Obrigado!\n\n");
                        system("pause");
                    }
                }
            }
        }
    } while (menu!=0);
}
