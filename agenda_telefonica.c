/*
 * agenda_telefonica.c
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "sistema.h"
#include "struct.h"

/*
 * Inicia a agenda telefonica com o padrao
 */
void inicia_agenda(T_agenda *agenda_telefonica) {
	agenda_telefonica->primeiro = 0;
	agenda_telefonica->ultimo = 0;
	agenda_telefonica->tamanho = 0;
}


/*
 * Apresenta o Menu de opções disponíveis no Sistema e trata opções inválidas
 */
char apresentar_menu() {
	char opcao;
	
	printf("----------------------- AGENDA ELETRONICA -----------------------\n\n");
	printf("Digite um comando para prosseguir:\n");
	printf("C – Para cadastrar um contato na agenda.\n");
	printf("L – Para listar todos os contatos já cadastrados na agenda.\n");
	printf("P – Procurar um contato na agenda pelo nome.\n");
	printf("R – Remover um contato da agenda pelo nome.\n");
	printf("E – Exibir todos os contatos que começam com uma letra.\n");
	printf("S – Sair da agenda eletrônica.\n");
	printf("----------------------------------------------------------------\n");
	printf("Selecione a opção desejada: ");
	scanf("%c", &opcao);
	getchar(); //Limpar buffer do Teclado
	
	if(opcao != 'C' && opcao != 'L' && opcao != 'P' && opcao != 'R' && opcao != 'S' && opcao != 'E'
			&& opcao != 'c' && opcao != 'l' && opcao != 'p' && opcao != 'r' && opcao != 's' && opcao != 'e') {
		limpar_tela();
		printf("Opção inválida. Digite uma opção válida\n");
		opcao = apresentar_menu(); 	
	}
	
	return opcao;
}

/*
 * Função responsável por reordenar a agenda por ordem alfabética do nome
 */
void ordenar_agenda_por_nome(T_agenda *agenda_telefonica) {
	int i, j=0, c;
	T_contato contato_temp;
	
	if(agenda_telefonica->tamanho == 0) {
		// agenda vazia... não tenho o que fazer.
		return;
	}
	
	while(j < agenda_telefonica->tamanho) {
		
		for(i = 0; i < agenda_telefonica->tamanho-1; i++) {
			c = comparar_string(agenda_telefonica->contatos[i].nome, agenda_telefonica->contatos[i+1].nome);
			if(c > 0) {
				contato_temp = agenda_telefonica->contatos[i];
				agenda_telefonica->contatos[i] = agenda_telefonica->contatos[i+1];
				agenda_telefonica->contatos[i+1] = contato_temp;
			}
		}
		
		j++;
	}
	
}

/*
 * Função responsável por reordenar a agenda por ordem dos numerais do telefone
 */
void ordenar_agenda_por_telefone(T_agenda *agenda_telefonica) {
	int i, j=0, c;
	T_contato contato_temp;
	
	if(agenda_telefonica->tamanho == 0) {
		// agenda vazia... não tenho o que fazer.
		return;
	}
	
	while(j < agenda_telefonica->tamanho) {
		
		for(i = 0; i < agenda_telefonica->tamanho-1; i++) {
			c = comparar_string(agenda_telefonica->contatos[i].telefone, agenda_telefonica->contatos[i+1].telefone);
			if(c > 0) {
				contato_temp = agenda_telefonica->contatos[i];
				agenda_telefonica->contatos[i] = agenda_telefonica->contatos[i+1];
				agenda_telefonica->contatos[i+1] = contato_temp;
			}
		}
		
		j++;
	}
	
}

/*
 * Função responsável por reordenar a agenda por ordem alfabetica dos emails
 */
