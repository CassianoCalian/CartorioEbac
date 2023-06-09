#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastras os clientes no sistema.
{
	
	//in�cio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da cria��o das vari�veis/string
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%S Refere-se as strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w");
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo , "a");
	fprintf (file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		char cpf[40];
		char conteudo[40];
		
		printf("Digite o CPF a ser consultado: \n");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("N�o foi poss�vel localizar o CPF informado. \n ");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\n Essas s�o as informa��es do usu�rio. ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file== NULL)
	{
		printf("Usu�rio n�o se encontra no invent�rio!  \n");
		system("pause"); // Respons�vel por que a p�gina pare e n�o atualize rapidamente.
		
	}
}


int main ()
{
	int opcao=0; // Definindo as Vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{

	system("cls");	
	
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("### Cart�rio da EBAC ### \n\n"); // In�cio do Menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opc�o: "); //Fim do Menu
	
	scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	system ("cls"); // Respons�vel por limpar a tela
	
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
		
		case 4:
		printf ("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf ("Essa op��o n�o esta dispon�vel!\n");
		system("pause");
		break;	
	}
}
}

