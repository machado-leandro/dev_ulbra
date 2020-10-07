#include<stdio.h>
#include<conio.h>
#include<string.h>

//protoripo das funções
void incluir();
void listar();
void consultar();
void editar();
void excluir();

//declaração das variaveis globais
	struct aluno{
		int cod;
		char nome[30];
		float n1,n2,media;
	}reg;//declara registro
	
	FILE *arq;	//declara o arquivo
	int teste;
	char resp;
	///////////////////////////=========================função principal=========================///////////////////////////
main(){
		char op;
		
		
		do{
	clrscr ();
	gotoxy(10,3);     printf("     menu     ");
	gotoxy(10,4);     printf("==============");
	gotoxy(10,6);	  printf(" 1 - incluir  ");
	gotoxy(10,7);	  printf(" 2 - Listar   ");
	gotoxy(10,8);	  printf(" 3 - Consultar");
	gotoxy(10,9);	  printf(" 4 - Editar   ");
	gotoxy(10,10);	  printf(" 5 - Excluir  ");
	gotoxy(10,11);    printf(" 6 - Sair     ");
	gotoxy(10,13);	  printf("    Opção     ");
	gotoxy(10,13);    op=getche ();				//le a opcao do usuario
	switch(op){									//faz a chamada a uma das funções
		case '1': 
			incluir ();
		break;
		
		case '2':
			listar ();
		break;
		
		case '3':
			consultar ();
		break;
		
		case '4':
			editar ();
		break;
		
		case '5':
			excluir ();
		break;
		
		case '6':
			clrscr();
			gotoxy(10,10);
				printf("o programa foi encerrado.");
			gotoxy(10,12);
				priintf("tecle algo para continuar...");
				getch();
			break;
		
		default:
			gotoxy(10,10);
				printf("opcao invalida.");
			gotoxy(10,17);
				printf("tecle algo para continuar...");
				getch();
		}
	}while (op!='6');
}

	///////////////////////////=========================função INCLUIR=========================///////////////////////////
	
	void incluir (){
		resp='s';
		
		arq=fopen("cad_aluno.txt", "ab"); //abre ou copia arquivo
		
		if (arq){
			//le os dados, calacula a media e grava o registro do arquivo
			while(resp=='s' || resp=='S'){
				clrscr();
				gotoxy(10,3);		printf("      Cadastro de aluno          ");
				gotoxy(10,5);		printf("=================================");
				gotoxy(10,7);		printf(" codigo......: ");
										scanf("%i", &reg.cod);
				gotoxy(10,8);		printf("Nome.....: ");
										fflush(stdin);
										fgets(reg.nome,30,stdin);
				gotoxy(10,9);		printf("NOTA 1.....: ");
										scanf("%f", &reg.n1);
				gotoxy(10,10);		printf("nota 2.....: ");
										scanf("%f",reg.n2);
				
				reg.media=(reg.n1+reg.n2)/2;
				gotoxy(10,11);
					printf("media.....:%f",reg.media);
	
			//o comando abaixo grava os dados do registro no arquivo
			//a variavel teste recebe o retorna da funçao fwrite
			//se ocorrer algum erro no proceso, a função retorna nulo
			teste = fwrite (&reg,sizeof(struct aluno),1,arq);
			
			if (teste){
				gotoxy(10,14);
					printf("Registro gravado com sucesso!");
			}
			gotoxy(10,20);
				printf("deseja continuar? s/n:  ");
	
			}
			fclose (arq);
		}
	}
	
	///////////////////////////=========================função LISTAR=========================///////////////////////////
	
	void listar (){
		int linha=9;
		
		arq=fopen("cad_aluno.txt","rb");//abre o arquivo para leitura
		
		clrscr();
		if(arq){//se o arquivo foi aberto corretamente, lista os dados
			gotoxy(10,3);		printf("					Lista geral de alunos						");
			gotoxy(10,5);		printf("================================================================");
			gotoxy(10,7);		printf("codigo		nome     	   					n1		n2		media");
			
			while(!feof(arq)){			//enquanto nao for o final do arquivo
			
			//o comando abaixo le os dados do registro, gravado no arquivo
			//a variavel teste recebe o retorno da função fread
			//se ocorrer algum erro no processo, função retorna nulo
			
			teste=fread(&reg,sizeof(struct aluno),1,arq);
			
			if (teste && strcmp(reg.nome, "")){//exibe os dados na tela
				gotoxy(10,linha);		printf("%04i",reg.cod);
				gotoxy(18,linha);		puts(reg.nome);
				gotoxy(40,linha);		printf("%.1f",reg.n1);
				gotoxy(45,linha);		printf("%.1f",reg.n2);
				gotoxy(50,linha);		printf("%.1f",reg.media);
				
				if(linha<17)
					linha++;
				else{		//rola os registros na tela
					gotoxy(10,22);
					printf("tecle ENTER p/ continuar exibindo os registros.");
					getch();
					gotoxy(10,9);		delline();
					gotoxy(10,17);		insline();
				}
			}
		}
		gotoxy(10,22);			printf("listagem concluida.");
		gotoxy(10,23);			printf("Tecle algo para voltar ao menu...");
		getch();
		fclose(arq);
	}
	else{
		gotoxy(10,18);			printf("arquivo vazio");
		gotoxy(10,10); 			printf("Tecle algo para voltar ao menu");
	}
}
	
	///////////////////////////=========================função CONSULTAR=========================///////////////////////////
	
	void consultar(){
		char nomepesq[30];
		int achei;
		resp='s';
		
		
		arq=fopen("cad_aluno.txt", "rb");
		
		if(arq){
			while (resp=='s' || resp=='S'){
				clrscr();
				gotoxy(10,3);			printf("             consulta registro de aluno              ");
				gotoxy(10,5);			printf("=====================================================");
				gotoxy(10,7);
					printf("Nome a ser pesquisado: ");
					fflush(stdin);
					fgets(nomepesq,30,stdin);
					
					achei=0;
					rewind(arq);	//posicioan o apontador de reg no incio do arquivo
					while(!feof (arq) && achei==0){
						//comando para ler os dados do registro, gravados no arquivo
						//variavel teste recebe o retorno da função fread
						//se ocorrer algum erro no processo, a função retorna nulo
						
						teste=fread(&reg,sizeof(struct aluno),1,arq);
						
						if(teste){
							//compara o campo nome do registro com o nime pesquisado
							if(strcmp(reg.nome, nomepesq)==0){
								//se o nome pesquisado foi encontrado
								//exibe os outros campos do registro na tela
								gotoxy(10,10);			printf("Pesquisa realizada com sucesso!");
								gotoxy(10,13);			printf("Codigo..: %i",reg.cod);
								gotoxy(10,14);			printf("Nome....: %s",reg.nome);
								gotoxy(10,15);			printf("Nota 1..: %.1f",reg.n1);
								gotoxy(10,16);			printf("Nota 2..: %.1f",reg.n2);
								gotoxy(10,17);			printf("media...: %.1f",reg.media);
								achei = 1;
							}
						}
					}
					if(achei==0){
						gotoxy(10,12);
							printf("Registro não encontrado");
				}
				gotoxy(10,20);
					printf("deseja continuar? s/n  ");
					resp=getche();
			}
			fclose(arq);		//fecha o arquivo
		}
		else{
			clrscr();
			gotoxy(10,8);			printf("arquivo vazio.");
			gotoxy(10,10);			printf("Tecle algo para voltar ao menu...");
		}
	}
	///////////////////////////=========================função EDITAR=========================///////////////////////////
	
	void editar(){
		char nomepesq[30];
		int achei, apontador;
		resp='s';
		
		arq=fopen("cad_aluno.txt", "rb+");				//abre o arquivo para leitura e escrita
		
		if(arq){
			while (resp=='S' || resp=='s'){
				achei=0;
				clrscr();
				gotoxy(10,3);			printf("                   Editar o registro de aluno                   ");
				gotoxy(10,5);			printf("================================================================");
				gotoxy(10,7);
				printf("nome a ser pesquisado: ");
				fflush(stdin);
				fgets(nomepesq,30,stdin);
				
				rewind(arq);		//posiciona o apontador de reg no inicio de arquivo
				apontador=0;
				while(!feof(arq) && achei==0){
					teste=fread(&reg,sizeof(struct aluno),1,arq);
					apontador++;
					if(teste){
					//compara o campo nome do registro com o nome pesquisado
						if(strcmp(reg.nome,nomepesq)==0) {
							//se o nome pesquisado foi encontrdo
							//exibe os outros campos do registro na tela
							gotoxy(10,13);			printf("Codigo..: %i", reg.cod);
							gotoxy(10,14);			printf("Nome....: %s", reg.nome);
							gotoxy(10,15);			printf("Nota 1..: %.1f", reg.n1);
							gotoxy(10,16);			printf("Nota 2..: %.1f", reg.n2);
							gotoxy(10,17);			printf("media...: %.1f",reg.media);
							
							//le os dados a serem editados
							gotoxy(40,10);			printf("Editando o registro...");
							gotoxy(40,11);			printf("===================================");
							gotoxy(40,13);			printf("Codigo: ");
														scanf("%i",reg.cod);
							gotoxy(40,14);			printf("Nome..: ");
														fflush(stdin);
														fgets(reg.nome,30,stdin);
							gotoxy(40,15);			printf("Nota 1: ");
														scanf("%f",reg.n1);
							gotoxy(40,16);			printf("Nota 2..: ");
														scanf("%f",reg.n2);
														
							reg.media=(reg.n1+reg.n2)/2;
							gotoxy(40,17);			printf("media.: %.1f",reg.media);
							
							gotoxy(40,20);			printf("Confirma a edição? s/n  ");
							gotoxy(63,20);			resp=getche();
							
							//se o usuario confirmar a edição
							//a função seek posiciona o apontador de registros
							//e fwrite grava as alterações no arquivo
							if(resp=='s' || resp=='S'){
								apontador--;
								fseek(arq,apontador * sizeof(struct aluno),SEEK_SET);
								teste=fwrite(&reg,sizeof(struct aluno),1,arq);
								if(teste){
									gotoxy(40,20);
										pritnf("registro editado com sucesso");
								}
							}
						}
				}
				
			}
			if(achei==0){
				gotoxy(10,12);			printf("Registro nao encontrado.");
			}
			gotoxy(10,22);		printf("Deseja continuar? s/n  ");
			resp=getche();
		}
		fclose(arq);			//fecha o arquivo
		}
		else{
			clrscr();
			gotoxy(10,8);		printf("Arquivo vazio.");
			gotoxy(10,10);		printf("Tecle algo para voltar ao menu.");
		}		
	}
	
	///////////////////////////=========================função EXCLUIR=========================///////////////////////////
	
	void excluir(){
		char nomepesq[30];
		int achei,apontador;
		resp='s';
		
		arq=fopen("cad_aluno.txt","rb+");//abre o arquivo para leitura e escrita
		
		if(arq){
			while(resp== 's' || resp== 'S'){
				achei=0;
				clrscr ();
				gotoxy(10,13);			printf("Exclui o registro do aluno");
				gotoxy(10,5);			pritnf("==========================");
				gotoxy(10,7);
				printf("Nome a ser pesquisado: ");
				fflush(stdin);
				fgets(nomepesq,30,stdin);
				
				rewind(arq);		//posiciona o apontador de reg no inicio do arquivo
				apontador=0;
				while(!feof (arq) && achei==0){
					teste=fread(&reg,sizeof(struct aluno),1, arq);
					apontador++;		//conta os registros lidos
					if(teste){
						//compara o campo nome do registro como o nome pesquisado
						if(strcmp(reg.nome,nomepesq)==0){
							//se o nome pesquisado foi enontrado
							//exibe os outros campos registrados na tela
							gotoxy(10,8);			printf("Pesquisa realizada com sucesso!");
							gotoxy(10,10);			printf("===============================");
							gotoxy(10,12);			printf("codigo..: %i",reg.cod);
							gotoxy(10,13);			printf("Nome....: %s",reg.nome);
							gotoxy(10,14);			printf("Nota 1..: %.1f",reg.n1);
							gotoxy(10,15);			printf("Nota 2..: %.1f",reg.n2);
							gotoxy(10,16);			printf("media...: %.1f",reg.media);
							achei = 1;
							
							//atribui branco as strings e zero aos campos numericos
							reg.cod=0;
							strcpy(reg.nome,"");
							reg.n1=0;
							reg.n2=0;
							reg.media=0;
							
							gotoxy(10,19);			printf("Confirma a exclusão? s/n");
							gotoxy(35,19);			resp=getche();
							
							//se o usuario confimrar a exclusao
							//a função seek posiciona o apontador dos registros
							//e fwrite grava as alterações no arquivo
							
							if (resp=='s' || resp=='S'){
								apontador--;
								fseek(arq,apontador * sizeof(struct aluno), SEEK_SET);
								teste=fwrite(&reg,sizeof(struct aluno),1,arq);
								if(teste){
									gotoxy(10,19);
									printf("Registro excluido com sucesso!");
								}
							}
						}
					}
				}
				if(achei==0){
					gotoxy(10,12);
					printf("Registro nao encontrado.");
				}
				gotoxy(10,22);
				printf("Deseja continuar? s/n  ");
				resp=getche();
			}
			fclose(arq);		//fecha o arquivo
		}
		else{
			clrscr();
			gotoxy(10,8);			printf("Arquivo vazio.");
			gotoxy(10,10);			printf("Tecle algo para voltar ao menu...");
			getch();
		}
	}
	
