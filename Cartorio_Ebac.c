#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
    //in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" sig. escrever
	fprintf(file,cpf); // salva o valor da vari�vel
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
	#include <locale.h> //biblioteca de aloca��es de texto por regi�o
	
    //in�cio da cria��o das vari�veis	
    char cpf[40];
    char conteudo[200];
    //fim da cria��o das variaveis

    printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");//abre o arquivo e o "r" sig. ler

    if(file == NULL)//" == " igual
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado\n");
    }

    while(fgets(conteudo, 200, file)!=NULL)// " != " diferente
    {
     	printf("\nEssas s�o as informa��es do usu�rio: ");
   	    printf("%s", conteudo);
	    printf("\n\n");
    }
  
        system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}

}


int main()

    {
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
				
		
       	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        printf("###Cart�rio da EBAC###\n\n"); // In�cio do menu
       	printf("Escolha a op��o desejada do menu:\n\n");
     	printf("\t1 - Registrar nomes \n");
       	printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n");
	    printf("\t4 - Sair do sistema \n");
    	printf("Op��o:"); //Fim do menu

	    scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
    	system("cls"); //respons�vel por limpar a tela
    	
    	switch(opcao)//in�cio da sele��o do menu
    	{
    		case 1:
			registro(); //chamada de fun��es
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
	      	printf("Essa op��o n�o est� disponivel!\n");
      		system("pause");
      		break;
      		
		}	//fim da sele��o
    }
	
}
