#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define tam 10

int main(){
	/* Faça um programa ler um vetor de V inteiros com 10 posições e moster o vetor
Apos leia o vetor V, crie um segundo vetor de K de inteiros com 10 posições
copiando somente os elementos do vetor V que sao pares
Para calcular a media dos valores pares faça a divisoa somentoe pelo numero de valores pares
encontrados no vetor V. zero e par
*/

	int v[tam],k[tam],media, i;//criou-se 2 vetores inteiro para armazenar 10 valores
	int cont=0, soma=0;
	
	system("color 1f");
	system ("cls");
	
	printf("\n Digite os valores de v: \n");
	
	//foi utilizada uma estrutura de repetição FOR
	for(i=0;i<tam;i++){
		printf("\n v[%d]",i);
		scanf("%d", &v[i]);
	}
	//copiar os valores pares
	for (i=0;i<tam;i++){
		if(v[i]%2==0){
			k[i]=v[i];
		}
		printf("\n k[%i]\n");
		printf("\n %i: ", i+1);
		scanf("%d", &k[i]);
		soma = soma + k[i];
}
/*
	for(i=0;i<tam;i++){
		printf("\n %i: ", i+1);
		scanf("%d", &k[i]);
		soma = soma + k[i];
	}*/
		
	media = soma/10;//media foi calculada dividindo a variavel que acumulou os valores pela quantidade ou seja 10
	
	for (i=0;i<tam;i++)
		if(k[i] > media)
			cont = cont +1;
			
	printf ("\n a media dos valores pare eh: %d", media);
	
	
}
