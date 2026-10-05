#include <stdio.h>
#include "personagem.h"

int main()
{
    CadastroPersonagem cadastro; /* Cria a variável que vai armazenar todos os personagens cadastrados. */

    inicializar_cadastro(&cadastro); /* Inicializa o cadastro, começando com zero personagens. */

    int opcao; /* Guarda a opção escolhida pelo usuário no menu. */

    do
    {

        printf("\n===== SISTEMA DE RPG =====\n");
        printf("1 - Cadastrar personagem\n");
        printf("2 - Buscar personagem\n");
        printf("3 - Alterar personagem\n");
        printf("4 - Excluir personagem\n");
        printf("5 - Listar personagens\n");
        printf("6 - Adicionar item\n");
        printf("7 - Listar inventario\n");
        printf("8 - Equipar item\n");
        printf("9 - Desequipar item\n");
        printf("10 - Mostrar atributos totais\n");
        printf("11 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao); /* Lê a opção escolhida pelo usuário. */

        switch (opcao) /* Verifica qual opção foi escolhida no menu. */
        {

        case 1:
        {

            Personagem personagem; /* Cria uma variável para armazenar os dados do novo personagem. */

            inicializar_personagem(&personagem); /* Inicializa todos os dados do personagem. */

            printf("\n===== CADASTRO =====\n");

            printf("ID: ");
            scanf("%d", &personagem.ID); /* Lê o ID do personagem. */

            printf("Nome: ");
            scanf(" %49[^\n]", personagem.Nome); /* Lê o nome, permitindo espaços e no máximo 49 caracteres. */

            printf("Raca:\n");
            printf("0 - Elfo\n");
            printf("1 - Humano\n");
            printf("2 - Anao\n");
            printf("3 - Halfling\n");
            printf("4 - Draconatos\n");
            printf("5 - Goblins\n");
            scanf("%d", (int *)&personagem.raca); /* Lê o número correspondente à raça escolhida. */

            printf("Classe: \n");
            printf("0 - Mago\n");
            printf("1 - Guerreiro\n");
            printf("2 - Ladino\n");
            printf("3 - Clerigo\n");
            printf("4 - Bardo\n");
            printf("5 - Barbaro\n");
            scanf("%d", (int *)&personagem.classe); /* Lê o número correspondente à classe escolhida. */

            printf("Nivel (1 - 20): ");
            scanf("%d", &personagem.Nivel); /* Lê o nível do personagem. */

            printf("Limite de vida (1-999): ");
            scanf("%d", &personagem.Limite_vida); /* Lê o limite máximo de vida. */

            printf("Vida atual: ");
            scanf("%d", &personagem.Atual_vida); /* Lê a quantidade de vida atual. */

            printf("Ataque (1-30):");
            scanf("%d", &personagem.Ataque); /* Lê o valor de ataque. */

            printf("Defesa (1-30):");
            scanf("%d", &personagem.Defesa); /* Lê o valor de defesa. */

            printf("Iniciativa (-5 ate 30):");
            scanf("%d", &personagem.Iniciativa); /* Lê o valor de iniciativa. */

            printf("Poder (1-100):");
            scanf("%d", &personagem.Poder); /* Lê o valor de poder. */

            if (cadastro_personagem(&cadastro, personagem)) /* Tenta cadastrar o personagem e verifica se deu certo. */
            {
                printf("Personagem cadastrado com sucesso!\n");
            }
            else
            {
                printf("Erro: personagem invalido, ID duplicado ou cadastro cheio.\n");
            }

            break; /* Encerra esse case e volta para o menu. */
        }

        case 2:
        {

            int ID; /* Guarda o ID que será procurado. */
            Personagem personagem; /* Guarda os dados do personagem encontrado. */

            printf("\n===== BUSCAR PERSONAGEM =====\n");

            printf("Digite o ID: ");
            scanf("%d", &ID); /* Lê o ID que o usuário deseja procurar. */

            if (busca_personagem(&cadastro, ID, &personagem)) /* Procura o personagem pelo ID. */
            {

                printf("\nPersonagem encontrado!\n");
                printf("ID = %d\n", personagem.ID);
                printf("Nome = %s\n", personagem.Nome);
                printf("Raca = %d\n", personagem.raca);
                printf("Classe = %d\n", personagem.classe);
                printf("Nivel = %d\n", personagem.Nivel);
                printf("Limite de vida = %d\n", personagem.Limite_vida);
                printf("Vida atual = %d\n", personagem.Atual_vida);
                printf("Ataque = %d\n", personagem.Ataque);
                printf("Defesa = %d\n", personagem.Defesa);
                printf("Iniciativa = %d\n", personagem.Iniciativa);
                printf("Poder = %d\n", personagem.Poder);
            }
            else
            {

                printf("Personagem nao encontrado.\n"); /* Informa que nenhum personagem possui esse ID. */
            }

            break; /* Encerra o case de busca. */
        }

        case 3:
        {

            int ID; /* Guarda o ID do personagem que será alterado. */
            Personagem personagem; /* Guarda os dados do personagem que será alterado. */

            printf("\n===== ALTERAR PERSONAGEM =====\n");

            printf("Digite o ID do personagem que deseja alterar: ");
            scanf("%d", &ID); /* Lê o ID do personagem que será procurado. */

            if (busca_personagem(&cadastro, ID, &personagem) == 0) /* Verifica se o personagem existe. */
            {

                printf("Personagem nao encontrado.\n");
                break; /* Volta para o menu caso o personagem não exista. */
            }

            printf("Novo ID: ");
            scanf("%d", &personagem.ID); /* Lê o novo ID do personagem. */

            printf("Novo nome: ");
            scanf(" %49[^\n]", personagem.Nome); /* Lê o novo nome do personagem. */

            printf("Nova raca (0-5): ");
            printf("0 - Elfo\n");
            printf("1 - Humano\n");
            printf("2 - Anao\n");
            printf("3 - Halfling\n");
            printf("4 - Draconatos\n");
            printf("5 - Goblins\n");
            scanf("%d", (int *)&personagem.raca); /* Lê a nova raça. */

            printf("Nova classe (0-5): ");
            printf("0 - Mago\n");
            printf("1 - Guerreiro\n");
            printf("2 - Ladino\n");
            printf("3 - Clerigo\n");
            printf("4 - Bardo\n");
            printf("5 - Barbaro\n");
            scanf("%d", (int *)&personagem.classe); /* Lê a nova classe. */

            printf("Novo nivel (1-20): ");
            scanf("%d", &personagem.Nivel); /* Lê o novo nível. */

            printf("Novo limite de vida (1-999): ");
            scanf("%d", &personagem.Limite_vida); /* Lê o novo limite de vida. */

            printf("Nova vida atual: ");
            scanf("%d", &personagem.Atual_vida); /* Lê a nova vida atual. */

            printf("Novo ataque (1-30): ");
            scanf("%d", &personagem.Ataque); /* Lê o novo ataque. */

            printf("Nova Defesa (1-30):");
            scanf("%d", &personagem.Defesa); /* Lê a nova defesa. */

            printf("Nova Iniciativa (-5 ate 30):");
            scanf("%d", &personagem.Iniciativa); /* Lê a nova iniciativa. */

            printf("Novo Poder (1-100):");
            scanf("%d", &personagem.Poder); /* Lê o novo poder. */

            if (alterar_personagem(&cadastro, ID, personagem)) /* Tenta substituir o personagem antigo pelos novos dados. */
            {
                printf("Personagem alterado com sucesso!\n");
            }
            else
            {
                printf("Erro ao alterar personagem.\n");
            }

            break; /* Encerra o case de alteração. */
        }

        case 4:
        {

            int ID; /* Guarda o ID do personagem que será excluído. */

            printf("\n===== EXCLUIR PERSONAGEM =====\n");

            printf("Digite o ID do personagem: ");
            scanf("%d", &ID); /* Lê o ID do personagem que será excluído. */

            if (excluir_personagem(&cadastro, ID)) /* Tenta excluir o personagem pelo ID. */
            {
                printf("Personagem excluido com sucesso!\n");
            }
            else
            {
                printf("Personagem nao encontrado.\n");
            }

            break; /* Encerra o case de exclusão. */
        }

        case 5:
        {

            printf("\n===== LISTA DE PERSONAGENS =====\n");

            listar_personagens(&cadastro); /* Mostra todos os personagens cadastrados. */

            break; /* Encerra o case de listagem. */
        }

        case 6:
        {

            int ID; /* Guarda o ID do personagem que receberá o item. */
            Personagem personagem; /* Guarda temporariamente os dados do personagem. */
            Item item; /* Guarda os dados do item que será criado. */

            printf("\n===== ADICIONAR ITEM =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID); /* Lê o ID do personagem que receberá o item. */

            if (busca_personagem(&cadastro, ID, &personagem) == 0) /* Procura o personagem pelo ID. */
            {

                printf("Personagem nao encontrado.\n");
                break; /* Volta para o menu caso o personagem não exista. */
            }

            printf("ID do item: ");
            scanf("%d", &item.ID); /* Lê o ID do item. */

            printf("Nome do item: ");
            scanf(" %49[^\n]", item.Nome); /* Lê o nome do item permitindo espaços. */

            printf("Tipos do Item (0-9):\n");
            printf("0 - Elmo\n");
            printf("1 - Peitoral\n");
            printf("2 - Manoplas\n");
            printf("3 - Calca\n");
            printf("4 - Botas\n");
            printf("5 - Anel\n");
            printf("6 - Colar\n");
            printf("7 - Cinto\n");
            printf("8 - Arma de uma mao\n");
            printf("9 - Arma de duas maos\n");
            scanf("%d", (int *)&item.tipo); /* Lê o tipo do item escolhido. */

            printf("Slots de equipamento (0-9):\n");
            scanf("%d", &item.espacos); /* Lê a quantidade de espaço que o item ocupa no inventário. */

            printf("Bonus de ataque: ");
            scanf("%d", &item.bonus_ataque); /* Lê o bônus de ataque do item. */

            printf("Bonus de defesa: ");
            scanf("%d", &item.bonus_defesa); /* Lê o bônus de defesa do item. */

            printf("Bonus de vida: ");
            scanf("%d", &item.bonus_vida); /* Lê o bônus de vida do item. */

            printf("Bonus de iniciativa: ");
            scanf("%d", &item.bonus_iniciativa); /* Lê o bônus de iniciativa do item. */

            printf("Poder: ");
            scanf("%d", &item.poder); /* Lê o poder fornecido pelo item. */

            if (adicionar_item(&personagem.inventario, item)) /* Tenta adicionar o item ao inventário do personagem. */
            {

                printf("Item adicionado com sucesso!\n");

                /* Atualiza o personagem dentro do cadastro */
                for (int i = 0; i < cadastro.quantidade; i++) /* Percorre os personagens cadastrados para encontrar o personagem alterado. */
                {

                    if (cadastro.personagem[i].ID == ID) /* Verifica se encontrou o personagem correto. */
                    {
                        cadastro.personagem[i] = personagem; /* Atualiza o personagem no cadastro com o novo inventário. */
                        break; /* Para o for depois de atualizar o personagem. */
                    }
                }
            }
            else
            {

                printf("Erro: item invalido, ID duplicado ou inventario sem espaco.\n");
            }

            break; /* Encerra o case de adicionar item. */
        }

        case 7:
        {

            int ID; /* Guarda o ID do personagem cujo inventário será mostrado. */
            Personagem personagem; /* Guarda temporariamente os dados do personagem. */

            printf("\n===== INVENTARIO =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID); /* Lê o ID do personagem. */

            if (busca_personagem(&cadastro, ID, &personagem) == 0) /* Procura o personagem pelo ID. */
            {

                printf("Personagem nao encontrado.\n");
                break; /* Volta para o menu caso o personagem não seja encontrado. */
            }

            printf("\nOcupacao: %d/50\n",
                   calcular_ocupacao(&personagem.inventario)); /* Calcula quanto espaço do inventário está sendo utilizado. */

            listar_itens(&personagem.inventario); /* Mostra todos os itens que estão no inventário. */

            break; /* Encerra o case de listar inventário. */
        }

        case 8:
        {

            int ID_personagem; /* Guarda o ID do personagem que vai equipar o item. */
            int ID_item; /* Guarda o ID do item que será equipado. */
            int posicao; /* Guarda a posição onde o item será equipado. */
            Personagem personagem; /* Guarda temporariamente os dados do personagem. */

            printf("\n===== EQUIPAR ITEM =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID_personagem); /* Lê o ID do personagem. */

            if (busca_personagem(&cadastro, ID_personagem, &personagem) == 0) /* Procura o personagem no cadastro. */
            {

                printf("Personagem nao encontrado.\n");
                break; /* Volta para o menu se o personagem não for encontrado. */
            }

            printf("ID do item: ");
            scanf("%d", &ID_item); /* Lê o ID do item que será equipado. */

            printf("Posicao do equipamento (0-9): ");
            scanf("%d", &posicao); /* Lê a posição onde o item será colocado. */

            if (equipar_item(&personagem, ID_item, (PosicaoEquipamento)posicao)) /* Tenta equipar o item na posição escolhida. */
            {

                printf("Item equipado com sucesso!\n");

                for (int i = 0; i < cadastro.quantidade; i++) /* Percorre o cadastro para encontrar o personagem alterado. */
                {

                    if (cadastro.personagem[i].ID == ID_personagem) /* Verifica se encontrou o personagem correto. */
                    {
                        cadastro.personagem[i] = personagem; /* Atualiza o personagem no cadastro com o equipamento novo. */
                        break; /* Para o for depois de atualizar o personagem. */
                    }
                }
            }
            else
            {

                printf("Nao foi possivel equipar o item.\n");
            }

            break; /* Encerra o case de equipar item. */
        }

        case 9:
        {

            int ID_personagem; /* Guarda o ID do personagem que vai desequipar o item. */
            int posicao; /* Guarda a posição do equipamento que será retirado. */
            Personagem personagem; /* Guarda temporariamente os dados do personagem. */

            printf("\n===== DESEQUIPAR ITEM =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID_personagem); /* Lê o ID do personagem. */

            if (busca_personagem(&cadastro, ID_personagem, &personagem) == 0) /* Procura o personagem no cadastro. */
            {

                printf("Personagem nao encontrado.\n");
                break; /* Volta para o menu caso o personagem não seja encontrado. */
            }

            printf("Posicao do equipamento (0-9): ");
            scanf("%d", &posicao); /* Lê a posição do equipamento que será retirado. */

            if (desequipar_item(&personagem, (PosicaoEquipamento)posicao)) /* Tenta retirar o item do equipamento. */
            {

                printf("Item desequipado com sucesso!\n");

                for (int i = 0; i < cadastro.quantidade; i++) /* Percorre o cadastro procurando o personagem alterado. */
                {

                    if (cadastro.personagem[i].ID == ID_personagem) /* Verifica se encontrou o personagem correto. */
                    {
                        cadastro.personagem[i] = personagem; /* Atualiza o personagem no cadastro com o item desequipado. */
                        break; /* Para o for depois de atualizar o personagem. */
                    }
                }
            }
            else
            {

                printf("Nao foi possivel desequipar o item.\n");
            }

            break; /* Encerra o case de desequipar item. */
        }

        case 10:
        {

            int ID; /* Guarda o ID do personagem que terá os atributos calculados. */
            Personagem personagem; /* Guarda temporariamente os dados do personagem. */

            printf("\n===== ATRIBUTOS TOTAIS =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID); /* Lê o ID do personagem. */

            if (busca_personagem(&cadastro, ID, &personagem) == 0) /* Procura o personagem no cadastro. */
            {

                printf("Personagem nao encontrado.\n");
                break; /* Volta para o menu caso o personagem não seja encontrado. */
            }

            printf("\nPersonagem: %s\n", personagem.Nome); /* Mostra o nome do personagem. */

            printf("Ataque total = %d\n",
                   calcular_ataque_total(&personagem)); /* Calcula e mostra o ataque base mais os bônus dos equipamentos. */

            printf("Defesa total = %d\n",
                   calcular_defesa_total(&personagem)); /* Calcula e mostra a defesa base mais os bônus dos equipamentos. */

            printf("Vida total = %d\n",
                   calcular_vida_total(&personagem)); /* Calcula e mostra a vida base mais os bônus dos equipamentos. */

            printf("Iniciativa total = %d\n",
                   calcular_iniciativa_total(&personagem)); /* Calcula e mostra a iniciativa base mais os bônus dos equipamentos. */

            printf("Poder total = %d\n",
                   calcular_poder_total(&personagem)); /* Calcula e mostra o poder base mais os bônus dos equipamentos. */

            break; /* Encerra o case de atributos totais. */
        }

        case 11:
        {

            printf("Saindo...\n"); /* Informa que o programa será encerrado. */

            break; /* Encerra o case de saída. */
        }

        default:
            printf("Opcao invalida!\n"); /* Mostra uma mensagem caso o usuário escolha uma opção que não existe. */
        }

    } while (opcao != 11); /* Continua mostrando o menu enquanto a opção escolhida for diferente de 11. */

    return 0; /* Encerra o programa indicando que terminou corretamente. */
}