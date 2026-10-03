#include <stdio.h>
#include "personagem.h"

int main()
{

    CadastroPersonagem cadastro;

    inicializar_cadastro(&cadastro);

    int opcao;

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
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
        {

            Personagem personagem;

            inicializar_personagem(&personagem);

            printf("\n===== CADASTRO =====\n");

            printf("ID: ");
            scanf("%d", &personagem.ID);

            printf("Nome: ");
            scanf(" %49[^\n]", personagem.Nome);

            printf("Raca (0-5): ");
            scanf("%d", (int *)&personagem.raca);

            printf("Classe (0-5): ");
            scanf("%d", (int *)&personagem.classe);

            printf("Nivel: ");
            scanf("%d", &personagem.Nivel);

            printf("Limite de vida: ");
            scanf("%d", &personagem.Limite_vida);

            printf("Vida atual: ");
            scanf("%d", &personagem.Atual_vida);

            printf("Ataque: ");
            scanf("%d", &personagem.Ataque);

            printf("Defesa: ");
            scanf("%d", &personagem.Defesa);

            printf("Iniciativa: ");
            scanf("%d", &personagem.Iniciativa);

            printf("Poder: ");
            scanf("%d", &personagem.Poder);

            if (cadastro_personagem(&cadastro, personagem))
            {
                printf("Personagem cadastrado com sucesso!\n");
            }
            else
            {
                printf("Erro: personagem invalido, ID duplicado ou cadastro cheio.\n");
            }

            break;
        }

        case 2:
        {

            int ID;
            Personagem personagem;

            printf("\n===== BUSCAR PERSONAGEM =====\n");

            printf("Digite o ID: ");
            scanf("%d", &ID);

            if (busca_personagem(&cadastro, ID, &personagem))
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

                printf("Personagem nao encontrado.\n");
            }

            break;
        }

        case 3:
        {

            int ID;
            Personagem personagem;

            printf("\n===== ALTERAR PERSONAGEM =====\n");

            printf("Digite o ID do personagem que deseja alterar: ");
            scanf("%d", &ID);

            if (busca_personagem(&cadastro, ID, &personagem) == 0)
            {

                printf("Personagem nao encontrado.\n");
                break;
            }

            printf("Novo ID: ");
            scanf("%d", &personagem.ID);

            printf("Novo nome: ");
            scanf(" %49[^\n]", personagem.Nome);

            printf("Nova raca (0-5): ");
            scanf("%d", (int *)&personagem.raca);

            printf("Nova classe (0-5): ");
            scanf("%d", (int *)&personagem.classe);

            printf("Novo nivel: ");
            scanf("%d", &personagem.Nivel);

            printf("Novo limite de vida: ");
            scanf("%d", &personagem.Limite_vida);

            printf("Nova vida atual: ");
            scanf("%d", &personagem.Atual_vida);

            printf("Novo ataque: ");
            scanf("%d", &personagem.Ataque);

            printf("Nova defesa: ");
            scanf("%d", &personagem.Defesa);

            printf("Nova iniciativa: ");
            scanf("%d", &personagem.Iniciativa);

            printf("Novo poder: ");
            scanf("%d", &personagem.Poder);

            if (alterar_personagem(&cadastro, ID, personagem))
            {
                printf("Personagem alterado com sucesso!\n");
            }
            else
            {
                printf("Erro ao alterar personagem.\n");
            }

            break;
        }

        case 4:
        {

            int ID;

            printf("\n===== EXCLUIR PERSONAGEM =====\n");

            printf("Digite o ID do personagem: ");
            scanf("%d", &ID);

            if (excluir_personagem(&cadastro, ID))
            {
                printf("Personagem excluido com sucesso!\n");
            }
            else
            {
                printf("Personagem nao encontrado.\n");
            }

            break;
        }

        case 5:
        {

            printf("\n===== LISTA DE PERSONAGENS =====\n");

            listar_personagens(&cadastro);

            break;
        }

        case 6:
        {

            int ID;
            Personagem personagem;
            Item item;

            printf("\n===== ADICIONAR ITEM =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID);

            if (busca_personagem(&cadastro, ID, &personagem) == 0)
            {

                printf("Personagem nao encontrado.\n");
                break;
            }

            printf("ID do item: ");
            scanf("%d", &item.ID);

            printf("Nome do item: ");
            scanf(" %49[^\n]", item.Nome);

            printf("Tipo do item (0-9): ");
            scanf("%d", (int *)&item.tipo);

            printf("Espacos ocupados: ");
            scanf("%d", &item.espacos);

            printf("Bonus de ataque: ");
            scanf("%d", &item.bonus_ataque);

            printf("Bonus de defesa: ");
            scanf("%d", &item.bonus_defesa);

            printf("Bonus de vida: ");
            scanf("%d", &item.bonus_vida);

            printf("Bonus de iniciativa: ");
            scanf("%d", &item.bonus_iniciativa);

            printf("Poder: ");
            scanf("%d", &item.poder);

            if (adicionar_item(&personagem.inventario, item))
            {

                printf("Item adicionado com sucesso!\n");

                /* Atualiza o personagem dentro do cadastro */
                for (int i = 0; i < cadastro.quantidade; i++)
                {

                    if (cadastro.personagem[i].ID == ID)
                    {
                        cadastro.personagem[i] = personagem;
                        break;
                    }
                }
            }
            else
            {

                printf("Erro: item invalido, ID duplicado ou inventario sem espaco.\n");
            }

            break;
        }

        case 7:
        {

            int ID;
            Personagem personagem;

            printf("\n===== INVENTARIO =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID);

            if (busca_personagem(&cadastro, ID, &personagem) == 0)
            {

                printf("Personagem nao encontrado.\n");
                break;
            }

            printf("\nOcupacao: %d/50\n",
                   calcular_ocupacao(&personagem.inventario));

            listar_itens(&personagem.inventario);

            break;
        }

        case 8:
        {

            int ID_personagem;
            int ID_item;
            int posicao;
            Personagem personagem;

            printf("\n===== EQUIPAR ITEM =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID_personagem);

            if (busca_personagem(&cadastro, ID_personagem, &personagem) == 0)
            {

                printf("Personagem nao encontrado.\n");
                break;
            }

            printf("ID do item: ");
            scanf("%d", &ID_item);

            printf("Posicao do equipamento (0-9): ");
            scanf("%d", &posicao);

            if (equipar_item(&personagem, ID_item, (PosicaoEquipamento)posicao))
            {

                printf("Item equipado com sucesso!\n");

                for (int i = 0; i < cadastro.quantidade; i++)
                {

                    if (cadastro.personagem[i].ID == ID_personagem)
                    {
                        cadastro.personagem[i] = personagem;
                        break;
                    }
                }
            }
            else
            {

                printf("Nao foi possivel equipar o item.\n");
            }

            break;
        }

        case 9:
        {

            int ID_personagem;
            int posicao;
            Personagem personagem;

            printf("\n===== DESEQUIPAR ITEM =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID_personagem);

            if (busca_personagem(&cadastro, ID_personagem, &personagem) == 0)
            {

                printf("Personagem nao encontrado.\n");
                break;
            }

            printf("Posicao do equipamento (0-9): ");
            scanf("%d", &posicao);

            if (desequipar_item(&personagem, (PosicaoEquipamento)posicao))
            {

                printf("Item desequipado com sucesso!\n");

                for (int i = 0; i < cadastro.quantidade; i++)
                {

                    if (cadastro.personagem[i].ID == ID_personagem)
                    {
                        cadastro.personagem[i] = personagem;
                        break;
                    }
                }
            }
            else
            {

                printf("Nao foi possivel desequipar o item.\n");
            }

            break;
        }

        case 10:
        {

            int ID;
            Personagem personagem;

            printf("\n===== ATRIBUTOS TOTAIS =====\n");

            printf("ID do personagem: ");
            scanf("%d", &ID);

            if (busca_personagem(&cadastro, ID, &personagem) == 0)
            {

                printf("Personagem nao encontrado.\n");
                break;
            }

            printf("\nPersonagem: %s\n", personagem.Nome);

            printf("Ataque total = %d\n",
                   calcular_ataque_total(&personagem));

            printf("Defesa total = %d\n",
                   calcular_defesa_total(&personagem));

            printf("Vida total = %d\n",
                   calcular_vida_total(&personagem));

            printf("Iniciativa total = %d\n",
                   calcular_iniciativa_total(&personagem));

            printf("Poder total = %d\n",
                   calcular_poder_total(&personagem));

            break;
        }

        case 11:
        {

            printf("Saindo...\n");

            break;
        }

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 11);

    return 0;
}