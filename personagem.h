#ifndef PERSONAGEM_H 
#define PERSONAGEM_H
/* 
#ifndef PERSONAGEM_H 
#define PERSONAGEM_H
Esta dizendo para a liguagem C criar uma caixa que ainda não existe.
"Se essa caixa ainda não foi criada, crie." */

#include "inventario.h"  /* "Ei C, eu vou usar coisas que estão na biblioteca inventario.h." */
#include "equipamento.h"/* "Ei C, eu vou usar coisas que estão na biblioteca equipamento.h." */

#define CAPACIDADE_PERSONAGENS 20 /* Aqui ta falando que que o cadastro pode guardar no máximo 20 personagens. */

typedef enum { /* enum vai criar as classes dos personagens.
O computador internamente transforma isso em números:
MAGO       = 0
GUERREIRO  = 1
LADINO     = 2
CLERIGO    = 3
BARDO      = 4
BARBARO    = 5

personagem.classe = MAGO;
personagem.classe = 0; */
    MAGO,
    GUERREIRO,
    LADINO,
    CLERIGO,
    BARDO,
    BARBARO,

} Classes;

typedef enum {/* Aqui acontece a mesma coisa que acontece lá em cima. ;-; */
    ELFO,
    HUMANO,
    ANAO,
    HALFLING,
    DRACONATOS,
    GOBLINS

} Racas;

typedef struct {/*Bom,  aqui estamos criando basicamente cavetas para a caixa personagem. */
    int ID;
    char Nome[50]; /* Significa que o nome pode guardar até 49 caracteres + \0. */
    Racas raca;
    Classes classe;
    int Nivel;
    int Limite_vida;
    int Atual_vida;
    int Ataque;
    int Defesa;
    int Iniciativa;
    int Poder;

    Inventario inventario; /* Aqui está dizendo que cada personagem tem um inventario. */

    Equipamentos equipamentos;/* Aqui está dizendo que cada personagem tem um equipamento. */

} Personagem;

typedef struct { /* Aqui basicamente é uma caixa que guarda vários personagem. */
    Personagem personagem[CAPACIDADE_PERSONAGENS];
    int quantidade; /* Diz quantos personagens realmente estão cadastrados. */

} CadastroPersonagem;

void inicializar_personagem(Personagem *personagem);
int validar_personagem(Personagem personagem);
void inicializar_cadastro(CadastroPersonagem *cadastro);
int cadastro_personagem(CadastroPersonagem *cadastro, Personagem personagem);
int busca_personagem(const CadastroPersonagem *cadastro, int ID, Personagem *personagem_encontrado);
int alterar_personagem(CadastroPersonagem *cadastro,int ID,Personagem personagem);
int excluir_personagem(CadastroPersonagem *cadastro,int ID);
void listar_personagens(const CadastroPersonagem *cadastro);
int equipar_item(Personagem *personagem, int ID, PosicaoEquipamento posicao);
int desequipar_item(Personagem *personagem, PosicaoEquipamento posicao);
int calcular_ataque_total(const Personagem *personagem);
int calcular_defesa_total(const Personagem *personagem);
int calcular_vida_total(const Personagem *personagem);
int calcular_iniciativa_total(const Personagem *personagem);
int calcular_poder_total(const Personagem *personagem);

#endif /* Esta fechando a caixa lá do começo. */