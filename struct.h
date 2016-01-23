/*
 *  Definição de tipos estruturais de objetos do programa
 */

typedef struct contato {
	String nome;
	String email;
	char telefone[11];
	char data_nascimento[10]; // Formato aaaa-mm-dd
}T_contato;

typedef struct agenda {
	T_contato contatos[MAX];
	int primeiro;
	int ultimo;
	int tamanho;
}T_agenda;

/*
 * struct.c
 * 
 * Copyright 2016 Bruno Nogueira de Oliveira <bruno@bruno-Inspiron-5547>
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
