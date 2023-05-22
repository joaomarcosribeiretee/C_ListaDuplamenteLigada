#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Celula {
    int elemento;
    struct Celula* next;
    struct Celula* ant;
} Celula;

typedef struct {
    int tamanho;
    Celula* inicio;
    Celula* fim;
} Lista;

Lista criarLista();	// Cria uma lista vazia
int determinarTamanho(Lista);	// Determina o tamanho da lista
bool listaVazia(Lista);	// Verifica se a lista está vazia
void mostrarLista(Lista);	// Mostra o conteúdo da lista
void mostrarListaDE(Lista);	// Mostra o conteúdo da lista em ordem decrescente
void inserirInicio(Lista*, char);	// Insere um elemento no início da lista
void inserirFim(Lista*, char);	// Insere um elemento no fim da lista
void removerItem(Lista*, char);	// Remove um elemento específico da lista
void removerkItem(Lista *, int);	// Remove o k-ésimo elemento da lista
Lista esvaziarLista(Lista);	// Esvazia a lista
char obterItem(Lista, int);	// Obtém o elemento de uma determinada posição da lista
int localizarMaior(Lista);  // Retorna a posição do maior valor na lista
int obterMaximo(Lista);  // Retorna o maior valor da lista
int obterSoma(Lista);  // Retorna a soma dos elementos da lista

int main() {
    Lista a;
    int tamanho;
    bool b;
	char item;
	
    a = criarLista();



    inserirInicio(&a, '5');
	inserirInicio(&a, '4');
	inserirInicio(&a, '8');
	inserirInicio(&a, '9');
	inserirInicio(&a, '1');
	inserirFim(&a, '6');
	inserirFim(&a, '7');
	removerkItem(&a, 1); //ele começa a remover a partir do incio 0, entao nesse caso removeria o segundo item da lista
	removerItem(&a , '4');

    item = obterItem(a, 3);
    printf("Item obtido: %c\n", item);
    
    int maior = obterMaximo(a);
    printf("Maior item: %c\n", maior);
    
    int contmaior = localizarMaior(a);
    printf("Maior item esta na posicao: %d\n", contmaior);
    
	
    b = listaVazia(a);
    mostrarListaDE(a);	
    mostrarLista(a);	
    
    tamanho = determinarTamanho(a);
    printf("Tamanho da Lista: %d\n", tamanho);

    return 0;
}

Lista criarLista() {
    Lista ap;
    ap.inicio = NULL;
    ap.fim = NULL;
    ap.tamanho = 0;
    return ap;
}

int determinarTamanho(Lista ap) {
	int c;
	c = ap.tamanho;
	return c;
}

bool listaVazia(Lista ap) {
    bool y;
    if (ap.tamanho == 0) {
        y = true;
        printf("Lista Vazia\n");
    } else {
        y = false;
        printf("Lista nao e Vazia\n");
    }
    return y;
}

void mostrarLista(Lista ap) {
    Celula* p = ap.inicio;
    printf("Conteudo da lista:");
    while (p != NULL) {
        printf(" %c", p->elemento);
        p = p->next;
    }
    printf("\n");
}

void mostrarListaDE(Lista ap) {
    Celula* p = ap.fim;
    printf("Conteudo da listaDE:");
    while (p != NULL) {
        printf(" %c", p->elemento);
        p = p->ant;
    }
    printf("\n");
}

void inserirInicio(Lista* ap, char y) {
	Celula *p;
    Celula* novo = malloc(sizeof(Celula));
    novo->ant = NULL;
    novo->elemento = y;

    if (ap->inicio == NULL) {
        novo->next = NULL;
        ap->inicio = novo;
        ap->fim = novo;
    } else {
        Celula* p = ap->inicio;
        novo->next = p;
        p->ant = novo;
        ap->inicio = novo;
    }

    ap->tamanho++;
}


void inserirFim(Lista *ap, char y){
	
	Celula *p, *novo;
	
	novo = malloc(sizeof(Celula));
	
	novo->next = NULL;
	novo->elemento = y;
	
	if(ap->fim == NULL){
		novo->ant = NULL;
		ap->inicio = novo;
		ap->fim = novo;
	}
	else{
		p = ap->fim;
		novo->ant = p;
		p->next = novo;
		ap->fim = novo;
	}
	
	ap->tamanho++;
}

