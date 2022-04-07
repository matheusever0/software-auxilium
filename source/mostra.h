int mostra (TcadMonitor dados)
{
	char nome[50], abc[50];
	int i, n, d, achou=-1, nota=0, media=0; 
	float ad;
	
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
					
	}
	
	
	printf("Digite o nome do monitor que deseja calcula a pontuacao---:");
	gets(nome);
	system("cls");
	linha();
	
	printf("\n\t##LISTAMOS TODAS AS NOTAS DO MONITOR ###\n");
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOME DO MONITOR\t\tNOTA DA MONITORIA") ;	
	printf("\n------------------------------------------------------------------------------");
  	
	do 
  	{
			
		while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // le a struct cadAluno 
		{
				
			if((strcmp(nome, cadMonitor.moni.ava) == 0))
			{
				
				printf ("\n%s\t\t\t%s\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.ava, cadMonitor.moni.nota) ;	// amostra a Disciplina e o nome do Aluno que esta com duvida	  	  		
				
				i++;
			}
				
		
		}									
		
	}while (!feof(resu));
	printf("\n-----------------------------fim----------------------------------------------\n");
	
	printf("\n\n###PREENCHA OS DADOS ABAIXO###\n\n");
	
	printf("Quantas nota deseja adicionar?\n");
	fflush(stdin);
	scanf("%f", &ad);
	
	
	for(d=0;d<ad;d++)
	{
		
		printf("Digite a nota: ");        
        scanf("%d",&nota);                                     
        media+=nota; 
	}
	printf("A soma da pontuacao do monitor %s e: %.2d\n\n", nome, media);
	itoa(media, cadMonitor.moni.media, 10);
	printf("Confirme o nome do monitor---: \n");
	fflush(stdin);
	gets(cadMonitor.moni.nomeConfi);
	printf("A string abc e %s", cadMonitor.moni.media);
	fseek(resu,0,SEEK_END);// posiciona no arquivo no final    
	fwrite(&cadMonitor,sizeof(struct monitor),1,resu); //Grava os dados da estrutura "cadCli" no arquivo 
	printf ("\nDados gravados com sucesso !!!\n\n");
	system("pause");
	
	
	
	
}
