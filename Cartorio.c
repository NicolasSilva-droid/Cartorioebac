#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", nome "); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usu�rio
	scanf("%s",nome); //"%s" refere-se a string
	
	file = fopen(arquivo,"a"); //cria o arquivo e o "a" siginifca adicionar dados ou informa��es
	fprintf(file,nome); //salva o nome do usu�rio
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", sobrenome ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando sobrenome do usu�rio
	scanf("%s",sobrenome); //"%s" refere-se a string
	
	file = fopen(arquivo,"a"); //cria o arquivo e o "a" siginifca adicionar dados ou informa��es
	fprintf(file,sobrenome); //salva o sobrenome do usu�rio
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", cargo ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando o cargo exercido pelo usu�rio
	scanf("%s",cargo); //"%s" refere-se a string
	
	file = fopen(arquivo,"a"); //cria o arquivo e o "a" siginifca adicionar dados ou informa��es
	fprintf(file,cargo); //salva o cargo do usu�rio
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela para o usu�rio visualisar a mensagem
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{   
	setlocale(LC_ALL, "Portuguese"); //Defini��o de idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando o cpf a ser consultado
	scanf("%s",cpf); //"%s" refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo e o "r" signfica ler 
	
	if(file == NULL) //se o resultado da busca for nula
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto for diferente de nulo ele escreve
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //apresenta as informa��es do usu�rio desejado 
		printf("%s", conteudo);
		printf("\n\n"); 
	}
	
	system("pause"); //pausa a tela para o usu�rio visualisar a mensagem
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando o cpf a ser deletado
	scanf("%s",cpf); //"%s" refere-se a string
	
	remove(cpf); //comando que remove o cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo o e "r" significa ler
	
	if(file == NULL) //se o resultado da busca for nula
	{
		printf("O usu�rio n�o se encontra no sitema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Defini��o de vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
	    
		setlocale(LC_ALL, "Portuguese"); //Defini��o de idioma
	
        printf("### Cart�rio da EBAC ###\n\n"); //in�cio de menu
	    printf("Escolha a op��o desejada do menu:\n\n"); //escolhas de menu
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Op��o: "); //final de menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //respons�vel por limpar a tela
	    
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada da fun��o registro
		    break;
		    
		    case 2:
		    consulta(); //chamada da fun��o consulta
		    break;
		    
		    case 3:
		    deletar(); //chamada da fun��o deletar
		    break;
		    
		    default:
		    printf("Essa opc�o n�o est� disponivel!\n");
		    system("pause");
		    break;
		} //fim da sele��o
    }
}
