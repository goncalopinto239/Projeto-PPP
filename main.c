#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX_STRING 1000


listaAlunos criaListaAlunos(){ /*criacao da lista de alunos*/
    listaAlunos aux;
    Aluno no,*noAux;
    noAux=malloc(sizeof(noAux));
    no=*noAux;
    aux = (listaAlunos) malloc(sizeof(No_Aluno));
    if(aux!=NULL){
        aux->aluno = no;
        aux->next = NULL;
    }
    return aux;
}

listaExames criaListaExames(){ /*criacao da lista de exames*/
    listaExames aux;
    Exame no,*noAux;
    noAux=malloc(sizeof(noAux));
    no=*noAux;
    aux = (listaExames) malloc(sizeof(No_Exame));
    if(aux!=NULL){
        aux->exame = no;
        aux->next = NULL;
    }
    return aux;
}

listaDisciplinas criaListaDisciplinas(){ /*criacao da lista de disciplinas*/
    listaDisciplinas aux;
    Disciplina no,*noAux;
    noAux=malloc(sizeof(noAux));
    no=*noAux;
    aux = (listaDisciplinas) malloc(sizeof(No_Disciplina));
    if(aux!=NULL){
        aux->disciplina = no;
        aux->next = NULL;
    }
    return aux;
}

listaApontAlunos criaListaApontAlunos(){ /*criacao da lista de apontadores para alunos*/
    listaApontAlunos aux;
    listaAlunos no,*noAux;
    noAux=malloc(sizeof(noAux));
    no=*noAux;
    aux = (listaApontAlunos) malloc(sizeof(No_ApontAluno));
    if(aux!=NULL){
        aux->lista = no;
        aux->next = NULL;
    }
    return aux;
}

void insereListaApontAlunos(listaApontAlunos lista,listaAlunos listaalunos){ /*insercao na lista de apontadores para alunos*/
    listaApontAlunos novo;
    listaApontAlunos ptr =lista;
    novo=(listaApontAlunos)malloc(sizeof(No_ApontAluno));
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    novo->lista=listaalunos;
    ptr->next=novo;
    novo->next=NULL;
}

