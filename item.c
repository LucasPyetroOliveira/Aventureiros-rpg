#include "item.h" /* Traz as informações do arquivo item.h para cá. */

int validar_item(Item item){
    if (item.ID <= 0){ /* Valida o ID do item. */
        return 0;
    }

    if (item.Nome[0] == '\0'){ /* Valida se o item tem nome. */
        return 0;
    }

    if (item.espacos < 1 || item.espacos > 50){ /* Se ele tem entre 1 e 50 de carga. */
        return 0;
    }

    if (item.poder < 0){ /* Seu nível de poder. */
        return 0;
    }

    if (item.tipo < ELMO || item.tipo > ARMA_DUAS_MAOS){ /* Se esta entre elmo e arma de duas mãos. */
        return 0;
    }

    return 1; /* Se passar por tudo isso retorna 1 = sim, ou seja item validado. */
}