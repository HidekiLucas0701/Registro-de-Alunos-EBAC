#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar das string-comando em fileiras

int registro()

{
    //in�cio da cria��o de vari�veis/string
    char pause;

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo [40];
    //fim da cria��o de vari�veis/string

    printf("Digite o CPF a ser cadastrado:"); //coletando dados do cliente
    scanf("%s",cpf); //%s significa salvar na string

    strcpy(arquivo, cpf); //reppons�vel por copiar o valor das strings

    FILE*file; //cria o arquivo
    file = fopen(arquivo,"w"); //abrir arquivo e "w" para escrever
    fprintf(file,cpf); //salvar valor da avel igual ao do CPF da pessoa
    fclose(file); //fechar arquvio

    file = fopen(arquivo,"a"); //"a" serve para atualizar uma informa��o
    fprintf(file, ",\n");
    fclose(file);

    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",\n");
    fclose(file);

    printf("Digite o nome a ser cadastrado:");
    scanf("%s",sobrenome);

    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",\n");
    fclose(file);

    printf("Digite o cargo a ser cadastrado:");
    scanf("%s",cargo);

    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    pause = getchar();



}

int consulta()
{
    setlocale(LC_ALL,"pt_BR_UTF-8");
    char pause;

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:");
    scanf("%s", cpf);

    FILE*file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        pause = getchar();
        printf("Este usu�rio n�o est� dispon�vel ou ainda n�o foi cadastrado!\n");
        pause = getchar();
        return 0;
    }

    pause = getchar();

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\n Essas s�o as informa��es do usu�rio:");
        printf("%s", conteudo);
        printf("\n\n");
    }
    pause = getchar();
}

int deletar()
{
    setlocale(LC_ALL,"pt_BR_UTF-8");
    char pause;

    char cpf[40];

    printf("Digite o CPF do usu�rio a ser deletado:");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file != NULL)
    {
        pause = getchar();
        fclose(file);
        remove(cpf);
        printf("Usu�rio deletado com sucesso!\n");
        pause = getchar();
    }

    else
    {
        pause = getchar();
        printf("Este usu�rio n�o se encontra no sistema!\n");
        pause = getchar();
    }
}
int main()
{
    int opcao=0; //definindo vari�vel
    int reset=1;

    for(reset=1;reset=1;) //
    {
        system("clear");
        char pause;

        setlocale(LC_ALL,"pt_BR_UTF-8");
        //definindo o idioma, para o sistema entender a acentua��o


        printf("\t<<<<< CART�RIO EBAC >>>>>\n\n"); //in�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar Novo Aluno\n");
        printf("\t2 - Consultar Lista de Alunos\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��o:"); //fim do menu

        scanf("%d",&opcao); //armazenar a escolha do usu�rio
        system("clear"); //limpar p�gina ap�s comando

        switch(opcao)
        {
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            default:
            pause = getchar();
            printf("Essa op��o n�o est� dispon�vel!\n");
            pause = getchar();
            break;
        }//fim da sele��o
    }
}
