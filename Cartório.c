#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação das variareis/string
	
	setlocale(LC_ALL,"Portuguese_Brasil.1252"); //para definifir o dicionário
	
	char arquivo[40]; //aqui vai copiar o valor de CPF
	char cpf[40]; //40 é o número máximo de caracteres - dificil um nome ter mais do que 40 letras, 40 variaveis etc
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação das variaveis
	
	printf("Digite o CPF do usuário que deseja cadastrar:\n");
	
	scanf("%s", cpf); // vai armazenar tudo dentro da string
	
	strcpy(arquivo, cpf); //string copy - responsavel por copiar os arquivos das strings para o cliente não precisar ficar digitando a mesma coisa várias vezes
	//aqui está arquivo e cpf porque os dois precisam se igualar, se não o usuario tem que saber o numero de arquivo, o que nao faz sentido
	
	FILE *file; //cria o arquivo - aqui estamos chamando um FILE que ja existe na biblioteca e criando, esse nome é padrão. Qual arquivo? o file.
	file = fopen(arquivo, "w"); //do que é composto o file? abra crie um arquivo que esta dentro da variavel arquivo, que é novo por tanto W = write
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //ao invés de passar para o usuário ele esta salvando dentro do arquivo - salvo o valor da variavel 
	fclose(file); //fecha o arquivo	
	
	//o próximo começa aqui
	file = fopen(arquivo, "a"); //aqui ele esta abrindo um arquivo que foi salvo - "a" é  porque quero atualizar a informação, quero acessar o arquivo que foi salvo e colocar mais informações nele
	fprintf(file,", \nNome: "); //para salvar e por uma virgula
	fclose(file);
	
	printf("Qual o primeiro nome do usuário? \n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abrir o arquivo fechado, atualizado
	fprintf(file,nome); //salvando o conteudo nome dentro do mesmo arquivo
	fclose(file);
	//
	file = fopen(arquivo, "a"); 
	fprintf(file,", \nSobrenome: "); //para salvar e por uma virgula
	fclose(file);
	
	printf("Qual o sobrenome do usuário? \n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abra aquele arquivo e atualize ele com o sobrenome
	fprintf(file,sobrenome); 
	fclose(file);
	//
	file = fopen(arquivo, "a"); 
	fprintf(file,", \nCargo: "); //para salvar e por uma virgula
	fclose(file);
	
	printf("Qual o cargo do usuário cadastrado? \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,".\n");
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese_Brasil.1252"); //para definifir o dicionário
	
	char cpf [40];
	char conteudo [200];
	
	printf("Qual CPF deseja consultar? Escreva e aperte enter. \n\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não localizado.\n");
		system("pause");
		return 0;
	}
	
		printf("\nEssas são as informações do usuário: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //para definifir o dicionário
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usuário não localizado.\n");
		system("pause");
		return 0;
	}
			
	printf("Ok, Usúario deletado. \n");
	system("pause");
	
	fclose(file);
	
}

int main() //função principal
{
	int opcao=0; //Definindo variáveis - aqui não pode por acentos, nos comandos
	
	int laco=1;
	
	for(laco=1;laco=1;) //enquanto o cliente não clicar em sair o programa continua se repetindo a cada ação, se colocar laco=1;laco=10 ele vai parar na decima vez
	{ //inicio da repetição do cliente a cada vez que finalizar algo  
		
		system("cls"); //responsavel por limpar a tela
		
	 	setlocale(LC_ALL, "Portuguese"); //para definifir o dicionário
	 
	 	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	 	printf("O que faremos hoje?!\n\n");
	 	printf("\t1 - Registrar nomes\n");
	 	printf("\t2 - Consultar nomes\n");
	 	printf("\t3 - Deletar nomes\n");
	 	printf("\t4 - Sair do sistema\n\n");
	 	printf("Opção:"); //fim do menu
	 
		scanf("%d", &opcao); //aqui vamos scanear o que o usuário coloca, para ele poder responder

		system("cls"); //função de limpar a tela
		
		switch(opcao) //inicio da seleção de opções
		{
			case 1: // "caso a opção for 1"
			registrar(); //chamada de funções
	 		break;
	 		
	 		case 2:
	 		consultar();
			break;
			 
			case 3:	
			deletar();
			break;
			
			case 4:
			printf("Até breve, sorria e tenha um dia delicioso!\n");
			return 0;
			break;
			
			default:
			printf("Opa! Opção não disponível! Tente novamente!\n"); 
			system("pause");
			break;
		}
    }
}


