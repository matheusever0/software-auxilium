int loginDeAcesso (TcadUsu dados) 
// inicio da fun��o para realizar o login
{
	
	int tam = 0;
	char login[100], senha[100];
	char correto[100];
	int tamanho=100, op;
	int achou=-1;
	memset(login, 0x00, sizeof(login));
 	memset(senha, 0x00, sizeof(senha));
 	// zerando as variaveis login e senha
	

	
	printf("\n\tLOGIN--:");
	gets(login);
	fflush(stdin);
		
	printf("\n\tSENHA--:");
	
	fflush(stdin);
	
	do // inicio do la�o
    {   
         senha[tam] = getch();          
         if(senha[tam] == 0x08 && tam > 0)  //Backspace
         {  
		 	/*
			se a string senha e a variavel tam for maior que 0
			o usuario digitou spa�o 
			executa as instru��es dessa condi��o
			*/  
            printf("\b \b"); 
            senha[tam] = 0x00;
            tam--;

         } 
         else if (senha[tam] == 13) // Enter
         {  
         	/*
			se a string senha for a igual 13 
			o usuario digitou enter 
			executa as instru��es dessa condi��o
			*/ 
            senha[tam] = 0x00;
            break;
        }
        else if (senha[tam] != 0x08)
        {
        	/*
			se a string senha for diferente de 0*08 
			o usuario digitou uma senha compativel 
			executa as instru��es dessa condi��o
			*/ 
            putchar('*');
            tam++;              
         }
    }while(tam < 10) ;
    // enquanto o valor da variavel tam for menor que 10 repete as instru��es que se encontra dentro do la�o 
    if((strcmp(login, "adm")==0))
    {
    	/*
		se login for igual a adm executa as proximas instru��es
		*/
    	menu_admi(); // retorna a fun��o que contem as instru��es do menu do administrador
    	
	}
	else
	{
		fseek(arq,0,SEEK_SET);    // posiciona o arquivo no inicio
  		do 
  		{
			fread(&dados, sizeof(struct nUsuario), 1, arq);	// le registro
				
			if  ((strcmp(login, dados.conta.Nusuario) == 0)) // verifica se o login digitado � igual ao login gravado no ato do cadastro
    		{
				if ((strcmp(senha, dados.conta.senha) == 0)) // verifica se a senha digitada � igual a senha gravada no ato do cadastro
				{	
			
					achou=ftell(arq); //retorna a posicao do registro encontrado
					break;
				}
    		}
       } while (!feof(arq));// enquanto o ponteiro arq n�o encontra feof(0) repete as instru��es do la�o
   	  	if (achou == -1)
   		{	// se a procura achou dados diferentes executa as instru��es dessa condi��o
   	 		printf ("\n\aErro: DADOS INCORRETOS !\n");
	 		system("pause");
   		}
	}
   return achou;  	
	
}// fim da fun��o para realizar o login
