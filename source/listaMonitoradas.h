
void listaMonitoradas (void)
// inicio da fun��o para mostra as monitorias que foi realizada pelo usuario
{
	
	int i=1;
	char op, C[10], ma[50];
    
    if ((fp=fopen("monitorar.dat","ab+"))==NULL) //Abre o arquivo disciplina.dat ou cria caso n�o exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo disciplina.dat ou cria caso n�o exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(fp,0,SEEK_SET);    // posiciona o arquivo no inicio
	fseek(file,0,SEEK_SET);	// posiciona o arquivo no inicio
	linha();
	printf ("\n\t\t### LISTA DE DISCIPLINAS MONITORADAS ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\tALUNO QUE RECEBEU MONITORIA") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // le a struct cadAluno
	{
		/*
		&cadAluno = � a regi�o de memoria na qual ser�o armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/	
		while(fread(&cadMonitor, sizeof(cadMonitor),1,fp) == 1) // le a struct cadMonitor
		{
			/*
			&cadMonitor = � a regi�o de memoria na qual ser�o armazenados os dados lidos
			sizeof = o tamanho da unidade a ser lida
			1 = total de unidades a ser lida
			fp = ponteiro para o arquivo
			*/
			if((strcmp(cadUsu.nome, cadMonitor.moni.confiNome) == 0)) // compara nome cadastrado com o nome digitado na hora de realizar a monitoria
			{
				/*
				se a compara��o for igual a 0 so vai mostra as monitorias do usuario que esta logado e
				executa as proximas instru��es dessa condi��o
				*/
				printf ("\n%s\t\t%s", cadMonitor.moni.confiMateria, cadAluno.disci.nome) ;	
				// mostra a disciplina e o aluno q recebeu monitoria	  	  		
				i++;
			}
		}
		i++;
    }
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause");
	
}// fim da fun��o para mostra as monitorias que foi realizada pelo usuario
