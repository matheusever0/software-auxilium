int menu_admi()
// inicio da função com as instruções para o menu do administrador
{	
	int opmo;
	do // inicio do laço repita
	{
		system("cls");
		linha(); // retorna a função para preencher o cabeçario 
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
		opmo=getche();// le a opção digitada pelo usuario
		fflush(stdin);
		switch (opmo) // inicio do escolha disbonibilizado para o usuario
		{
			case '1': // mostra todas as disciplinas cadastradas
				system("cls");
				linha();
				DisciplinaCadastrada(); // retornar a função que contém as instruções para mostra todas as disciplinas 
				break;
			case '2': // mostra todas as monitoris cadastradas 
				system("cls");
				linha();
				MonitoriaCadastrada(); // retornar a função que contém as instruções para mostra todas as monitorias
				break;
			case '3':// mostra as pontuações dos monitores 
				system("cls");
				linha();
				pontuacao(); // retornar a função que contém as instruções para mostra todas as pontuações dos monitores
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
	}while (opmo!='5'); // enquanto a opção que o usuario digitar for diferente de 4 executar as instruções que está dentro do laço
}// fim da função com as instruções para o menu do administrador
