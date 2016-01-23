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

/*
 * Essa função serve para limpar a tela.
 * 
 * Abstração para encapsular detalhes do Sistema Operacional.
 */
void limpar_tela() {
	system("clear"); // Linux
	// system("cls"); //windows (descomente para usar)
}
/*
 * Essa função aparece para o usuário quando ele termina de fazer alguma ação no sistema. 
 * Ela solicita que o usuário digite enter para voltar para o fluxo principal
 * 
 */
void travatela(){	
	printf("Digite ENTER para continuar\n");
	getchar();
	
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

int main(int argc, char **argv) {
	
	char opcao;
	
	do {
		limpar_tela();
		opcao = apresentar_menu();
	} while(opcao != 'S' && opcao != 's');
	
	return 0;
}

