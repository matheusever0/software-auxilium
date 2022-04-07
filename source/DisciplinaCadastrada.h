void DisciplinaCadastrada (void)
// inicio da função para mostra ao administrador as disciplinas cadastradas no sistema
{
	
	int i=1;
	char op;
    
    if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo disciplina.dat ou cria caso não exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(file,0,SEEK_SET);    // posiciona o arquivo no inicio 	
	
	printf ("\n\t\t### LISTA DE DISCIPLINAS CADASTRADAS NO SISTEMA ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOME DO ALUNO") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // laço para ler a região de memoria enquanto a total de unidade for igual 1 
	{
		/*
		&cadAluno = é a região de memoria na qual serão armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/
		printf ("\n%s\t\t\t%s",cadAluno.disci.materia, cadAluno.disci.nome) ;
		/*	
		mostra todas as disciplinas cadastradas como os respectivos nomes que à cadastrou	  	  		
		*/
		i++; 		
    } // fim do laço para ler a região de memoria &cadAluno
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause"); // pausa o programa
	
}// fim da função para mostra ao administrador as disciplinas cadastradas no sistema
