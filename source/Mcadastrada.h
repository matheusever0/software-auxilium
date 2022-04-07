void MonitoriaCadastrada (void)
{
	int i=1;
	char op, C[10], ma[50];
    
    if ((fp=fopen("monitorar.dat","ab+"))==NULL) //Abre o arquivo clientes.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	if ((file=fopen("discipliina.dat","ab+"))==NULL) //Abre o arquivo clientes.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(fp,0,SEEK_SET);    // posiciona o arquivo no inicio
	fseek(file,0,SEEK_SET);	
	linha();
	printf ("\n\t\t### LISTA DE DISCIPLINAS MONITORADAS ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\t\tALUNO QUE RECEBEU MONITORIA") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // le a struct cadAluno
	{
		while(fread(&cadMonitor, sizeof(cadMonitor),1,fp) == 1) // le a struct cadMonitor
		{
		printf ("\n%s\t\t\t\t%s", cadMonitor.moni.confiMateria, cadAluno.disci.nome) ;		  	  		
		
		i++;
		}
		i++;
    }
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause");
	
}
