#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings


int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistemas
{
    //inicia da cria��o de variaveis/STRING
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de variaveis/STRING
    
	printf("Digite o cpf a ser cadastrado \n:"); //Coletando informa��es do usu�rio
	scanf("%s" ,cpf); // %s Refere-se ao string
    
    strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
    
    FILE *file; // Cria arquivo
    file = fopen(arquivo, "w"); // Cria o aquivo e o "W" significa escrever
    fprintf(file, "CPF: ");
    fprintf(file, cpf); // salva o valor da vari�vel
    fclose(file); // fecha arquivo
    
    file = fopen(arquivo, "a"); // O "a" Refere-se a adicionar/atualizar o arquivo
    fprintf(file, "\nNome: ");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: \n"); //Coletando informa��es do usu�rio
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\nSobrenome: ");
    fclose(file);
    
    printf(" Digite o sobrenome a ser cadastrado: \n"); //Coletando informa��es do usu�rio
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a"); 
    fprintf(file, "\nCargo:");
    fclose(file);
    
    printf("digite o cargo a ser cadastrado: \n "); //Coletando informa��es do usu�rio
    scanf("%s", cargo);
    
    file= fopen(arquivo, "a");
    fprintf(file, cargo);
    fprintf(file, "\n\n");
    fclose(file);
    
    system("pause"); // Pausa ou congela a tela durante uma escolha de op��o
    
    
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
    char cpf [40];
    char conteudo[200];
    
    printf("digite o cpf a ser consultado: \n"); //Coletando informa��es do usu�rio
    scanf("%s", cpf);
    printf("\n");
    
    FILE *file;
    file = fopen(cpf, "r");
    
    
    if(file == NULL)
    {
    	printf (" N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	printf("Essas s�o as informa��es do usu�rio: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		 
		printf("%s", conteudo);	
	}
	
	system("pause");
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite cpf do usu�rio a ser deletado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf);
	
	remove(cpf);
	printf("Usu�rio Deletado com sucesso!"); //Coletando informa��es do usu�rio
	printf("\n\n");
	system("pause");
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usu�rio n�o se encontra no sistema!.\n"); //Coletando informa��es do usu�rio
		system("pause");
	}
	
	}



int main()
{
    int opcao=0;//definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
	{
	         
	    system ("cls"); // Responsavel por limpar a tela
	    setlocale(LC_ALL, "portuguese"); //Defini��o de linguagem

       	printf (" >>> Cart�rio EBAC <<<\n\n");
     	printf (" Escolha uma das op��es a seguir:\n\n"); //Inicio Do Menu
        printf (" \t1 - Registrar usu�rio\n");
     	printf (" \t2 - Consultar usu�rio\n");
     	printf (" \t3 - Deletar usu�rio\n");//Fim do menu
     	printf ("Op��o:");
  	  
     	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls"); 
	
    	switch(opcao) // Inicio da sele��o do meno
	{
	
	    case 1:
		registro(); // Chamada de fun��es
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
			
	    default:
	    printf("Essa op��o n�o est� dispon�vel!\n"); 
		system("pause");
		break;
	}            //Fim da sele��o	
    

}
	
}
	
	

