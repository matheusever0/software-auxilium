void Usuario_Cadastrado (void)
// inicio fun��o para mostra ao administrador as monitorias cadastradas no sistema
{
	
	int i=1;
	char op, C[10], ma[50];
    
    if ((arq=fopen("usuario.dat","ab+"))==NULL) //Abre o arquivo mointorar.dat ou cria caso n�o exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(arq,0,SEEK_SET);    // posiciona o arquivo no inicio 
	/*
		fp, file = ponteiro 
		0 = a posi��o que o SEEK_SET ira posiciona o ponteiro
		SEEK_SET = posicionar o ponteiro no in�cio do arquivo
	*/
	
	printf ("\n\t\t### LISTA DE USUARIO CADASTRADO NO SISTEMA ###\n") ;	
	printf("\n--------------------------------------------------------------------------------");			
	printf ("\nNOME") ;	
	printf("\n--------------------------------------------------------------------------------");
	while(fread(&cadUsu,sizeof(cadUsu),1,arq)==1) // la�o para ler a regi�o de memoria enquanto a total de unidade for igual 1
	{
		/*
		&cadAluno = � a regi�o de memoria na qual ser�o armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/	
		printf ("\n%s", cadUsu.nome);	
		/*	
		mostra todas as disciplinas monitoradas com os respectivos nomes que realizou e recebeu a monitoria	  	  		
		*/  	  		
		i++;
    }// fim do la�o para ler a regi�o de memoria &cadAluno
	printf("\n-----------------------------fim------------------------------------------------\n");
	system("pause");
	
}// fim da fun��o para mostra a
