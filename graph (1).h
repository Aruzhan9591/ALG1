#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

/**
 * @brief Třída reprezentující neorientovaný graf
 * uložený pomocí matice sousednosti.
 */
class Graph {
private:
    // Počet vrcholů grafu.
    int n;

    // Matice sousednosti grafu.
    // Hodnota 1 znamená existenci hrany,
    // hodnota 0 znamená neexistenci hrany.
    std::vector<std::vector<int>> adjacencyMatrix;

public:

    /**
     * @brief Konstruktor třídy Graph.
     * Inicializuje prázdný graf.
     */
    Graph();

    /**
     * @brief Načte graf ze vstupního textového souboru.
     *
     * Soubor obsahuje počet vrcholů
     * a následně matici sousednosti.
     *
     * @param filename Název vstupního souboru.
     *
     * @return true pokud byl graf načten správně.
     * @return false pokud při načítání nastala chyba.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Ověří, zda je graf bipartitní.
     *
     * Funkce používá algoritmus BFS
     * a obarvování vrcholů dvěma barvami.
     *
     * @return true pokud je graf bipartitní.
     * @return false pokud graf není bipartitní.
     */
    bool isBipartite() const;

    /**
     * @brief Vrátí počet vrcholů grafu.
     *
     * @return Počet vrcholů.
     */
    int getVertexCount() const;

    /**
     * @brief Vypíše matici sousednosti grafu.
     */
    void printMatrix() const;
};

#endif