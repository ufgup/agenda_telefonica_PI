/*
 * Biblioteca responsável por guardar as funções básicas de sistema.
 */ 

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
 * sistema.h
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
 * 
 */
