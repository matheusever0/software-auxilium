int consulta_nota()
//inicio da fun��o para o usuario consulta sua nota
{
	int i;
	linha();
	if ((resu=fopen("avalia��o.dat","ab+"))==NULL) //Abre o arquivo avalia��o.dat ou cria caso n�o exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio
	printf("\n\t##LISTAMOS TODAS AS SUAS NOTAS ABAIXO ###\n");
	printf("------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOTA DA MONITORIA") ;	
	printf("\n------------------------------------------------------------------------------");	
	while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // la�o para ler a regi�o de memoria enquanto a total de unidade for igual 1 
	{
		/*
		&cadAluno = � a regi�o de memoria na qual ser�o armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/
		
			
		printf ("\n%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.nota) ;
		/*	
		mostra todas as disciplinas cadastradas como os respectivos nomes que � cadastrou	  	  		
		*/
			
		
		i++; 		
    } // fim do la�o para ler a regi�o de memoria &cadAluno
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause"); // pausa o programa
	
	
}//fim da fun��o para o usuario consulta sua nota			          
