void listaDisciplina (void)
// inicio da fun��o para mostra as disciplinas que o usuario tem cadastrado no sistema
{
	int i=1;
	char op;
    
    if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo clientes.dat ou cria caso n�o exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(file,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	printf ("\n\t\t### LISTA DE DISCIPLINAS CADASTRADAS ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOME DO ALUNO") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // le a struct cadAluno
	{
		if ((strcmp(cadUsu.nome, cadAluno.disci.nome) ==0 ))
		{
		
			printf ("\n%s\t\t\t%s",cadAluno.disci.materia, cadAluno.disci.nome) ;
		 	  		
			i++;
		}
    }
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause");
	
}// fim da fun��o para mostra as disciplinas que o usuario tem cadastrado no sistema
