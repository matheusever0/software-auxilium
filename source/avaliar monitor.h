int avaliar_monitor()
//inicio da função para o aluno avaliar o monitor
{
	
	int i=1;
	char op, C[20];
    
    if ((fp=fopen("monitorar.dat","ab+"))==NULL) //Abre o arquivo monitorar.dat ou cria caso não exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	if ((arq=fopen("usuario.dat","ab+"))==NULL) //Abre o usuario.dat ou cria caso não exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(fp,0,SEEK_SET);    // posiciona o arquivo no inicio
	fseek(arq,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	printf ("\n\t\t### LISTA DE MONITORES ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nMONITOR\t\t\tDISCIPLINA") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadMonitor,sizeof(cadMonitor),1,fp)==1) // le a struct cadAluno 
	{
		/*
		&cadAluno = é a região de memoria na qual serão armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/	
		if((strcmp(cadUsu.nome, cadMonitor.moni.confiNome) != 0))
		{
			/*
			se a comparação for igual diferente de 0 so vai mostra as monitorias do usuario que 
			o nome seja diferente do nome do usuario que esta logado e
			executa as proximas instruções dessa condição
			*/
			printf ("\n%s\t\t\t%s",cadMonitor.moni.confiNome, cadMonitor.moni.confiMateria) ;	
			// mostra o nome do monitor e a disciplina	  	  		
		
			i++;
		}
    }
	printf("\n-----------------------------fim----------------------------------------------\n");
	fclose(fp);
	
	
	
	
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	printf("Digite o nome do monitor que voce deseja avaliar\n");
	fflush(stdin);
	gets(cadMonitor.moni.ava); //guarda o nome do monitor que vai avaliar
	
	
	printf("Qual foi a disciplina que voce recebeu monitoria ?\n");
	fflush(stdin);
	gets(cadMonitor.moni.amo); // guarda a disciplina que voce foi monitorado
	
	printf("Nota da monitoria [0/10]\n");
	fflush(stdin);
	gets(cadMonitor.moni.nota); // guarda a nota da sua avaliação
	do 
	{
		printf("\n\nConfirma sua avaliacao [S/N] ?");
		gets(C);
		// inicio da condição para saber se a comparação de C com "s ou n" é igual a 0
		if ((strcmp(C,"s")!=0) && (strcmp(C,"S")!=0) && (strcmp(C,"n")!=0) && (strcmp(C,"N")!=0))
		{
			/*
			se a comparação for diferete de 0 executa as proximas instruções
			*/
	 		printf("\nOpcao invalida !!!");
		}
		else if	((strcmp(C,"s")==0) || (strcmp(C,"S")==0))
		{
			/*
			se a comparação for igual a 0 executa as proximas instruções
			*/
	   		fseek(resu,0,SEEK_END);// posiciona no arquivo no final    
			fwrite(&cadMonitor,sizeof(struct monitor),1,resu); 
			/*
			Grava os dados da estrutura "cadMonitor" no arquivo resu
			&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
			sizeof = o tamanho da unidade a ser lida
			1 = total de unidades a ser lida
			resu = ponteiro para o arquivo 
			*/									    
		}	
       	else
		{
	  		printf("\nDados nao foi salvo !\n");					  
		}                    
			
	} while ((strcmp(C,"s")!=0) && (strcmp(C,"S")!=0) && (strcmp(C,"n")!=0) && (strcmp(C,"N")!=0));
	// enquanto a comparação da variavel ShC com "s ou n" for diferente de 0 repete as instruções que se encontra dentro do laço
	fclose(fp);
	system("pause");
		
}//fim da função para o aluno avaliar o monitor
