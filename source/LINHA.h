void linha() { // preenche o cabecario com a nome do sistema versao 
 
 int cont;
 for (cont=0;cont<80;cont++){
 	printf("\xDC"); // mostra em tela a moldura 
 }
 
 printf("\n\t\tAUXILIUM\tVersao 1.0\t\t\n"); // mostra em tela o nome do projeto e a versão
 for(cont=0;cont<80;cont++) printf("\xDC");
}//***Fim funcao linha
