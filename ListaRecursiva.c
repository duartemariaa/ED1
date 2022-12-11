#include<stdio.h>
#include<stdlib.h>

typedef struct TipoListaRecursiva{
	int chave;
	struct TipoListaRecursiva *prox;
}TLr;

void insereFim(TLr **p, int k);
void removeInicio(TLr **p);
void liberaNos(TLr **p);
TLr *buscaNo(TLr *p, int k);
void imprime(TLr *p);
void imprimeInvertido(TLr *p);

int main(){
	TLr *prim=NULL, *busca=NULL;
	int valor;
	int op=1;
	
	while(op!=0){
		printf("\n1 - Insere fim");
		printf("\n2 - Remove inicio");//erro, libera tudo
		printf("\n3 - Libera nos");
		printf("\n4 - Buscar no"); //erro
		printf("\n5 - Somar nos");//nao codificado
		printf("\n6 - imprime invertido");//imprimindo duas vezes
		printf("\n7 - imprime");
		printf("\n0 - Sair: ");
		scanf("%d", &op);
		switch(op){
			case 1:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				insereFim(&prim, valor);
			}break;
			case 2: removeInicio(&prim); break;
			case 3: liberaNos(&prim); break;
			case 4:{
				printf("\nvalor: ");
				scanf("%d", &valor);
				busca = buscaNo(prim, valor);
				if(busca == NULL){
					printf("\nvalor nao encontrado!");
				}else{
					printf("\nvalor %d encontrado!", busca->chave);
				}
			}break;
			case 5:
			case 6: imprimeInvertido(prim);
			case 7: imprime(prim);
		}
	}
	
}

void insereFim(TLr **p, int k){
	TLr *no = NULL;
	if(*p == NULL){
		no = (TLr *)malloc(sizeof(TLr));
		if(no == NULL) return;
		no->chave = k;
		no->prox = NULL;
		*p = no;
	}else{
		insereFim(&((*p)->prox), k);
	}
}

void removeInicio(TLr **p){
	if(*p == NULL) return;
	TLr *aux = *p;
	removeInicio(&(aux)->prox);
	*p = (*p)->prox;
	free(p);
	p = NULL;
}

void liberaNos(TLr **p){
	if(*p == NULL) return;
	removeInicio(&(*p)->prox);
	free(*p);
	*p = NULL;
}

TLr *buscaNo(TLr *p, int k){
	if(p == NULL){
		printf("\nLista vazia!");
		return;
	}else{
		if(p->chave == k)
			return p;
		buscaNo(p->chave, k);
	}
}

void imprime(TLr *p){
	if(p == NULL) {
		//printf("\nLista vazia!");
		return;	
	}
	else{
		printf("%d ", p->chave);
		imprime(p->prox);
	}
}

void imprimeInvertido(TLr *p){
	if(p == NULL) return;
	else{
		imprimeInvertido(p->prox);
		printf("%d ", p->chave);
	}
}




