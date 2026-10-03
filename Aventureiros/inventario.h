#ifndef INVENTARIO_H
#define INVENTARIO_H
/*
#ifndef INVENTARIO_H
#define INVENTARIO_H 
Está dizendo para a liguagem C criar uma caixa que ainda não existe.
"Se essa caixa ainda não foi criada, crie." */

#include "item.h" /* Aqui está falando "C, pega a definição de Item lá na biblioteca item.h." "*/

#define CAPACIDADE_INVENTARIO 50 /* Aqui está definindo a capacidade do meu inventario de 50. */

typedef struct{
    Item itens[CAPACIDADE_INVENTARIO]; /*Capacidade de 50.*/
    int quantidade; /* Quantos itens existem atualmente. */

}Inventario ;

void inicializar_inventario(Inventario *inventario);
int calcular_ocupacao(const Inventario *inventario);
int adicionar_item(Inventario *inventario, Item item);
int buscar_item(const Inventario *inventario, int ID, Item *item_encontrado);
int remover_item(Inventario *inventario, int ID);
void listar_itens(const Inventario *inventario);

#endif /* Ta fechando a caixa.*/