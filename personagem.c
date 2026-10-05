#include <stdio.h>
#include "personagem.h"
#include <string.h>

void inicializar_personagem(Personagem *personagem){

    personagem->ID = 0;
    personagem->Nome[0] = '\0';/* Está dizendo que a string está vazia. */
    personagem->raca = 0;
    personagem->classe = 0;
    personagem->Nivel = 0;
    personagem->Limite_vida = 0;
    personagem->Atual_vida = 0;
    personagem->Ataque = 0;
    personagem->Defesa = 0;
    personagem->Iniciativa = 0;
    personagem->Poder = 0;

    inicializar_inventario(&personagem->inventario); /* Aqui está chamando o endereço do inventario desse personagem. */
    inicializar_equipamentos(&personagem->equipamentos);  /* Aqui está chamando o endereço do equipamento desse personagem. */
    
}

int validar_personagem(Personagem personagem){ /* Aqui vamos validar o personagem 0 = não e 1 = sim. */

    if (personagem.ID <= 0){
        return 0; /* Igual se o ID dele for 0 ou < vai retornar 0 = não, ou seja não é valido. */
    }

    if (personagem.Nome[0] == '\0'){ /* Nesse caso é se o nome estiver vazio. */
        return 0;
    }

    if (strlen(personagem.Nome) > 49){ /* Aqui vai ser invalido se o nome do personagem tiver mais de 49 caracteres. */
        return 0;
    }

    /*Validando as raças*/
    if (personagem.raca < ELFO || personagem.raca > GOBLINS){ /* Aqui está dizendo que a raça precisa estar entre ELFO e GOBLINS ou seja entre 0 e 5. :)*/
        return 0;
    }

    /*Aqui acontece a mesma coisa que as raças só que agora com as classes. ;-:*/
    if (personagem.classe < MAGO || personagem.classe > BARBARO){
        return 0;
    }

    if (personagem.Nivel < 1 || personagem.Nivel > 20){ /* Se o nível do personagem estiver abaixo de 1 ou acima de 20 não vai validar o personagem. */
        return 0;
    }

    if (personagem.Limite_vida < 1 || personagem.Limite_vida > 999){ /* Mesma coisa do nível só que agora é a vida do personagem. */
        return 0;
    }

    if (personagem.Atual_vida < 0 || personagem.Atual_vida > personagem.Limite_vida){ /*Aqui basicamente está falando que não tem como o personagem ter mais vida que o seu limite de vida. (: */
        return 0;
    }

    if (personagem.Ataque < 0 || personagem.Ataque > 30){ /* O ataque do personagem está entre 0  e 30 de dano. */
        return 0;
    }

    if (personagem.Defesa < 1 || personagem.Defesa > 30){ /* Defesa entre 1 e 30.*/
        return 0;
    }

    if (personagem.Iniciativa < -5 || personagem.Iniciativa > 20){ /*Iniciativa entre -5 e 20. */
        return 0;
    }

    if (personagem.Poder < 1 || personagem.Poder > 100){/*Poder entre 1 e 100.*/
        return 0;
    }

    return 1; /*Está dizendo basicamente se o personagem passou por isso tudo ele é valido. Ebaaaa ;)*/
}

void inicializar_cadastro(CadastroPersonagem *cadastro){

    cadastro->quantidade = 0; /* Significa que ainda não tem nenhum personagem cadastrado. */
}

int cadastro_personagem(CadastroPersonagem *cadastro, Personagem personagem){ /* Essa função tenta colocar um personagem dentro do cadastro. */

    if (cadastro->quantidade >= CAPACIDADE_PERSONAGENS){ /* Se já tiver 20 personagem não cabe mais. */
        return 0;
    }

    if (validar_personagem(personagem) == 0){ /* Verifica se o personagem é valido. */
        return 0;
    }

    for(int i = 0;i < cadastro->quantidade;i++){ /* Aqui percorremos todos os personagens já cadastrados. */

        if(cadastro->personagem[i].ID == personagem.ID){ /* Isso garante que os IDs sejam únicos. */
            return 0;
        }
    }

    cadastro->personagem[cadastro->quantidade] = personagem; /* Coloca os personagens em suas posições. */

    cadastro->quantidade++; /* Está dizendo agora temos mais um personagem. */

    return 1;
}

int busca_personagem(const CadastroPersonagem *cadastro,int ID,Personagem *personagem_encontrado){ /* Basicamente vai procurar os personagens pelo ID.
O const diz que essa função pode olhar o cadastro, mas não pode modificá-lo. */

    for(int i = 0;i < cadastro->quantidade;i++){
        
        if(cadastro->personagem[i].ID == ID){
            *personagem_encontrado = cadastro->personagem[i];

            return 1;
        }
    }

    return 0;
}

int alterar_personagem(CadastroPersonagem *cadastro,int ID,Personagem personagem){ /*Basicamente vai procura um personagem e substitui pelos novos dados.*/

    if (validar_personagem(personagem) == 0){ /*O novo personagem precisa ser válido.*/
        return 0;
    }

    for(int i = 0;i < cadastro->quantidade;i++){ /*Procura dentro do cadastro.*/

        if (cadastro->personagem[i].ID == personagem.ID && cadastro->personagem[i].ID != ID){ /* Isso está protegendo contra ID duplicado. */
            return 0;
        }

        if (cadastro->personagem[i].ID == ID){
            cadastro->personagem[i] = personagem;
            /*Substitua o personagem antigo pelo novo.*/

            return 1; /*Alteração feita.*/
        }

    }

    return 0;
}

