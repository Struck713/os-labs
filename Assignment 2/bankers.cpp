#include <iostream>
#include <fstream>
#include <string>
  
const int PROCESSES = 5;
const int RESOURCES = 3;

bool checkSafe(int processes[], int available[], int max[][RESOURCES], int allocated[][RESOURCES]);

int main() {
    int processes[] = { 0, 1, 2, 3, 4 };
    
    std::ifstream table("table.txt", std::ios_base::in);
    if (!table) {
        std::cout << "Failed to open table.txt." << std::endl;
        return EXIT_FAILURE;
    }

    int max[PROCESSES][RESOURCES];
    int allocated[PROCESSES][RESOURCES];
    int available[RESOURCES];

    for (int i = 0; i < PROCESSES; ++i) {
        // load allocation and max
        for (int j = 0; j < RESOURCES; ++j) table >> allocated[i][j];
        for (int j = 0; j < RESOURCES; ++j) table >> max[i][j];

        // first row of file will contain avaliable resources
        if (i == 0) for (int j = 0; j < RESOURCES; ++j) table >> available[j];
    }

    std::cout << "Allocated: ";
    for (int i = 0; i < PROCESSES; ++i)
        for (int j = 0; j < RESOURCES; ++j) std::cout << allocated[i][j] << ' ';
    std::cout << std::endl;

    std::cout << "Max: ";
    for (int i = 0; i < PROCESSES; ++i)
        for (int j = 0; j < RESOURCES; ++j) std::cout << max[i][j] << ' ';
    std::cout << std::endl;

    std::cout << "Available: ";
    for (int i = 0; i < RESOURCES; ++i) std::cout << available[i] << ' ';
    std::cout << std::endl;

    checkSafe(processes, available, max, allocated);
    return EXIT_SUCCESS;
}
  
bool checkSafe(int processes[], int available[], int max[][RESOURCES], int allocated[][RESOURCES]) {

    int need[PROCESSES][RESOURCES];
    for (int i = 0 ; i < PROCESSES ; i++) {
        for (int j = 0 ; j < RESOURCES ; j++) need[i][j] = max[i][j] - allocated[i][j];
    }
  
    bool done[PROCESSES] = {0};
    int sequence[PROCESSES];

    int work[RESOURCES];
    for (int i = 0; i < RESOURCES; i++) work[i] = available[i];
  
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