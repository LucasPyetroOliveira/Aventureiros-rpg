# Aventureiros-rpg

SISTEMA AUXILIAR DE MESTRE DE RPG

Alunos:Kauã Alegório e Lucas Pyetro

Projeto desenvolvido para a Mini-Tarefa 1.

Funcionalidades:
- Cadastro de personagens
- Busca de personagens
- Alteração de personagens
- Exclusão de personagens
- Listagem de personagens
- Cadastro e gerenciamento de itens
- Inventário com capacidade de 50 espaços
- Equipamento de itens
- Desequipamento de itens
- Armas de uma e duas mãos
- Cálculo dos atributos totais

Arquivos:
- main.c
- personagem.c
- personagem.h
- inventario.c
- inventario.h
- item.c
- item.h
- equipamento.c
- equipamento.h

Compilação:

gcc -std=c11 -Wall -Wextra -pedantic main.c personagem.c inventario.c item.c equipamento.c -o personagens

Execução:

./personagens

OBSERVAÇÕES

O sistema utiliza armazenamento estático em memória.
Os personagens possuem capacidade máxima de 20 registros.
Cada personagem possui um inventário com capacidade máxima de 50 espaços.

Os IDs dos personagens devem ser únicos.
Os IDs dos itens devem ser únicos dentro do inventário de cada personagem.

O projeto não utiliza arquivos para armazenamento permanente
nem alocação dinâmica de memória.