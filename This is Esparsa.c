//João Marcos Della Torre Divino - N° USP 10377708

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	float valor;
	int col;
	struct elemento *next;
} E;

typedef E *p;

typedef struct{
	p *Lista_ligada;
	int l;
	int c;
} ME;

int main(){
	
	int flag = 0, o = 0, linhas = 0, colunas = 0, i = 0, j = 0;
	
	/*
	int flag: Variável para controlar o prosseguimento do programa.
	int o: Variável de controle do menu de opções para manipulação da matriz.
	int linhas: Variável auxiliar para definir a quantidade de linhas da matriz, a linha onde será inserido um valor ou a linha onde está certo valor. 
	int colunas: Variável auxiliar para definir a quantidade de colunas da matriz, a coluna onde será inserido um valor ou a coluna onde está certo valor.
	int i: Variável de controle para loop.
	int j: Variável de controle para loop.
	*/
	
	float v = 0, soma = 0;

	/*
	float v: Variável auxiliar para inserir valor na matriz.
	float soma: Variável auxiliar para retornar a soma dos valores ou de cada coluna ou de cada linha.
	*/
	
	printf("\t->-> Matriz Esparsa <-<-\n\n\t1 - Inicializar matriz\n\t0 - Sair\n\n\t--> ");
	scanf("%d", &flag);
	
	while(flag < 0 || flag > 1){
		printf("\n\n\tInsira um valor valido... --> ");
		scanf("%d", &flag);
	}
	
	while(flag){
		
		system("cls");
		
		ME esparsa;
		
		printf("\t->-> Inicializar matriz <-<-");
		printf("\n\n\tInsira o numero de linhas da matriz: ");
		scanf("%d", &linhas);
		esparsa.l = linhas;
		printf("\n\tInsira o numero de colunas da matriz: ");
		scanf("%d", &colunas);
		esparsa.c = colunas;
		
		esparsa.Lista_ligada = (p *) calloc(linhas, sizeof(p));
		
		if(esparsa.Lista_ligada == NULL){
			system("cls");
			printf("\n\n\n\tFalha na alocacao de memoria...\n\n\n");
			exit(1);
		}
		
		printf("\n\n\n\tMatriz inicializada...");
		
		while(flag){
			
			printf("\n\n\n\tO que voce deseja fazer agora?\n\n\t1 - Atribuir valor\n\t2 - Consultar valor\n\t3 - Soma dos valores de cada linha\n\t4 - Soma dos valores de cada coluna\n\t5 - Excluir matriz\n\n\t--> ");
			scanf("%d", &o);
			
			while(o < 1 || o > 5){
				printf("\n\tInsira uma opcao valida... --> ");
				scanf("%d", &o);
			}
				
			switch(o){
					
				case 1:
					system("cls");
					printf("\t->-> Atribuir valor <-<-");
					
					printf("\n\n\tDigite o valor a ser inserido na matriz: ");
					scanf("%f", &v);
					printf("\n\tDigite a linha na qual o valor sera inserido: ");
					scanf("%d", &linhas);
					
					while(linhas < 0 || linhas > esparsa.l){
						printf("\n\tInsira uma linha valida... -->");
						scanf("%d", &linhas);
					}
					
					printf("\n\tDigite a coluna na qual o valor sera inserido: ");
					scanf("%d", &colunas);
					
					while(colunas < 0 || colunas > esparsa.c){
						printf("\n\tInsira uma coluna valida... --> ");
						scanf("%d", &colunas);
					}
					
					
					p before = NULL;
					p current = esparsa.Lista_ligada[linhas];
					
					//Buscar posição onde será incluso o valor.
					while(current != NULL && current->col < colunas){
						before = current;
						current = current->next;
					}
					
					//Condição caso o local onde será incluso o valor já exista.
					if(current != NULL && current->col == colunas){
						if(v == 0){
							if(before == NULL) esparsa.Lista_ligada[linhas] = current->next;
							else before->next = current->next;
							free(current);
						}
						else current->valor = v;
					}
					
					//Condição caso o local onde será incluso o valor não exista.
					else {	
						
						p new_e = (p)malloc(sizeof(E));
						
						if(new_e == NULL){
							system("cls");
							printf("\n\n\n\tFalha na alocacao de memoria...\n\n\n");
							exit(1);
						}
						
						new_e->col = colunas;
						new_e->valor = v;
						new_e->next = current;
						if(before == NULL) esparsa.Lista_ligada[linhas] = new_e;
						else before->next = new_e;
					
					}
								
					break;
						
				case 2:
					system("cls");
					printf("\t->-> Consultar valor <-<-");
					
					printf("\n\n\tDigite a linha desejada: ");
					scanf("%d", &linhas);
					
					while(linhas < 0 || linhas > esparsa.l){
						printf("\n\tInsira uma linha valida... --> ");
						scanf("%d", &linhas);
					}
					
					printf("\n\tDigite a coluna desejada: ");
					scanf("%d", &colunas);
					
					while(colunas < 0 || colunas > esparsa.c){
						printf("\n\tInsira uma coluna valida... --> ");
						scanf("%d", &colunas);
					}
					
					//Buscar posição desejada.
					p search = esparsa.Lista_ligada[linhas];
					while(search != NULL && search->col < colunas){
						search = search->next;
					}
					
					//Retornar valor caso exista.
					if(search != NULL && search->col == colunas){
						printf("\n\n\tValor da linha %d e coluna %d: %f", linhas, colunas, search->valor);
					}
					
					//Retornar 0 caso não exista.
					else printf("\n\n\tValor da linha %d e coluna %d: 0", linhas, colunas);
					
					break;
						
				case 3:
					system("cls");
					printf("\t->-> Soma dos valores de cada linha <-<-\n");
					
					i = 0;
					
					while(i < esparsa.l){
						
						soma = 0;
						
						p soma_l = esparsa.Lista_ligada[i];
						
						while(soma_l != NULL && soma_l->col < esparsa.c){
							soma += (soma_l->valor);
							soma_l = soma_l->next;
						}
						
						printf("\n\tSoma dos valores da linha %d: %f", i, soma);
						i++;
					}
					
					break;
						
				case 4:
					system("cls");
					printf("\t->-> Soma dos valores de cada coluna <-<-\n");
					
					i = 0;
					
					while(i < esparsa.c){
						
						soma = 0;
						
						for(j = 0; j < esparsa.l; j++){
							
							p soma_c = esparsa.Lista_ligada[j];
							
							if(soma_c != NULL){
								while(soma_c != NULL && soma_c->col < i){
									if(soma_c->next == NULL){
										break;
									}
									soma_c = soma_c->next;
								}
								
								if(soma_c->col == i){
									soma += soma_c->valor;
								}
							}
						}
						
						printf("\n\tSoma dos valores da coluna %d: %f", i, soma);
						i++;
					}
					
					break;
				
				case 5:
					system("cls");
					printf("\n\n\t->-> Matriz excluida com sucesso... <-<-");
					free(esparsa.Lista_ligada);
					break;
			}
			
			if(o == 5){
				printf("\n\n\tDeseja inicializar outra matriz?\n\n\t1 - Sim\n\t0 - Nao\n\n\t--> ");
				scanf("%d", &flag);
				
				if(flag == 1){
					system("cls");
					printf("\t->-> Inicializar matriz <-<-");
					printf("\n\n\tInsira o numero de linhas da matriz: ");
					scanf("%d", &linhas);
					esparsa.l = linhas;
					printf("\n\tInsira o numero de colunas da matriz: ");
					scanf("%d", &colunas);
					esparsa.c = colunas;
					
					esparsa.Lista_ligada = (p *) calloc(linhas, sizeof(p));
					
					printf("\n\tMatriz inicializada...");
				}
			}
			
		}

	}
	
	printf("\n\n\n\tAte logo!!! o/");
	
	return(0);
	
}
