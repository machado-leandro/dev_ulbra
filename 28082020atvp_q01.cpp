#include<stdio.h>
#include<stdlib.h>

int main(){
	//vetor de 12 posições
	int v[12], i, cont,cont1,cont2,aux[12];
	float porcentagem,porcentagem1,porcentagem2;
	
	system ("color 1b");
	system ("CLS");
	printf("\n Digite os valores do vetor: \n");
	
	for(i=0; i<12; i++){
		printf("%i: ", i+1);
		scanf("%i",&v[i]);
	}
	
	
	for(i=0; i<12;i++)//*
		if (v[i] <=20)
			cont = cont +1;
			
	for (i=0; i<12;i++)
		if (v[i] >=21|| 30)
			cont=cont+1;

	
	//calculo da porcentagem
	porcentagem = (cont*i)/100;//*
	
	printf("\n\t vetor ",&v[12]);
	//saida dos valores
	printf("\n\t Porcentagem dentro do range de 1..20: %.2f \n",porcentagem);//*
	printf("\n\t Porcentagem dentro do range de 22..30: %.2f \n",porcentagem);
		
	
	system("pause");
}

