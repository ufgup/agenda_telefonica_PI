/*
 *  Definição de tipos estruturais de objetos do programa
 */

#define CAR 40 // Definindo quantidade de caracteres de uma String
#define MAX 100 // Para redimensionar a capacidade da fila, basta modificar essa constante para o valor desejado.

typedef char String[CAR];

typedef struct contato {
	String nome;
	String email;
	char telefone[11];
}T_contato;

typedef struct agenda {
	T_contato contatos[MAX];
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
