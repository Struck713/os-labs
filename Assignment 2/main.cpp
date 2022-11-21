#include <iostream>
#include <fstream>
#include <string>
  
const int PROCESSES = 5;
const int RESOURCES = 3;
  
void calculateNeed(int need[PROCESSES][RESOURCES], int max[PROCESSES][RESOURCES], int allocated[PROCESSES][RESOURCES])
{
    for (int i = 0 ; i < PROCESSES ; i++) {
        for (int j = 0 ; j < RESOURCES ; j++) need[i][j] = max[i][j] - allocated[i][j];
    }
}
  
bool isSafe(int processes[], int availiable[], int max[][RESOURCES], int allocated[][RESOURCES]) {

    int need[PROCESSES][RESOURCES];
    calculateNeed(need, max, allocated);
  
    bool done[PROCESSES] = {0};
    int sequence[PROCESSES];

    int work[RESOURCES];
    for (int i = 0; i < RESOURCES; i++) work[i] = availiable[i];
  
    int count = 0;
    while (count < PROCESSES) {

        bool found = false;
        for (int p = 0; p < PROCESSES; p++) {
            if (done[p] == 0) {

                int j = 0;
                for (j = 0; j < RESOURCES; j++) {
                    if (need[p][j] > work[j]) break;
                }

                if (j == RESOURCES) {
                    for (int k = 0 ; k < RESOURCES; k++) work[k] += allocated[p][k];
  
                    sequence[count++] = p;
                    done[p] = 1;
  
                    found = true;
                }
            }
        }
  
        if (!found) {
            std::cout << "The system is not in a safe state." << std::endl;
            return false;
        }
    }
  
    std::cout << "The system is in safe state. Safe sequence is: ";
    for (int i = 0; i < PROCESSES ; i++) std::cout << sequence[i] << ' ';
    std::cout << std::endl;
  
    return true;
}

int main() {
    int processes[] = { 0, 1, 2, 3, 4 };
    
    std::ifstream table("table.txt", std::ios_base::in);
    if (!table) {
        std::cout << "Failed to open table.txt." << std::endl;
        return EXIT_FAILURE;
    }

    int max[PROCESSES][RESOURCES];
    int allocated[PROCESSES][RESOURCES];
    int availiable[RESOURCES];

    for (int i = 0; i < PROCESSES; ++i) {
        // load allocation and max
        for (int j = 0; j < RESOURCES; ++j) table >> allocated[i][j];
        for (int j = 0; j < RESOURCES; ++j) table >> max[i][j];

        // first row of file will contain avaliable resources
        if (i == 0) for (int j = 0; j < RESOURCES; ++j) table >> availiable[i];
    }

    isSafe(processes, availiable, max, allocated);
    return EXIT_SUCCESS;
}