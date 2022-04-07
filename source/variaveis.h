struct cadMonitor // variavel que contem outras variaveis
{
	char confiNome[50]; // variavel utilizada para grava a confirmação do nome na hora de realizar a monitoria
	char confiMateria[50];// variavel utilizada para grava a confirmação da materia na hora de realizar a monitoria
	char nomeCalcu[50];// variavel utilizada para grava a confirmação do nome na hora de solicitar o calculo dos pontos
	char media[50]; // variavel utilizada para grava o resultado do calculo das notas do monitor
	char nomeConfi[50];// variavel utilizada para grava a confirmação do nome do monitor que o adm fez o calculo
	char ava[50]; // variavel utilizada para grava o nome do monitor que vai ser avaliado
	char amo[50]; //variavel utilizada para grava a disciplina que voce recebeu monitoria
	char nota[50];// variavel utilizada para grava a nota da avaliação
	
	
};

typedef struct monitor // a struct cadMonitor, agora passa a chama monitor
{
	struct cadMonitor moni;// variavel que contem outras variaveis
	
}TcadMonitor; // fim da typedef monitor
TcadMonitor cadMonitor; // TcadMonitor passa a se chama cadMonitor

struct cadAl // variavel que contem outras variaveis
{
	char materia[30]; // variavel utilizada para grava a materia que esta com dificuldade
	char nome[50]; // variavel utilizada para confirma o nome quando voce cadastra a disciplina que esta com dificuldade
	char tel[50]; // variavel utilizada para confirma o telefone quando voce cadastra a disciplina que esta com dificuldade
};

typedef struct aluno // a struct cadAl, agora passa a chama aluno
{
	struct cadAl disci; // a struct cadAl passa a se chama disci	
}TcadAluno;// fim da typedef aluno
TcadAluno cadAluno; // TcadAluno passa a se chama cadAluno


struct cadConta
{
	char Nusuario[30]; // variavel utilizada para grava a criação do login de acesso ao sistema
	char senha[30]; // variavel utilizada para grava a criação da senha de acesso ao sistema
		    
};

typedef struct nUsuario // a struct cadConta, agora passa a chama nUsuario
{
	char nome[50]; // variavel utilizada para grava o do nome do usuario
	char sobrenome[50]; // variavel utilizada para grava o sobrenome do usuario
	char cpf[11];// variavel utilizada para grava o cpf do usuario
	char email[50]; // variavel utilizada para grava o email do usuario
	char telefone[20];// variavel utilizada para grava	o telefone do usuario
	char curso [50]; // variavel utilizada para grava o curso do usuario
	char insti[50]; // variavel utilizada para grava a instituição de ensino do usuario
	char cidade[50];// variavel utilizada para grava a cidade do usuario
	char estado[50];// variavel utilizada para grava o estado do usuario
	struct cadConta conta;
	
}TcadUsu;// fim da typedef nUsuario
TcadUsu cadUsu;// TcadUsu passa a se chama cadUsu

FILE*arq; // ponteiro utilizado para armazena o endereço do arquivo usuario
FILE*resu;// ponteiro utilizado para armazena o endereço do arquivo avaliação
FILE*file;// ponteiro utilizado para armazena o endereço do arquivo disciplina
FILE*fp;// ponteiro utilizado para armazena o endereço do arquivo monitorar
FILE*av;// ponteiro utilizado para armazena o endereço do arquivo pontuação

