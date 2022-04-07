int calcular_pontMonitor (TcadMonitor dados)
// inicio da função usada para calcular os pontos do monitor
{
	
	char nome[50], abc[50];
	int i, n, d, achou=-1, nota=0, media=0; 
	float ad;
	
	if ((resu=fopen("avaliação.dat","ab+"))==NULL) //Abre o arquivo avaliação.dat ou cria caso não exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instruçoes dessa condição
		printf("O arquivo de DADOS nao pode ser aberto!");
					
	}// fim da verificação
	
	
	printf("Digite o nome do monitor que deseja calcula a pontuacao---:");
	gets(nome); // guarda o nome que o usuario digitar
	system("cls"); // limpa tela
	linha(); // retorna a função preencher cabeçario 
	
	printf("\n\t##LISTAMOS TODAS AS NOTAS DO MONITOR ###\n");
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOME DO MONITOR\t\tNOTA DA MONITORIA") ;	
	printf("\n------------------------------------------------------------------------------");
  	
	do // inicio do laço repita
  	{
		while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // le a struct cadMonitor 
		{
				
			if((strcmp(nome, cadMonitor.moni.ava) == 0)) // condição para saber se a comparação de nome com cadMonitor.moni.ava é igual 0
			{
				/*
				se a comparação for igual a 0 executa as proximas instruções
				*/
				printf ("\n%s\t\t\t%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.ava, cadMonitor.moni.nota) ;	
				// amostra a Disciplina e o nome do Aluno que esta com duvida	  	  		
				
				i++;
			}
				
		
		}									
		
	}while (!feof(resu)); // enquanto o ponteiro resu for !feof(0) repete as instruções que se encontra dentro do laço 
	printf("\n-----------------------------fim----------------------------------------------\n");
	
	printf("\n\n###PREENCHA OS DADOS ABAIXO###\n\n");
	
	printf("Quantas nota deseja adicionar?\n"); // solicitar ao adm quantas notas ele deseja adicionar para calcular a pontuação do monitor
	fflush(stdin);// limpa o buffer
	scanf("%f", &ad); // guarda a quantitade de vezes que o adm digitou
	
	
	for(d=0;d<ad;d++) // laço para executa as instruções enquanto a variavel contadora for menor que a quantidade de vezes que o adm digitou
	{
		
		printf("Digite a nota: ");  // solicitar ao adm a nota      
        scanf("%d",&nota); // armazena a nota digita                                  
        media+=nota; // a variavel media recebe media e soma com o valor da variavel nota
	}
	printf("A soma da pontuacao do monitor %s e: %.2d\n\n", nome, media); // amostra o resultado do calculo que armazenou na variavel media
	itoa(media, cadMonitor.moni.media, 10); // converter a variavel inteira media para uma variavel do tipo char com o nome cadMonitor.moni.media
	printf("Confirme o nome do monitor---: \n");// solicita a confirmação do nome do monitor
	fflush(stdin);
	gets(cadMonitor.moni.nomeConfi); // guarda a confirmação do nome do monitor
	fseek(resu,0,SEEK_END);// posiciona no arquivo no final    
	fwrite(&cadMonitor,sizeof(struct monitor),1,resu); 
	/*
	Grava os dados da estrutura "cadMonitor" no arquivo
	&cadMonitor = é a região de memoria na qual serão armazenados os dados lidos
	sizeof = o tamanho da unidade a ser lida
	1 = total de unidades a ser lida
	resu = ponteiro para o arquivo 
	*/
	
}// inicio da função usada para calcular os pontos do monitor
	
