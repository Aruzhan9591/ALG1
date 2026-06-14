
/**
 * @file main.cpp
 * @brief Hlavní soubor programu pro kontrolu bipartitního grafu.
 *
 * Program načte graf ze vstupního souboru,
 * vypíše matici sousednosti a ověří,
 * zda je graf bipartitní pomocí BFS algoritmu.
 */

#include "graph.h"
#include <iostream>

/**
 * @brief Hlavní funkce programu.
 *
 * Funkce zpracuje argumenty příkazové řádky,
 * načte graf ze souboru a vypíše výsledek kontroly.
 *
 * @param argc Počet argumentů příkazové řádky.
 * @param argv Pole argumentů příkazové řádky.
 * @return int Návratová hodnota programu.
 *         0 = úspěch
 *         1 = chyba
 */
int main(int argc, char* argv[]) {

    // Kontrola počtu argumentů
    // Program očekává přesně jeden vstupní soubor
    if (argc != 2) {

        // Výpis správného použití programu
        std::cout << "Pouziti: ./bipartite nazev_souboru.txt" << std::endl;

        // Ukončení programu s chybou
        return 1;
    }

    // Vytvoření objektu grafu
    Graph graph;

    // Pokus o načtení grafu ze souboru
    if (!graph.loadFromFile(argv[1])) {

        // Pokud se načtení nepovede,
        // program se ukončí
        return 1;
    }

    // Výpis počtu vrcholů grafu
    std::cout << "Nacteny graf ma "
              << graph.getVertexCount()
              << " vrcholu."
              << std::endl;

    // Výpis matice sousednosti
    std::cout << "Matice sousednosti:" << std::endl;

    // Zavolání funkce pro výpis matice
    graph.printMatrix();

    // Kontrola, zda je graf bipartitní
    if (graph.isBipartite()) {

        // Graf je bipartitní
        std::cout << "Vysledek: Graf je bipartitni."
                  << std::endl;

    } else {

        // Graf není bipartitní
        std::cout << "Vysledek: Graf neni bipartitni."
                  << std::endl;
    }

    // Úspěšné ukončení programu
    return 0;
}