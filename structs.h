
typedef struct no_Aluno *listaAlunos;

typedef struct no_Disciplina *listaDisciplinas;

typedef struct no_Exame *listaExames;

typedef struct no_ApontAluno *listaApontAlunos;

typedef struct aluno{
    char *nome;
    long numero;
    int anoMatricula;
    char *curso;
    char *regime;
}Aluno;

typedef struct no_Aluno{
    Aluno aluno;
    listaAlunos next;

}No_Aluno;

typedef struct no_ApontAluno{
    listaAlunos lista;
    listaApontAlunos next;

}No_ApontAluno;

typedef struct disciplina{
    char *nome;
    char *responsavel;
}Disciplina;

typedef struct no_Disciplina{
    Disciplina disciplina;
    listaDisciplinas next;

}No_Disciplina;

typedef struct data{
    int dia;
    int mes;
    int ano;
    int minutos;
    int horas;
}Data;

typedef struct duracao{
    int horas;
    int minutos;
}Duracao;

typedef struct exame{
    listaDisciplinas disciplina;
    char *epoca;
    Data data;
    Duracao duracao;
    char **sala;
    int numInscritos;
    int numSalas;
    listaApontAlunos inscritos;
    int codigo;
}Exame;

typedef struct no_Exame{
    Exame exame;
    listaExames next;
}No_Exame;


listaAlunos criaListaAlunos();
listaExames criaListaExames();
listaDisciplinas criaListaDisciplinas();
listaApontAlunos criaListaApontAlunos();
void insereListaApontAlunos(listaApontAlunos lista,listaAlunos listaalunos);
listaAlunos posicaoAluno(listaAlunos lista,Aluno aluno);
int listaAlunosVazia(listaAlunos lista);
int listaExamesVazia(listaExames lista);
int listaDisciplinasVazia(listaDisciplinas lista);
void destroiListaAlunos(listaAlunos lista);
void destroiListaExames(listaExames lista);
void destroiListaDisciplinas(listaDisciplinas lista);
void insereListaAlunos(listaAlunos lista,Aluno aluno);
void insereListaDisciplinas(listaDisciplinas lista,Disciplina disciplina);
int procuraCodigoExame(listaExames lista,int codigo);
Exame codigoExameExistente(listaExames lista,int codigo);
int confirmaNome(char *nome,int opc);
listaDisciplinas initListaDisciplinas2();
void savelistaDisciplinas(listaDisciplinas listadisciplinas);
int procuraNumeroAluno(listaAlunos lista,long numeroAluno);
Aluno numeroAlunoExistente(listaAlunos lista,long numeroAluno);
int procuraDisciplina(listaDisciplinas lista,char *nomeDisciplina,int opcao);
Disciplina disciplinaExistente(listaDisciplinas lista,char *nomeDisciplina);
int confirmaNumeroAluno(long numero, listaAlunos listaalunos,int opc);
int confirmaRegimeAluno(char *regime,int opc);
int confirmaAnoMatricula(char *anoMatricula,int opc);
listaAlunos initListaAlunos2();
void savelistaAlunos(listaAlunos listaalunos);
void numerosAlunoExistentes(listaAlunos listaalunos);
Aluno criaAluno(listaAlunos listaalunos);
void disciplinasExistentes(listaDisciplinas listadisciplinas);
Disciplina criaDisciplina(listaDisciplinas listadisciplinas);
int confirmaEpoca(char *epoca,int opc);
int confirmaData(Data *data);
int comparaData(Data *data1,Data *data2,int opc);
void  inserirExameOrdenado(listaExames lista,Exame exame,int inicio);
Data somaDuracao(Data data,Duracao duracao);
int confirmaSala(char* sala, listaExames listaexames,Data data,Duracao duracao);
listaDisciplinas posicaoDisciplina(listaDisciplinas lista,char *disciplina);
listaExames initListaExamesApont2(listaAlunos listaalunos,listaDisciplinas listadisciplinas);
void saveListaExames(listaExames listaexames);
int dataFormatoCerto(char *data);
int horaFormatoCerto(char *hora);
Data passaData(char *data,char *hora);
Duracao passaDuracao(char *duracao);
int confirmaInteiro(char *num);
int confirmaCodigo(listaExames lista,char *codigo);
void codigosExistentes(listaExames listaexames);
Exame criaExame(listaExames listaexames,listaDisciplinas listadisciplinas);
void removeExamesPassadosDataPredefinida(listaExames listaexames);
void removeExamesPassados(listaExames listaexames);
void imprimeListaExames(listaExames listaexames,int opc);
void imprimeListaDisciplinas(listaDisciplinas listadisciplinas,int opc);
void imprimeListaAlunos(listaAlunos listaalunos,int opc);
void imprimeListaInscritosExame(Exame exame,int opc);
void examesApontAluno(listaExames listaexames,long numeroAluno,int opc);
int verificaInscrito(listaExames listaexames,Aluno aluno,Exame exame);
void inscreveAluno(listaAlunos listaalunos,listaExames listaexames);
void removeInscricaoApont(listaExames listaexames,listaAlunos listaalunos);
void alteraDadosAluno(listaAlunos listaalunos,Aluno aluno);
void alteraDadosDisciplina(listaDisciplinas listadisciplinas,Disciplina disciplina);
void eliminaAluno(listaExames listaexames,listaAlunos listaalunos,long numAluno);
void eliminaDisciplina(listaExames listaexames,listaDisciplinas listadisciplinas,char* disciplina);
int ficheiroListagens();
void menu(listaAlunos listaalunos,listaExames listaexames,listaDisciplinas listadisciplinas,int ficheiroAuxiliar);
