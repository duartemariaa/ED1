#include<stdio.h>
#include<stdlib.h>

typedef struct TipoListaCircular{
	int chave;
	struct TipoListaCircular *prox;
}TLc;


void insereInicio(TLc **p, int k);
TLc *insereFim(TLc **p, int k);
void removeFim(TLc **p);
void removeNo(TLc **p, int k);
void copiaLista(TLc *p1, TLc *p2); //erro
void imprime(TLc *p);

int main(){
	TLc *pLista = NULL;
	TLc *pLista2 = NULL;
	int op=1, valor=0;
	
	while(op!=0){
		printf("\n1 - Inserir inicio");
		printf("\n2 - Inserir fim");
		printf("\n3 - Remove fim");
		printf("\n4 - Remove no");
		printf("\n5 - Copia lista");
		printf("\n6 - Imprimir");
		printf("\n0 - Sair: ");
		scanf("%d", &op);
		switch(op){
			case 1:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				insereInicio(&pLista, valor);
			}break;
			case 2:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				insereFim(&pLista, valor);
			}break;
			case 3:{
				removeFim(&pLista);
			}break;
			case 4:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				removeNo(&pLista, valor);
			}break;
			case 5:{
				copiaLista(pLista, pLista2);
				printf("\nLista 2: ");
				imprime(pLista2);
			}break;
			case 6:{
				imprime(pLista);
			}break;
		}
	}
}

void insereInicio(TLc **p, int k){
	if(*p == NULL){
		*p = (TLc *)malloc(sizeof(TLc));
		if(*p != NULL){
			(*p)->chave = k;
			(*p)->prox = *p;
		}
	}
	else{
		TLc *novo = (TLc *)malloc(sizeof(TLc));
		if(novo == NULL) return;
		novo->chave = k;
		novo->prox = (*p)->prox;
		(*p)->prox = novo;
		//(*p) = (*p)->prox; //insere fim
	}
}

TLc *insereFim(TLc **p, int k){
	TLc *novo = (TLc *)malloc(sizeof(TLc));
	if(novo == NULL) return;
	
	novo->chave = k;
	novo->prox = NULL;
	
	if(*p == NULL){
		novo->prox = novo;
		*p = novo;
		return novo;
	}
	novo->prox = (*p)->prox;
	(*p)->prox = novo;
	*p = novo; //tirando, insere inicio
	return novo;
}

void removeFim(TLc **p){
	if(*p == NULL){
		printf("\nLista vazia!");
		return;
	}
	TLc *pPrim = (*p)->prox;
	TLc *pPenult = (*p)->prox;
	
	if(pPrim->prox != pPrim){
		while(pPenult->prox != *p){
			pPenult = pPenult->prox;
		}
		free(*p);
		*p = pPenult;
		pPenult->prox = pPrim;
	}
	else{
		free(*p);
		*p = NULL;
	}
}

void removeNo(TLc **p, int k){
	TLc *aux = *p, *aux2 = *p;
	
	if(*p == NULL){
		printf("\nLista vazia!");
		return;
	}
	if(((*p)->chave == k) && ((*p)->prox == *p)){
		free(*p);
		*p = NULL;
		return;
	}
	if((*p)->chave == k){
		while(aux->prox != *p){
			aux = aux->prox;
		}
		aux->prox = (*p)->prox;
		aux = (*p)->prox;
		free(*p);
		*p = aux;
		return;
	}
	do{
		if(aux->chave == k){
			aux2->prox = aux->prox;
			free(aux);
			aux = NULL;
			return;
		}
		aux2 = aux;
		aux = aux->prox;
	}while(aux != (*p));	
}

void copiaLista(TLc *p1, TLc *p2){
	TLc *aux=p1;
	while(aux != p1){
		insereInicio(&p2, aux->chave);
		aux = aux->prox;
	}
}

void imprime(TLc *p){
	if(p == NULL){
		printf("\nLista vazia!");
		return;
	}
	TLc *aux = p;
	do{
		printf("%d ", aux->chave);
		aux = aux->prox;
	}while(aux != p);
}





