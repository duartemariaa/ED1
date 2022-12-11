#include<stdio.h>
#include<stdlib.h>

typedef struct TipoListaDuplaEncadeada{
	int chave;
	struct TipoListaDuplaEncadeada *prox;
	struct TipoListaDuplaEncadeada *ant;
}TLd;

TLd *alocaNo(int k);
void insereInicio(TLd **p, int k);
void removeInicio(TLd **p);
void removeNo(TLd **p, int k);
TLd *copiaLista(TLd **p1);
TLd *buscaNo(TLd *p, int k);
void imprime(TLd *p);
void imprimeInvertido(TLd *p);

int main(){
	TLd *prim=NULL, *pBusca=NULL, *prim2=NULL, *copia=NULL;
	int op=1, valor;
	
	while(op != 0){
		printf("\n1 - Inserir inicio");
		printf("\n2 - Inserir fim");//ainda nao
		printf("\n3 - Remover inicio");//erro ao remover apenas 1 no
		printf("\n4 - RemoveNo");//erro ao remover o ultimo
		printf("\n5 - Copiar lista");
		printf("\n6 - Buscar no");
		printf("\n7 - Imprimir");
		printf("\n8 - Imprimir invertido");
		printf("\n0 - Sair: ");
		scanf("%d", &op);
		switch(op){
			case 1:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				insereInicio(&prim, valor);
			}break;
			case 2:{
				
			}break;
			case 3:{
				removeInicio(&prim);
			}break;
			case 4:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				removeNo(&prim, valor);
			}break;
			case 5:{
				copia = copiaLista(&prim);
				imprime(copia);
			}break;
			case 6:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				pBusca = buscaNo(prim, valor);
				if(pBusca){
					printf("\nvalor %d encontrado!", pBusca->chave);
				}else{
					printf("\nvalor nao encontrado!");
				}
			}break;
			case 7:{
				imprime(prim);
			}break;
			case 8:{
				imprimeInvertido(prim);
			}break;
		}
	}
}

TLd *alocaNo(int k){
	TLd *no = (TLd *)malloc(sizeof(TLd));
	if(no == NULL) return NULL;
	no->chave = k;
	no->prox = NULL;
	no->ant = NULL;
	return no;
}

void insereInicio(TLd **p, int k){
	TLd *novo;
	novo = alocaNo(k);
	if(novo == NULL) return;
	novo->prox = *p;
	if(*p != NULL){
		(*p)->ant = novo;
	}
	*p = novo;
}

void removeInicio(TLd **p){
	TLd *aux = *p;
	if(*p == NULL){
		printf("\nLista vazia!");
		return;
	}else{
		*p = (*p)-> prox;
		(*p)->ant = NULL;
		free(aux);
	}
}

void removeNo(TLd **p, int k){
	TLd *aux = *p;
	if(*p == NULL){
		printf("\nLista vazia!");
		return;
	}
	
	if((*p)->chave == k){
		*p = (*p)->prox;
		(*p)->ant = NULL;
		aux->prox = NULL;
		aux->ant = NULL;
		free(aux);
	}
	else{
		while(aux != NULL){
			if(aux->chave == k){
				TLd *anterior = aux->ant, *proximo = aux->prox;
				anterior->prox = proximo;
				proximo->ant = anterior;
				aux->prox = NULL;
				aux->ant = NULL;
				free(aux);
				return;
				//aux->ant->prox = aux->prox;
				//aux->prox->ant = aux->ant;
			}
			aux = aux->prox;
		}
	}
	printf("\nNao encontrou!");
}

TLd *copiaLista(TLd **p1){
	TLd *aux = *p1;
	TLd *p2 = NULL;
	while(aux != p1){
		insereInicio(&p2, aux->chave);
		aux = aux->prox;
	}
	return p2;
}

TLd *buscaNo(TLd *p, int k){
	TLd *aux;
	for(aux=p; aux!=NULL; aux=aux->prox){
		if(aux->chave == k){
			return aux;
		}
	}
	return NULL;
}

void imprimeInvertido(TLd *p){
	if(p == NULL){
		printf("\nLista vazia!");
		return;
	}
	while(p->prox != NULL){
		p = p->prox;
	}
	while(p != NULL){
		printf("%d ", p->chave);
		p = p->ant;
	}
}

void imprime(TLd *p){
	TLd *aux;
	if(p == NULL){
		printf("\nLista vazia!");
		return;
	}
	for(aux=p; aux!=NULL; aux=aux->prox){
		printf("%d ", aux->chave);
	}
}



