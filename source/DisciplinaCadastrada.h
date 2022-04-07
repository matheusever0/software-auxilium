void DisciplinaCadastrada (void)
// inicio da fun��o para mostra ao administrador as disciplinas cadastradas no sistema
{
	
	int i=1;
	char op;
    
    if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo disciplina.dat ou cria caso n�o exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(file,0,SEEK_SET);    // posiciona o arquivo no inicio 	
	
	printf ("\n\t\t### LISTA DE DISCIPLINAS CADASTRADAS NO SISTEMA ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOME DO ALUNO") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // la�o para ler a regi�o de memoria enquanto a total de unidade for igual 1 
	{
		/*
		&cadAluno = � a regi�o de memoria na qual ser�o armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/
		printf ("\n%s\t\t\t%s",cadAluno.disci.materia, cadAluno.disci.nome) ;
		/*	
		mostra todas as disciplinas cadastradas como os respectivos nomes que � cadastrou	  	  		
		*/
		i++; 		
    } // fim do la�o para ler a regi�o de memoria &cadAluno
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause"); // pausa o programa
	
}// fim da fun��o para mostra ao administrador as disciplinas cadastradas no sistema
