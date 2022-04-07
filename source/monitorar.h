
int monitorar(TcadAluno dados)
// inicio da função para monitorar alguma disciplina
{
	char ma[50];
	char certo[50];
	char in[50];
	char ch[100];
	int achou=-1;
	
	int m;
	char maiusculo[20];
	char C[10];
	
	int i=1;
	char op;
    
    if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	if ((arq=fopen("usuario.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(file,0,SEEK_SET);    // posiciona o arquivo no inicio	
	fseek(arq,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	printf ("\n\t\t### LISTA DE DISCIPLINAS CADASTRADAS ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOME DO ALUNO") ;	
	printf("\n------------------------------------------------------------------------------");		
	if((strcmp(cadUsu.nome, cadAluno.disci.nome) != 0))
	{
		while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // le a struct cadAluno 
		{
		
			if((strcmp(cadUsu.nome, cadAluno.disci.nome) != 0))
			{
			
				printf ("\n%s\t\t\t\%s",cadAluno.disci.materia, cadAluno.disci.nome) ;	// amostra a Disciplina e o nome do Aluno que esta com duvida	  	  		
		
				i++;
			}
		
    	}
	}
	printf("\n-----------------------------fim----------------------------------------------\n");
	
	
	
		
	printf("\nMonitor %s, digite qual disciplina acima deseja monitorar? \n", cadUsu.nome);	
	gets(ma);
	fflush(stdin);
	
	
	if ((fp=fopen("monitorar.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}	
		
	printf("VAMOS CONFIRMAR SEUS DADOS\n");
	
	printf("\n\nConfirme seu nome----------------------------:");
	fflush(stdin);
	gets(cadMonitor.moni.confiNome);
		
	printf("\n\nConfirme a materia que deseja monitorar------:");
	fflush(stdin);
	gets(cadMonitor.moni.confiMateria);	
	do
	{
	
		if((strcmp(cadMonitor.moni.confiNome, cadUsu.nome) ==0 ))
		{
			if((strcmp(cadMonitor.moni.confiMateria, ma) == 0))
			{
				achou=ftell(fp);
				fseek(fp,0,SEEK_END);// posiciona no arquivo no final    
				fwrite(&cadMonitor,sizeof(struct monitor),1,fp); //Grava os dados da estrutura "cadMonitor" no arquivo discipliina.dat 
				printf ("\nDados gravados com sucesso !!!\n\n");
				break;									    
			}
			else
			{
				printf("\nDados nao foi salvo !\n");					  
			}  
							
		}
			
		
	}while(!feof(fp));
	if (achou == -1)
   	{
   		printf ("\n\aErro: DADOS INCORRETOS !\n");
		system("pause");
   	}
   	
	fclose(fp);
	return 1;
}// fim da função para monitorar alguma disciplina
	
		

