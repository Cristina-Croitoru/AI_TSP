#include "TSP.h"
#include <chrono>   
void bfs(TSP& tsp);
void ucs(TSP& tsp);
void a_star(TSP& tsp);

int main() {
    TSP tsp(9);
    tsp.cities = {
        {0, "R"},
        {1, "T"},
        {2, "M"},
        {3, "V"},
        {4, "B"},
        {5, "F"},
        {6, "N"},
        {7, "P"},
        {8, "C"},
    };

    tsp.addDistance(0, 1, 653);
    tsp.addDistance(0, 2, 579);
    tsp.addDistance(0, 3, 530);
    tsp.addDistance(0, 4, 379);
    tsp.addDistance(0, 5, 275);
    tsp.addDistance(0, 6, 228);
    tsp.addDistance(0, 7, 927);
    tsp.addDistance(0, 8, 796);

    tsp.addDistance(1, 2, 142);
    tsp.addDistance(1, 3, 403);
    tsp.addDistance(1, 4, 331);
    tsp.addDistance(1, 5, 432);
    tsp.addDistance(1, 6, 889);
    tsp.addDistance(1, 7, 1589);
    tsp.addDistance(1, 8, 1458);

    tsp.addDistance(2, 3, 278);
    tsp.addDistance(2, 4, 213);
    tsp.addDistance(2, 5, 313);
    tsp.addDistance(2, 6, 771);
    tsp.addDistance(2, 7, 1471);
    tsp.addDistance(2, 8, 1340);

    tsp.addDistance(3, 4, 154);
    tsp.addDistance(3, 5, 268);
    tsp.addDistance(3, 6, 726);
    tsp.addDistance(3, 7, 1425);
    tsp.addDistance(3, 8, 1294);

    tsp.addDistance(4, 5, 128);
    tsp.addDistance(4, 6, 586);
    tsp.addDistance(4, 7, 1285);
    tsp.addDistance(4, 8, 1154);

    tsp.addDistance(5, 6, 472);
    tsp.addDistance(5, 7, 1172);
    tsp.addDistance(5, 8, 1041);

    tsp.addDistance(6, 7, 717);
    tsp.addDistance(6, 8, 586);

    tsp.addDistance(7, 8, 210);

    auto start = chrono::high_resolution_clock::now();
    a_star(tsp);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "A* Execution time: " << duration << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    ucs(tsp);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "UCS Execution time: " << duration << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    bfs(tsp);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "BFS Execution time: " << duration << " seconds" << endl;
    return 0;
}