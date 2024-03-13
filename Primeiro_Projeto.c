#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings


int registro() // Função responsável por cadastrar os usuários no sistemas
{
    //inicia da criação de variaveis/STRING
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variaveis/STRING
    
	printf("Digite o cpf a ser cadastrado \n:"); //Coletando informações do usuário
	scanf("%s" ,cpf); // %s Refere-se ao string
    
    strcpy(arquivo, cpf); // responsável por copiar os valores das string
    
    FILE *file; // Cria arquivo
    file = fopen(arquivo, "w"); // Cria o aquivo e o "W" significa escrever
    fprintf(file, "CPF: ");
    fprintf(file, cpf); // salva o valor da variável
    fclose(file); // fecha arquivo
    
    file = fopen(arquivo, "a"); // O "a" Refere-se a adicionar/atualizar o arquivo
    fprintf(file, "\nNome: ");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: \n"); //Coletando informações do usuário
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\nSobrenome: ");
    fclose(file);
    
    printf(" Digite o sobrenome a ser cadastrado: \n"); //Coletando informações do usuário
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a"); 
    fprintf(file, "\nCargo:");
    fclose(file);
    
    printf("digite o cargo a ser cadastrado: \n "); //Coletando informações do usuário
    scanf("%s", cargo);
    
    file= fopen(arquivo, "a");
    fprintf(file, cargo);
    fprintf(file, "\n\n");
    fclose(file);
    
    system("pause"); // Pausa ou congela a tela durante uma escolha de opção
    
    
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
    char cpf [40];
    char conteudo[200];
    
    printf("digite o cpf a ser consultado: \n"); //Coletando informações do usuário
    scanf("%s", cpf);
    printf("\n");
    
    FILE *file;
    file = fopen(cpf, "r");
    
    
    if(file == NULL)
    {
    	printf (" Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	printf("Essas são as informações do usuário: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		 
		printf("%s", conteudo);	
	}
	
	system("pause");
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite cpf do usuário a ser deletado: "); //Coletando informações do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	printf("Usuário Deletado com sucesso!"); //Coletando informações do usuário
	printf("\n\n");
	system("pause");
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usuário não se encontra no sistema!.\n"); //Coletando informações do usuário
		system("pause");
	}
	
	}



int main()
{
    int opcao=0;//definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
	{
	         
	    system ("cls"); // Responsavel por limpar a tela
	    setlocale(LC_ALL, "portuguese"); //Definição de linguagem

       	printf (" >>> Cartório EBAC <<<\n\n");
     	printf (" Escolha uma das opções a seguir:\n\n"); //Inicio Do Menu
        printf (" \t1 - Registrar usuário\n");
     	printf (" \t2 - Consultar usuário\n");
     	printf (" \t3 - Deletar usuário\n");//Fim do menu
     	printf ("Opção:");
  	  
     	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    	system("cls"); 
	
    	switch(opcao) // Inicio da seleção do meno
	{
	
	    case 1:
		registro(); // Chamada de funções
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
			
	    default:
	    printf("Essa opção não está disponível!\n"); 
		system("pause");
		break;
	}            //Fim da seleção	
    

}
	
}
	
	

