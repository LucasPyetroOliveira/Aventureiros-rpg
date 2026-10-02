#include "equipamento.h"
/*Inicializa os equipamentos do personagem.
No começo, todas as posições ficam vazias.
ocupado[i] = 0 -> posição vaziaocupado[i] = 1 -> posição ocupada*/
void inicializar_equipamentos(Equipamentos *equipamentos){

    /*Percorre todas as 10 posições dos equipamentos.*/
    for(int i = 0; i < 10; i++){
        /*Coloca 0 na posição atual, indicando que ela está vazia.*/
        equipamentos->ocupado[i] = 0;
    }
}

/*Verifica se o tipo do item é compatível com a posição onde queremos equipá-lo.
Retorna:
1 -> item pode ser colocado nessa posição
0 -> item não pode ser colocado nessa posição. */
int tipo_compativel(Item item, PosicaoEquipamento posicao){

    /*O switch verifica qual é o tipo do item recebido.*/
    switch(item.tipo){

        /*Se o item for um ELMO, ele só pode ficar na posição SLOT_ELMO.*/
        case ELMO:
            return posicao == SLOT_ELMO;

        /*Se o item for um PEITORAL, ele só pode ficar na posição SLOT_PEITORAL.*/
        case PEITORAL:
            return posicao == SLOT_PEITORAL;

        /*Se o item for uma MANOPLA, ela só pode ficar na posição SLOT_MANOPLAS.*/
        case MANOPLAS:
            return posicao == SLOT_MANOPLAS;

        /*Se o item for uma CALÇA, ela só pode ficar na posição SLOT_CALCA.*/
        case CALCA:
            return posicao == SLOT_CALCA;

        /*Se o item for uma BOTA, ela só pode ficar na posição SLOT_BOTAS.*/
        case BOTAS:
            return posicao == SLOT_BOTAS;

        /*Se o item for um ANEL, ele só pode ficar na posição SLOT_ANEL.*/
        case ANEL:
            return posicao == SLOT_ANEL;

        /*Se o item for um COLAR, ele só pode ficar na posição SLOT_COLAR.*/
        case COLAR:
            return posicao == SLOT_COLAR;

        /*Se o item for um CINTO, ele só pode ficar na posição SLOT_CINTO.*/
        case CINTO:
            return posicao == SLOT_CINTO;

        /*Uma arma de uma mão pode ser equipada tanto na mão direita quanto na mão esquerda.
        O operador || significa "OU".*/
        case ARMA_UMA_MAO:
            return posicao == SLOT_MAO_DIREITA ||
                   posicao == SLOT_MAO_ESQUERDA;

        /*Uma arma de duas mãos pode ser colocadaa partir de uma das posições das mãos.
        Depois, na função de equipar, devemos
        verificar se as DUAS mãos estão livres.*/
        case ARMA_DUAS_MAOS:
            return posicao == SLOT_MAO_DIREITA ||
                   posicao == SLOT_MAO_ESQUERDA;

        /*Caso o tipo do item não seja nenhum dos tipos conhecidos.*/
        default:
            return 0;
    }
}