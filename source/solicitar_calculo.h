int solicitar_calculo ()
//inicio da função para o usuario fazer a solicitação do calculo de suas nota
{
	
	char ShC[10], Cc[10];
	linha();	

	if ((av=fopen("pontuação.dat","ab+"))==NULL) //Abre o arquivo pontuação.dat ou cria caso não exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
					
	}
	printf("\nConfirme seu nome ---: ");
	gets(cadMonitor.moni.nomeCalcu);// guarda a confirmação do nome
	do // inicio do laço repita 
	{
		printf("\n\nConfirma a solicitacao [S/N] ?");
		gets(Cc);
		// inicio da condição para saber se a comparação de Cc com "s ou n" é igual a 0
		if ((strcmp(Cc,"s")!=0) && (strcmp(Cc,"S")!=0) && (strcmp(Cc,"n")!=0) && (strcmp(Cc,"N")!=0))
		{
			/*
			se a comparação for diferete de 0 executa as proximas instruções
			*/
	  		printf("\nOpcao invalida !!!");
		}
		else if	((strcmp(Cc,"s")==0) || (strcmp(Cc,"S")==0))
		{
	   		/*
			se a comparação for igual a 0 executa as proximas instruções
			*/
			fseek(av,0,SEEK_END);// posiciona no arquivo no final    
			fwrite(&cadMonitor,sizeof(struct monitor),1,av); 
			/*
			Grava os dados da estrutura "cadMonitor" no arquivo 
			&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
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
	// enquanto a comparação da variavel ShC com "s ou n" for diferente de 0 repete as instruções que se encontra dentro do laço 
	system("cls");             
		
}//fim da função para o usuario fazer a solicitação do calculo de suas nota
