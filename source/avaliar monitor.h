int avaliar_monitor()
//inicio da fun��o para o aluno avaliar o monitor
{
	
	int i=1;
	char op, C[20];
    
    if ((fp=fopen("monitorar.dat","ab+"))==NULL) //Abre o arquivo monitorar.dat ou cria caso n�o exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	if ((arq=fopen("usuario.dat","ab+"))==NULL) //Abre o usuario.dat ou cria caso n�o exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
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
		&cadAluno = � a regi�o de memoria na qual ser�o armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/	
		if((strcmp(cadUsu.nome, cadMonitor.moni.confiNome) != 0))
		{
			/*
			se a compara��o for igual diferente de 0 so vai mostra as monitorias do usuario que 
			o nome seja diferente do nome do usuario que esta logado e
			executa as proximas instru��es dessa condi��o
			*/
			printf ("\n%s\t\t\t%s",cadMonitor.moni.confiNome, cadMonitor.moni.confiMateria) ;	
			// mostra o nome do monitor e a disciplina	  	  		
		
			i++;
		}
    }
	printf("\n-----------------------------fim----------------------------------------------\n");
	fclose(fp);
	
	
	
	
	if ((resu=fopen("avalia��o.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso n�o exista.
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
	gets(cadMonitor.moni.nota); // guarda a nota da sua avalia��o
	do 
	{
		printf("\n\nConfirma sua avaliacao [S/N] ?");
		gets(C);
		// inicio da condi��o para saber se a compara��o de C com "s ou n" � igual a 0
		if ((strcmp(C,"s")!=0) && (strcmp(C,"S")!=0) && (strcmp(C,"n")!=0) && (strcmp(C,"N")!=0))
		{
			/*
			se a compara��o for diferete de 0 executa as proximas instru��es
			*/
	 		printf("\nOpcao invalida !!!");
		}
		else if	((strcmp(C,"s")==0) || (strcmp(C,"S")==0))
		{
			/*
			se a compara��o for igual a 0 executa as proximas instru��es
			*/
	   		fseek(resu,0,SEEK_END);// posiciona no arquivo no final    
			fwrite(&cadMonitor,sizeof(struct monitor),1,resu); 
			/*
			Grava os dados da estrutura "cadMonitor" no arquivo resu
			&cadMonitor = � a regi�o de memoria na qual ser�o armazenados os dados lidos
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
	// enquanto a compara��o da variavel ShC com "s ou n" for diferente de 0 repete as instru��es que se encontra dentro do la�o
	fclose(fp);
	system("pause");
		
}//fim da fun��o para o aluno avaliar o monitor
