int verificar_qtd(TcadUsu dados)
{
	int  C, i, ii, n, cont, d, dd, ddd, ee;
	int o;
	char shC[10];
	char ShC[10];
	char Cc[10];
	char info[50];
	char m[30];
	float soma=0, media;
	char nota[50], pi[50];
	int continua;
	char nome[50], s[50];
	int achou =-1;
	char *caracter;
	int numPalavras =0;
	int comecouPalavra;
	float nota1, nota2, nota3;
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso não exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!");
			
	}
		
			
	
	system("cls");		
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	
	printf("\nConfirme seu nome para procurar seus pontos\n");
	gets(nome);
	
	fseek(arq,0,SEEK_SET);    // posiciona o arquivo no inicio
  	do 
  	{
		fread(&dados, sizeof(struct nUsuario), 1, arq);	// le registro
				
		if  ((strcmp(nome, cadUsu.nome) == 0)) // verifica se o login digitado é igual ao login gravado no ato do cadastro
    	{
    		
			achou=ftell(arq);
			printf("\n\t##LISTAMOS TODAS AS SUAS NOTAS ABAIXO ###\n");
			printf ("\n\t\t### RESULTADO ###\n") ;	
			printf("\n------------------------------------------------------------------------------");			
			printf ("\nDISCIPLINA\t\tNOME DO MONITOR\t\tNOTA DA MONITORIA") ;	
			printf("\n------------------------------------------------------------------------------");		
			while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // le a struct cadAluno 
			{
				if((strcmp(nome, cadMonitor.moni.ava) == 0))
				{
				
					printf ("\n%s\t\t\t%s\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.ava, cadMonitor.moni.nota) ;	// amostra a Disciplina e o nome do Aluno que esta com duvida	  	  		
				
					i++;
				}
		    }									
			printf("\n-----------------------------fim----------------------------------------------\n");
								    
			
			printf("\n-----------------------------------------------\n");
			printf("1- Solicitar calculo das notas\n");
			printf("2- Verificar resultado da solicitacao do calculo");
			printf("\n-----------------------------------------------\n");
			printf("Digite a opcao: [ ]\b\b");
			o=getche();
			fflush(stdin);
			switch (o)
			{
				case '1':
					system("cls");
					solicitar_calculo();
					break;
				case '2':
					system("cls");
					verificar_hrs();
					break;
					
				
			}				                
			system("pause");	
			break;
			
		}//if
	} while (!feof(arq));// se a busca chegou ao fim, para 
   if (achou == -1)
   {
   	 printf ("\n\aErro: DADOS INCORRETOS !\n");
	 system("pause");
   }
	
	
}