void ordenar_agenda_por_email(T_agenda *agenda_telefonica) {
	int i, j=0, c;
	T_contato contato_temp;
	
	if(agenda_telefonica->tamanho == 0) {
		// agenda vazia... não tenho o que fazer.
		return;
	}
	
	while(j < agenda_telefonica->tamanho) {
		
		for(i = 0; i < agenda_telefonica->tamanho-1; i++) {
			c = comparar_string(agenda_telefonica->contatos[i].email, agenda_telefonica->contatos[i+1].email);
			if(c > 0) {
				contato_temp = agenda_telefonica->contatos[i];
				agenda_telefonica->contatos[i] = agenda_telefonica->contatos[i+1];
				agenda_telefonica->contatos[i+1] = contato_temp;
			}
		}
		
		j++;
	}
	
}

/*
 * Função responsável por reordenar a agenda por ordem alfabetica dos emails
 */
void ordenar_agenda_por_data_nascimento(T_agenda *agenda_telefonica) {
	int i, j=0, c;
	T_contato contato_temp;
	
	if(agenda_telefonica->tamanho == 0) {
		// agenda vazia... não tenho o que fazer.
		return;
	}
	
	while(j < agenda_telefonica->tamanho) {
		
		for(i = 0; i < agenda_telefonica->tamanho-1; i++) {
			c = comparar_string(agenda_telefonica->contatos[i].data_nascimento, agenda_telefonica->contatos[i+1].data_nascimento);
			if(c > 0) {
				contato_temp = agenda_telefonica->contatos[i];
				agenda_telefonica->contatos[i] = agenda_telefonica->contatos[i+1];
				agenda_telefonica->contatos[i+1] = contato_temp;
			}
		}
		
		j++;
	}
	
}

/*
 * Cadastra um novo contato na agenda;
 */
void cadastrar_novo_contato(T_agenda *agenda_telefonica) {
	T_contato novo_contato;
	
	printf("Digite o nome do contato: ");
	fgets(novo_contato.nome, CAR, stdin);
	
	printf("Digite o email do contato: ");
	fgets(novo_contato.email, CAR, stdin);
	
	printf("Digite o telefone do contato: ");
	scanf("%s", novo_contato.telefone);
	getchar();
	
	printf("Digite a data de nascimento (formato: aaaa-mm-dd): ");
	scanf("%s", novo_contato.data_nascimento);
	getchar();
	
	agenda_telefonica->contatos[agenda_telefonica->ultimo] = novo_contato;
	agenda_telefonica->ultimo++;
	agenda_telefonica->tamanho++;
	
	printf("Novo contato cadastrado\n");
	travatela();
}
/*
 * Mostra todos os dados de um contato
 */
void apresentar_contato(T_contato contato_agenda) {
		printf("Nome: %s", contato_agenda.nome);
		printf("Email: %s", contato_agenda.email);
		printf("Telefone: %s\n", contato_agenda.telefone);
		printf("Data Nascimento: %s\n", contato_agenda.data_nascimento);
		printf("===========================================================\n");
} 

/*
 * Listagem de contatos da agenda.
 * 
 * A lista está ordenada pela ordem que os contatos foram cadastrados.
 * Ordenação deve ser feita no momento do cadastro.
 */
void listar_contatos(T_agenda *agenda_telefonica) {
	int i;
	char op;
	
	printf("Informe a forma como você deseja que os contatos sejam ordenados na apresentação\n");
	printf("N - por nome\n");
	printf("T - por telefone\n");
	printf("E - por email\n");
	printf("D - por data de nascimento\n");
	printf("Digite a opção desejada: ");
	scanf("%c", &op);
	getchar();
	limpar_tela();
	
	switch(op) {
		case('n'):
		case('N'):
			printf("Contatos ordenados por nome:\n\n");
			ordenar_agenda_por_nome(agenda_telefonica);
			break;
		case('t'):
		case('T'):
			printf("Contatos ordenados por telefone:\n\n");
			ordenar_agenda_por_telefone(agenda_telefonica);
			break;
		case('e'):
		case('E'):
			printf("Contatos ordenados por email:\n\n");
			ordenar_agenda_por_email(agenda_telefonica);
			break;
			
		case('d'):
		case('D'):
			printf("Contatos ordenados por data de nascimento:\n\n");
			ordenar_agenda_por_data_nascimento(agenda_telefonica);
			break;
			
		default:
			printf("Opção desconhecida. Vou ordenar por nome\n");
			ordenar_agenda_por_nome(agenda_telefonica);
	}
	
	for(i = 0; i < agenda_telefonica->tamanho ; i++) {
		apresentar_contato(agenda_telefonica->contatos[i]);
	}
	
	travatela();
}

