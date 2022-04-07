int consulta_nota()
//inicio da função para o usuario consulta sua nota
{
	int i;
	linha();
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo avaliação.dat ou cria caso não exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio
	printf("\n\t##LISTAMOS TODAS AS SUAS NOTAS ABAIXO ###\n");
	printf("------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOTA DA MONITORIA") ;	
	printf("\n------------------------------------------------------------------------------");	
	while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // laço para ler a região de memoria enquanto a total de unidade for igual 1 
	{
		/*
		&cadAluno = é a região de memoria na qual serão armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/
		
			
		printf ("\n%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.nota) ;
		/*	
		mostra todas as disciplinas cadastradas como os respectivos nomes que à cadastrou	  	  		
		*/
			
		
		i++; 		
    } // fim do laço para ler a região de memoria &cadAluno
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause"); // pausa o programa
	
	
}//fim da função para o usuario consulta sua nota			          
