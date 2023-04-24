#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio da cria��o das variareis/string
	
	setlocale(LC_ALL,"Portuguese_Brasil.1252"); //para definifir o dicion�rio
	
	char arquivo[40]; //aqui vai copiar o valor de CPF
	char cpf[40]; //40 � o n�mero m�ximo de caracteres - dificil um nome ter mais do que 40 letras, 40 variaveis etc
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o das variaveis
	
	printf("Digite o CPF do usu�rio que deseja cadastrar:\n");
	
	scanf("%s", cpf); // vai armazenar tudo dentro da string
	
	strcpy(arquivo, cpf); //string copy - responsavel por copiar os arquivos das strings para o cliente n�o precisar ficar digitando a mesma coisa v�rias vezes
	//aqui est� arquivo e cpf porque os dois precisam se igualar, se n�o o usuario tem que saber o numero de arquivo, o que nao faz sentido
	
	FILE *file; //cria o arquivo - aqui estamos chamando um FILE que ja existe na biblioteca e criando, esse nome � padr�o. Qual arquivo? o file.
	file = fopen(arquivo, "w"); //do que � composto o file? abra crie um arquivo que esta dentro da variavel arquivo, que � novo por tanto W = write
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //ao inv�s de passar para o usu�rio ele esta salvando dentro do arquivo - salvo o valor da variavel 
	fclose(file); //fecha o arquivo	
	
	//o pr�ximo come�a aqui
	file = fopen(arquivo, "a"); //aqui ele esta abrindo um arquivo que foi salvo - "a" �  porque quero atualizar a informa��o, quero acessar o arquivo que foi salvo e colocar mais informa��es nele
	fprintf(file,", \nNome: "); //para salvar e por uma virgula
	fclose(file);
	
	printf("Qual o primeiro nome do usu�rio? \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abrir o arquivo fechado, atualizado
	fprintf(file,nome); //salvando o conteudo nome dentro do mesmo arquivo
	fclose(file);
	//
	file = fopen(arquivo, "a"); 
	fprintf(file,", \nSobrenome: "); //para salvar e por uma virgula
	fclose(file);
	
	printf("Qual o sobrenome do usu�rio? \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abra aquele arquivo e atualize ele com o sobrenome
	fprintf(file,sobrenome); 
	fclose(file);
	//
	file = fopen(arquivo, "a"); 
	fprintf(file,", \nCargo: "); //para salvar e por uma virgula
	fclose(file);
	
	printf("Qual o cargo do usu�rio cadastrado? \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,".\n");
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese_Brasil.1252"); //para definifir o dicion�rio
	
	char cpf [40];
	char conteudo [200];
	
	printf("Qual CPF deseja consultar? Escreva e aperte enter. \n\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o localizado.\n");
		system("pause");
		return 0;
	}
	
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //para definifir o dicion�rio
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usu�rio n�o localizado.\n");
		system("pause");
		return 0;
	}
			
	printf("Ok, Us�ario deletado. \n");
	system("pause");
	
	fclose(file);
	
}

int main() //fun��o principal
{
	int opcao=0; //Definindo vari�veis - aqui n�o pode por acentos, nos comandos
	
	int laco=1;
	
	for(laco=1;laco=1;) //enquanto o cliente n�o clicar em sair o programa continua se repetindo a cada a��o, se colocar laco=1;laco=10 ele vai parar na decima vez
	{ //inicio da repeti��o do cliente a cada vez que finalizar algo  
		
		system("cls"); //responsavel por limpar a tela
		
	 	setlocale(LC_ALL, "Portuguese"); //para definifir o dicion�rio
	 
	 	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	 	printf("O que faremos hoje?!\n\n");
	 	printf("\t1 - Registrar nomes\n");
	 	printf("\t2 - Consultar nomes\n");
	 	printf("\t3 - Deletar nomes\n");
	 	printf("\t4 - Sair do sistema\n\n");
	 	printf("Op��o:"); //fim do menu
	 
		scanf("%d", &opcao); //aqui vamos scanear o que o usu�rio coloca, para ele poder responder

		system("cls"); //fun��o de limpar a tela
		
		switch(opcao) //inicio da sele��o de op��es
		{
			case 1: // "caso a op��o for 1"
			registrar(); //chamada de fun��es
	 		break;
	 		
	 		case 2:
	 		consultar();
			break;
			 
			case 3:	
			deletar();
			break;
			
			case 4:
			printf("At� breve, sorria e tenha um dia delicioso!\n");
			return 0;
			break;
			
			default:
			printf("Opa! Op��o n�o dispon�vel! Tente novamente!\n"); 
			system("pause");
			break;
		}
    }
}


