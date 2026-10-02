#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include "item.h"

typedef enum {

    SLOT_ELMO,
    SLOT_PEITORAL,
    SLOT_MANOPLAS,
    SLOT_CALCA,
    SLOT_BOTAS,
    SLOT_ANEL,
    SLOT_COLAR,
    SLOT_CINTO,
    SLOT_MAO_DIREITA,
    SLOT_MAO_ESQUERDA

} PosicaoEquipamento;


/*
    Estrutura que representa os equipamentos
    que o personagem está usando.
*/
typedef struct {

    Item itens[10];

    int ocupado[10];

} Equipamentos;


void inicializar_equipamentos(Equipamentos *equipamentos);

int tipo_compativel(Item item, PosicaoEquipamento posicao);

#endif