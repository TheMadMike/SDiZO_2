#include <iostream>
#include <fstream>
#include "IncidenceMatrix.hpp"
#include "MST.hpp"

using namespace sdizo;

static const char* MENU =  
"[1] Load a graph from file \n"
"[2] Generate random graph \n"
"[3] Print graph representations \n"
"[4] Kruskal's algorithm \n"
"[5] Prim's algorithm \n"
"[6] Dijkstra's algorithm \n"
"[7] Bellman-Ford's algorithm \n"
"[8] Ford-Fulkerson's method \n"
"[9] Run time benchmark \n"
"[0] Exit \n\n"
"?: ";

static IncidenceMatrix<int> incidenceMatrix;

void loadGraphsFromFile(const char* fileName);
void generateRandomGraphs(size_t vertexCount, float density);
void printGraphs();

int main(void) {
    int option = 0;
    std::string fileName;
    size_t vertexCount;
    float density;
    IncidenceMatrix<int> mstMatrix;

    do {
        std::cout << MENU;
        std::cin >> option;
        switch(option) {
            case 1:
                std::cin >> fileName;
                loadGraphsFromFile(fileName.c_str());
            break;
            case 2:
                std::cout << "Vertex count: ";
                std::cin >> vertexCount;
                std::cout << "Graph density [%]: ";
                std::cin >> density;
                generateRandomGraphs(vertexCount, density);
            break;
            case 3:
                printGraphs();
            break;
            case 4:
                mstMatrix = MST::kruskal(incidenceMatrix);
                std::cout << "MST incidence matrix: \n";
                mstMatrix.printMatrix();
                std::cout << "MST incidence list: \n";
            break;
            case 5:
                mstMatrix = MST::prim(incidenceMatrix);
                std::cout << "MST incidence matrix: \n";
                mstMatrix.printMatrix();
                std::cout << "MST incidence list: \n";
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 0: break;

            default:
                std::cout << "\n\nInvalid option!\n\n";
            break;
        }
    } while(option != 0);
}

void loadGraphsFromFile(const char* fileName) {
    std::ifstream file(fileName);
    size_t edgeCount, vertexCount;
    file >> edgeCount >> vertexCount;

    size_t start, end;
    int weight;
    for(size_t i = 0; i < edgeCount; ++i) {
        file >> start >> end >> weight;
        incidenceMatrix.addEdge(start, end, weight);
    }
}

void generateRandomGraphs(size_t vertexCount, float density) {
    std::cout << vertexCount << density;
}

void printGraphs() {
    incidenceMatrix.printMatrix();
}