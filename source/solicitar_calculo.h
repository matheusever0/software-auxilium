int solicitar_calculo ()
//inicio da fun��o para o usuario fazer a solicita��o do calculo de suas nota
{
	
	char ShC[10], Cc[10];
	linha();	

	if ((av=fopen("pontua��o.dat","ab+"))==NULL) //Abre o arquivo pontua��o.dat ou cria caso n�o exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
					
	}
	printf("\nConfirme seu nome ---: ");
	gets(cadMonitor.moni.nomeCalcu);// guarda a confirma��o do nome
	do // inicio do la�o repita 
	{
		printf("\n\nConfirma a solicitacao [S/N] ?");
		gets(Cc);
		// inicio da condi��o para saber se a compara��o de Cc com "s ou n" � igual a 0
		if ((strcmp(Cc,"s")!=0) && (strcmp(Cc,"S")!=0) && (strcmp(Cc,"n")!=0) && (strcmp(Cc,"N")!=0))
		{
			/*
			se a compara��o for diferete de 0 executa as proximas instru��es
			*/
	  		printf("\nOpcao invalida !!!");
		}
		else if	((strcmp(Cc,"s")==0) || (strcmp(Cc,"S")==0))
		{
	   		/*
			se a compara��o for igual a 0 executa as proximas instru��es
			*/
			fseek(av,0,SEEK_END);// posiciona no arquivo no final    
			fwrite(&cadMonitor,sizeof(struct monitor),1,av); 
			/*
			Grava os dados da estrutura "cadMonitor" no arquivo 
			&cadMonitor = � a regi�o de memoria na qual ser�o armazenados os dados lidos
			sizeof = o tamanho da unidade a ser lida
			1 = total de unidades a ser lida
			av = ponteiro para o arquivo 
			*/
			printf("Sua solicitacao foi realizada com sucesso\n");
			printf("o prazo para resposta e de ate 3 dias.\n\n");									    
		}	
	   	else
		{
	  		printf("\nDados nao foi salvo !\n");					  
		}                    
			
	} while ((strcmp(Cc,"s")!=0) && (strcmp(Cc,"S")!=0) && (strcmp(Cc,"n")!=0) && (strcmp(Cc,"N")!=0));
	// enquanto a compara��o da variavel ShC com "s ou n" for diferente de 0 repete as instru��es que se encontra dentro do la�o 
	system("cls");             
		
}//fim da fun��o para o usuario fazer a solicita��o do calculo de suas nota
