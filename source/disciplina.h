
int disciplina()
// inicio da função para mostra as disciplinas que o usuario tem cadastrado no sistema	
{
	
	char C[10];
	int posicao=-1;
	
	if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo disciplina.dat ou cria caso não exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		return 1;
	}
	
	
	printf("\n\nQual disciplina esta com dificuldade? ---: ");
	fflush(stdin);
	gets(cadAluno.disci.materia); // guarda a disciplina que esta com dificuldade
	
	
	printf("VAMOS CONFIRMAR SEUS DADOS\n");
	
	printf("\n\nConfirme seu nome--------------:");
	fflush(stdin);
	gets(cadAluno.disci.nome); // guarda a confirmação do nome 
	
	printf("\n\nConfirme seu telefone[DD]------:");
	fflush(stdin);
	gets(cadAluno.disci.tel); // guarda a confirmação do telefone
	
	if((strcmp(cadAluno.disci.nome, cadUsu.nome) == 0)) // verificar se a confirmação digitada é igual ao nome cadastrado
	{
		
			fseek(arq,posicao-sizeof(cadUsu),0); //Posicao do inicio do registro atual
			fread(&cadUsu,sizeof(cadUsu),1,arq); //lê os dados     
			fseek(arq,posicao-sizeof(cadUsu),0); //Rentorna novamente para Posicao do inicio do registro atual		   		
			printf ("\nNOME -----------------------: %s", cadUsu.nome) ;	  
			printf("\nDISCIPLINA COM DIFICULDADE--: %s", cadAluno.disci.materia);
						
			do // inicio do laço
			{
				printf("\n\nConfirma gravacao da disciplina que esta com dificuldade [S/N] ?");
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
			   		fseek(file,0,SEEK_END);// posiciona no arquivo no final    
					fwrite(&cadAluno,sizeof(struct aluno),1,file); 
					printf("Disciplina gravada com sucesso\n");
					/*
					Grava os dados da estrutura "cadAluno" no arquivo disciplina.dat
					&cadAluno = é a região de memoria na qual serão armazenados os dados lidos
					sizeof = o tamanho da unidade a ser lida
					1 = total de unidades a ser lida
					resu = ponteiro para o arquivo 
					*/									    
				}	
		       	else
				{
			  		printf("\nDados nao foi salvo !\n");					  
				}                    
					system("pause");
			} while ((strcmp(C,"s")!=0) && (strcmp(C,"S")!=0) && (strcmp(C,"n")!=0) && (strcmp(C,"N")!=0));
			// enquanto a comparação da variavel ShC com "s ou n" for diferente de 0 repete as instruções que se encontra dentro do laço		
		
	}
	else
	{
		printf("OS DADOS NAO CONFEREM\n");
		system("pause");
	}
	
	fclose(file);
	return 1;
}// fim da função para mostra as disciplinas que o usuario tem cadastrado no sistema

