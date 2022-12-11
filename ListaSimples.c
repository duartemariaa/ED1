#include<stdio.h>
#include<stdlib.h>

typedef struct TipoListaSimples{
	int chave;
	struct TipoListaSimples *prox;
}TLs;

TLs *alocaNo(int k);
void insereInicio(TLs **p, int k);
TLs *insereFim(TLs **p, int k);
void atualizaNo(TLs *p, int k);
TLs *pesquisaNo(TLs *p, int k);
TLs *copiaLista(TLs **p);
TLs *intersecaoLista(TLs *p1, TLs *p2);
void contaNo(TLs **p);
int alturaNo(TLs **p, int k);
void removeInicio(TLs **p);
void removeFim(TLs **p);
void removeNo(TLs **p, int k);
void imprimeLista(TLs *p);
void liberaNos(TLs **p);

/*
void insereRemove(TLs **p1, TLs **p2);
void transplantaNo(TLs **p1, TLs **p2);
void insereRemove(TLs **p1, TLs **p2);
void transplantaNo(Tls **p1, TLs **p2);
int alturaNo(TLs **p, int k);
int profundidade(TLs **p, int k);
*/

int main(){
	TLs *prim=NULL, *prim2=NULL, *pBusca=NULL, *copia=NULL, *intersecao=NULL;
	int op=1, valor=0, valor2=0;
	
	while(op != 0){
		printf("\n1 - Inserir inicio");
		printf("\n2 - Atualizar primeiro no");
		printf("\n3 - Inserir fim");
		printf("\n4 - Pesquisa no");
		printf("\n5 - Remove Inicio"); 
		printf("\n6 - Remove fim");//erro
		printf("\n7 - Remove no");
		printf("\n8 - Copia lista");
		printf("\n9 - Intersecao");
		printf("\n10 - insereRemove");//nao codificado
		printf("\n11 - Transplanta no");//nao codificado
		printf("\n12 - Conta no");
		printf("\n13 - altura do no");//nao codificado
		printf("\n14 - Profundidado do no");//nao codificado
		printf("\n15 - Imprimir");
		printf("\n16 - Desalocar");//erro
		printf("\n0 - Sair: ");
		scanf("%d", &op);
		switch(op){
			case 1:{
				printf("\nValor: ");
				scanf("%d", &valor);
				insereInicio(&prim, valor);
				//printf("\nValor2: ");
				//scanf("%d", &valor2);
				//insereInicio(&prim2, valor2); //lista 2 para verificacao da funcao intersecao
			}break;
			case 2:{
				printf("\nValor: ");
				scanf("%d", &valor);
				atualizaNo(prim, valor);
			}break;
			case 3:{
				printf("\nValor: ");
				scanf("%d", &valor);
				insereFim(&prim, valor);
			}break;
			case 4:{
				printf("\nValor: ");
				scanf("%d", &valor);
				pBusca = pesquisaNo(prim, valor);
				if(pBusca != NULL){
					printf("\nvalor %d encontrado!", pBusca->chave);
				}else{
					printf("\nelemento nao encontrado!");
				}
			}break;
			case 5:{
				removeInicio(&prim);
			}
			case 6:{
				removeFim(&prim);
			}break;
			case 7:{
				printf("\nValor: ");
				scanf("%d", &valor);
				removeNo(&prim, valor);
			}break;
			case 8:{
				copia = copiaLista(&prim);
				printf("\nLista copiada\n");
				imprimeLista(copia);
			}break;
			case 9:{
				intersecao = intersecaoLista(prim, prim2);
				if(intersecao != NULL){
					imprimeLista(intersecao);
				}
			}break;
			case 10: {
				
			}break;
			case 11: {
				
			}break;
			case 12: {
				contaNo(&prim);
			}break;
			case 13: {
				
			}break;
			case 14: {
				
			}break;
			case 15: {
				imprimeLista(prim);
			}break;
			case 16:{
				liberaNos(&prim);
			}break;
		}
	}
}

