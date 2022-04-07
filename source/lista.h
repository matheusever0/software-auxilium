int lista()
{
	int opmo;
	do
	{
	
		printf("\n\n\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB-----------------------------------------------\xDB\xDB\xDB");	
		printf("\n\t\t\xDB\xDB\xDB            	MENU DO ADMINISTRADOR             \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB-----------------------------------------------\xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 1 - DISCIPLINAS CADASTRADAS             	  \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 2 - DISCIPLINAS MONITORADAS             	  \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 3 - PONTUACAO DO MONITOR       	          \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB                                               \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 4 - VOLTAR AO MENU PRINCIPAL                  \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB---------------------------                    \xDB\xDB\xDB");			
		printf("\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");
		printf("\n\t\tEntre com a Opcao: [ ]\b\b");						
		opmo=getche();
		fflush(stdin);
		switch (opmo)
		{
			case '1':
				system("cls");
				linha();
				DisciplinaCadastrada();
				break;
			case '2':
				system("cls");
				linha();
				break;
			case '3':
				system("cls");
				linha();
				break;
			default:
				printf("\n\tEscolha invalida! Por favor, escolha novamente.");
		}// fim do switch
		system("cls");
	}while (opmo!='4');
}
