void DisciplinaCadastrada (void)
{
	int i=1;
	char op;
    
    if ((file=fopen("discipliina.dat","ab+"))==NULL) //Abre o arquivo clientes.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(file,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	printf ("\n\t\t### LISTA DE DISCIPLINAS CADASTRADAS ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\t\t\tNOME DO ALUNO") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // le a struct cadAluno
	{
		printf ("\n%s\t\t\t\t\t%s",cadAluno.disci.materia, cadAluno.disci.nome) ;
				  	  		
		
		i++;		
    }
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause");
	
}
