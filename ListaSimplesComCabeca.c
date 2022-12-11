#include<stdio.h>
#include<stdlib.h>

typedef struct TipoListaComCabeca{
	int chave;
	struct TipoListaComCabeca *prox;
}TLsc;

TLsc *criaLista();
TLsc *alocaNo(int k);
void insereInicio(TLsc *pcabeca, int k);
void insereFim(TLsc *pcabeca, int k);
void insereOrdenado(TLsc *pcabeca, int k);
void atualizaNo(TLsc *pcabeca, int novoValor);
TLsc *pesquisaNo(TLsc *pcabeca, int k);
TLsc *copiaLista(TLsc *pcabeca);
TLsc *ordenaLista(TLsc *pcabeca);
void removeInicio(TLsc *pcabeca);
void removeUltimoNo(TLsc *pcabeca);
void removeNo(TLsc *pcabeca, int k);
void liberaNos(TLsc *pcabeca);
void imprime(TLsc *pcabeca);

/*
void LiberaTudo(TLsc **pcabeca);
TLsc *intersecaoListas(TLsc *pcabeca1, TLsc *pcabeca2);
void insereRemove(TLsc *pcabeca1, TLsc *pcabeca2);
void transplantaNo(TLsc *pcabeca1, TLsc *pcabeca2);
*/

int main(){
	TLsc *cabeca=criaLista(), *pPesquisa=NULL, *cabeca2=NULL;
	int op=1, valor=0;
	
	while(op != 0){
			printf("\n1 - Inserir inicio");
			printf("\n2 - Inserir fim");
			printf("\n3 - Inserir ordenado");
			printf("\n4 - Atualizar primeiro no");
			printf("\n5 - Pesquisar no");//erro
			printf("\n6 - Copiar lista");
			printf("\n7 - Ordenar lista");
			printf("\n8 - Remover inicio");//erro ao remover quando a lista ta vazia
			printf("\n9 - Remove ultimo no");
			printf("\n10 - Remove qualquer no");//queria colocar um printf quando nao existe o numero
			printf("\n11 - Remove todos os nos");
			printf("\n12 - imprimir");
			printf("\n0 - Sair: ");
			scanf("%d", &op);
		switch(op){
			case 1:{
				printf("\nValor: ");
				scanf("%d", &valor);
				insereInicio(cabeca, valor);	
			}break;
			case 2:{
				printf("\nValor: ");
				scanf("%d", &valor);
				insereFim(cabeca, valor);
			}break;
			case 3:{
				printf("\nValor: ");
				scanf("%d", &valor);
				insereOrdenado(cabeca, valor);
			}break;
			case 4:{
				printf("\nValor: ");
				scanf("%d", &valor);
				atualizaNo(cabeca->prox, valor);
			}break;
			case 5:{
				printf("\nValor: ");
				scanf("%d", &valor);
				pPesquisa = pesquisaNo(cabeca, valor);
				if(pPesquisa == NULL) printf("\nvalor nao encontrado");
			}break;
			case 6:{
				cabeca2 = copiaLista(cabeca);
				imprime(cabeca2->prox);
			}break;
			case 7:{
				cabeca2 = ordenaLista(cabeca);
				printf("\nLista ordenada\n");
				imprime(cabeca2->prox);
			}break;
			case 8:{
				removeInicio(cabeca);
			}break;
			case 9:{
				removeUltimoNo(cabeca);
			}break;
			case 10:{
				printf("\nValor: ");
				scanf("%d", &valor);
				removeNo(cabeca, valor);
			}break;
			case 11:{
				liberaNos(cabeca);
			}break;
			case 12:{
				imprime(cabeca->prox);
			}break;
		}
	}
	
	
}

TLsc *criaLista(){
	TLsc *cabeca=(TLsc *)malloc(sizeof(TLsc));
	if(cabeca == NULL) return;
	cabeca->chave = 0;
	cabeca->prox = NULL;
	return cabeca;
}

TLsc *alocaNo(int k){
	TLsc *no = (TLsc *)malloc(sizeof(TLsc));
	if(no == NULL) return;
	no->chave = k;
	no->prox = NULL;
	return no;
}

void insereInicio(TLsc *pcabeca, int k){
	TLsc *no = alocaNo(k);
	if(no == NULL) return;
	no->prox = pcabeca->prox;
	pcabeca->prox = no;
}

void insereFim(TLsc *pcabeca, int k){
	TLsc *no = alocaNo(k);
	if(no==NULL)return;
	TLsc *aux=NULL;
	aux = pcabeca;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = no;
}

