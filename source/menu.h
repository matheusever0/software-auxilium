#include "biblioteca_auxilium.h" //bibliotecas criada para armazena todas as biliotecas criada para o auxilium

int menu ()
// inicio da fun��o menu
{
	 
	int opcao, op;
	int opmonitor, opm;
	int posicao=-1; 
	int posi=-1; 
	 
	
	if ((arq=fopen("usuario.dat","a+b"))==NULL) //Abre o arquivo usuario.dat ou cria caso n�o exista.
	{
		printf("O arquivo de DADOS nao pode ser aberto!"); // amostrar em tela se caso n�o abrir o arquivo
		return 1;
	}// fim da verifica��o para abrir o arquivo usuario.dat
	do
	{
		system("cls"); // limpa a tela
		linha(); // retorna a fun��o que preenche o cabe�ario 
		fflush(stdin);// zera a sujeira
		// amostra em tela o menu principal                				
		printf("\n\n\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB---------------------------\xDB\xDB\xDB");	
		printf("\n\t\t\xDB\xDB\xDB   MENU PRINCIPAL          \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB---------------------------\xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 1 - LOGIN                 \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 2 - CADASTRO              \xDB\xDB\xDB");		
		printf("\n\t\t\xDB\xDB\xDB                           \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB                           \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 3 - SAIR                  \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB---------------------------\xDB\xDB\xDB");			
		printf("\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");
		printf("\n\t\tEntre com a Opcao: [ ]\b\b");						
		opcao=getche();
		fflush(stdin);		
		switch (opcao) // inicio da estrutura para verificar a escolha do usuario
		{
			case '1': // Caso 1 o usuario deseja realizar o login
				system("cls"); // Limpa a tela
				linha(); // retorna a fun��o que preenche o cabe�ario
				posicao=loginDeAcesso(cadUsu); // variavel posicao recebe loginDeAcesso
				if (posicao>=0) // verifica��o para saber se posicao � maior ou igual a 0
				{
					do // inicio do la�o
					{
											
						system("cls"); // limpa a tela
						linha();
						fflush(stdin);  
						fseek(arq,posicao-sizeof(cadUsu),0); //Posicao do inicio do registro atual
						fread(&cadUsu,sizeof(cadUsu),1,arq); //l� os dados     
						fseek(arq,posicao-sizeof(cadUsu),0); //Rentorna novamente para Posicao do inicio do registro atual		   		
						printf ("\nNOME --------: %-30s", cadUsu.nome) ; // amostra o nome do usuario		  
						printf ("\nCURSO--------: %s", cadUsu.curso) ; // amostra o curso
						printf ("\nINSTITIUCAO--: %s", cadUsu.insti); // amostra a institui��o	
						//amostra o menu do usuario	                   				
						printf("\n\n\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB-----------------------------------------------\xDB\xDB\xDB");	
						printf("\n\t\t\xDB\xDB\xDB               MENU DO USUARIO                 \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB-----------------------------------------------\xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB 1 - SE CADASTRAR EM ALGUMA DISCIPLINA         \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB 2 - DISCIPLINAS CADASTRADAS             	  \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB 3 - MONITORAR ALGUMA DISCIPLINA               \xDB\xDB\xDB");	
						printf("\n\t\t\xDB\xDB\xDB 4 - DISCIPLINAS MONITORADAS             	  \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB 5 - AVALIAR MONITOR             	          \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB 6 - CONSULTAR PONTOS         		  \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB                                               \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB 7 - VOLTAR AO MENU PRINCIPAL                  \xDB\xDB\xDB");
						printf("\n\t\t\xDB\xDB\xDB-----------------------------------------------\xDB\xDB\xDB");			
						printf("\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");
						printf("\n\t\tEntre com a Opcao: [ ]\b\b");						
						op=getche();
						fflush(stdin);
						switch (op) 
						{
							case '1': // o usuario deseja se cadastrar em alguma disciplina
								system("cls");
								linha ();
								disciplina(); // retorna a fun��o disciplina
								break;
								
							case '2': // o usuario deseja consulta suas disciplinas cadastradas
								system("cls");
								listaDisciplina();
								// retorna a fun��o que contem as instru��es para amostra ao usuario as disciplinas que ele se cadastrou				
								break;
							case '3': // o usuario deseja realiza uma monitoria
								system("cls");
								posi=monitorar(cadAluno); // a variavel posi recebe a fun��o monitorar
								if (posi>=0) 
								{
									fseek(file,posi-sizeof(cadAluno),0); //Posicao do inicio do registro atual
									fread(&cadAluno,sizeof(cadAluno),1,file); //l� os dados     
									fseek(file,posi-sizeof(cadAluno),0); //Rentorna novamente para Posicao do inicio do registro atual
									system("cls");
									linha();
									printf("\nMonitor %s entre em contato com o aluno %s \n", cadUsu.nome, cadAluno.disci.nome);
									printf("atraves do numero %s e agende sua monitoria.\n\n\n\n\n\n\n", cadAluno.disci.tel);
									// amostra ao usuario(monitor) o nome e o telefone do aluno para entrar em contato e agenda a monitoria
									system("pause");
								}
								
								break; 
							case '4':// o usuario deseja consulta suas monitorias realizadas
								system("cls");
								listaMonitoradas(); 
								// retorna a fun��o que contem as instru��es para amostra ao usuario as monitorias que ele confirmou em realizar
								break;
							case '5':// o usuario deseja avaliar o monitor
								system("cls");
								avaliar_monitor(); // retorna a fun��o onde cont�m as instru��es para o aluno avaliar o monitor
								break; 
							case '6':// usuario deseja consulta seus pontos
								system("cls");
								consulta_pontos(cadUsu); // retorna a fun��o ond cont�m as instru��es para o monitor consultar sua nota
							
								break;    				
							default:
								printf("\n\tEscolha invalida! Por favor, escolha novamente.");
						}// fim do switch op
						system("cls");
					}while(op!='7'); // se op for diferente de 6 sai do la�o
				}// fim do if
				
				break;
					
			case '2':
				system ("cls");
				linha ();
				cadastrarUsuario (); //retorna a fun��o para cadastrar o usuario
				break;
			case '3':  
				break;      				
			default:
				printf("\n\tEscolha invalida! Por favor, escolha novamente.");
				
		} // fim do switch opcao
	} while (opcao!='3'); // se opcao for diferente de 3, sai do la�o
	

}// fim da fun��o menu
