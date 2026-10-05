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

    for(int i = 0;i < cadastro->quantidade;i++){ /* Percorre todos os personagens que estão cadastrados. */
        
        if(cadastro->personagem[i].ID == ID){ /* Verifica se o ID do personagem atual é igual ao ID procurado. */
            *personagem_encontrado = cadastro->personagem[i]; /* Copia o personagem encontrado para a variável recebida pela função. */

            return 1; /* Retorna 1 indicando que o personagem foi encontrado. */
        }
    }

    return 0; /* Se terminar o for sem encontrar o ID, retorna 0. */
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

    return 0; /* Retorna 0 caso o personagem com o ID informado não seja encontrado. */
}

int excluir_personagem(CadastroPersonagem *cadastro,int ID){ 

    for(int i = 0;i < cadastro->quantidade;i++){ /*Procura o personagem pelo ID.*/

        if (cadastro->personagem[i].ID == ID){ /*Quando encontra*/
            
            for(int j = i;j < cadastro->quantidade - 1;j++){ /* Isso serve para puxar todo mundo para trás. */
                cadastro->personagem[j] = cadastro->personagem[j + 1]; /* Copia o próximo personagem para a posição atual. */
            }

            cadastro->quantidade--; /* E diminui a quantidade de personagem. */

            return 1; /* Retorna 1 indicando que o personagem foi excluído. */
        }
    }

    return 0; /* Se o ID não for encontrado, retorna 0. */
}

void listar_personagens(const CadastroPersonagem *cadastro){ 

    for(int i = 0;i < cadastro->quantidade;i++){ /* Essa função simplesmente passa por todos. */

        printf("ID = %d | Nome = %s | Raca = %d | Classe = %d | Nivel = %d | Limite de vida = %d | Atual vida = %d | Ataque = %d | Defesa = %d | Iniciativa = %d | Poder = %d\n",
            cadastro->personagem[i].ID, /* Mostra o ID do personagem. */
            cadastro->personagem[i].Nome, /* Mostra o nome do personagem. */
            cadastro->personagem[i].raca, /* Mostra a raça do personagem. */
            cadastro->personagem[i].classe, /* Mostra a classe do personagem. */
            cadastro->personagem[i].Nivel, /* Mostra o nível do personagem. */
            cadastro->personagem[i].Limite_vida, /* Mostra o limite máximo de vida. */
            cadastro->personagem[i].Atual_vida, /* Mostra a vida atual. */
            cadastro->personagem[i].Ataque, /* Mostra o valor de ataque. */
            cadastro->personagem[i].Defesa, /* Mostra o valor de defesa. */
            cadastro->personagem[i].Iniciativa, /* Mostra o valor de iniciativa. */
            cadastro->personagem[i].Poder); /* Mostra o poder do personagem. */
    }
}

int equipar_item(Personagem *personagem, int ID, PosicaoEquipamento posicao){

    Item item; /* Cria uma variável para armazenar temporariamente o item que será equipado. */

    if (posicao < SLOT_ELMO || posicao > SLOT_MAO_ESQUERDA){ /* Verifica se a posição informada existe entre os slots permitidos. */
        return 0; /* Retorna 0 caso a posição seja inválida. */
    }

    if (buscar_item(&personagem->inventario, ID, &item) == 0){ /* Procura o item dentro do inventário usando o ID informado. */
        return 0; /* Retorna 0 caso o item não seja encontrado. */
    }

    if (tipo_compativel(item, posicao) == 0){ /* Verifica se o tipo do item pode ser colocado nessa posição. */
        return 0; /* Retorna 0 caso o item não seja compatível com o slot. */
    }

    if (personagem->equipamentos.ocupado[posicao] == 1){ /* Verifica se o espaço escolhido já possui um item equipado. */
        return 0; /* Retorna 0 caso o slot já esteja ocupado. */
    }

    if (item.tipo == ARMA_DUAS_MAOS){ /* Verifica se o item é uma arma que utiliza as duas mãos. */

        if (personagem->equipamentos.ocupado[SLOT_MAO_DIREITA] == 1 ||
            personagem->equipamentos.ocupado[SLOT_MAO_ESQUERDA] == 1){ /* Verifica se alguma das duas mãos já está ocupada. */
            return 0; /* Retorna 0 se uma das mãos já estiver ocupada. */
        }

    }

    if (item.tipo == ARMA_DUAS_MAOS){ /* Se for uma arma de duas mãos, ela será colocada nos dois slots das mãos. */

        personagem->equipamentos.itens[SLOT_MAO_DIREITA] = item; /* Coloca o item no slot da mão direita. */
        personagem->equipamentos.itens[SLOT_MAO_ESQUERDA] = item; /* Coloca o mesmo item no slot da mão esquerda. */

        personagem->equipamentos.ocupado[SLOT_MAO_DIREITA] = 1; /* Marca a mão direita como ocupada. */
        personagem->equipamentos.ocupado[SLOT_MAO_ESQUERDA] = 1; /* Marca a mão esquerda como ocupada. */

    } else {

        personagem->equipamentos.itens[posicao] = item; /* Coloca o item no slot escolhido. */
        personagem->equipamentos.ocupado[posicao] = 1; /* Marca o slot escolhido como ocupado. */

    }

    remover_item(&personagem->inventario, ID); /* Remove o item do inventário porque agora ele está equipado. */

    return 1; /* Retorna 1 indicando que o item foi equipado com sucesso. */
}

