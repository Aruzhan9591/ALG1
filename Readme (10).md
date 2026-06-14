# Algoritmy projekt — Bipartitní graf

Tento projekt byl vypracován v rámci předmětu **Algoritmy I** (letní semestr 2025/2026) na VŠB-TUO.

## Cíl projektu

Cílem projektu je implementovat algoritmus, který rozhodne, zda je zadaný graf bipartitní.

Graf je načten ze vstupního souboru ve formě matice sousednosti.
Program následně pomocí BFS (prohledávání do šířky) ověří,
zda lze vrcholy rozdělit do dvou skupin tak, aby žádná hrana
nespojovala dva vrcholy ze stejné skupiny.

## Struktura projektu

- `main.cpp` – vstupní bod programu, zpracování argumentů a výpis výsledků  
- `graph.cpp` – implementace třídy Graph a algoritmu BFS  
- `graph.h` – deklarace třídy Graph  
- `Makefile` – soubor pro kompilaci programu  
- `Doxyfile` – konfigurační soubor pro dokumentaci  
- `*.txt` – testovací vstupní soubory  

## Kompilace

Program lze přeložit pomocí Makefile:

make

Makefile automaticky přeloží všechny soubory.

Program lze přeložit také ručně:

g++ -Wall -Wextra -pedantic -std=c++17 -c main.cpp  
g++ -Wall -Wextra -pedantic -std=c++17 -c graph.cpp  
g++ -Wall -Wextra -pedantic -std=c++17 main.o graph.o -o bipartite  

## Spuštění programu

Program se spouští takto:

./bipartite nazev_souboru.txt

## Například:

./bipartite BipartiteGraph1.txt 

Program vypíše matici sousednosti a informaci, zda je graf bipartitní nebo ne.

## Program lze spustit i pro více souborů najednou:

for f in BipartiteGraph*.txt bp_test_*.txt CyclicGraph.txt; do
  echo "===== $f ====="
  ./bipartite "$f"
done

## Dokumentace

Dokumentaci lze vygenerovat:

doxygen Doxyfile

Výstup se nachází ve složce:

html/index.html

## Autor

Aruzhan Abilmazhinova  
ABI0008