int excluir_personagem(CadastroPersonagem *cadastro,int ID){ 

    for(int i = 0;i < cadastro->quantidade;i++){ /*Procura o personagem pelo ID.*/

        if (cadastro->personagem[i].ID == ID){ /*Quando encontra*/
            
            for(int j = i;j < cadastro->quantidade - 1;j++){ /* Isso serve para puxar todo mundo para trás. */
                cadastro->personagem[j] = cadastro->personagem[j + 1];
            }

            cadastro->quantidade--; /* E diminui a quantidade de personagem. */

            return 1;
        }
    }

    return 0;
}

void listar_personagens(const CadastroPersonagem *cadastro){ 

    for(int i = 0;i < cadastro->quantidade;i++){ /* Essa função simplesmente passa por todos. */

        printf("ID = %d | Nome = %s | Raca = %d | Classe = %d | Nivel = %d | Limite de vida = %d | Atual vida = %d | Ataque = %d | Defesa = %d | Iniciativa = %d | Poder = %d\n",
            cadastro->personagem[i].ID,
            cadastro->personagem[i].Nome,
            cadastro->personagem[i].raca,
            cadastro->personagem[i].classe,
            cadastro->personagem[i].Nivel,
            cadastro->personagem[i].Limite_vida,
            cadastro->personagem[i].Atual_vida,
            cadastro->personagem[i].Ataque,
            cadastro->personagem[i].Defesa,
            cadastro->personagem[i].Iniciativa,
            cadastro->personagem[i].Poder);
    }
}

int equipar_item(Personagem *personagem, int ID, PosicaoEquipamento posicao){

    Item item;

    if (posicao < SLOT_ELMO || posicao > SLOT_MAO_ESQUERDA){
        return 0;
    }

    if (buscar_item(&personagem->inventario, ID, &item) == 0){
        return 0;
    }

    if (tipo_compativel(item, posicao) == 0){
        return 0;
    }

    if (personagem->equipamentos.ocupado[posicao] == 1){
        return 0;
    }

    if (item.tipo == ARMA_DUAS_MAOS){

        if (personagem->equipamentos.ocupado[SLOT_MAO_DIREITA] == 1 ||
            personagem->equipamentos.ocupado[SLOT_MAO_ESQUERDA] == 1){
            return 0;
        }

    }

    if (item.tipo == ARMA_DUAS_MAOS){

        personagem->equipamentos.itens[SLOT_MAO_DIREITA] = item;
        personagem->equipamentos.itens[SLOT_MAO_ESQUERDA] = item;

        personagem->equipamentos.ocupado[SLOT_MAO_DIREITA] = 1;
        personagem->equipamentos.ocupado[SLOT_MAO_ESQUERDA] = 1;

    } else {

        personagem->equipamentos.itens[posicao] = item;
        personagem->equipamentos.ocupado[posicao] = 1;

    }

    remover_item(&personagem->inventario, ID);

    return 1;
}

int desequipar_item(Personagem *personagem, PosicaoEquipamento posicao){

    if (personagem->equipamentos.ocupado[posicao] == 0){
        return 0;
    }

    Item item = personagem->equipamentos.itens[posicao];

    if (adicionar_item(&personagem->inventario, item) == 0){
        return 0;
    }

    if (item.tipo == ARMA_DUAS_MAOS){

        personagem->equipamentos.ocupado[SLOT_MAO_DIREITA] = 0;
        personagem->equipamentos.ocupado[SLOT_MAO_ESQUERDA] = 0;

    } else {

        personagem->equipamentos.ocupado[posicao] = 0;

    }

    return 1;
}

int calcular_ataque_total(const Personagem *personagem){

    int total = personagem->Ataque;

    for(int i = 0; i < 10; i++){

        if(personagem->equipamentos.ocupado[i] == 1){
            total += personagem->equipamentos.itens[i].bonus_ataque;
        }

    }

    return total;
}

int calcular_defesa_total(const Personagem *personagem){

    int total = personagem->Defesa;

    for(int i = 0; i < 10; i++){

        if(personagem->equipamentos.ocupado[i] == 1){
            total += personagem->equipamentos.itens[i].bonus_defesa;
        }

    }

    return total;
}

int calcular_vida_total(const Personagem *personagem){

    int total = personagem->Limite_vida;

    for(int i = 0; i < 10; i++){

        if(personagem->equipamentos.ocupado[i] == 1){
            total += personagem->equipamentos.itens[i].bonus_vida;
        }

    }

    return total;
}

int calcular_iniciativa_total(const Personagem *personagem){

    int total = personagem->Iniciativa;

    for(int i = 0; i < 10; i++){

        if(personagem->equipamentos.ocupado[i] == 1){
            total += personagem->equipamentos.itens[i].bonus_iniciativa;
        }

    }

    return total;
}

int calcular_poder_total(const Personagem *personagem){

    int total = personagem->Poder;

    for(int i = 0; i < 10; i++){

        if(personagem->equipamentos.ocupado[i] == 1){
            total += personagem->equipamentos.itens[i].poder;
        }

    }

    return total;
}