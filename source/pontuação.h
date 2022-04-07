
int pontuacao ()
// inicio da fun��o para o administrador ver as pontua��o que cada monitor recebeu
{
	
	int i, ii;
	char ShC[10];
	char nome[50];
	int achou=-1;
	
	if ((resu=fopen("avalia��o.dat","ab+"))==NULL) //Abre o arquivo avalia��o.dat ou cria caso n�o exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
			
	}
	
		printf("\n\t### LISTAMOS TODAS AS NOTAS AVALIADA NO SISTEMA ABAIXO ###\n");
			
		printf("------------------------------------------------------------------------------");			
		printf ("\nDISCIPLINA\t\tNOME DO MONITOR\t\tNOTA DA MONITORIA") ;	
		printf("\n------------------------------------------------------------------------------");		
				
		while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // la�o para ler a regi�o de memoria enquanto a total de unidade for igual 1
		{
			/*
			&cadMonitor = � a regi�o de memoria na qual ser�o armazenados os dados lidos
			sizeof = o tamanho da unidade a ser lida
			1 = total de unidades a ser lida
			resu = ponteiro para o arquivo
			*/	
			printf ("\n%s\t\t\t%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.ava, cadMonitor.moni.nota) ;	
			/*
			amostra todas as pontua��es que tem cadastrada no sistema
			*/
			i++;
		
			
		}
		printf("\n-----------------------------fim----------------------------------------------\n");
		fclose(resu);
		do // inicio do la�o repita
		{
			printf("\n\nDeseja verificar se algum monitor solicitou o calculo dos pontos ? [S/N] ?");
			gets(ShC);
			// inicio da condi��o para saber se a compara��o de ShC com "s ou n" � igual a 0
			if ((strcmp(ShC,"s")!=0) && (strcmp(ShC,"S")!=0) && (strcmp(ShC,"n")!=0) && (strcmp(ShC,"N")!=0))
			{
				/*
				se a compara��o for diferete de 0 executa as proximas instru��es
				*/
				printf("\nOpcao invalida !!!");
			}
			else if	((strcmp(ShC,"s")==0) || (strcmp(ShC,"S")==0))
			{
				/*
				se a compara��o for igual a 0 executa as proximas instru��es
				*/
				system("cls");
				linha();// retorna a fun��o do cabe�ario
				if ((av=fopen("pontua��o.dat","ab+"))==NULL) //Abre o arquivo pontua��o.dat ou cria caso n�o exista.
				{
					// se a compara��o for difente de NULL executa as proximas instru�oes dessa condi��o
					printf("O arquivo de DADOS nao pode ser aberto!");
						
				}// fim da verifica��o 
				printf("\n\t### SOLICITACAO DE CALCULO DE PONTUACAO ###\n");
				printf("\n------------------------------------------------------------------------------");			
				printf ("\nNOME DO MONITOR QUE SOLICITOU O CALCULO DA PONTUACAO");	
				printf("\n------------------------------------------------------------------------------\n");	
				while(fread(&cadMonitor,sizeof(cadMonitor),1,av)==1) // la�o para ler a regi�o de memoria enquanto a total de unidade for igual 1
				{
					/*
					&cadMonitor = � a regi�o de memoria na qual ser�o armazenados os dados lidos
					sizeof = o tamanho da unidade a ser lida
					1 = total de unidades a ser lida
					resu = ponteiro para o arquivo
					*/	
					printf ("%s\n", cadMonitor.moni.nomeCalcu) ;
					// mostra o nome do monitor que solicitou o calculo da pontua��o
					ii++;
				}
				printf("\n-----------------------------fim----------------------------------------------\n");
				
				calcular_pontMonitor(cadMonitor); // retorna a fun��o que calcula os pontos do monitor								
			}
								
		} while ((strcmp(ShC,"s")!=0) && (strcmp(ShC,"S")!=0) && (strcmp(ShC,"n")!=0) && (strcmp(ShC,"N")!=0));	
		// enquanto a compara��o da variavel ShC com "s ou n" for diferente de 0 repete as instru��es que se encontra dentro do la�o		
		system("pause");	
		

}// fim da fun��o para o administrador ver as pontua��o que cada monitor recebeu
