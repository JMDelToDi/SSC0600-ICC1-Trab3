//João Marcos Della Torre Divino - N° USP 10377708

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int m = 0, o = 0;
	
	printf("\t->-> Matriz Esparsa <-<-\n\n\t1 - Inicializar matriz\n\t2 - Sair\n\n\t--> ");
	scanf("%d", &m);
	
	//Inicializa a matriz
		
	printf("\n\tMatriz inicializada... O que voce deseja fazer agora?\n\n\t1 - Atribuir valor\n\t2 - Consultar valor\n\t3 - Soma dos valores de cada linha\n\t4 - Soma dos valores de cada coluna\n\t5 - Calculo do determinante\n\t6 - Resolucao de sistema linear (Metodo de Gauss-Seidel)\n\t7 - Excluir matriz\n\n\t--> ");
	scanf("%d", &o);
		
	switch(o){
			
		case 1:
			printf("\t->-> Atribuir valor <-<-");
			break;
				
		case 2:
			printf("\t->-> Consultar valor <-<-");
			break;
				
		case 3:
			printf("\t->-> Soma dos valores de cada linha <-<-");
			break;
				
		case 4:
			printf("\t->-> Soma dos valores de cada coluna <-<-");
			break;
		
		case 5:
			printf("\t->-> Calculo do determinante <-<-");
			break;
				
		case 6:
			printf("\t->-> Resolucao de sistema linear (Metodo de Gauss-Seidel) <-<-");
			break;
			
		case 7:
			printf("\t->-> Excluir matriz <-<-");
			break;
	}
	
	return(0);
}
