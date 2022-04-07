void MonitoriaCadastrada (void)
// inicio função para mostra ao administrador as monitorias cadastradas no sistema
{
	
	int i=1;
	char op, C[10], ma[50];
    
    if ((fp=fopen("monitorar.dat","ab+"))==NULL) //Abre o arquivo mointorar.dat ou cria caso não exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo disciplina.dat ou cria caso não exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(fp,0,SEEK_SET);    // posiciona o arquivo no inicio 
	fseek(file,0,SEEK_SET);	// posiciona o arquivo no inicio 
	/*
		fp, file = ponteiro 
		0 = a posição que o SEEK_SET ira posiciona o ponteiro
		SEEK_SET = posicionar o ponteiro no início do arquivo
	*/
	
	printf ("\n\t\t### LISTA DE DISCIPLINAS MONITORADAS NO SISTEMA ###\n") ;	
	printf("\n--------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\tALUNO QUE RECEBEU MONITORIA\tNOME DO MONITOR") ;	
	printf("\n--------------------------------------------------------------------------------");
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // laço para ler a região de memoria enquanto a total de unidade for igual 1
	{
		/*
		&cadAluno = é a região de memoria na qual serão armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/	
		while(fread(&cadMonitor, sizeof(cadMonitor),1,fp) == 1) // laço para ler a região de memoria enquanto a total de unidade for igual 1
		{
			/*
			&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
			sizeof = o tamanho da unidade a ser lida
			1 = total de unidades a ser lida
			fp = ponteiro para o arquivo
			*/
			printf ("\n%s\t\t%s\t\t\t\t%s", cadMonitor.moni.confiMateria, cadAluno.disci.nome, cadMonitor.moni.confiNome) ;	
			/*	
			mostra todas as disciplinas monitoradas com os respectivos nomes que realizou e recebeu a monitoria	  	  		
			*/  	  		
			i++;
		}// fim do laço para ler a região de memoria &cadMonitor
		i++;
    }// fim do laço para ler a região de memoria &cadAluno
	printf("\n-----------------------------fim------------------------------------------------\n");
	system("pause");
	
}// fim da função para mostra ao administrador as monitorias cadastradas no sistema
