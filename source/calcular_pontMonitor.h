int calcular_pontMonitor (TcadMonitor dados)
// inicio da fun��o usada para calcular os pontos do monitor
{
	
	char nome[50], abc[50];
	int i, n, d, achou=-1, nota=0, media=0; 
	float ad;
	
	if ((resu=fopen("avalia��o.dat","ab+"))==NULL) //Abre o arquivo avalia��o.dat ou cria caso n�o exista.
	{
		// se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
					
	}// fim da verifica��o
	
	
	printf("Digite o nome do monitor que deseja calcula a pontuacao---:");
	gets(nome); // guarda o nome que o usuario digitar
	system("cls"); // limpa tela
	linha(); // retorna a fun��o preencher cabe�ario 
	
	printf("\n\t##LISTAMOS TODAS AS NOTAS DO MONITOR ###\n");
	printf("\n------------------------------------------------------------------------------");			
	printf ("\nDISCIPLINA\t\tNOME DO MONITOR\t\tNOTA DA MONITORIA") ;	
	printf("\n------------------------------------------------------------------------------");
  	
	do // inicio do la�o repita
  	{
		while(fread(&cadMonitor,sizeof(cadMonitor),1,resu)==1) // le a struct cadMonitor 
		{
				
			if((strcmp(nome, cadMonitor.moni.ava) == 0)) // condi��o para saber se a compara��o de nome com cadMonitor.moni.ava � igual 0
			{
				/*
				se a compara��o for igual a 0 executa as proximas instru��es
				*/
				printf ("\n%s\t\t\t%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.ava, cadMonitor.moni.nota) ;	
				// amostra a Disciplina e o nome do Aluno que esta com duvida	  	  		
				
				i++;
			}
				
		
		}									
		
	}while (!feof(resu)); // enquanto o ponteiro resu for !feof(0) repete as instru��es que se encontra dentro do la�o 
	printf("\n-----------------------------fim----------------------------------------------\n");
	
	printf("\n\n###PREENCHA OS DADOS ABAIXO###\n\n");
	
	printf("Quantas nota deseja adicionar?\n"); // solicitar ao adm quantas notas ele deseja adicionar para calcular a pontua��o do monitor
	fflush(stdin);// limpa o buffer
	scanf("%f", &ad); // guarda a quantitade de vezes que o adm digitou
	
	
	for(d=0;d<ad;d++) // la�o para executa as instru��es enquanto a variavel contadora for menor que a quantidade de vezes que o adm digitou
	{
		
		printf("Digite a nota: ");  // solicitar ao adm a nota      
        scanf("%d",&nota); // armazena a nota digita                                  
        media+=nota; // a variavel media recebe media e soma com o valor da variavel nota
	}
	printf("A soma da pontuacao do monitor %s e: %.2d\n\n", nome, media); // amostra o resultado do calculo que armazenou na variavel media
	itoa(media, cadMonitor.moni.media, 10); // converter a variavel inteira media para uma variavel do tipo char com o nome cadMonitor.moni.media
	printf("Confirme o nome do monitor---: \n");// solicita a confirma��o do nome do monitor
	fflush(stdin);
	gets(cadMonitor.moni.nomeConfi); // guarda a confirma��o do nome do monitor
	fseek(resu,0,SEEK_END);// posiciona no arquivo no final    
	fwrite(&cadMonitor,sizeof(struct monitor),1,resu); 
	/*
	Grava os dados da estrutura "cadMonitor" no arquivo
	&cadMonitor = � a regi�o de memoria na qual ser�o armazenados os dados lidos
	sizeof = o tamanho da unidade a ser lida
	1 = total de unidades a ser lida
	resu = ponteiro para o arquivo 
	*/
	
}// inicio da fun��o usada para calcular os pontos do monitor
	
