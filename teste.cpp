#include<stdio.h>
#include<stdlib.h>

int main(){
	//vetor de 12 posições
	int v[12], i, cont,cont1,cont2;
	float porcentagem,porcentagem1,porcentagem2;
	
	system ("color 1b");
	system ("CLS");
	printf("\n Digite os valores do vetor: \n");
	
	for(i=0; i<12; i++){
		printf("%i: ", i);
		scanf("%i",&v[i]);
	}
	
	
	for(i=0; i<12;i++){//*
		if (v[i] <=20)
		cont = cont + 1;
		else if (v[i]>=21 || v[i]<=30)
			cont1=cont1 + 1;
		else if (v[i]>=31 || v[i]<=50)
			cont2=cont2 + 1;
}
	
	//mostrar vetor v
	for(i=0;i<10;i++)
		printf(" %d\t", v[i]);

	
	//calculo da porcentagem
	porcentagem = (cont/12)*100;//*
	porcentagem1 = (cont1/12)*100;
	porcentagem2 = (cont2/12)*100;

	
	
	//saida dos valores
	printf("\n\t Porcentagem dentro do range de 1..20: %.2f \n",porcentagem);//*
	printf("\n\t Porcentagem dentro do range de 21..30: %.2f \n",porcentagem1);
	printf("\n\t Procentagem dentro do range de 31..50: %.2f \n", porcentagem2);
		
		
	system("pause");
	return 0;
}