/*
 * Busca um contato na agenda de acordo com o nome passado por parâmetro
 */
int buscar_contato(T_agenda *agenda_telefonica) {
	int i = 0;
	String nome;
	
	printf("Digite o nome do contato que você deseja buscar: ");
	fgets(nome, CAR, stdin);
	
	while(i < agenda_telefonica->ultimo) {
		if( comparar_string(agenda_telefonica->contatos[i].nome, nome) == true ) {
			apresentar_contato(agenda_telefonica->contatos[i]);
			travatela();
			return i;
		}
		i++;
	}
	
	// Se chegar aqui é porque deu ruim;
	printf("Nao identifiquei nenhum contato com o nome %s\n", nome);
	travatela();
	return -1;
}

/*
 * Busca todos os contatos cujo nome comece com a letra informada no parâmetro
 */
void buscar_contatos_por_letra(T_agenda *agenda_telefonica) {
	char letra;
	int i;
	
	printf("Digite a letra inicial do nome dos contatos que você deseja buscar: ");
	scanf("%c", &letra);
	getchar();
	
	ordenar_agenda_por_nome(agenda_telefonica);
	
	for(i = 0; i < agenda_telefonica->tamanho ; i++) {
		if(agenda_telefonica->contatos[i].nome[0] == letra) {
			apresentar_contato(agenda_telefonica->contatos[i]);
		}
	}
	
	travatela();
}

/*
 * Remove um contato da agenda pelo nome
 */
void excluir_contato(T_agenda *agenda_telefonica) {
	int index, i;
	
	index = buscar_contato(agenda_telefonica);
	
	if(index != -1) {
		for(i = index; i < agenda_telefonica->tamanho; i++) {
			agenda_telefonica->contatos[i] = agenda_telefonica->contatos[i+1];
		}
		
		agenda_telefonica->ultimo--;
		agenda_telefonica->tamanho--;
	}
}

/*
 * Função principal do programa.
 */
int main(int argc, char **argv) {
	
	char opcao;
	T_agenda agenda_telefonica;
	
	inicia_agenda(&agenda_telefonica);
	
	do {
		limpar_tela();
		opcao = apresentar_menu();
		limpar_tela();
		
		switch(opcao) {
			case('c'):
			case('C'):
				printf("Cadastrar um contato na agenda.\n\n");
				cadastrar_novo_contato(&agenda_telefonica);
				break;
				
			case('l'):
			case('L'):
				printf("Listar todos os contatos já cadastrados na agenda.\n\n");
				listar_contatos(&agenda_telefonica);
				break;
				
			case('p'):
			case('P'):
				printf("Procurar um contato na agenda pelo nome.\n\n");
				buscar_contato(&agenda_telefonica);
				break;
				
			case('r'):
			case('R'):
				printf("Remover um contato da agenda pelo nome.\n\n");
				excluir_contato(&agenda_telefonica);
				break;
				
			case('e'):
			case('E'):
				printf("Exibir todos os contatos que começam com uma letra.\n\n");
				buscar_contatos_por_letra(&agenda_telefonica);
				break;
			
			case('s'):
			case('S'):
				printf("Obrigado por usar nossa agenda! Até mais!\n\n");
				break;
		}
		
	} while(opcao != 'S' && opcao != 's');
	
	return 0;
}

