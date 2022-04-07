int abc(TcadMonitor dados)
{
	int i;
	char nome[50];
	int achou=-1;
	
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
			
	}
		
			
	
	system("cls");		
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	
	printf("\nDigite seu nome para procuramos seus pontos\n");
	gets(nome);
	
	   // posiciona o arquivo no inicio
  	do 
  	{
		fread(&dados, sizeof(struct monitor), 1, fp);	// le registro
				
		if  ((strcmp(nome, cadMonitor.moni.confiNome) == 0)) // verifica se o login digitado é igual ao login gravado no ato do cadastro
    	{
    		
			achou=ftell(fp);
			printf("\n\t##LISTAMOS TODAS AS SUAS NOTAS ABAIXO ###\n");
			printf ("\n\t\t### RESULTADO ###\n") ;	
			printf("\n------------------------------------------------------------------------------");			
			printf ("\nDISCIPLINA\t\tNOME DO MONITOR\t\tNOTA DA MONITORIA") ;	
			printf("\n------------------------------------------------------------------------------");		
			while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // le a struct cadAluno 
			{
				
				
					printf ("\n%s\t\t\t%s\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.ava, cadMonitor.moni.nota) ;	// amostra a Disciplina e o nome do Aluno que esta com duvida	  	  		
				
					i++;
				
		    }									
			printf("\n-----------------------------fim----------------------------------------------\n");
															    
			fclose(resu);		
		}
	}while (!feof(arq));
}
