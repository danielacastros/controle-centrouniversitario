#include <stdio.h>
#include<string.h>
#include <locale.h>
#define TF 30
#define TFA 10
#define TFD 5

main()
{
	int i=0, j=0, vRA[TFA], op, op1, op2, op3, op4, RA, TLA=0, achou, TLD=0, vCod[TFD], cod, vRA_mat[TFA*TFD], vCod_mat[TFA*TFD], TLM=0, pos;
	char nome[TF][30], continuar, disciplina[TF][30];
	float vNota1[TFA*TFD], vNota2[TFA*TFD], media[TFA*TFD];
	
	
	printf("\n---------- MENU PRINCIPAL ----------");
	printf("\n 1 - Cadastrar");
	printf("\n 2 - Lancar Notas");
	printf("\n 3 - Excluir Aluno");
	printf("\n 4 - Relatorios");
	printf("\n 5 - Finalizar");
	printf("\n Opcao:");
	scanf("%d", &op);
	
	
	
	while(op!=5)
	{
		switch (op)
		{
			case 1: printf("\n---------- MENU CADASTRO ----------");
					printf("\n 1 - Cadastrar aluno");
					printf("\n 2 - Cadastrar Disciplina");
					printf("\n 3 - Lista de Alunos Cadastrados");
					printf("\n 4 - Finalizar");
					printf("\n Opcao:");
					scanf("%d", &op1);
					
					while(op1!=4)
					{

						switch(op1)
						{
							case 1: printf("\nDigite o RA do aluno:");
									scanf("%d", &RA);									
									while (RA>0 && TLA<TFA)
									{
										achou=0;
										for(i=0;i<TLA;i++)
										  if(RA==vRA[i])
										    achou=1;
										if (achou==1)
											printf("\nAluno ja cadastrado.");
										else
										{
										
										    printf("\nDigite o nome do aluno:");
								            fflush(stdin);
										    gets(nome[TLA]);
											
											vRA[TLA]=RA;
											TLA++;
									    }
										if(TLA<TFA)
										{
										  printf("\nDigite o RA do aluno:");
										  scanf("%d", &RA);
									    }
									}
									
									while(RA>0 && TLA<TFA)
									{
										printf("Aluno [%d]:  RA: %d", i, vRA[i]);
									}														
									break;
									
							case 2: printf("\nDigite o Codigo da disciplina:");
									scanf("%d", &cod);									
									while (cod>0 && TLD<TFD)
									{									
										achou=0;
											for(i=0;i<TLD;i++)																					
												if(cod==vCod[i])
											    	achou=1;
												if (achou==1)
													printf("Disciplina ja cadastrada.");
												else
												{
											
												    printf("\nDigite o nome da disciplina:");
										            fflush(stdin);
												    gets(disciplina[TLD]);
													
													vCod[TLD]=cod;
													TLD++;
										    	}
										    	if(TLD<TFD)
												{
													printf("\nDigite o Codigo da disciplina:");
													scanf("%d", &cod);
											    }											
									}
									break;
									
							case 3: printf("\n---------- ALUNOS CADASTRADOS ----------");
									for(i=0;i<TLA;i++)																			
										printf("\n[%d]: %s RA %d", i, nome[i], vRA[i]);									
									break;								
						}
						printf("\n---------- MENU CADASTRO ----------");
					    printf("\n 1 - Cadastrar Aluno");
					    printf("\n 2 - Cadastrar Disciplina");
					    printf("\n 3 - Lista de Alunos Cadastrados");
						printf("\n 4 - Finalizar");					    
					    printf("\n Opcao:");
					    scanf("%d", &op1);														
					}
					break;
										
			case 2: printf("\n---------- MENU LANCAMENTO DE NOTAS ----------");
					printf("\n 1 - Lancar notas 1 e 2");
					printf("\n 2 - Finalizar");
					printf("\n Opcao:");
					scanf("%d", &op2);
															
					while(op2!=2)
					{	
						switch (op2)
						{
							case 1: printf("\nDigite o RA do aluno:");
									scanf("%d", &RA); 
									while(RA>0 && TLM<TFA*TFD)
									{	
										pos=0;
										while(RA!=vRA[pos]&&pos<TLA)
											pos++;
													
										if(pos<TLA)
										{
											printf("\nDigite o Codigo da disciplina:");
											scanf("%d", &cod);
											pos=0;
									        while(cod!=vCod[pos]&&pos<TLD)
									        	pos++;
											if(pos<TLD)
											{
												pos=0;
												while(pos<TLM && (RA!=vRA_mat[pos] || cod!=vCod_mat[pos]))										
													pos++;												
												if(pos==TLM && pos<TFD*TFA)	
												{									
													vRA_mat[TLM]=RA;
													vCod_mat[TLM]=cod;
													printf("\nAluno [%d] cadastrado com sucesso!", TLM);
													printf("\nDigite a nota 1:");
													scanf("%f", &vNota1[TLM]);
													printf("\nDigite a nota 2:");
													scanf("%f", &vNota2[TLM]);
													media[TLM]=(vNota1[TLM]+vNota2[TLM])/2;
													printf("\nMedia %.2f", media[TLM]);
													TLM++;
												}
												else
												printf("Aluno ja cadastrado");																																		
											}
											else
											  printf("\nDisciplina nao encontrada");															
										}											
										else												
											printf("\nRA nao encontrado");
										printf("\nDigite o RA do aluno:");
								        scanf("%d", &RA); 													
									}								
									break;
						}	
						printf("\n---------- MENU LANCAMENTO DE NOTAS ----------");
					    printf("\n 1 - Lancar notas 1 e 2");
					    printf("\n 2 - Finalizar");
					    printf("\n Opcao:");
					    scanf("%d", &op2);																					
					}							
					break;
			case 3: printf("---------- EXCLUSAO DE ALUNOS ----------");
					printf("\nInsira o RA do aluno=");
					scanf("%d", &RA);
					pos=0;
					while(pos<TLA && RA!=vRA[pos])
						pos++;
					if(pos<TLA)
					{																	
						for(i=pos;i<TLA-1;i++)
						{
							vRA[i]=vRA[i+1];
							strcpy(nome[i], nome[i+1]);
						}
						TLA--;
												
						printf("\nAluno excluido com sucesso");
					}
					else
						printf("\nAluno nao encontrado");																
					break;
					
			case 4: printf("\n---------- MENU RELATORIO DE NOTAS ----------");
					printf("\n 1 - Listagem de Notas");
					printf("\n 2 - Consulta Aprovados por disciplina");
					printf("\n 3 - Consulta Reprovados por disciplina");
					printf("\n 4 - Finalizar");
					printf("\n Opcao:");
					scanf("%d", &op4);
					
					while(op4!=4)
					{
					
						switch(op4)
						{						
							case 1: printf("\n---------- LISTAGEM DE NOTAS ----------");
									for(i=0;i<TLA;i++)
									{
										printf("\nAluno: %s", nome[i]);
										for(j=0;j<TLM;j++)
										{
											if(vRA[i]==vRA_mat[j])
											{
												pos=0;
												while(pos<TLD && vCod_mat[j]!=vCod[pos])
													pos++;													
												printf("\nDisciplina: %d - %s		Nota 1: %.2f		Nota 2:%.2f		Media:%.2f", vCod_mat[j], disciplina[pos], vNota1[j], vNota2[j], media[j]);													
											}											
										}
									}																																																				
									break;
									
							case 2: printf("\n---------- ALUNOS APROVADOS POR DISCIPLINA ----------");
									printf("\nInsira o codigo da disciplina:");
									scanf("%d", &cod);
																		
									pos=0;
									while(pos<TLD && cod!=vCod[pos])
										pos++;
									printf("\nDisciplina: %d - %s", vCod[pos], disciplina[pos]);
									for(i=0;i<TLM;i++)
									{
										if(media[i]>6 && vCod_mat[i]==vCod[pos])
										{
											j=0;
											while(j<TLA && vRA_mat[i]!=vRA[j])
												j++;
											printf("\nNome: %s		 RA: %d 	Media: %.2f", nome[j], vRA_mat[i], media[i]);												
										}										
									}
									break;
									
							case 3: printf("\n---------- ALUNOS REPROVADOS POR DISCIPLINA ----------");
									printf("\nInsira o codigo da disciplina:");
									scanf("%d", &cod);
																		
									pos=0;
									while(pos<TLD && cod!=vCod[pos])
										pos++;
									printf("\nDisciplina: %d - %s", vCod[pos], disciplina[pos]);
									for(i=0;i<TLM;i++)
									{
										if(media[i]<6 && vCod_mat[i]==vCod[pos])
										{
											j=0;
											while(j<TLA && vRA_mat[i]!=vRA[j])
												j++;
											printf("\nNome: %s		 RA: %d 	Media: %.2f", nome[j], vRA_mat[i], media[i]);												
										}
									}
									break;
						}
						printf("\n---------- MENU RELATORIO DE NOTAS ----------");
						printf("\n 1 - Listagem de Notas");
						printf("\n 2 - Consulta Aprovados por disciplina");
						printf("\n 3 - Consulta Reprovados por disciplina");
						printf("\n 4 - Finalizar");
						printf("\n Opcao:");
						scanf("%d", &op4);
					}				
					break;						
		}
		printf("\n---------- MENU PRINCIPAL ----------");
	  	printf("\n 1 - Cadastrar");
		printf("\n 2 - Lancar Notas");
		printf("\n 3 - Excluir Aluno");
		printf("\n 4 - Relatorios");
		printf("\n 5 - Finalizar");
		printf("\n Opcao:");
		scanf("%d", &op);
	}	
}

