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
	printf("S – Sair da agenda eletrônica.\n");
	printf("----------------------------------------------------------------\n");
	printf("Selecione a opção desejada: ");
	scanf("%c", &opcao);
	getchar(); //Limpar buffer do Teclado
	
	if(opcao != 'C' && opcao != 'L' && opcao != 'P' && opcao != 'R' && opcao != 'S' 
			&& opcao != 'c' && opcao != 'l' && opcao != 'p' && opcao != 'r' && opcao != 's') {
		limpar_tela();
		printf("Opção inválida. Digite uma opção válida\n");
		opcao = apresentar_menu(); 	
	}
	
	return opcao;
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
	
	agenda_telefonica->contatos[agenda_telefonica->ultimo] = novo_contato;
	agenda_telefonica->ultimo++;
	agenda_telefonica->tamanho++;
	
	printf("Novo contato cadastrado\n");
	travatela();
}

void apresentar_contato(T_contato contato_agenda) {
		printf("Nome: %s", contato_agenda.nome);
		printf("Email: %s", contato_agenda.email);
		printf("Telefone: %s\n", contato_agenda.telefone);
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
	
	for(i = 0; i < agenda_telefonica->tamanho ; i++) {
		apresentar_contato(agenda_telefonica->contatos[i]);
	}
	
	travatela();
}

/*
 * Busca um contato na agenda de acordo com o nome passado por parâmetro
 */
void buscar_contato(T_agenda *agenda_telefonica) {
	int i = 0;
	String nome;
	
	printf("Digite o nome do contato que você deseja buscar: ");
	fgets(nome, CAR, stdin);
	
	while(i < agenda_telefonica->ultimo) {
		if( comparar_string(agenda_telefonica->contatos[i].nome, nome) == true ) {
			apresentar_contato(agenda_telefonica->contatos[i]);
			travatela();
			return;
		}
		i++;
	}
	
	// Se chegar aqui é porque deu ruim;
	printf("Nao identifiquei nenhum contato com o nome %s\n", nome);
	travatela();
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
		
		switch(opcao) {
			case('c'):
			case('C'):
				limpar_tela();
				printf("Cadastrar novo contato\n\n");
				cadastrar_novo_contato(&agenda_telefonica);
				break;
				
			case('l'):
			case('L'):
				limpar_tela();
				printf("Lista de contatos\n\n");
				listar_contatos(&agenda_telefonica);
				break;
				
			case('p'):
			case('P'):
				limpar_tela();
				printf("Buscar um contato\n\n");
				buscar_contato(&agenda_telefonica);
				break;
			
			case('s'):
			case('S'):
				printf("Obrigado por usar nossa agenda! Até mais!\n\n");
				break;
		}
		
	} while(opcao != 'S' && opcao != 's');
	
	return 0;
}

