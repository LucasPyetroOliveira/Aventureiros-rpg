#ifndef ITEM_H
#define ITEM_H
/* 
#ifndef ITEM_H
#define ITEM_H
Esta dizendo para a liguagem C criar uma caixa que ainda não existe.
"Se essa caixa ainda não foi criada, crie." */

typedef enum{ /*Estamos criando uma lista de tipos possíveis de item.*/
    ELMO,
    PEITORAL,
    MANOPLAS,
    CALCA,
    BOTAS,
    ANEL,
    COLAR,
    CINTO,
    ARMA_UMA_MAO,
    ARMA_DUAS_MAOS
} TipoDoItem; /*Estamos dando o nome TipoDoItem para esse tipo.
E essa variável só deve representar um dos tipos que criamos.*/

typedef struct{ /* Aqui está falando C, um ITEM possui todas essas informações. */
    int ID;
    char Nome[50];
    TipoDoItem tipo;
    int espacos;
    int bonus_ataque;
    int bonus_defesa;
    int bonus_vida;
    int bonus_iniciativa;
    int poder;
}Item ;

#endif /* Esta fechando a caixa lá do começo. */