listaAlunos posicaoAluno(listaAlunos lista,Aluno aluno){ /*funcao que devolve um ponteiro para o endereco de memoria do no da lista de alunos que contem o aluno passado como parametro*/
    listaAlunos atual = lista->next;
    while (atual!=NULL){
        if(atual->aluno.numero == aluno.numero){
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}

int listaAlunosVazia(listaAlunos lista){ /*verifica se a lista de alunos se encontra vazia*/
    return (lista->next == NULL ? 1 : 0);
}

int listaExamesVazia(listaExames lista){ /*verifica se a lista de exames se encontra vazia*/
    return (lista->next == NULL ? 1 : 0);
}

int listaDisciplinasVazia(listaDisciplinas lista){ /*verifica se a lista de disciplinas se encontra vazia*/
    return (lista->next == NULL ? 1 : 0);
}

void destroiListaAlunos(listaAlunos lista){ /*destruir a lista de alunos*/
    listaAlunos temp_ptr;
    while(listaAlunosVazia(lista) == 0){
        temp_ptr = lista;
        lista = lista->next;
        free(temp_ptr);
    }
    free(lista);
}

void destroiListaExames(listaExames lista){ /*destruir a lista de exames*/
    listaExames temp_ptr;
    while(listaExamesVazia(lista) == 0){
        temp_ptr = lista;
        lista = lista->next;
        free(temp_ptr);
    }
    free(lista);
}

void destroiListaDisciplinas(listaDisciplinas lista){ /*destruir a lista de disciplinas*/
    listaDisciplinas temp_ptr;
    while(listaDisciplinasVazia(lista) == 0){
        temp_ptr = lista;
        lista = lista->next;
        free(temp_ptr);
    }
    free(lista);
}

void insereListaAlunos(listaAlunos lista,Aluno aluno){ /*insercao na lista de alunos*/
    listaAlunos novo;
    listaAlunos ptr =lista;
    novo=(listaAlunos)malloc(sizeof(No_Aluno));
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    novo->aluno.nome=aluno.nome;
    novo->aluno.numero=aluno.numero;
    novo->aluno.anoMatricula=aluno.anoMatricula;
    novo->aluno.curso=aluno.curso;
    novo->aluno.regime=aluno.regime;
    ptr->next=novo;
    novo->next=NULL;
}

void insereListaDisciplinas(listaDisciplinas lista,Disciplina disciplina){ /*insercao na lista de disciplinas*/
    listaDisciplinas novo;
    listaDisciplinas ptr =lista;
    novo=(listaDisciplinas)malloc(sizeof(No_Disciplina));
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    novo->disciplina.nome=disciplina.nome;
    novo->disciplina.responsavel=disciplina.responsavel;
    ptr->next=novo;
    novo->next=NULL;
}

int procuraCodigoExame(listaExames lista,int codigo){ /*devolve 1 caso o codigo passado como parametro corresponda a um exame existente, 0 caso contrario*/
    listaExames atual = lista->next;
    while (atual!=NULL){
        if(atual->exame.codigo == codigo){
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

Exame codigoExameExistente(listaExames lista,int codigo){ /*devolve o Exame que tem como campo codigo o codigo passado como parametro*/
    Exame exame,*exameAux;
    listaExames atual = lista->next;
    exameAux=malloc(sizeof(exameAux));
    exame=*exameAux;
    while (atual!=NULL){
        if(atual->exame.codigo == codigo){
            return atual->exame;
        }
        atual = atual->next;
    }
    return exame;
}

int confirmaNome(char *nome,int opc){ /*verifica se um nome so possui letras*/
    char *ptr,*endptr;
    endptr=nome+strlen(nome);
    for(ptr=nome;ptr<endptr;ptr++){
        if(((*ptr<65) && (*ptr!=32)) || ((*ptr>90) && (*ptr<97)) || (*ptr>122)){
            if(opc==1)
                printf("Simbolos,caracteres numericos e sinais nao sao validos.Introduza uma nome valido por favor\n");
            return 0;
        }
    }
    return 1;
}

listaDisciplinas initListaDisciplinas2(){ /*inicializacao da lista de disciplinas*/
    char aux[MAX_STRING];
    FILE *ficheiro;
    Disciplina disciplina;
    int l;
    char nomeAux[MAX_STRING],responsavelAux[MAX_STRING];
    listaDisciplinas novo=criaListaDisciplinas();
    ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/disciplinas.txt","r");
    while(fgets(aux,MAX_STRING,ficheiro)!=NULL){
        if(sscanf(aux,"%[^*]*%[^*]*\n",nomeAux,responsavelAux)==2){
            l = strlen(nomeAux)+1;
            disciplina.nome=(char *)malloc(l*sizeof(char));
            strcpy(disciplina.nome,nomeAux);
            l = strlen(responsavelAux)+1;
            disciplina.responsavel=(char *)malloc(l*sizeof(char));
            strcpy(disciplina.responsavel,responsavelAux);
            if(confirmaNome(disciplina.nome,0)==1 && confirmaNome(disciplina.responsavel,0)==1)
                insereListaDisciplinas(novo,disciplina);
        }
    }
    fclose(ficheiro);
    return novo;
}

void savelistaDisciplinas(listaDisciplinas listadisciplinas){ /*guardar lista de disciplinas no ficheiro*/
    FILE *ficheiro;
    listaDisciplinas p = listadisciplinas->next;
    ficheiro = fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/disciplinas.txt","w");
    while(p!=NULL){
        fprintf(ficheiro,"%s*%s*\n",p->disciplina.nome,p->disciplina.responsavel);
        p = p->next;
    }
    fclose(ficheiro);
}

int procuraNumeroAluno(listaAlunos lista,long numeroAluno){ /*verifica se o numero de aluno passado como parametro corresponde a um aluno ja existente*/
    listaAlunos atual = lista->next;
    while (atual!=NULL){
        if(atual->aluno.numero == numeroAluno){
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

Aluno numeroAlunoExistente(listaAlunos lista,long numeroAluno){ /*devolve o Aluno que contem o campo numero igual a numeroAluno*/
    Aluno aluno,*alunoAux;
    listaAlunos atual = lista->next;
    alunoAux=malloc(sizeof(alunoAux));
    aluno=*alunoAux;
    while (atual!=NULL){
        if(atual->aluno.numero == numeroAluno){
            return atual->aluno;
        }
        atual = atual->next;
    }
    return aluno;
}


int procuraDisciplina(listaDisciplinas lista,char *nomeDisciplina,int opcao){
    listaDisciplinas atual = lista->next;
    while (atual!=NULL){
        if(strcmp(atual->disciplina.nome,nomeDisciplina)==0){
            if(opcao==0){
                printf("Disciplina ja existente\n");
            }
            return 0;
        }
        atual = atual->next;
    }
    if(opcao==1){
        printf("Disciplina inexistente\n");
    }
    return 1;
}

Disciplina disciplinaExistente(listaDisciplinas lista,char *nomeDisciplina){
    Disciplina disciplina,*disciplinaAux;
    listaDisciplinas atual = lista->next;
    disciplinaAux=malloc(sizeof(disciplinaAux));
    disciplina=*disciplinaAux;
    while (atual!=NULL){
        if(strcmp(atual->disciplina.nome,nomeDisciplina)==0){
            return atual->disciplina;
        }
        atual = atual->next;
    }
    return disciplina;
}

int confirmaNumeroAluno(long numero, listaAlunos listaalunos,int opc){
    int max=10;
	int digitos=0;
	long aux=numero;
	while(aux!=0){
		aux/=10;
		digitos++;
	}
	if (digitos==max){
		if(procuraNumeroAluno(listaalunos, numero)==1){
            if(opc==1)
                printf("Numero de aluno ja existente, por favor introduza um novo numero\n");
			return 0;
		}
		else
			return 1;
	}
	else{
        if(opc==1)
            printf("Numero de aluno invalido, por favor introduza um novo numero\n");
		return 2;
	}
}

int confirmaRegimeAluno(char *regime,int opc){
    if(strcmp(regime,"Normal")==0 || strcmp(regime,"Trabalhador-estudante")==0 || strcmp(regime,"Atleta")==0 || strcmp(regime,"Dirigente Associativo")==0 || strcmp(regime,"Erasmus")==0){
        return 1;
    }
    if(opc==1)
        printf("Regime invalido.Por favor introduza um dos regimes existentes(Normal,Trabalhador-estudante,Atleta,Dirigente Associativo,Erasmus");
    return 0;
}

int confirmaAnoMatricula(char *anoMatricula,int opc){
    char *ptr,*endptr;
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    int anoAtual=tm.tm_year+1900;
    endptr=anoMatricula+strlen(anoMatricula);
    if(strlen(anoMatricula)==4){
        if(atoi(anoMatricula)<=anoAtual){
            for(ptr=anoMatricula;ptr>endptr;ptr++){
                if(*ptr<48 || *ptr>57){
                    if(opc==1)
                        printf("Caracteres nao sao validos.Por favor introduza um numero valido\n");
                    return 0;
                }
            }
            return 1;
        }
        else{
            if(opc==1)
                printf("Ano futuro.Por favor introduza um ano ate ao ano corrente\n");
            return 0;
        }
    }
    else{
        if(opc==1)
            printf("Ano invalido.Por favor introduza um ano valido\n");
        return 0;
    }
}

listaAlunos initListaAlunos2(){
    char aux[MAX_STRING];
    FILE *ficheiro;
    Aluno aluno;
    int l;
    listaAlunos novo=criaListaAlunos();
    char nomeAux[MAX_STRING],cursoAux[MAX_STRING],regimeAux[MAX_STRING],anoMaticulaAux[MAX_STRING];
    ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/alunos.txt","r");
    while(fgets(aux,MAX_STRING,ficheiro)!=NULL){
        if(sscanf(aux,"%[^*]*%ld*%d*%[^*]*%[^*]*\n",nomeAux,&aluno.numero,&aluno.anoMatricula,cursoAux,regimeAux)==5){
            l=strlen(nomeAux)+1;
            aluno.nome = (char *)malloc(l*sizeof(char));
            strcpy(aluno.nome,nomeAux);
            l=strlen(cursoAux)+1;
            aluno.curso = (char *)malloc(l*sizeof(char));
            strcpy(aluno.curso,cursoAux);
            l=strlen(regimeAux)+1;
            aluno.regime = (char *)malloc(l*sizeof(char));
            strcpy(aluno.regime,regimeAux);
            sprintf(anoMaticulaAux, "%d", aluno.anoMatricula);
            if(confirmaNome(aluno.nome,0)==1 && confirmaNumeroAluno(aluno.numero,novo,0)==1 && confirmaAnoMatricula(anoMaticulaAux,0)==1 && confirmaNome(aluno.curso,0)==1 && confirmaRegimeAluno(aluno.regime,0)==1)
                insereListaAlunos(novo,aluno);
        }
    }
    fclose(ficheiro);
    return novo;
}

void savelistaAlunos(listaAlunos listaalunos){
    FILE *ficheiro;
    listaAlunos p = listaalunos->next;
    ficheiro = fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/alunos.txt","w");
    while(p!=NULL){
        fprintf(ficheiro,"%s*%ld*%d*%s*%s*\n",p->aluno.nome,p->aluno.numero,p->aluno.anoMatricula,p->aluno.curso,p->aluno.regime);
        p = p->next;
    }
    fclose(ficheiro);
}

void numerosAlunoExistentes(listaAlunos listaalunos){
    listaAlunos p;
    printf("Numeros de aluno existentes\n");
    p=listaalunos->next;
    while(p!=NULL){
        printf("%ld\n",p->aluno.numero);
        p=p->next;
    }
}

Aluno criaAluno(listaAlunos listaalunos){
    Aluno aluno;
    int l;
    char anoMatricula[MAX_STRING],nomeAux[MAX_STRING],cursoAux[MAX_STRING],regimeAux[MAX_STRING];
    do{
        printf("Nome:");
        scanf(" ");
        gets(nomeAux);
    }while(confirmaNome(nomeAux,1)!=1);
    l=strlen(nomeAux)+1;
    aluno.nome=(char *)malloc(l*sizeof(char));
    strcpy(aluno.nome,nomeAux);
    numerosAlunoExistentes(listaalunos);
    do{
        printf("Numero de Aluno:");
        scanf("%ld",&aluno.numero);
    }while(confirmaNumeroAluno(aluno.numero,listaalunos,1)!= 1);
    do{
        printf("Ano de matricula:");
        scanf(" ");
        gets(anoMatricula);
    }while(confirmaAnoMatricula(anoMatricula,1)!=1);
    aluno.anoMatricula=atoi(anoMatricula);
    do{
        printf("Curso:");
        scanf(" ");
        gets(cursoAux);
    }while(confirmaNome(cursoAux,1)!=1);
    l=strlen(cursoAux)+1;
    aluno.curso=(char *)malloc(l*sizeof(char));
    strcpy(aluno.curso,cursoAux);
    do{
        printf("Regime(Normal,Trabalhador-estudante,Atleta,Dirigente Associativo,Erasmus):");
        scanf(" ");
        gets(regimeAux);
    }while(confirmaRegimeAluno(regimeAux,1)!=1);
    l=strlen(regimeAux)+1;
    aluno.regime=(char *)malloc(l*sizeof(char));
    strcpy(aluno.regime,regimeAux);
    printf("Aluno criado com sucesso\n");
    return aluno;
}

void disciplinasExistentes(listaDisciplinas listadisciplinas){
    listaDisciplinas p;
    printf("Disciplinas existentes\n");
    p=listadisciplinas->next;
    while(p!=NULL){
        printf("%s\n",p->disciplina.nome);
        p=p->next;
    }
}

Disciplina criaDisciplina(listaDisciplinas listadisciplinas){
    Disciplina disciplina;
    int l;
    char nomeAux[MAX_STRING],responsavelAux[MAX_STRING];
    disciplinasExistentes(listadisciplinas);
    do{
        printf("Nome da disciplina:");
        scanf(" ");
        gets(nomeAux);
    }while(confirmaNome(nomeAux,1)!=1 || procuraDisciplina(listadisciplinas,nomeAux,0)!=1);
    l=strlen(nomeAux)+1;
    disciplina.nome=(char *)malloc(l*sizeof(char));
    strcpy(disciplina.nome,nomeAux);
    do{
        printf("Nome do responsavel:");
        scanf(" ");
        gets(responsavelAux);
    }while(confirmaNome(responsavelAux,1)!=1);
    l=strlen(responsavelAux)+1;
    disciplina.responsavel=(char *)malloc(l*sizeof(char));
    strcpy(disciplina.responsavel,responsavelAux);
    printf("Disciplina criada com sucesso\n");
    return disciplina;
}

int confirmaEpoca(char *epoca,int opc){
    fflush(stdin);
    if(strcmp(epoca,"Normal")==0 || strcmp(epoca,"Recurso")==0 || strcmp(epoca,"Especial")==0){
        return 1;
    }
    if(opc==1){
        printf("Epoca invalida.Por favor introduza uma das seguintes epocas:Normal,Recurso,Especial\n");
    }
    return 0;
}

int confirmaData(Data *data){
    int conf = 0;
    if(data->mes==2){
        if(data->ano % 4 == 0 && (data->ano % 400 == 0 || data->ano % 100 != 0)){
            if(data->dia>=1 && data->dia<=29){
                if(data->horas>=0 && data->horas<=23){
                    if(data->minutos>=0 && data->minutos<=59){
                        conf = 1;
                    }
                    else{
                        conf = 0;
                    }
                }
                else{

                    conf = 0;
                }
            }
            else{
                conf = 0;
            }
        }
        else{
            if(data->dia>=1 && data->dia<=28){
                if(data->horas>=0 && data->horas<=23){
                    if(data->minutos>=0 && data->minutos<=59){
                        conf = 1;
                    }
                    else{
                        conf = 0;
                    }
                }
                else{
                    conf = 0;
                }
            }
        }
    }
    else if(data->mes==4 || data->mes==6 || data->mes==9 || data->mes==11){
        if(data->dia>=1 && data->dia<=30){
            if(data->horas>=0 && data->horas<=23){
                if(data->minutos>=0 && data->minutos<=59){
                    conf = 1;
                }
                else{
                    conf = 0;
                }
            }
            else{
                conf = 0;
            }
        }
        else{
            conf = 0;
        }

    }
    else if(data->mes==1 || data->mes==3 || data->mes==5 || data->mes==7 || data->mes==8 || data->mes==10 || data->mes==12 ){
        if(data->dia>=1 && data->dia<=31){
            if(data->horas>=0 && data->horas<=23){
                if(data->minutos>=0 && data->minutos<=59){
                    conf = 1;
                }
                else{
                    conf = 0;
                }
            }
            else{
                conf = 0;
            }
        }
        else{
            conf = 0;
        }
    }
    if(conf==0){
        printf("A data ou hora introduzida nao se encontra de acordo com as normas do calendario.Por favor introduza uma data valida\n");
    }
    return conf;
}


int comparaData(Data *data1,Data *data2,int opc){
    int conf = 0;
    if (data1->ano>data2->ano){
        conf = 1;
    }
    else if(data1->ano<data2->ano){
        conf = -1;
    }
    else{
        if (data1->mes>data2->mes){
            conf = 1;
        }
        else if (data1->mes<data2->mes){
            conf = -1;
        }
        else{
            if (data1->dia>data2->dia){
                conf = 1;
            }
            else if(data1->dia<data2->dia){
                conf = -1;
            }
            else{
                if(data1->horas>data2->horas){
                    conf = 1;
                }
                else if(data1->horas<data2->horas){
                    conf = -1;
                }
                else{
                    if(data1->minutos>data2->minutos){
                        conf = 1;
                    }
                    else if(data1->minutos < data2->minutos){
                        conf = -1;
                    }
                }
            }
        }
    }
    if(opc==1 && conf!=-1)
        printf("Data passada.Por favor introduza uma data futura\n");
    return conf;
}

void  inserirExameOrdenado(listaExames lista,Exame exame,int inicio){
   listaExames novo;
   listaExames ant,act;
   act = lista->next;
   novo=(listaExames)malloc(sizeof(No_Exame));
   novo->exame.disciplina=exame.disciplina;
   novo->exame.epoca=exame.epoca;
   novo->exame.data.dia=exame.data.dia;
   novo->exame.data.mes=exame.data.mes;
   novo->exame.data.ano=exame.data.ano;
   novo->exame.data.horas=exame.data.horas;
   novo->exame.data.minutos=exame.data.minutos;
   novo->exame.duracao.horas=exame.duracao.horas;
   novo->exame.duracao.minutos=exame.duracao.minutos;
   novo->exame.numInscritos=exame.numInscritos;
   novo->exame.numSalas=exame.numSalas;
   novo->exame.sala=exame.sala;
   novo->exame.inscritos=exame.inscritos;
   novo->exame.codigo=exame.codigo;
   ant=lista;
   act=lista->next;
   while(act!=NULL && comparaData(&(act->exame.data),&(novo->exame.data),0)==inicio){ /*para inserir entre a data mais recente e a data mais antiga a data que estamos a introduzir*/
        ant=ant->next;
        act=act->next;
   }
   ant->next=novo;
   novo->next=act;
}

Data somaDuracao(Data data,Duracao duracao){ /*soma a uma data uma dada duracao*/
    Data ret;
    ret.dia = data.dia;
    ret.mes = data.mes;
    ret.ano = data.ano;
    ret.horas = data.horas+duracao.horas;
    ret.minutos = data.minutos+duracao.minutos;
    if(ret.minutos >= 60){
        ret.horas ++;
        ret.minutos = ret.minutos % 60;
    }
    return ret;
}
int confirmaSala(char* sala, listaExames listaexames,Data data,Duracao duracao){ /*confirma se a sala passada como parametro esta em utilizacao na Data que e passada como parametro*/
    int i;
    Data aux,aux2;
    listaExames atual = listaexames->next;
    while (atual!=NULL){
        for(i=0;i<atual->exame.numSalas;i++){
            if(strcmp(atual->exame.sala[i],sala)==0){
                aux = somaDuracao(data,duracao);
                aux2 = somaDuracao(atual->exame.data,atual->exame.duracao);
                if((comparaData(&data,&(atual->exame.data),0)==-1 && comparaData(&aux,&(atual->exame.data),0)==1) || (comparaData(&data,&(atual->exame.data),0)==0) || (comparaData(&data,&(atual->exame.data),0)==1 && comparaData(&data,&(aux2),0)==-1)){
                     printf("Sala ocupada.Por favor escolha outra sala\n");
                     return 0;
                }
            }
        }
        atual = atual->next;
    }
    return 1;
}

listaDisciplinas posicaoDisciplina(listaDisciplinas lista,char *disciplina){
    listaDisciplinas atual = lista->next;
    while (atual!=NULL){
        if(strcmp(atual->disciplina.nome,disciplina)==0){
            return atual;
        }
        atual = atual->next;
    }
    return NULL;
}

listaExames initListaExamesApont2(listaAlunos listaalunos,listaDisciplinas listadisciplinas){
    char aux[MAX_STRING];
    FILE *ficheiro;
    int i,j,l;
    int conf = 1;
    int contador = 0;
    Exame exame;
    Aluno aluno,aluno2;
    listaAlunos pos;
    char epocaAux[MAX_STRING],nomeDisciplinaAux[MAX_STRING],salaAux[MAX_STRING];
    listaExames novo=criaListaExames();
    ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/exames.txt", "r");
     while(fgets(aux,MAX_STRING,ficheiro)!=NULL){
        if(sscanf(aux,"%[^*]*%[^*]*%d/%d/%d-%d:%d*%d:%d*%d*%d*%d*\n",nomeDisciplinaAux,epocaAux,&exame.data.dia,&exame.data.mes,&exame.data.ano,&exame.data.horas,&exame.data.minutos,&exame.duracao.horas,&exame.duracao.minutos,&exame.codigo,&exame.numSalas,&exame.numInscritos)==12){
            l=strlen(epocaAux)+1;
            exame.epoca = (char *)malloc(l*sizeof(char));
            strcpy(exame.epoca,epocaAux);
            if(procuraDisciplina(listadisciplinas,nomeDisciplinaAux,2)==0){
                exame.disciplina=posicaoDisciplina(listadisciplinas,nomeDisciplinaAux);
                exame.sala=(char **)malloc(exame.numSalas*sizeof(char *));
                for(j=0;j<strlen(aux);j++){
                    if(aux[j]=='*')
                        contador++;
                    if(contador==7){ /*contador para verificar quando aparece o setimo *,pois a seguir estao as salas*/
                        contador=0;
                        break;
                    }
                }
                for(i=0;i<exame.numSalas;i++){
                    sscanf(aux+(j+1),"%[^,],",salaAux);
                    if(confirmaNome(salaAux,0)!=1 || confirmaSala(salaAux,novo,exame.data,exame.duracao)!=1){
                        conf = 0;
                        break;
                    }
                    else{
                        l=strlen(salaAux)+1;
                        exame.sala[i]=(char *)malloc(l*sizeof(char));
                        strcpy(exame.sala[i],salaAux);
                        j+=l;
                    }
                }
                if(conf==1){
                    sscanf(aux,"*");
                    j++;
                    exame.inscritos=criaListaApontAlunos();
                    for(i=0;i<exame.numInscritos;i++){
                        if(sscanf(aux+(j+1),"%ld:",&aluno.numero)==1){
                            if(confirmaNumeroAluno(aluno.numero,listaalunos,0)!=0){
                                conf = 0;
                                break;
                            }
                            else{
                                aluno2 = numeroAlunoExistente(listaalunos,aluno.numero);
                                pos=posicaoAluno(listaalunos,aluno2);
                                insereListaApontAlunos(exame.inscritos,pos);
                                j+=11;
                            }
                        }
                        else{
                            conf = 0;
                            break;
                        }
                    }
                    if(conf==1){
                        sscanf(aux,"*\n");
                        if(confirmaData(&exame.data)==1 && confirmaEpoca(exame.epoca,0)){ /*caso algo nao esteja no formato certo essa linha nao e inserida na lista*/
                            inserirExameOrdenado(novo,exame,-1);
                        }
                    }
                }
            }
        }
    }
    return novo;

}

void saveListaExames(listaExames listaexames){
    FILE *ficheiro;
    int i;
    listaExames p = listaexames->next;
    listaApontAlunos inscritos;
    ficheiro = fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/exames.txt","w");
    while(p!=NULL){
        inscritos = p->exame.inscritos;
        inscritos = inscritos->next;
        fprintf(ficheiro,"%s*%s*%d/%d/%d-%d:%d*%d:%d*%d*%d*%d*",p->exame.disciplina->disciplina.nome,p->exame.epoca,p->exame.data.dia,p->exame.data.mes,p->exame.data.ano,p->exame.data.horas,p->exame.data.minutos,p->exame.duracao.horas,p->exame.duracao.minutos,p->exame.codigo,p->exame.numSalas,p->exame.numInscritos);
        for(i=0;i<p->exame.numSalas;i++){
            fprintf(ficheiro,"%s,",p->exame.sala[i]);
        }
        fprintf(ficheiro,"*");
        while(inscritos!=NULL){
            fprintf(ficheiro,"%ld:",inscritos->lista->aluno.numero);
            inscritos= inscritos->next;
        }
        fprintf(ficheiro,"*\n");
        p=p->next;
    }
    fclose(ficheiro);
}

int dataFormatoCerto(char *data){
    int conf = 1;
    char *ptr;
    char *endptr=data+strlen(data);
    if(strlen(data)==10){
        for(ptr=data;ptr<endptr;ptr++){
            if(ptr==data+2 || ptr==data+5){
                if(*ptr!='/'){
                    conf=0;
                }
            }
            else{
                if(isdigit(*ptr)==0){
                    conf = 0;
                }
            }
        }
    }
    else{
        conf = 0;
    }
    if(conf==0)
        printf("A data introduzida nao se encontra no formato correto. Por favor introduza uma data no formato dd/mm/aaaa\n");
    return conf;
}

int horaFormatoCerto(char *hora){
    int conf = 1;
    char *ptr;
    char *endptr=hora+strlen(hora);
    if(strlen(hora)==5){
        for(ptr=hora;ptr<endptr;ptr++){
            if(ptr==hora+2){
                if(*ptr!=':'){
                    conf=0;
                }
            }
            else{
                if(isdigit(*ptr)==0){
                    conf = 0;
                }
            }
        }
    }
    else{
        conf = 0;
    }
    if(conf==0)
        printf("A hora introduzida nao se encontra no formato certo. Por favor introduza uma hora no formato hh:mm\n");
    return conf;
}

Data passaData(char *data,char *hora){
    Data data2;
    char dia[MAX_STRING],mes[MAX_STRING],ano[MAX_STRING],horas[MAX_STRING],minutos[MAX_STRING];
    int dia2,mes2,ano2,horas2,minutos2;
    strcpy(dia,"");
    strcpy(mes,"");
    strcpy(ano,"");
    strcpy(horas,"");
    strcpy(minutos,"");
    memcpy(dia,data,2);
    *(dia+2)='\0';
    dia2=atoi(dia);
    memcpy(mes,data+3,2);
    *(mes+2)='\0';
    mes2=atoi(mes);
    memcpy(ano,data+6,4);
    *(ano+4)='\0';
    ano2=atoi(ano);
    memcpy(horas,hora,2);
    *(horas+2)='\0';
    horas2=atoi(horas);
    memcpy(minutos,hora+3,2);
    *(minutos+2)='\0';
    minutos2=atoi(minutos);
    data2.dia=dia2;
    data2.mes=mes2;
    data2.ano=ano2;
    data2.horas=horas2;
    data2.minutos=minutos2;
    return data2;
}

Duracao passaDuracao(char *duracao){
    Duracao duracao2;
    char horas[MAX_STRING],minutos[MAX_STRING];
    int horas2,minutos2;
    strcpy(horas,"");
    strcpy(minutos,"");
    memcpy(horas,duracao,2);
    *(horas+2)='\0';
    horas2=atoi(horas);
    memcpy(minutos,duracao+3,2);
    *(minutos+2)='\0';
    minutos2=atoi(minutos);
    duracao2.horas=horas2;
    duracao2.minutos=minutos2;
    return duracao2;
}


int confirmaInteiro(char *num){
    char *ptr;
    char *endptr=num+strlen(num);
    for(ptr=num;ptr<endptr;ptr++){
        if(isdigit(*ptr)==0){
            printf("Caracteres nao sao validos.Por favor introduza um numero valido\n");
            return 0;
        }
    }
    return 1;
}


int confirmaCodigo(listaExames lista,char *codigo){ /*verifica se um dado codigo ja se encontra em utilizacao*/
    listaExames atual = lista->next;
    while (atual!=NULL){
        if(atual->exame.codigo==atoi(codigo)){
            printf("Codigo ja existente.Por favor introduza um codigo diferente\n");
            return 0;
        }
        atual = atual->next;
    }
    return 1;
}

void codigosExistentes(listaExames listaexames){
    listaExames p;
    printf("Codigos de exame existente\n");
    p=listaexames->next;
    while(p!=NULL){
       printf("%d\n",p->exame.codigo);
       p=p->next;
    }
}


Exame criaExame(listaExames listaexames,listaDisciplinas listadisciplinas){
    Exame exame;
    Data dataAux;
    Duracao duracaoAux;
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    Data dataSistema;
    int i,l;
    char nomeAux[MAX_STRING],epocaAux[MAX_STRING],data[MAX_STRING],hora[MAX_STRING],duracao[MAX_STRING],num[MAX_STRING],salaAux[MAX_STRING];
    dataSistema.ano=tm.tm_year+1900;
    dataSistema.mes=tm.tm_mon+1;
    dataSistema.dia=tm.tm_mday;
    dataSistema.horas=tm.tm_hour;
    dataSistema.minutos=tm.tm_min;
    disciplinasExistentes(listadisciplinas);
    do{
        printf("Nome da disciplina:");
        scanf(" ");
        gets(nomeAux);
    }while(procuraDisciplina(listadisciplinas,nomeAux,1)!=0);
    exame.disciplina=posicaoDisciplina(listadisciplinas,nomeAux);
    do{
        printf("Epoca(Normal,Recurso,Especial):");
        scanf(" ");
        gets(epocaAux);
    }while(confirmaEpoca(epocaAux,1)!=1);
    l=strlen(epocaAux)+1;
    exame.epoca=(char *)malloc(l*sizeof(char));
    strcpy(exame.epoca,epocaAux);
    do{
        printf("Data(dd/mm/aaaa):");
        scanf(" ");
        gets(data);
        printf("Hora(hh:mm):");
        scanf(" ");
        gets(hora);
        dataAux=passaData(data,hora);
    }while(dataFormatoCerto(data)!=1 || horaFormatoCerto(hora)!=1 || comparaData(&dataSistema,&dataAux,1)!=-1|| confirmaData(&dataAux)!=1);
    exame.data.dia=dataAux.dia;
    exame.data.mes=dataAux.mes;
    exame.data.ano=dataAux.ano;
    exame.data.horas=dataAux.horas;
    exame.data.minutos=dataAux.minutos;
    do{
        printf("Duracao(hh:mm):");
        scanf(" ");
        gets(duracao);
    }while(horaFormatoCerto(duracao)!=1);
    duracaoAux=passaDuracao(duracao);
    exame.duracao.horas=duracaoAux.horas;
    exame.duracao.minutos=duracaoAux.minutos;
    do{
        printf("Numero de salas para o exame:");
        scanf(" ");
        gets(num);
    }while(confirmaInteiro(num)!=1);
    exame.numSalas=atoi(num);
    exame.sala=(char **)malloc(exame.numSalas*sizeof(char *));
    for(i=0;i<exame.numSalas;i++){
        do{
            printf("Sala:");
            scanf(" ");
            gets(salaAux);
        }while(confirmaNome(salaAux,1)!=1 || confirmaSala(salaAux,listaexames,exame.data,exame.duracao)!=1);
        l=strlen(salaAux)+1;
        exame.sala[i]=(char *)malloc(l*sizeof(char));
        strcpy(exame.sala[i],salaAux);
    }
    codigosExistentes(listaexames);
    do{
        printf("Codigo:");
        scanf(" ");
        gets(num);
    }while(confirmaInteiro(num)!=1 || confirmaCodigo(listaexames,num)!=1);
    exame.codigo=atoi(num);
    exame.numInscritos=0;
    exame.inscritos=criaListaApontAlunos();
    printf("Exame criado com sucesso\n");
    return exame;

}

void removeExamesPassadosDataPredefinida(listaExames listaexames){ /*remove exames anteriores a uma data predefinida*/
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    Data dataSistema;
    Data dataAux;
    Data aux;
    int conf = 0;
    char data[MAX_STRING],hora[MAX_STRING];
    listaExames p = listaexames->next;
    listaExames ant,atual;
    ant=listaexames;
    dataSistema.ano=tm.tm_year+1900;
    dataSistema.mes=tm.tm_mon+1;
    dataSistema.dia=tm.tm_mday;
    dataSistema.horas=tm.tm_hour;
    dataSistema.minutos=tm.tm_min;
    do{
        printf("Data(dd/mm/aaaa):");
        scanf(" ");
        gets(data);
        printf("Hora(hh:mm):");
        scanf(" ");
        gets(hora);
        dataAux=passaData(data,hora);
    }while(dataFormatoCerto(data)!=1 || horaFormatoCerto(hora)!=1 || comparaData(&dataSistema,&dataAux,1)!=-1|| confirmaData(&dataAux)!=1);
    while(p!=NULL){
        aux=somaDuracao(p->exame.data,p->exame.duracao);
        if(comparaData(&dataAux,&aux,0)!=-1){
            conf = 1;
            atual = p;
            if(atual!=NULL){
                ant->next=atual->next;
                free(atual);
            }
        }
        ant = ant->next;
        p = p->next;
    }
    if(conf==1)
        printf("Exames anteriores a %d/%d/%d as %d:%d horas eliminados com sucesso\n",dataAux.dia,dataAux.mes,dataAux.ano,dataAux.horas,dataAux.minutos);
    else
        printf("Nao existem exames anteriores a %d/%d/%d as %d:%d horas ja concluidos\n",dataAux.dia,dataAux.mes,dataAux.ano,dataAux.horas,dataAux.minutos);
}

void removeExamesPassados(listaExames listaexames){ /*remove exames anteriores a data de sistema*/
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    Data dataSistema;
    Data aux;
    listaExames p = listaexames->next;
    listaExames ant,atual;
    ant=listaexames;
    dataSistema.ano=tm.tm_year+1900;
    dataSistema.mes=tm.tm_mon+1;
    dataSistema.dia=tm.tm_mday;
    dataSistema.horas=tm.tm_hour;
    dataSistema.minutos=tm.tm_min;
    while(p!=NULL){
        aux = somaDuracao(p->exame.data,p->exame.duracao);
        if(comparaData(&dataSistema,&aux,0)!=-1){
            atual = p;
            if(atual!=NULL){
                ant->next=atual->next;
                free(atual);
            }
        }
        ant = ant->next;
        p = p->next;
    }
}

void imprimeListaExames(listaExames listaexames,int opc){
    char salas[MAX_STRING];
    int i;
    listaExames p;
    FILE *ficheiro;
    printf("\nExames existentes\n\n");
    if(opc==1)
        ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/auxiliar.txt", "a");
    strcpy(salas,"");
    p=listaexames->next;
    while(p!=NULL){
        for(i=0;i<p->exame.numSalas;i++){
            strcat(salas,p->exame.sala[i]);
            if(i!=p->exame.numSalas-1)
                strcat(salas,",");
        }
        printf("Codigo:%d\nDisciplina:%s\nEpoca:%s\nData:%d-%d-%d as %d:%d horas\nDuracao:%d horas e %d minutos\nSalas:%s\nNumero de alunos inscritos:%d\n\n",p->exame.codigo,p->exame.disciplina->disciplina.nome,p->exame.epoca,p->exame.data.dia,p->exame.data.mes,p->exame.data.ano,p->exame.data.horas,p->exame.data.minutos,p->exame.duracao.horas,p->exame.duracao.minutos,salas,p->exame.numInscritos);
        if(opc==1){
            fprintf(ficheiro,"Codigo:%d\nDisciplina:%s\nEpoca:%s\nData:%d-%d-%d as %d:%d horas\nDuracao:%d horas e %d minutos\nSalas:%s\nNumero de alunos inscritos:%d\n\n",p->exame.codigo,p->exame.disciplina->disciplina.nome,p->exame.epoca,p->exame.data.dia,p->exame.data.mes,p->exame.data.ano,p->exame.data.horas,p->exame.data.minutos,p->exame.duracao.horas,p->exame.duracao.minutos,salas,p->exame.numInscritos);
        }
        p=p->next;
        strcpy(salas,"");
    }
    if(opc==1){
        fprintf(ficheiro,"\n");
        fclose(ficheiro);
    }
}

void imprimeListaDisciplinas(listaDisciplinas listadisciplinas,int opc){
    listaDisciplinas p;
    FILE *ficheiro;
    printf("\nDisciplinas existentes\n\n");
    if(opc==1)
        ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/auxiliar.txt", "a");
    p=listadisciplinas->next;
    while(p!=NULL){
        printf("Disciplina:%s\nDocente responsavel:%s\n\n",p->disciplina.nome,p->disciplina.responsavel);
        if(opc==1){
            fprintf(ficheiro,"Disciplina:%s\nDocente responsavel:%s\n\n",p->disciplina.nome,p->disciplina.responsavel);
        }
        p=p->next;
    }
    if(opc==1){
        fprintf(ficheiro,"\n");
        fclose(ficheiro);
    }
}

void imprimeListaAlunos(listaAlunos listaalunos,int opc){
    listaAlunos p;
    FILE *ficheiro;
    printf("\nAlunos existentes\n\n");
    if(opc==1)
        ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/auxiliar.txt", "a");
    p=listaalunos->next;
    while(p!=NULL){
        printf("Nome:%s\nNumero:%ld\nCurso:%s\nRegime:%s\nAno de matricula:%d\n\n",p->aluno.nome,p->aluno.numero,p->aluno.curso,p->aluno.regime,p->aluno.anoMatricula);
        if(opc==1){
            fprintf(ficheiro,"Nome:%s\nNumero:%ld\nCurso:%s\nRegime:%s\nAno de matricula:%d\n\n",p->aluno.nome,p->aluno.numero,p->aluno.curso,p->aluno.regime,p->aluno.anoMatricula);
        }
        p=p->next;
    }
    if(opc==1){
        fprintf(ficheiro,"\n");
        fclose(ficheiro);
    }
}

void imprimeListaInscritosExame(Exame exame,int opc){
    listaApontAlunos p;
    FILE *ficheiro;
    printf("\nAlunos inscritos no exame %d\n\n",exame.codigo);
    if(opc==1)
        ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/auxiliar.txt", "a");
    p=exame.inscritos->next;
    while(p!=NULL){
        printf("Nome:%s\nNumero:%ld\n\n",p->lista->aluno.nome,p->lista->aluno.numero);
        if(opc==1){
           fprintf(ficheiro,"Nome:%s\nNumero:%ld\n\n",p->lista->aluno.nome,p->lista->aluno.numero);
        }
        p=p->next;
    }
    if(opc==1){
        fprintf(ficheiro,"\n");
        fclose(ficheiro);
    }
}

void examesApontAluno(listaExames listaexames,long numeroAluno,int opc){
    char salas[MAX_STRING];
    int i;
    listaExames p;
    listaApontAlunos a;
    FILE *ficheiro;
    strcpy(salas,"");
    printf("\nLista de exames do aluno n %ld\n\n",numeroAluno);
    if(opc==1)
        ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/auxiliar.txt", "a");
    p=listaexames->next;
    while(p!=NULL){
        for(i=0;i<p->exame.numSalas;i++){
            strcat(salas,p->exame.sala[i]);
            if(i!=p->exame.numSalas-1)
                strcat(salas,",");
        }
        a=p->exame.inscritos->next;
        while(a!=NULL){
            if(a->lista->aluno.numero==numeroAluno){
                printf("Disciplina:%s\nEpoca:%s\nData:%d-%d-%d as %d:%d horas\nDuracao:%d horas e %d minutos\nSalas:%s\nNumero de alunos inscritos:%d\n\n",p->exame.disciplina->disciplina.nome,p->exame.epoca,p->exame.data.dia,p->exame.data.mes,p->exame.data.ano,p->exame.data.horas,p->exame.data.minutos,p->exame.duracao.horas,p->exame.duracao.minutos,salas,p->exame.numInscritos);
                if(opc==1){
                    fprintf(ficheiro,"Disciplina:%s\nEpoca:%s\nData:%d-%d-%d as %d:%d horas\nDuracao:%d horas e %d minutos\nSalas:%s\nNumero de alunos inscritos:%d\n\n",p->exame.disciplina->disciplina.nome,p->exame.epoca,p->exame.data.dia,p->exame.data.mes,p->exame.data.ano,p->exame.data.horas,p->exame.data.minutos,p->exame.duracao.horas,p->exame.duracao.minutos,salas,p->exame.numInscritos);
                }
            }
            a=a->next;
        }
        p=p->next;
        strcpy(salas,"");
    }
    if(opc==1){
        fprintf(ficheiro,"\n");
        fclose(ficheiro);
    }
}

int verificaInscrito(listaExames listaexames,Aluno aluno,Exame exame){ /*verifica se o aluno passado como parametro se encontra inscrito no exame passado tambem como parametro*/
    listaExames p = listaexames->next;
    listaApontAlunos ant,atual;
    while(p!=NULL){
        if(p->exame.codigo == exame.codigo){
            ant = p->exame.inscritos;
            atual = ant->next;
            while(atual!=NULL && atual->lista->aluno.numero != aluno.numero){
                atual=atual->next;
                ant=ant->next;
            }
            if(atual!=NULL){
                return 1;
            }
        }
        p = p->next;
    }
    return 0;
}


void inscreveAluno(listaAlunos listaalunos,listaExames listaexames){
    long num;
    int cod;
    char salaAux[MAX_STRING];
    int l;
    Aluno aluno;
    Exame exame;
    Data dataSistema;
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    listaExames p;
    listaAlunos aux;
    dataSistema.ano=tm.tm_year+1900;
    dataSistema.mes=tm.tm_mon+1;
    dataSistema.dia=tm.tm_mday;
    dataSistema.horas=tm.tm_hour;
    dataSistema.minutos=tm.tm_min;
    p=listaexames->next;
    imprimeListaExames(listaexames,0);
    do{
        printf("Codigo do exame:");
        scanf("%d",&cod);
    }while(procuraCodigoExame(listaexames,cod)!=1);
    exame = codigoExameExistente(listaexames,cod);
    imprimeListaInscritosExame(exame,0);
    imprimeListaAlunos(listaalunos,0);
    do{
        printf("Numero do aluno que deseja inscrever:");
        scanf("%ld",&num);
    }while(procuraNumeroAluno(listaalunos,num)!=1);
    aluno = numeroAlunoExistente(listaalunos,num);
    if(comparaData(&dataSistema,&exame.data,0)==-1){ /*verifica se o exame ja ocorreu*/
        if(verificaInscrito(listaexames,aluno,exame)!=1){ /*verifica se o aluno ja se encontra inscrito*/
            if(strcmp(aluno.regime,"Trabalhador-estudante")==0 || strcmp(aluno.regime,"Atleta")==0 || strcmp(aluno.regime,"Dirigente Associativo")==0 || aluno.anoMatricula+3==dataSistema.ano){
                while(p!=NULL){
                    if(p->exame.codigo==exame.codigo){
                        if(p->exame.numSalas*30 == p->exame.numInscritos){
                            printf("Salas atuais cheias.Introduza uma nova sala para o exame:");
                            do{
                                scanf(" ");
                                gets(salaAux);
                            }while(confirmaNome(salaAux,1)!=1 || confirmaSala(salaAux,listaexames,p->exame.data,p->exame.duracao)!=1);
                            p->exame.numSalas++;
                            p->exame.sala=(char **)realloc(p->exame.sala,(p->exame.numSalas)*sizeof(char *)); /*aloca mais uma sala*/
                            l=strlen(salaAux)+1;
                            p->exame.sala[p->exame.numSalas-1]=(char *)malloc(l*sizeof(char));
                            strcpy(p->exame.sala[p->exame.numSalas-1],salaAux);
                            printf("Sala adicionada com sucesso ao exame\n");
                        }
                        p->exame.numInscritos++;
                        aux=posicaoAluno(listaalunos,aluno); /*obtem o ponteiro para o no da lista de alunos que contem o Aluno aluno*/
                        insereListaApontAlunos(p->exame.inscritos,aux);
                    }
                    p=p->next;
                }
                printf("Aluno inscrito no exame com sucesso\n");
            }
            else{
                if(strcmp(exame.epoca,"Especial")==0){
                    printf("O aluno em causa nao possui estatuto para a realizacao deste exame\n");
                }
                else{
                    while(p!=NULL){
                        if(p->exame.codigo==exame.codigo){
                            if(p->exame.numSalas*30 == p->exame.numInscritos){
                                printf("Salas atuais cheias.Introduza uma nova sala para o exame:");
                                do{
                                    scanf(" ");
                                    gets(salaAux);
                                }while(confirmaNome(salaAux,1)!=1 || confirmaSala(salaAux,listaexames,p->exame.data,p->exame.duracao)!=1);
                                p->exame.numSalas++;
                                p->exame.sala=(char **)realloc(p->exame.sala,(p->exame.numSalas)*sizeof(char *)); /*aloca mais uma sala*/
                                l=strlen(salaAux)+1;
                                p->exame.sala[p->exame.numSalas-1]=(char *)malloc(l*sizeof(char));
                                strcpy(p->exame.sala[p->exame.numSalas-1],salaAux);
                                printf("Sala adicionada com sucesso ao exame\n");
                            }
                            p->exame.numInscritos++;
                            aux=posicaoAluno(listaalunos,aluno); /*obtem o ponteiro para o no da lista de alunos que contem o Aluno aluno*/
                            insereListaApontAlunos(p->exame.inscritos,aux);
                        }
                        p=p->next;
                    }
                    printf("Aluno inscrito no exame com sucesso\n");
                }
            }
        }
        else{
            printf("O aluno selecionado ja se encontra inscrito neste exame\n");
        }
    }
    else{
        printf("As inscricoes para este exame ja nao se encontram disponiveis visto que o exame se encontra a decorrer\n");
    }
}


void removeInscricaoApont(listaExames listaexames,listaAlunos listaalunos){
    int cod;
    long num;
    listaExames p = listaexames->next;
    listaApontAlunos ant,atual;
    imprimeListaExames(listaexames,0);
    do{
        printf("Codigo:");
        scanf("%d",&cod);
    }while(procuraCodigoExame(listaexames,cod)!=1);
    imprimeListaAlunos(listaalunos,0);
    do{
        printf("Numero do aluno a cancelar a inscricao:");
        scanf("%ld",&num);
    }while(procuraNumeroAluno(listaalunos,num)!=1);
    if(verificaInscrito(listaexames,numeroAlunoExistente(listaalunos,num),codigoExameExistente(listaexames,cod))){
        while(p!=NULL){
            if(p->exame.codigo == cod){
                ant = p->exame.inscritos;
                atual = ant->next;
                while(atual!=NULL && atual->lista->aluno.numero != num){
                    atual=atual->next;
                    ant=ant->next;
                }
                if(atual!=NULL){
                    ant->next=atual->next;
                    p->exame.numInscritos--;
                    free(atual);
                }
            }
            p = p->next;
        }
        printf("Inscricao cancelada com sucesso\n");
    }
    else{
        printf("O aluno em causa nao se encontra inscrito no referido exame\n");
    }
}

void alteraDadosAluno(listaAlunos listaalunos,Aluno aluno){
    int l;
    char escolha[MAX_STRING],anoAux[MAX_STRING],nomeAux[MAX_STRING],cursoAux[MAX_STRING],regimeAux[MAX_STRING];
    long numeroAux;
    listaAlunos p = listaalunos->next;
    while(p!=NULL){
        if(p->aluno.numero==aluno.numero){
            printf("Alterar:\n1-Nome\n2-Numero de aluno\n3-Ano de matricula\n4-Curso\n5-Regime\n6-Sair\nEscolha:");
            scanf("%s",escolha);
            switch(atoi(escolha)){
                case 1:
                    do{
                        printf("Novo nome:");
                        scanf(" ");
                        gets(nomeAux);
                    }while(confirmaNome(nomeAux,1)!=1);
                    l=strlen(nomeAux)+1;
                    p->aluno.nome=(char *)malloc(l*sizeof(char));
                    strcpy(p->aluno.nome,nomeAux);
                    printf("Alteracao realizada com sucesso\n");
                    break;
                case 2:
                    do{
                        printf("Novo numero de aluno:");
                        scanf(" ");
                        scanf("%ld",&numeroAux);
                    }while(confirmaNumeroAluno(numeroAux,listaalunos,1)!=1);
                    p->aluno.numero=numeroAux;
                    printf("Alteracao realizada com sucesso\n");
                    break;
                case 3:
                    do{
                        printf("Novo ano de matricula:");
                        scanf(" ");
                        scanf("%s",anoAux);
                    }while(confirmaAnoMatricula(anoAux,1)!=1);
                    p->aluno.anoMatricula=atoi(anoAux);
                    printf("Alteracao realizada com sucesso\n");
                    break;
                case 4:
                    do{
                        printf("Novo curso:");
                        scanf(" ");
                        gets(cursoAux);
                    }while(confirmaNome(cursoAux,1)!=1);
                    l=strlen(cursoAux)+1;
                    p->aluno.curso=(char *)malloc(l*sizeof(char));
                    strcpy(p->aluno.curso,cursoAux);
                    printf("Alteracao realizada com sucesso\n");
                    break;
                case 5:
                    do{
                        printf("Novo regime:");
                        scanf(" ");
                        gets(regimeAux);
                    }while(confirmaRegimeAluno(regimeAux,1)!=1);
                    l=strlen(regimeAux)+1;
                    p->aluno.regime=(char *)malloc(l*sizeof(char));
                    strcpy(p->aluno.regime,regimeAux);
                    printf("Alteracao realizada com sucesso\n");
                    break;
                case 6:
                    break;
                default:
                    printf("Escolha invalida.Por favor introduza uma das opcoes existentes\n");
                    alteraDadosAluno(listaalunos,aluno);
            }
        }
        p=p->next;
    }

}

void alteraDadosDisciplina(listaDisciplinas listadisciplinas,Disciplina disciplina){
    char escolha[MAX_STRING],nomeAux[MAX_STRING],responsavelAux[MAX_STRING];
    int l;
    listaDisciplinas p;
    p = listadisciplinas->next;
    while(p!=NULL){
        if(strcmp(p->disciplina.nome,disciplina.nome)==0){
            printf("Alterar:\n1-Nome da disciplina\n2-Responsavel da disciplina\n3-Sair\nEscolha:");
            scanf("%s",escolha);
            switch(atoi(escolha)){
                case 1:
                    do{
                        printf("Novo nome da disciplina:");
                        scanf(" ");
                        gets(nomeAux);
                    }while(confirmaNome(nomeAux,1)!=1);
                    l=strlen(nomeAux)+1;
                    p->disciplina.nome=(char *)malloc(l*sizeof(char));
                    strcpy(p->disciplina.nome,nomeAux);
                    printf("Alteracao realizada com sucesso\n");
                    break;
                case 2:
                    do{
                        printf("Novo responsavel da disciplina:");
                        scanf(" ");
                        gets(responsavelAux);
                    }while(confirmaNome(responsavelAux,1)!=1);
                    l=strlen(responsavelAux)+1;
                    p->disciplina.responsavel=(char *)malloc(l*sizeof(char));
                    strcpy(p->disciplina.responsavel,responsavelAux);
                    printf("Alteracao realizada com sucesso\n");
                    break;
                case 3:
                    break;
                default:
                    printf("Escolha invalida.Por favor introduza uma das opcoes existentes\n");
                    alteraDadosDisciplina(listadisciplinas,disciplina);
            }
        }
        p=p->next;
    }
}

void eliminaAluno(listaExames listaexames,listaAlunos listaalunos,long numAluno){
    listaAlunos p = listaalunos->next;
    listaExames e = listaexames->next;
    listaApontAlunos a,antAp,actAp;
    listaAlunos ant,atual;
    ant=listaalunos;
    while(e!=NULL){
        a=e->exame.inscritos->next;
        antAp=e->exame.inscritos;
        while(a!=NULL){
            if(a->lista->aluno.numero==numAluno){
                actAp=a;
                while(actAp!=NULL && actAp->lista->aluno.numero != numAluno){
                    actAp=actAp->next;
                    antAp=antAp->next;
                }
                if(actAp!=NULL){
                    antAp->next=actAp->next;
                    e->exame.numInscritos--;
                    free(actAp);
                }
            }
            antAp=antAp->next;
            a=a->next;
        }
        e=e->next;
    }
    while(p!=NULL){
        if(p->aluno.numero==numAluno){
            atual=p;
            if(atual!=NULL){
                ant->next=atual->next;
                free(atual);
                printf("Aluno eliminado com sucesso\n");
            }
        }
        ant=ant->next;
        p=p->next;
    }
}

void eliminaDisciplina(listaExames listaexames,listaDisciplinas listadisciplinas,char* disciplina){
    listaDisciplinas p = listadisciplinas->next;
    listaDisciplinas ant,atual;
    listaExames e = listaexames->next;
    listaExames antE,atualE;
    antE = listaexames;
    while(e!=NULL){
        if(strcmp(e->exame.disciplina->disciplina.nome,disciplina)==0){
            atualE=e;
            if(atualE!=NULL){
                antE->next=atualE->next;
                free(atualE);
            }
        }
        antE=antE->next;
        e=e->next;
    }
    ant = listadisciplinas;
    while(p!=NULL){
        if(strcmp(p->disciplina.nome,disciplina)==0){
            atual=p;
            if(atual!=NULL){
                ant->next=atual->next;
                free(atual);
                printf("Disciplina eliminado com sucesso\n");
            }
        }
        ant=ant->next;
        p=p->next;
    }
}

int ficheiroListagens(){ /*funcao saber se o utilizador deseja ou nao guardar as listagens no ficheiro auxiliar*/
    char escolha[MAX_STRING];
    int ret;
    printf("Deseja guardar o historico de listagens desta iteracao?:\n1-Sim\n2-Nao\nEscolha:");
    scanf("%s",escolha);
    switch(atoi(escolha)){
        case 1:
            ret = 1;
            break;
        case 2:
            ret = 2;
            break;
        default:
            printf("Opcao invalida. Por favor introduza uma das opcoes validas(1-Sim,2-Nao)\n");
            ret = -1;
            ficheiroListagens();
            break;
    }
    return ret;
}

void menu(listaAlunos listaalunos,listaExames listaexames,listaDisciplinas listadisciplinas,int ficheiroAuxiliar){
    char escolha[MAX_STRING],escolha2[MAX_STRING],aux[MAX_STRING];
    long num;
    int cod;
    removeExamesPassados(listaexames);
    saveListaExames(listaexames);
    printf("1-Alunos\n2-Disciplinas\n3-Exames\n4-Sair\nEscolha:");
    scanf(" %s",escolha);
    switch(atoi(escolha)){
        case 1:
            printf("1-Criar\n2-Listar alunos\n3-Listar exames de um aluno\n4-Alterar dados de um aluno\n5-Apagar aluno\n6-Voltar\nEscolha:");
            scanf(" %s",escolha2);
            switch(atoi(escolha2)){
                case 1:
                    insereListaAlunos(listaalunos,criaAluno(listaalunos));
                    savelistaAlunos(listaalunos);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 2:
                    imprimeListaAlunos(listaalunos,ficheiroAuxiliar);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 3:
                    imprimeListaAlunos(listaalunos,ficheiroAuxiliar);
                    do{
                        printf("Numero do aluno que pretende consultar exames:");
                        scanf("%ld",&num);
                    }while(procuraNumeroAluno(listaalunos,num)!=1);
                    examesApontAluno(listaexames,num,ficheiroAuxiliar);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 4:
                    imprimeListaAlunos(listaalunos,ficheiroAuxiliar);
                    do{
                        printf("Numero do aluno que pretende alterar dados:");
                        scanf("%ld",&num);
                    }while(procuraNumeroAluno(listaalunos,num)!=1);
                    alteraDadosAluno(listaalunos,numeroAlunoExistente(listaalunos,num));
                    savelistaAlunos(listaalunos);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 5:
                    do{
                        printf("Numero do aluno que pretende eliminar:");
                        scanf("%ld",&num);
                    }while(procuraNumeroAluno(listaalunos,num)!=1);
                    eliminaAluno(listaexames,listaalunos,num);
                    savelistaAlunos(listaalunos);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 6:
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                default:
                    printf("Escolha invalida.Por favor introduza uma das opcoes do menu\n");
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
            }
            break;
        case 2:
            printf("1-Criar\n2-Listar disciplinas\n3-Alterar dados de uma disciplina\n4-Apagar disciplina\n5-Voltar\nEscolha:");
            scanf(" %s",escolha2);
            switch(atoi(escolha2)){
                case 1:
                    insereListaDisciplinas(listadisciplinas,criaDisciplina(listadisciplinas));
                    savelistaDisciplinas(listadisciplinas);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 2:
                    imprimeListaDisciplinas(listadisciplinas,ficheiroAuxiliar);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 3:
                    disciplinasExistentes(listadisciplinas);
                    do{
                        printf("Disciplina que pretende alterar dados:");
                        scanf(" ");
                        gets(aux);
                    }while(procuraDisciplina(listadisciplinas,aux,1)!=0);
                    alteraDadosDisciplina(listadisciplinas,disciplinaExistente(listadisciplinas,aux));
                    savelistaDisciplinas(listadisciplinas);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 4:
                    disciplinasExistentes(listadisciplinas);
                    do{
                        printf("Disciplina que pretende apagar:");
                        scanf(" ");
                        gets(aux);
                    }while(procuraDisciplina(listadisciplinas,aux,1)!=0);
                    eliminaDisciplina(listaexames,listadisciplinas,aux);
                    savelistaDisciplinas(listadisciplinas);
                    saveListaExames(listaexames);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 5:
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                default:
                    printf("Escolha invalida.Por favor introduza uma das opcoes do menu\n");
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
            }
            break;
        case 3:
            printf("1-Criar\n2-Listar exames\n3-Listar alunos inscritos num exame\n4-Inscrever aluno em exame\n5-Cancelar inscricao em exame\n6-Eliminar exames anteriores a uma data\n7-Voltar\nEscolha:");
            scanf(" %s",escolha2);
            switch(atoi(escolha2)){
                case 1:
                    inserirExameOrdenado(listaexames,criaExame(listaexames,listadisciplinas),-1);
                    saveListaExames(listaexames);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 2:
                    imprimeListaExames(listaexames,ficheiroAuxiliar);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 3:
                    imprimeListaExames(listaexames,ficheiroAuxiliar);
                    do{
                        printf("Codigo do exame que pretende consultar os alunos inscritos:");
                        scanf("%d",&cod);
                    }while(procuraCodigoExame(listaexames,cod)!=1);
                    imprimeListaInscritosExame(codigoExameExistente(listaexames,cod),ficheiroAuxiliar);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 4:
                    inscreveAluno(listaalunos,listaexames);
                    saveListaExames(listaexames);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 5:
                    removeInscricaoApont(listaexames,listaalunos);
                    saveListaExames(listaexames);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 6:
                    removeExamesPassadosDataPredefinida(listaexames);
                    saveListaExames(listaexames);
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                case 7:
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
                default:
                    printf("Escolha invalida.Por favor introduza uma das opcoes do menu\n");
                    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
                    break;
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Escolha invalida.Por favor introduza uma das opcoes do menu\n");
            menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
            break;
    }

}

int main()
{
    FILE *ficheiro;
    int ficheiroAuxiliar;
    listaAlunos listaalunos=initListaAlunos2();
    listaDisciplinas listadisciplinas = initListaDisciplinas2();
    listaExames listaexames=initListaExamesApont2(listaalunos,listadisciplinas);
    ficheiro=fopen("/Users/Goncalopinto/Documents/PPP/Projeto1617/auxiliar.txt", "w");
    fclose(ficheiro);
    ficheiroAuxiliar = ficheiroListagens();
    menu(listaalunos,listaexames,listadisciplinas,ficheiroAuxiliar);
    destroiListaAlunos(listaalunos);
    destroiListaExames(listaexames);
    destroiListaDisciplinas(listadisciplinas);
    return 0;
}
