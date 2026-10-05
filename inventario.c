#include <stdio.h>
#include "inventario.h"

void inicializar_inventario(Inventario *inventario){

    inventario->quantidade = 0; /* O inventario começa com nenhum item. */

}

int calcular_ocupacao(const Inventario *inventario){

    int soma = 0;

    for(int i = 0;i < inventario->quantidade;i++){ /* Vai passar por todos os itens do inventario. */

        soma += inventario->itens[i].espacos;/* Aqui ta falando pra pegar o item atual e ver quantos espaços ele ocupa.*/

    }

    return soma;
}

int adicionar_item(Inventario *inventario, Item item){ /* Essa função tenta colocar um item no inventário. */

    if(validar_item(item) == 0){ /* Aqui vamos validar o item. */
        return 0; 
    }

    for(int i = 0;i < inventario->quantidade;i++){ /* Percorre todos os itens existentes. */
        if (inventario->itens[i].ID == item.ID){ /* Não deixa adicionar um item com o mesmo ID. */
            return 0;
        }
    }

    if (calcular_ocupacao(inventario) + item.espacos > 50){ /* Não deixa adicionar um item que passe a capacidade maxima. */
        return 0;
    }

    inventario->itens[inventario->quantidade] = item; /*coloca cada item em sua posição. */
    inventario->quantidade++; /* Adiciona um novo item. Vamooooo*/

    return 1;
}

int buscar_item(const Inventario *inventario, int ID, Item *item_encontrado){

    for(int i = 0;i < inventario->quantidade;i++){ /*Vai passar por cada item do inventario. */

        if (inventario->itens[i].ID == ID){
            *item_encontrado = inventario->itens[i];/* 
            Item atual -> ID 8
            ID procurado -> 8*/
            return 1; /*Achou o item. */
        }
    }

    return 0;
}

int remover_item(Inventario *inventario, int ID){

    for(int i = 0;i < inventario->quantidade;i++){ /* Vai procurar o item que deseja ser removido. */

        if (inventario->itens[i].ID == ID){ /* Se encontrar. */

            for(int j = i;j < inventario->quantidade - 1;j++){  /* Isso serve para puxar todo mundo para trás. */

                inventario->itens[j] = inventario->itens[j + 1];
            }

            inventario->quantidade--; /* Passa a ter menos um item. */

            return 1;
        }
    }

    return 0;
}

void listar_itens(const Inventario *inventario){ /* Essa função simplesmente passa por todos. */


    for(int i = 0;i < inventario->quantidade;i++){
        printf("ID = %d | Nome = %s | Tipo = %d | Espaco = %d | Bonus de ataque = %d | Bonus de defesa = %d | Bonus de vida = %d | Bonus de iniciativa = %d | Poder = %d\n", 
            inventario->itens[i].ID,
            inventario->itens[i].Nome,
            inventario->itens[i].tipo,
            inventario->itens[i].espacos,inventario->itens[i].bonus_ataque,inventario->itens[i].bonus_defesa,inventario->itens[i].bonus_vida,inventario->itens[i].bonus_iniciativa,inventario->itens[i].poder);
    }
}