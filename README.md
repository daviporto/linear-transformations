# Trabalho Prático 3: Transformações Lineares

**Autor:** Davi Porto Araújo (2022036004)  
**Departamento de Ciência da Computação – Universidade Federal de Minas Gerais (UFMG)**  
**Belo Horizonte – MG – Brazil**  
**Email:** portodaviporto@gmail.com

## Introdução
Este relatório descreve um programa desenvolvido para auxiliar as crianças da cidade de Nlogônia a aplicar transformações lineares de maneira eficiente. O programa utiliza algoritmos que operam sobre uma árvore de segmentação para aplicar essas transformações de forma otimizada.

## Descrição do Ambiente
O ambiente em que o programa foi desenvolvido e testado é o seguinte:
- **Linguagem:** C++
- **Compilador:** g++

## Método

### 1. Tipos Abstratos de Dados
A estrutura central deste programa é uma árvore de segmentação que possui matrizes em cada nó. Outras estruturas auxiliares incluem ponto e matriz.

- **Árvore de Segmentação:** Implementada usando um array, escolhida por ser uma árvore completa, evitando desperdício de memória e proporcionando acesso eficiente aos nós pais e filhos.
- **Matriz:** Implementada como um array com 4 posições, inicialmente populado com a matriz identidade, simplificando operações e evitando a necessidade de construção recursiva da árvore.
- **Ponto:** Estrutura que contém as coordenadas x e y, permitindo operações centralizadas e concisas, utilizando overloading operators do C++.

### 2. Métodos
O programa possui dois métodos principais para a pesquisa e atualização da árvore de segmentos, além de algoritmos para impressão e leitura de dados.

- **Atualização da Árvore:** Estrutura recursiva que percorre a árvore até as folhas, atualizando a requisitada e, em seguida, atualizando os nós pais afetados. A operação principal é a multiplicação de matrizes.
- **Multiplicação de Matrizes e Pontos:** Implementada de forma estática para matrizes e de forma semelhante para pontos, ambas com tamanho fixo.

## Análise de Complexidade
- **Atualização da Árvore:** Complexidade de O(log(n)), pois apenas os nós afetados pela folha atualizada precisam ser atualizados.
- **Consulta (Query):** Complexidade semelhante de O(log(n)), visitando no máximo 4 nós por nível.
- **Multiplicação de Ponto e Matriz:** Complexidade de O(1), com número constante de operações.

## Estratégias de Robustez
As principais estratégias de robustez incluem o uso das ferramentas Valgrind e GDB durante o desenvolvimento, além do uso de exceções para validação de entrada e prevenção de erros.

- **Verificação de Entrada:** Uso de exceções para interromper a execução em caso de operações inválidas.
- **Padronização de Código:** Uso de um tipo numérico único (`unsigned long long int`) para evitar entradas negativas e suportar números grandes.
- **Documentação e Comentários:** Código padronizado em inglês, seguindo convenções de nomenclatura (snake case para variáveis e métodos, camelCase para classes), e documentação usando o padrão Javadoc.
- **Testes com Valgrind:** Execução de testes de estresse para verificar a corretude e identificar possíveis vazamentos de memória.

## Análise Experimental
O programa foi testado usando um script em Python para medir o tempo das funções `update` e `query`. As entradas foram geradas por um script disponibilizado no Moodle e as medições foram feitas com `getrusage` e `clock_gettime`.

### Resultados
- **Update:** A análise mostrou uma complexidade de tempo logarítmica, conforme previsto.
- **Query:** A análise também confirmou a complexidade logarítmica teorizada.

## Conclusões
O programa permite o cálculo eficiente do deslocamento de um ponto em determinado espaço de tempo usando uma árvore de segmentos. Durante o desenvolvimento, conceitos de POO e estruturas de dados foram revisitados, destacando as vantagens de uma árvore de segmentos para esse tipo de problema.

## Bibliografia
1. Slides da disciplina fornecidos pelos professores no Moodle, juntamente com as aulas que ocorreram de forma remota durante a pandemia.
2. Cormen, T., Leiserson, C., Rivest, R., Stein, C. Introduction to Algorithms, Third Edition, MIT Press, 2009. Versão Traduzida: Algoritmos – Teoria e Prática 3ª. Edição, Elsevier, 2012.
3. Discrete Mathematics and Its Applications, Eighth Edition, Kenneth H. Rosen.
4. Aula 9 - SegTree acessado em 2 de dezembro de 2023.
5. [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) acessado em 2 de dezembro de 2023.