char obterItem(Lista ap, int x) {
    int cont = 0;
    Celula* celulaAtual = ap.inicio;
    char item = '\0'; // Valor padrão caso o item não seja encontrado

    while (celulaAtual != NULL) {
        cont++;
        if (cont == x) {
            item = celulaAtual->elemento;
            printf("Item: %c\n", item);
        }
        celulaAtual = celulaAtual->next;
    }

    return item;
}

int localizarMaior(Lista ap) {
    Celula* celulaAtual = ap.inicio;
    char maiorItem = 0;
    int posicao = -1;  // Inicializamos a posição com um valor inválido

    int cont = 1;
    while (celulaAtual != NULL) {
        if (maiorItem < celulaAtual->elemento) {
            maiorItem = celulaAtual->elemento;
            posicao = cont;  // Atualiza a posição do maior elemento
        }
        celulaAtual = celulaAtual->next;
        cont++;
    }

    return posicao;
}


int obterMaximo(Lista ap) {
	int i;
	Celula* celulaAtual = ap.inicio;
	char maiorItem = 0;
	
	while (celulaAtual != NULL) {
		if (maiorItem < celulaAtual->elemento){
			maiorItem = celulaAtual->elemento;
		}
		celulaAtual = celulaAtual->next;
	}
	
	return maiorItem;
}

//	/*int obterSoma(Lista ap) {
//	    	int soma = 0;
//	    	Celula *p = ap.inicio;
//	    	while (p != NULL) {
//	        	soma += p->elemento;
//	        	p = p->next;
//	    	}
//	    	return soma;
//		}
//		
//		-> Só funcionaria caso os itens colocados na lista fossem do tipo int
//	*/

	void removerkItem(Lista *ap, int k){
		Celula *p, *celk;
		celk = ap->inicio;
		int i = 0;
		
		if(ap->inicio != NULL){
			
			while(celk != NULL && i != k)
			{
				p = celk;
				celk = celk->next;
				i++;
			}
			
			if(celk != NULL) //verifica se o indice existe na lista
			{
				if(celk == ap->fim){ //se a celula for o fim
					if(ap->tamanho == 1){ //se o tamnho for 1 atualizar comeco e fim
						ap->inicio = NULL;
						ap->fim = NULL;
					}
					else{ //senao a proxima celula recebe a anterior a celk e o fim passa a ser a anterior a celk
						celk->ant->next = NULL;
						ap->fim = celk->ant;
					}
				}
				else if(celk == ap->inicio){ //como ja foi feito o teste para ver se eh o fim, apenas atualizar a proxima celula a celk e o comeco
					celk->next->ant = NULL;
					ap->inicio = celk->ant;
				}
				else{ //senao for nem comeco nem fim apenas atualizar a proxima celula anterior e a proxima
					p->next = celk->next;
					celk->next->ant = p;
				}
				ap->tamanho--;
				free(celk);
			}
	}
	else
	printf("Lista Vazia\n");
		
	}

void removerItem(Lista *ap, char item) {
    Celula *p, *celk;
    celk = ap->inicio;

    if (ap->inicio != NULL) {
        while (celk != NULL && celk->elemento != item) {
            p = celk;
            celk = celk->next;
        }

        if (celk != NULL) { // verifica se o item existe na lista
            if (celk == ap->fim) { // se a célula for o fim
                if (ap->tamanho == 1) { // se o tamanho for 1, atualizar início e fim
                    ap->inicio = NULL;
                    ap->fim = NULL;
                } else { // caso contrário, a próxima célula recebe a anterior à celk e o fim passa a ser a anterior à celk
                    celk->ant->next = NULL;
                    ap->fim = celk->ant;
                }
            } else if (celk == ap->inicio) { // como já foi feito o teste para ver se é o fim, apenas atualizar a próxima célula e o início
                celk->next->ant = NULL;
                ap->inicio = celk->next;
            } else { // caso não seja nem início nem fim, apenas atualizar a próxima célula anterior e a próxima
                p->next = celk->next;
                celk->next->ant = p;
            }
            ap->tamanho--;
            free(celk);
            printf("Item removido: %c\n", item);
        } else {
            printf("Item não encontrado na lista\n");
        }
    } else {
        printf("Lista Vazia\n");
    }
}
