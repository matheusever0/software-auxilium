int resultado (TcadMonitor dados)
// inicio da função para o monitor consulta o resultado da avaliação
{
	
	char resul[50], no[50];
	int achou=-1, i;
	
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo avaliação.dat ou cria caso não exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}
	
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio
  		
	linha(); // retorna a função para preencher o cabeçario
	
	while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // le a struct cadAluno 
	{
		/*
		&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
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
   
}// fim da função para o monitor consulta o resultado da avaliação
