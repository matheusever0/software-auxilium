
int pontuacao ()
// inicio da função para o administrador ver as pontuação que cada monitor recebeu
{
	
	int i, ii;
	char ShC[10];
	char nome[50];
	int achou=-1;
	
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo avaliação.dat ou cria caso não exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
			
	}
	
		printf("\n\t### LISTAMOS TODAS AS NOTAS AVALIADA NO SISTEMA ABAIXO ###\n");
			
		printf("------------------------------------------------------------------------------");			
		printf ("\nDISCIPLINA\t\tNOME DO MONITOR\t\tNOTA DA MONITORIA") ;	
		printf("\n------------------------------------------------------------------------------");		
				
		while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // laço para ler a região de memoria enquanto a total de unidade for igual 1
		{
			/*
			&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
			sizeof = o tamanho da unidade a ser lida
			1 = total de unidades a ser lida
			resu = ponteiro para o arquivo
			*/	
			printf ("\n%s\t\t\t%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.ava, cadMonitor.moni.nota) ;	
			/*
			amostra todas as pontuações que tem cadastrada no sistema
			*/
			i++;
		
			
		}
		printf("\n-----------------------------fim----------------------------------------------\n");
		fclose(resu);
		do // inicio do laço repita
		{
			printf("\n\nDeseja verificar se algum monitor solicitou o calculo dos pontos ? [S/N] ?");
			gets(ShC);
			// inicio da condição para saber se a comparação de ShC com "s ou n" é igual a 0
			if ((strcmp(ShC,"s")!=0) && (strcmp(ShC,"S")!=0) && (strcmp(ShC,"n")!=0) && (strcmp(ShC,"N")!=0))
			{
				/*
				se a comparação for diferete de 0 executa as proximas instruções
				*/
				printf("\nOpcao invalida !!!");
			}
			else if	((strcmp(ShC,"s")==0) || (strcmp(ShC,"S")==0))
			{
				/*
				se a comparação for igual a 0 executa as proximas instruções
				*/
				system("cls");
				linha();// retorna a função do cabeçario
				if ((av=fopen("pontuação.dat","ab+"))==NULL) //Abre o arquivo pontuação.dat ou cria caso não exista.
				{
					// se a comparação for difente de NULL executa as proximas instruçoes dessa condição
					printf("O arquivo de DADOS nao pode ser aberto!");
						
				}// fim da verificação 
				printf("\n\t### SOLICITACAO DE CALCULO DE PONTUACAO ###\n");
				printf("\n------------------------------------------------------------------------------");			
				printf ("\nNOME DO MONITOR QUE SOLICITOU O CALCULO DA PONTUACAO");	
				printf("\n------------------------------------------------------------------------------\n");	
				while(fread(&cadMonitor,sizeof(cadMonitor),1,av)==1) // laço para ler a região de memoria enquanto a total de unidade for igual 1
				{
					/*
					&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
					sizeof = o tamanho da unidade a ser lida
					1 = total de unidades a ser lida
					resu = ponteiro para o arquivo
					*/	
					printf ("%s\n", cadMonitor.moni.nomeCalcu) ;
					// mostra o nome do monitor que solicitou o calculo da pontuação
					ii++;
				}
				printf("\n-----------------------------fim----------------------------------------------\n");
				
				calcular_pontMonitor(cadMonitor); // retorna a função que calcula os pontos do monitor								
			}
								
		} while ((strcmp(ShC,"s")!=0) && (strcmp(ShC,"S")!=0) && (strcmp(ShC,"n")!=0) && (strcmp(ShC,"N")!=0));	
		// enquanto a comparação da variavel ShC com "s ou n" for diferente de 0 repete as instruções que se encontra dentro do laço		
		system("pause");	
		

}// fim da função para o administrador ver as pontuação que cada monitor recebeu
