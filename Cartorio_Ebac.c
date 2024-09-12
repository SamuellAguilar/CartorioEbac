#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//função responsável por cadastrar os usuários no sistema
{
    //início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" sig. escrever
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" usado para adicionar, atualizar
	fprintf(file,", ");
	fclose(file);
	
    printf("Digite o nome a ser Cadastratado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser Cadastratado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	

	
	system("pause");
	
}

int consulta()
{
	#include <locale.h> //biblioteca de alocações de texto por região
	
    //início da criação das variáveis	
    char cpf[40];
    char conteudo[200];
    //fim da criação das variaveis

    printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");//abre o arquivo e o "r" sig. ler

    if(file == NULL)//" == " igual
    {
    	printf("Não foi possível abrir o arquivo, não localizado\n");
    }

    while(fgets(conteudo, 200, file)!=NULL)// " != " diferente
    {
     	printf("\nEssas são as informações do usuário: ");
   	    printf("%s", conteudo);
	    printf("\n\n");
    }
  
        system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}

}


int main()

    {
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
				
		
       	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        printf("###Cartório da EBAC###\n\n"); // Início do menu
       	printf("Escolha a opção desejada do menu:\n\n");
     	printf("\t1 - Registrar nomes \n");
       	printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n\n");
    	printf("Opção:"); //Fim do menu

	    scanf("%d" , &opcao); //armazenando a escolha do usuário
	
    	system("cls"); //responsável por limpar a tela
    	
    	switch(opcao)//início da seleção do menu
    	{
    		case 1:
			registro(); //chamada de funções
	        break;
	        
	        case 2:
			consulta();
		    break;
		    
		    case 3:
		    deletar();
	      	break;
	      	
	      	default:
	      	printf("Essa opção não está disponivel!\n");
      		system("pause");
      		break;
      		
		}	//fim da seleção
    }
	
}
