#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável cpf
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", nome "); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando nome do usuário
	scanf("%s",nome); //"%s" refere-se a string
	
	file = fopen(arquivo,"a"); //cria o arquivo e o "a" siginifca adicionar dados ou informações
	fprintf(file,nome); //salva o nome do usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", sobrenome ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando sobrenome do usuário
	scanf("%s",sobrenome); //"%s" refere-se a string
	
	file = fopen(arquivo,"a"); //cria o arquivo e o "a" siginifca adicionar dados ou informações
	fprintf(file,sobrenome); //salva o sobrenome do usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,", cargo ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando o cargo exercido pelo usuário
	scanf("%s",cargo); //"%s" refere-se a string
	
	file = fopen(arquivo,"a"); //cria o arquivo e o "a" siginifca adicionar dados ou informações
	fprintf(file,cargo); //salva o cargo do usuário
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela para o usuário visualisar a mensagem
}

int consulta() //Função responsável por consultar os usuários no sistema
{   
	setlocale(LC_ALL, "Portuguese"); //Definição de idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando o cpf a ser consultado
	scanf("%s",cpf); //"%s" refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo e o "r" signfica ler 
	
	if(file == NULL) //se o resultado da busca for nula
	{
		printf("Não foi possível abrir o arquivo, não foi localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto for diferente de nulo ele escreve
	{
		printf("\nEssas são as informações do usuário: "); //apresenta as informações do usuário desejado 
		printf("%s", conteudo);
		printf("\n\n"); 
	}
	
	system("pause"); //pausa a tela para o usuário visualisar a mensagem
}

int deletar() //Função responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando o cpf a ser deletado
	scanf("%s",cpf); //"%s" refere-se a string
	
	remove(cpf); //comando que remove o cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //cria o arquivo o e "r" significa ler
	
	if(file == NULL) //se o resultado da busca for nula
	{
		printf("O usuário não se encontra no sitema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definição de variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
	    
		setlocale(LC_ALL, "Portuguese"); //Definição de idioma
	
        printf("### Cartório da EBAC ###\n\n"); //início de menu
	    printf("Escolha a opção desejada do menu:\n\n"); //escolhas de menu
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Opção: "); //final de menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsável por limpar a tela
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada da função registro
		    break;
		    
		    case 2:
		    consulta(); //chamada da função consulta
		    break;
		    
		    case 3:
		    deletar(); //chamada da função deletar
		    break;
		    
		    default:
		    printf("Essa opcão não está disponivel!\n");
		    system("pause");
		    break;
		} //fim da seleção
    }
}