void insereOrdenado(TLsc *pcabeca, int k){
	TLsc *aux = NULL, *no = alocaNo(k);
	if(no == NULL) return;
	
	if(pcabeca->prox == NULL){
		no->prox = NULL;
		pcabeca->prox = no;
		return;
	}
	else if(no->chave < pcabeca->prox->chave){
		no->prox = pcabeca->prox;
		pcabeca->prox = no;
	}
	else{
		aux = pcabeca->prox;
		while(aux->prox && no->chave > aux->prox->chave){
			aux = aux->prox;
		}
		no->prox = aux->prox;
		aux->prox = no;
	}
}

void atualizaNo(TLsc *pcabeca, int novoValor){
	if(pcabeca == NULL){
		printf("\nLista vazia!");
	}
	pcabeca->chave = novoValor;
}

TLsc *pesquisaNo(TLsc *pcabeca, int k){
	if(pcabeca->prox == NULL){
		printf("\nLista vazia!");
	}
	while(pcabeca != NULL){
		if(pcabeca->chave == k){
			printf("\nno %d encontrado!", pcabeca->chave);
			pcabeca = pcabeca->prox;
		}
	}
}

TLsc *copiaLista(TLsc *pcabeca){
	TLsc *novaLista=NULL, *aux=NULL;
	if(pcabeca == NULL){
		printf("\nLista vazia!");
		return NULL;
	}
	novaLista = criaLista(); //poderia ter feito na main
	if(novaLista == NULL) return NULL;
	
	aux = pcabeca->prox;
	while(aux != NULL){
		insereInicio(novaLista, aux->chave);
		aux = aux->prox;
	}
	return novaLista;
}

TLsc *ordenaLista(TLsc *pcabeca){
	TLsc *novo, *novaLista, *aux, *t;
	int chave;
	if(pcabeca == NULL) return NULL;
	if(pcabeca->prox == NULL){
		printf("\nLista vazia!");
		return NULL;
	}
	novaLista = criaLista();
	if(novaLista == NULL) return NULL;
	aux = pcabeca->prox;
	if(aux->prox == NULL){
		novo = (TLsc *)malloc(sizeof(TLsc));
		if(novo == NULL) return NULL;
		novo->chave = aux->chave;
		novo->prox = NULL;
		novaLista->prox = novo;
		return novaLista;
	}
	novaLista = copiaLista(pcabeca);
	if(novaLista == NULL) return NULL;
	
	aux = novaLista;
	while(aux != NULL){
		t = aux->prox;
		while(t != NULL){
			if(aux->chave > t->chave){
				chave = aux->chave;
				aux->chave = t->chave;
				t->chave = chave;
			}
			t = t->prox;
		}
		aux = aux->prox;
	}
	return novaLista;
}

void removeInicio(TLsc *pcabeca){
	TLsc *aux = pcabeca->prox;
	if(aux == NULL){
		printf("\nLista vazia!");
	}
	pcabeca->prox = aux->prox;
	free(aux);
	aux = NULL;
}

void removeUltimoNo(TLsc *pcabeca){
	TLsc *aux = pcabeca;
	if(pcabeca->prox == NULL){
		printf("\nLista vazia!");
		return;
	}
	while(aux->prox->prox != NULL){
		aux = aux->prox;
	}
	TLsc *aux2 = aux->prox;
	aux->prox = NULL;
	free(aux2);
	aux2 = NULL;
}

void removeNo(TLsc *pcabeca, int k){
	TLsc *remove=NULL, *aux;
	if(pcabeca->prox == NULL){
		printf("\nLista vazia!");
		return;
	}
	if(pcabeca->prox->chave == k){
		remove = pcabeca->prox;
		pcabeca->prox = remove->prox;
	}else{
		aux = pcabeca->prox;
		while(aux->prox && aux->prox->chave != k){
			aux = aux->prox;
		}
		if(aux->prox){
			remove = aux->prox;
			aux->prox = remove->prox;
		}
	}
}

void liberaNos(TLsc *pcabeca){
	TLsc *aux=pcabeca->prox;
	if(aux == NULL){
		printf("\nLista vazia!");
	}
	while(pcabeca->prox != NULL){
		pcabeca->prox = aux->prox;
	}
	free(aux);
	aux = NULL;
}

void imprime(TLsc *pcabeca){
	if(pcabeca == NULL){
		printf("\nLista vazia!");
	}
	else{
		printf("\nLista: ");
		while(pcabeca != NULL){
			printf("%d ", pcabeca->chave);
			pcabeca = pcabeca->prox;
		}
	}	
}

















