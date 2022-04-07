int proximaMonitoria() // Busca a ultima conta cadastrada no arquivo de cliente
{
 struct monitor auxmonitor;
 // posiciona o arquivo no final do registros
 if (fseek(fp,-1*sizeof(struct monitor),SEEK_END)==0)
 {
	fread(&auxmonitor,sizeof(struct monitor),1,fp); //ir para o proximo registro 
	totalusuario=monitorar(auxmonitor, auxmonitor.moni.confiNome,"-2")/sizeof(struct monitor);
	return (auxmonitor.moni.confiNome+1);    
 }
 else
 { 
	totalusuario=0;
	return 1; 
 } 
}// ***Fim proximaConta***
