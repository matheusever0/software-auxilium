int resultado (TcadMonitor dados)
// inicio da fun��o para o monitor consulta o resultado da avalia��o
{
	
	char resul[50], no[50];
	int achou=-1, i;
	
	if ((resu=fopen("avalia��o.dat","ab+"))==NULL) //Abre o arquivo avalia��o.dat ou cria caso n�o exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio
  		
	linha(); // retorna a fun��o para preencher o cabe�ario
	
	while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // le a struct cadAluno 
	{
		/*
		&cadMonitor = � a regi�o de memoria na qual ser�o armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		resu = ponteiro para o arquivo
		*/	
		printf ("\n%s",cadMonitor.moni.media); //mostra a Disciplina e o nome do Aluno que esta com duvida	  	  		
		i++;
		break;
		system("pause");
	
   	}
	
   
   
	return achou; 	
   
}// fim da fun��o para o monitor consulta o resultado da avalia��o