TLs *alocaNo(int k){
	TLs *no = (TLs *)malloc(sizeof(TLs));
	if(no == NULL) return NULL;
	no->chave = k;
	no->prox = NULL;
}

void insereInicio(TLs **p, int k){
	if(p == NULL) return;
	TLs *no = alocaNo(k);
	if(p == NULL) return;
	no->prox = *p;
	*p = no;
}

TLs *insereFim(TLs **p, int k){
	TLs *aux = *p;
	TLs *no = alocaNo(k);
	if(no == NULL) return;
	
	if(*p == NULL){
		*p = no;
	}else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
	}
	return aux;
}

void atualizaNo(TLs *p, int k){
	if(p == NULL) {
		printf("\nLista vazia!");
	}
	p->chave = k;
}

TLs *pesquisaNo(TLs *p, int k){
	if(p == NULL){
		printf("\nLista vazia!");
	}
	while(p != NULL){
		if(p->chave == k)
			return p;
		p = p->prox;
	}
}

TLs *copiaLista(TLs **p){
	TLs *aux = *p;
	TLs *prim2 = NULL; //ponteiro da nova lista
	
	if(p == NULL){
		printf("\nLista vazia!");
		return;
	}
	while(aux != NULL){
		insereInicio(&prim2, aux->chave);
		aux = aux->prox;
	}
	return prim2;
}

TLs *intersecaoLista(TLs *p1, TLs *p2){
	TLs *p3 = NULL, *novoNo, *aux1, *aux2=p2;
	int k=0;
	
	if((p1 == NULL) || (p2 == NULL)){
		printf("\nLista vazia!");
	}
	while(p1 != NULL){
		p2 = aux2;
		while(p2 != NULL){
			if(p1->chave == p2->chave){
				aux1 = novoNo;
				novoNo = (TLs *)malloc(sizeof(TLs));
				if(novoNo == NULL) return NULL;
				novoNo->chave = p1->chave;
				novoNo->prox = NULL;
				if(k == 0){
					p3 = novoNo;
				}else{
					aux1->prox = novoNo;
				}
				k++;
			}
			p2 = p2->prox;
		}
		p1 = p1->prox;
	}
	return p3;
}

void contaNo(TLs **p){
	TLs *aux = *p;
	int cont=0;
	if(p == NULL){
		printf("\nLista vazia!");
	}
	while(aux != NULL){
		cont++;
		aux = aux->prox;
	}
	printf("\nQuantidade: %d", cont);
}

void removeInicio(TLs **p){
	if(p == NULL){
		printf("\nLista vazia!");
	}
	TLs *aux = *p;
	*p = (*p)->prox;
	free(aux);
}

void removeFim(TLs **p){
	TLs *aux = p;
	
	if(p == NULL){
		printf("\nLista vazia!");
	}
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	TLs *aux2 = aux->prox;
	aux->prox = NULL;
	free(aux2);
}

void removeNo(TLs **p, int k){
	if(p == NULL){
		printf("\nLista vazia!");
	}
	TLs *aux1=NULL, *aux2=NULL;
	if((*p)->chave == k){
		aux1 = *p;
		*p = aux1->prox;
	}else{
		aux2 = *p;
		while(aux2->prox && aux2->prox->chave != k){
			aux2 = aux2->prox;
		}
		if(aux2->prox){
			aux1 = aux2->prox;
			aux2->prox = aux1->prox;
		}
	}
	return aux1;
	
}


void imprimeLista(TLs *p){
	if(p == NULL){
		printf("\nLista vazia!");
	}else{
		printf("\nLista: ");
		while(p != NULL){
			printf("%d ", p->chave);
			p = p->prox;
		}
	}	
}

void liberaNos(TLs **p){
	if(p == NULL) {
		printf("\nLista vazia!");
	}
	TLs *aux = *p;
	liberaNos(&(*p)->prox);
	(*p)->prox = NULL;
	free(*p);
	*p = NULL;
}






