#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o  de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de tezto por regi�o
#include <string.h> // biblioteca responsavel pelas strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//termino da cria��o das variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��es do usuario
	scanf("%s", cpf); // %s refere-se as strings
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // escreve o arquivo
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file, "CPF: "); // escreve categoria 
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  // atualiza o arquivo
	fprintf(file, "\nNome: "); // escreve categoria 
	fclose(file);  // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informa��es do usuario
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");  // atualiza o arquivo
	fprintf(file,nome);
	fprintf(file, "\nSobrenome: "); // escreve categoria 
	fclose(file);  // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");   // Coletando informa��es do usuario
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,sobrenome);
	fprintf(file, "\nCargo: "); // escreve categoria 
	fclose(file);   // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");   // Coletando informa��es do usuario
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");   // atualiza o arquivo
	fprintf(file,cargo);
	fclose(file);   // fecha o arquivo
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // defindo a linguagem
	
		//inicio da cria��o das variaveis/string
	char cpf[40];
	char conteudo[200];
	//termino da cria��o das variaveis/string
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��es do usuario
	scanf("%s",cpf);
	printf("\nEssas s�o as informa��es do usu�rio: \n");
	
	FILE * file;
	file = fopen(cpf,"r"); //l� o arquivo
	

	if(file == NULL)
	{
		printf("CPF n�o cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	    
		printf("%s", conteudo);
		printf("\n\n");
				
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); // defindo a linguagem
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema!");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
	}
	system("pause");
	}
	

int main()
{
	int opcao=0; // definindo variaveis
    int x=1;
    
    char Usuario [10]="a";
    char Senha [10]="b";
    int comparacao;
    
    printf("###Cart�rio da EBAC###\n\n");
    printf("Digite seu usuario: ");
     scanf("%s",Usuario);
    printf("\nDigite sua senha: ");
    scanf("%s",Senha);

    comparacao = strcmp(Usuario,"admin");
    comparacao = strcmp(Senha,"admin");
    
    if(comparacao == 0)
    {
	
    
   		for (x=1;x=1;)// definindo repeti��o
		{
		 system("cls");
	 
		setlocale(LC_ALL, "Portuguese"); // defindo a linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); // Inicio do menu
		printf("\tBem-Vindo!\n\n");
		printf("Escolha a op��o desejada\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls");
	
		switch(opcao) // inicio da sele��o
		{case 1:
		 registro();
    	 break;
     
		case 2:
		 consulta();
		 break;
		
		case 3:
		 deletar();
		 break;
		 
		 case 4:
		 printf("Obrigado por utilizar o sistema!\n");
		 return 0;
		 break;
	 
 		
		default:
		printf("Op��o Invalida!\n");
		system("pause");	
		break;} // fim da sele��o
		}
	}
	else 
		printf("Usuario ou senha incorretos!");
}
	


