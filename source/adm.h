int menu_admi()
// inicio da fun��o com as instru��es para o menu do administrador
{	
	int opmo;
	do // inicio do la�o repita
	{
		system("cls");
		linha(); // retorna a fun��o para preencher o cabe�ario 
		printf("\n\n\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB----------------------------------\xDB\xDB\xDB");	
		printf("\n\t\t\xDB\xDB\xDB      MENU DO ADMINISTRADOR       \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB----------------------------------\xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 1 - DISCIPLINAS CADASTRADAS      \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 2 - DISCIPLINAS MONITORADAS      \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 3 - PONTUACAO DO MONITOR         \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 4 - USUARIOS CADASTRADOS         \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB                                  \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB 5 - VOLTAR AO MENU PRINCIPAL     \xDB\xDB\xDB");
		printf("\n\t\t\xDB\xDB\xDB----------------------------------\xDB\xDB\xDB");			
		printf("\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");
		printf("\n\t\tEntre com a Opcao: [ ]\b\b");						
		opmo=getche();// le a op��o digitada pelo usuario
		fflush(stdin);
		switch (opmo) // inicio do escolha disbonibilizado para o usuario
		{
			case '1': // mostra todas as disciplinas cadastradas
				system("cls");
				linha();
				DisciplinaCadastrada(); // retornar a fun��o que cont�m as instru��es para mostra todas as disciplinas 
				break;
			case '2': // mostra todas as monitoris cadastradas 
				system("cls");
				linha();
				MonitoriaCadastrada(); // retornar a fun��o que cont�m as instru��es para mostra todas as monitorias
				break;
			case '3':// mostra as pontua��es dos monitores 
				system("cls");
				linha();
				pontuacao(); // retornar a fun��o que cont�m as instru��es para mostra todas as pontua��es dos monitores
				break;
			case '4':
				system("cls");
				linha();
				Usuario_Cadastrado();
				break;
			default:
				printf("\n\tEscolha invalida! Por favor, escolha novamente.");
		}// fim da escolha disbonibilizado para o usuario
		system("cls");
	}while (opmo!='5'); // enquanto a op��o que o usuario digitar for diferente de 4 executar as instru��es que est� dentro do la�o
}// fim da fun��o com as instru��es para o menu do administrador