int desequipar_item(Personagem *personagem, PosicaoEquipamento posicao){

    if (personagem->equipamentos.ocupado[posicao] == 0){ /* Verifica se o slot escolhido está vazio. */
        return 0; /* Retorna 0 porque não existe item para desequipar. */
    }

    Item item = personagem->equipamentos.itens[posicao]; /* Copia o item equipado para uma variável temporária. */

    if (adicionar_item(&personagem->inventario, item) == 0){ /* Tenta colocar o item novamente no inventário. */
        return 0; /* Se não houver espaço no inventário, não desequipa o item. */
    }

    if (item.tipo == ARMA_DUAS_MAOS){ /* Verifica se o item utiliza as duas mãos. */

        personagem->equipamentos.ocupado[SLOT_MAO_DIREITA] = 0; /* Libera o slot da mão direita. */
        personagem->equipamentos.ocupado[SLOT_MAO_ESQUERDA] = 0; /* Libera o slot da mão esquerda. */

    } else {

        personagem->equipamentos.ocupado[posicao] = 0; /* Libera somente o slot onde o item estava equipado. */

    }

    return 1; /* Retorna 1 indicando que o item foi desequipado com sucesso. */
}

int calcular_ataque_total(const Personagem *personagem){

    int total = personagem->Ataque; /* Começa o cálculo usando o ataque base do personagem. */

    for(int i = 0; i < 10; i++){ /* Percorre todos os 10 slots de equipamentos. */

        if(personagem->equipamentos.ocupado[i] == 1){ /* Verifica se existe um item equipado nesse slot. */
            total += personagem->equipamentos.itens[i].bonus_ataque; /* Soma o bônus de ataque do equipamento ao ataque total. */
        }

    }

    return total; /* Retorna o ataque base somado aos bônus dos equipamentos. */
}

int calcular_defesa_total(const Personagem *personagem){

    int total = personagem->Defesa; /* Começa o cálculo usando a defesa base do personagem. */

    for(int i = 0; i < 10; i++){ /* Percorre todos os 10 slots de equipamentos. */

        if(personagem->equipamentos.ocupado[i] == 1){ /* Verifica se existe um item equipado nesse slot. */
            total += personagem->equipamentos.itens[i].bonus_defesa; /* Soma o bônus de defesa do equipamento à defesa total. */
        }

    }

    return total; /* Retorna a defesa base somada aos bônus dos equipamentos. */
}

int calcular_vida_total(const Personagem *personagem){

    int total = personagem->Limite_vida; /* Começa o cálculo usando o limite de vida base do personagem. */

    for(int i = 0; i < 10; i++){ /* Percorre todos os 10 slots de equipamentos. */

        if(personagem->equipamentos.ocupado[i] == 1){ /* Verifica se existe um item equipado nesse slot. */
            total += personagem->equipamentos.itens[i].bonus_vida; /* Soma o bônus de vida do equipamento à vida total. */
        }

    }

    return total; /* Retorna o limite de vida base somado aos bônus dos equipamentos. */
}

int calcular_iniciativa_total(const Personagem *personagem){

    int total = personagem->Iniciativa; /* Começa o cálculo usando a iniciativa base do personagem. */

    for(int i = 0; i < 10; i++){ /* Percorre todos os 10 slots de equipamentos. */

        if(personagem->equipamentos.ocupado[i] == 1){ /* Verifica se existe um item equipado nesse slot. */
            total += personagem->equipamentos.itens[i].bonus_iniciativa; /* Soma o bônus de iniciativa do equipamento à iniciativa total. */
        }

    }

    return total; /* Retorna a iniciativa base somada aos bônus dos equipamentos. */
}

int calcular_poder_total(const Personagem *personagem){

    int total = personagem->Poder; /* Começa o cálculo usando o poder base do personagem. */

    for(int i = 0; i < 10; i++){ /* Percorre todos os 10 slots de equipamentos. */

        if(personagem->equipamentos.ocupado[i] == 1){ /* Verifica se existe um item equipado nesse slot. */
            total += personagem->equipamentos.itens[i].poder; /* Soma o poder do equipamento ao poder total. */
        }

    }

    return total; /* Retorna o poder base somado aos poderes dos equipamentos. */
}