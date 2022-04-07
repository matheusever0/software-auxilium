int verificar_hrs()
//inicio da função para mostra ao usuario o resultado da solicitação de calculo da nota
{
	
	int i=1;
	char op;
	int media;
	int total;
	
    
    if ((av=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo clientes.dat ou cria caso não exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}// fim da verificação
	
			
	if ((file=fopen("disciplina.dat","ab+"))==NULL) //Abre o arquivo clientes.dat ou cria caso não exista.
	{
		// se a abertura do arquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
		
	}// fim da verificação
	
	fseek(av,0,SEEK_SET);    // posiciona o arquivo no inicio
	fseek(file,0,SEEK_SET);	// posiciona o arquivo no inicio
	linha();
	printf ("\n\t\t### RESULTADO DO CALCULO DAS NOTAS ###\n") ;	
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nNOTA TOTAL") ;	
	printf("\n------------------------------------------------------------------------------");		
	while(fread(&cadAluno,sizeof(cadAluno),1,file)==1) // le a struct cadAluno
	{
		/*
		&cadAluno = é a região de memoria na qual serão armazenados os dados lidos
		sizeof = o tamanho da unidade a ser lida
		1 = total de unidades a ser lida
		file = ponteiro para o arquivo
		*/
		while(fread(&cadMonitor, sizeof(cadMonitor),1,av) == 1) // le a struct cadMonitor
		{
			/*
			&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
			sizeof = o tamanho da unidade a ser lida
			1 = total de unidades a ser lida
			av = ponteiro para o arquivo
			*/
			if((strcmp(cadUsu.nome, cadMonitor.moni.nomeConfi) == 0)) // inicio da verificação 
			{
				/* se a comparação entre a string cadUsu.nome e a cadMonitor.moni.nomeConfi 
				for igual a 0 executa as instruções dessa condição
				*/
				printf ("\n%s", cadMonitor.moni.media) ;
				//mostra o resultado do calculo de suas notas		  	  		
				
				total = atoi(cadMonitor.moni.media);
				// converter a string cadMonitor.moni.media para o inteiro total
				i++;
				media = total / 5; // a variavel media recebe o valor da variavel total dividio por 5
				/*
				mostra a mensagem informativa
				*/
				printf("\n\nO sistema auxilium trabalha com a cada 10 pontos avaliado pelo aluno\n");
				printf("e convertido para duas (2) horas de atividade complementar.\n");
				printf("Para realizar a troca de pontos voce tem que atiginr o\n");
				printf("numero minimo de horas que e 30hrs.\n\n\n\n");
				/*
				mostra quantos pontos e a conversão em horas o usuario tem
				*/
				printf("Voce tem %.0d pontos esses pontos convertido em horas da um total de %.0d\n", total, media);
				printf("horas de atividade complementar\n\n");
				
				if (media >= 30) 
				{
					// se media for maior ou igual a 30 executar as instruções dessa condição
					printf("Parabens voce conseguiu atingir %.0f horas de atividade complementar\n\n",media);
					printf("Utilize o codigo ##123456##, para debitar as 30horas na sua faculdade\n\n");
										
				}
				else 
				{
					// se media for menor que 30 executar as instruções dessa condição
					printf("Voce ainda nao pode troca seus pontos\n");
					printf("porque esta com nota menor do que o limite exigido que e: 30hrs.\n\n");
				}
							       		
			}// fim da verificação 
		}// fim do laço para ler a região de memoria &cadMonitor
		i++;
    }
	printf("\n-----------------------------fim----------------------------------------------\n");
	system("pause");				
}//fim da função para mostra ao usuario o resultado da solicitação de calculo da nota
