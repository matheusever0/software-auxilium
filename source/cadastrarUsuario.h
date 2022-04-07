
int cadastrarUsuario () 
// inicio da fun�ao para cadastra usuario
{
	
	char nome[50], sobre[50], usu[50];
	char senha[50], shC[30]; // usada na fun��o strcpy
	int ij, x;
	int tam = 0;
	memset(cadUsu.conta.senha, 0x00, sizeof(cadUsu.conta.senha));
	// zerando a string cadUsu.conta.senha
	
	
	
	printf("\n===============================================\n");
	printf("\t\tINICIANDO CADASTRO\n");
	printf("\n===============================================\n");
	
		
	printf ("\nNOME-------------: ");
	fflush(stdin);	
	gets(cadUsu.nome); // guarda o nome 
	if (strcmp(cadUsu.nome,"\0")!=0) // verificar se a variavel cadUsu � diferente de 0
	{   
		printf("\n\nSOBRENOME--------: ");
		fflush(stdin);
		gets(cadUsu.sobrenome);// guarda o sobrenome
		
		printf("\n\nEMAIL------------: ");
		fflush(stdin);
		gets(cadUsu.email); // guarda o email
		
		do //inicio do la�o
  		{
		  printf ("\n\nCPF--------------: ");
		  fflush(stdin);
		  gets (cadUsu.cpf); // guarda o cpf
		  if (strlen(cadUsu.cpf)!=11) // verificar se o cpf tem 11 digitos
		  {
	 	   	 printf("\nCPF invalido !! %d (%s), favor digite novamente\n",strlen(cadUsu.cpf),cadUsu.cpf);
      	  }	
        } while (strlen(cadUsu.cpf)!=11); 
	    /*
		enquanto o numero caracteres dentro da string cadUsu.cpf 
		for diferente de 11 repite as instru��es que se encontra dentro do la�o
		*/ 
		printf("\n\nUSUARIO----------: ");
		fflush(stdin);
		gets (cadUsu.conta.Nusuario); // guarda o usuario de acesso
		
		printf("\n\nSENHA------------: ");
		fflush(stdin);
			
			
		do // inicio do la�o
		{   
		    cadUsu.conta.senha[tam] = getch();          
		    if(cadUsu.conta.senha[tam] == 0x08 && tam > 0)  
		    {  
		 	/*
			se a string cadUsu.conta.senha 0*08 e a variavel tam for maior que 0
			o usuario digitou spa�o 
			executa as instru��es dessa condi��o
			*/ 
		    	printf("\b \b"); 
		        cadUsu.conta.senha[tam] = 0x00; // a string recebe o valor 0
		        tam--; // a variavel decrementada 
		
		    } 
		    else if (cadUsu.conta.senha[tam] == 13) // Enter
		    {  
		    /*
			se a string cadUsu.conta.senha for a igual 13 
			o usuario digitou enter 
			executa as instru��es dessa condi��o
			*/ 
		    	cadUsu.conta.senha[tam] = 0x00;
		        break;
		    }
		    else if (cadUsu.conta.senha[tam] != 0x08)
		    {
		    /*
			se a string cadUsu.conta.senha for diferente de 0*08 
			o usuario digitou uma senha compativel 
			executa as instru��es dessa condi��o
			*/ 
		    	putchar('\n*');
		       	tam++;              
		    }
		}while(tam < 10) ;
		// enquanto o valor da variavel tam for menor que 10 repete as instru��es que se encontra dentro do la�o 
			
		do // inicio do la�o repita
	  	{
			printf("\n\n\nTELEFONE[DD]-----: ");
			fflush(stdin);
			gets (cadUsu.telefone); // guarda o telefone
			if (strlen(cadUsu.telefone)!=11) // verificar se o  tem 11 digitos
			{
		 		printf("\nTelefone invalido !! %d (%s), favor digite novamente\n",strlen(cadUsu.telefone),cadUsu.telefone);
	      	}	
	    } while (strlen(cadUsu.telefone)!=11);
		// enquanto o numero de linhas da string for diferente de 11 repete as instru��es que se encontra dentro do la�o
		printf("\n\nCURSO------------: ");
		fflush(stdin);
		gets(cadUsu.curso); // guarda o curso
		
		printf("\n\nINSTITUICAO------: ");
		fflush(stdin);
		gets(cadUsu.insti); // guarda a institui��o
		
		printf("\n\nCIDADE-----------: ");
		fflush(stdin);
		gets(cadUsu.cidade); // guarda a cidade
		
		printf("\n\nESTADO-----------: ");
		fflush(stdin);
		gets(cadUsu.estado); //guarda o estado
			
	
		do 
		{
			printf("\n\nConfirma gravacao do novo usuario [S/N] ?");
			gets(shC);
			// inicio da condi��o para saber se a compara��o de Cc com "s ou n" � igual a 0
			if ((strcmp(shC,"s")!=0) && (strcmp(shC,"S")!=0) && (strcmp(shC,"n")!=0) && (strcmp(shC,"N")!=0))
			{
			/*
			se a compara��o for diferete de 0 executa as proximas instru��es
			*/
				printf("\nOpcao invalida !!!");
			}
			else if	((strcmp(shC,"s")==0) || (strcmp(shC,"S")==0))
			{
			/*
			se a compara��o for igual a 0 executa as proximas instru��es
			*/
				fseek(arq,0,SEEK_END);// posiciona no arquivo no final    
				fwrite(&cadUsu,sizeof(struct nUsuario),1,arq);
				/*
				Grava os dados da estrutura "cadUsu" no arquivo usuario.dat
				&cadUsu = � a regi�o de memoria na qual ser�o armazenados os dados lidos
				sizeof = o tamanho da unidade a ser lida
				1 = total de unidades a ser lida
				arq = ponteiro para o arquivo 
				*/									    
			}	
            else
			{
				printf("\nDados nao foi salvo !\n");					  
			}                    
			system("pause");	
		} while ((strcmp(shC,"s")!=0) && (strcmp(shC,"S")!=0) && (strcmp(shC,"n")!=0) && (strcmp(shC,"N")!=0));	
		// enquanto a compara��o da variavel ShC com "s ou n" for diferente de 0 repete as instru��es que se encontra dentro do la�o 
	return 1;
	}
}// fim da fun�ao para cadastra usuario
