#include "graph.h"

#include <fstream>
#include <iostream>
#include <queue>

// Konstruktor třídy Graph.
// Na začátku nastaví počet vrcholů na 0.
Graph::Graph() {
    n = 0;
}

// Funkce načte graf ze vstupního textového souboru.
// Soubor musí obsahovat nejprve počet vrcholů n,
// a potom n řádků matice sousednosti.
bool Graph::loadFromFile(const std::string& filename) {
    // Otevření vstupního souboru.
    std::ifstream file(filename);

    // Pokud se soubor nepodaří otevřít, funkce vrátí false.
    if (!file.is_open()) {
        std::cerr << "Soubor se nepodarilo otevrit: " << filename << std::endl;
        return false;
    }

    // Načtení počtu vrcholů grafu.
    file >> n;

    // Kontrola, zda je počet vrcholů platný.
    if (n <= 0) {
        std::cerr << "Neplatny pocet vrcholu." << std::endl;
        return false;
    }

    // Vymazání původní matice a vytvoření nové matice velikosti n × n.
    adjacencyMatrix.clear();
    adjacencyMatrix.resize(n, std::vector<int>(n, 0));

    // Pomocná proměnná pro načítání jednoho řádku matice sousednosti ze souboru.
    std::string row;

    // Postupné načítání jednotlivých řádků matice sousednosti.
    for (int i = 0; i < n; i++) {
        file >> row;

        // Každý řádek musí mít přesně n znaků.
        if ((int)row.length() != n) {
            std::cerr << "Neplatna delka radku matice." << std::endl;
            return false;
        }

        // Zpracování jednotlivých znaků v řádku.
        for (int j = 0; j < n; j++) {
            // Matice může obsahovat pouze znaky 0 nebo 1.
            if (row[j] != '0' && row[j] != '1') {
                std::cerr << "Matice muze obsahovat pouze hodnoty 0 a 1." << std::endl;
                return false;
            }

            // Převod znaku '0' nebo '1' na číslo 0 nebo 1.
            adjacencyMatrix[i][j] = row[j] - '0';
        }
    }

    // Pokud vše proběhlo správně, graf byl úspěšně načten.
    return true;
}

// Funkce ověřuje, zda je graf bipartitní.
// Používá algoritmus BFS a barvení vrcholů dvěma barvami.
bool Graph::isBipartite() const {
    // Pole barev vrcholů.
    // Hodnota -1 znamená, že vrchol ještě nebyl obarven.
    std::vector<int> color(n, -1);

    // Procházíme všechny vrcholy, protože graf nemusí být souvislý.
    for (int start = 0; start < n; start++) {
        // Pokud vrchol ještě nemá barvu, začneme z něj nové BFS.
        if (color[start] == -1) {
            // Vytvoření fronty pro BFS algoritmus.
            std::queue<int> q;


            // První vrchol komponenty obarvíme barvou 0.
            color[start] = 0;
            // Přidání počátečního vrcholu do fronty.
            q.push(start);

            // BFS prochází vrcholy postupně pomocí fronty.
            while (!q.empty()) {
                // Vezmeme první vrchol z fronty.
                int vertex = q.front();
                // Odstranění zpracovaného vrcholu z fronty
                q.pop();

                // Projdeme všechny možné sousedy daného vrcholu.
                for (int neighbor = 0; neighbor < n; neighbor++) {
                    // Kontrola, zda mezi vrcholy existuje hrana.
                    // Hodnota 1 v matici znamená spojení mezi vrcholy.
                    if (adjacencyMatrix[vertex][neighbor] == 1) {
                        // // Kontrola smyčky z vrcholu do sebe.Pokud vrchol ukazuje sám na sebe, graf nemůže být bipartitní.
                        if (neighbor == vertex) {
                            return false;
                        }

                        // Pokud soused ještě není obarven,
                        // přiřadíme mu opačnou barvu než má aktuální vrchol.
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[vertex];
                            // Přidání sousedního vrcholu do fronty pro další zpracování.
                            q.push(neighbor);
                        }
                        // Pokud soused už barvu má a je stejná jako u aktuálního vrcholu,
                        // graf nemůže být bipartitní.
                        else if (color[neighbor] == color[vertex]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    // Pokud nebyl nalezen žádný konflikt barev, graf je bipartitní.
    return true;
}

// Funkce vrací počet vrcholů grafu.
int Graph::getVertexCount() const {
    return n;
}

// Funkce vypíše matici sousednosti na standardní výstup.
void Graph::printMatrix() const {
    // Procházíme všechny řádky matice.
    for (int i = 0; i < n; i++) {
        // V každém řádku vypíšeme všechny hodnoty.
        for (int j = 0; j < n; j++) {
            std::cout << adjacencyMatrix[i][j];
        }

        // Po vypsání jednoho řádku přejdeme na nový řádek.
        std::cout << std::endl;
    }
}