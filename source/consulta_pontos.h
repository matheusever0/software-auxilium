int consulta_pontos(TcadUsu dados)
{
	//fun��o para o monitor consulta seus pontos
	int   i;
	int o;
	char nome[50];
	int achou =-1;
	
	if ((resu=fopen("avalia��o.dat","ab+"))==NULL) //Abre o arquivo discipliina.dat ou cria caso n�o exista.
	{
		//se a abertura do aquivo for difente de NULL executa as proximas instru�oes dessa condi��o
		printf("O arquivo de DADOS nao pode ser aberto!");
			
	}
			
	system("cls");		
	fseek(resu,0,SEEK_SET);    // posiciona o arquivo no inicio	
	linha();
	
	printf("\nConfirme seu nome para procurar seus pontos\n");
	gets(nome); // guarda a confirma��o 
	
	
	fseek(arq,0,SEEK_SET);    // posiciona o arquivo no inicio
	
	fflush(stdin);
  	do
	{
		system("cls");
		linha();
		printf("\n-------------------------------------------------\n");
		printf("1 - Solicitar calculo das notas\n");
		printf("2 - Verificar resultado da solicitacao do calculo\n");
		printf("3 - Consulta suas notas\n\n");
		printf("4 - Volta ao menu principal");
		printf("\n-------------------------------------------------\n");
		printf("Digite a opcao: [ ]\b\b");
		o=getche();// le a op��o digitada pelo usuario
		fflush(stdin);
		switch (o) // inicio do escolha disbonibilizado para o usuario
		{
			case '1': // solicitar os casos da nota
				system("cls");
				solicitar_calculo(); // retorna a fun��o onde contem as instru��es para calcular a nota
				break;
			case '2':// verificar resultado da solicita��o
				system("cls");
				verificar_hrs(); // retorna a fun��o onde cont�m as intru��es para verificar o resultado da solicita��o
				break;
			case '3':
				system("cls");
				
				do 
			  	{	
					fread(&dados, sizeof(struct nUsuario), 1, arq);	// le registro
							
					
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
							
						if((strcmp(nome, cadUsu.nome) == 0))
						{
						
							printf ("\n%s\t\t\t%s",cadMonitor.moni.amo, cadMonitor.moni.nota) ;
							/*	
							mostra todas as disciplinas cadastradas como os respectivos nomes que � cadastrou	  	  		
							*/
						}
							
						i++; 		
				   } // fim do la�o para ler a regi�o de memoria &cadAluno
					printf("\n-----------------------------fim----------------------------------------------\n");
					system("pause"); // pausa o programa
							
				} while (feof(arq));// se a busca chegou ao fim, para 
			   
			   	break;
			case '4':
				break;
				default:
				printf("\n\tEscolha invalida! Por favor, escolha novamente.");			
		}
				
		system("cls");
	}while(o!='4');
	fclose(resu);
	
	
	
}
