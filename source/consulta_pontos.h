int consulta_pontos(TcadUsu dados)
{
	//função para o monitor consulta seus pontos
	int   i;
	int o;
	char nome[50];
	int achou =-1;
	
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
			
	}
			
	system("cls");		
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	
	printf("\nConfirme seu nome para procurar seus pontos\n");
	gets(nome); // guarda a confirmação 
	
	
	fseek(arq,0,SEEK_SET);    // posiciona o arquivo no inicio
	
	fflush(stdin);
  	do
	{
		system("cls");
		linha();
		printf("\n-------------------------------------------------\n");
		printf("1 - Solicitar calculo das notas\n");
		printf("2 - Verificar resultado da solicitacao do calculo\n");
		printf("3 - Consulta suas notas\n\n");
		printf("4 - Volta ao menu principal");
		printf("\n-------------------------------------------------\n");
		printf("Digite a opcao: [ ]\b\b");
		o=getche();// le a opção digitada pelo usuario
		fflush(stdin);
		switch (o) // inicio do escolha disbonibilizado para o usuario
		{
			case '1': // solicitar os casos da nota
				system("cls");
				solicitar_calculo(); // retorna a função onde contem as instruções para calcular a nota
				break;
			case '2':// verificar resultado da solicitação
				system("cls");
				verificar_hrs(); // retorna a função onde contém as intruções para verificar o resultado da solicitação
				break;
			case '3':
				system("cls");
				
				do 
			  	{	
					fread(&dados, sizeof(struct nUsuario), 1, arq);	// le registro
							
					
			    	printf("\n\t##LISTAMOS TODAS AS SUAS NOTAS ABAIXO ###\n");
					printf("------------------------------------------------------------------------------");			
					printf ("\nDISCIPLINA\t\tNOTA DA MONITORIA") ;	
					printf("\n------------------------------------------------------------------------------");	
					while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // laço para ler a região de memoria enquanto a total de unidade for igual 1 
					{
						/*
						&cadAluno = é a região de memoria na qual serão armazenados os dados lidos
						sizeof = o tamanho da unidade a ser lida
						1 = total de unidades a ser lida
						file = ponteiro para o arquivo
						*/
							
						if((strcmp(nome, cadUsu.nome) == 0))
						{
						
							printf ("\n%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.nota) ;
							/*	
							mostra todas as disciplinas cadastradas como os respectivos nomes que à cadastrou	  	  		
							*/
						}
							
						i++; 		
				   } // fim do laço para ler a região de memoria &cadAluno
					printf("\n-----------------------------fim----------------------------------------------\n");
					system("pause"); // pausa o programa
							
				} while (feof(arq));// se a busca chegou ao fim, para 
			   
			   	break;
			case '4':
				break;
				default:
				printf("\n\tEscolha invalida! Por favor, escolha novamente.");			
		}
				
		system("cls");
	}while(o!='4');
	fclose(resu);
	
	
	
}
