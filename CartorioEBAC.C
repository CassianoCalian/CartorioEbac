#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastras os clientes no sistema.
{
	
	//início da criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da criação das variáveis/string
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%S Refere-se as strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w");
	fprintf(file, cpf); //salva o valor da variável
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
			printf("Não foi possível localizar o CPF informado. \n ");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\n Essas são as informações do usuário. ");
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
		printf("Usuário não se encontra no inventário!  \n");
		system("pause"); // Responsável por que a página pare e não atualize rapidamente.
		
	}
}


int main ()
{
	int opcao=0; // Definindo as Variáveis
	int x=1;
	
	for(x=1;x=1;)
	{

	system("cls");	
	
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("### Cartório da EBAC ### \n\n"); // Início do Menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opcão: "); //Fim do Menu
	
	scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	system ("cls"); // Responsável por limpar a tela
	
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
		printf ("Essa opção não esta disponível!\n");
		system("pause");
		break;	
	}
}
}

