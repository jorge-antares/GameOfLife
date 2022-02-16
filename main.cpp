//
//  main.cpp
//  Game_of_Life
//
//  Created by Jorge A Garcia on 2020-04-03.
//  Copyright © 2020 Jorge A Garcia. All rights reserved.
//

#include <iostream>
#include <cmath>
#define PS 512.0

using namespace std;


int main(int argc, const char * argv[]) {
    int T = 25;
    char alive = '#';
    char dead = ' ';
    int colCA = 20;
    int rowCA = 15;
    char CA0[rowCA][colCA];
    char CA1[rowCA][colCA];
    srand(6);
    
    // Assigning initial condition
    for (int i = 0; i < rowCA; i++) {
        for (int j = 0; j < colCA; j++) {
            if (j == floor(colCA/2) or j == (floor(colCA/2) + 1)) {
                CA0[i][j] = alive;
                CA1[i][j] = alive;
            } else {
                CA0[i][j] = dead;
                CA1[i][j] = dead;
            }
        }
    }

    // Printing initial condition
    for (int i = 0; i < rowCA; i++) {
        for (int j = 0; j < colCA; j++) {
            cout << CA0[i][j];
            if (j == (colCA - 1)) {
                cout << "\n";
            }
        }
    }
    cout << "\n\n";
    
    // Simulation
    int t = 0;
    while (t <= T) {
        
        for (int i = 0; i < rowCA; i++) {
            for (int j = 0; j < colCA; j++) {
                int aliveNum = 0;
                
                // Summing alive cells
                for(int k = i - 1; k <= i + 1; k++) {
                    for(int l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 and l >=0 and k < rowCA and l < colCA) {
                            if (CA0[k][l] == alive) {
                                aliveNum++;
                            }
                        }
                    }
                }
                //cout << aliveNum << "\n";
                
                // Rule of surviving
                if (CA0[i][j] == alive and (aliveNum > 4 or aliveNum < 3)) {
                    CA1[i][j] = dead;
                }
                
                if (CA0[i][j] == dead and aliveNum == 3) {
                    CA1[i][j] = alive;
                }
            }
        }
        
        // Assigning new old table & printing
        for (int i = 0; i < rowCA; i++) {
            for (int j = 0; j < colCA; j++) {
                CA0[i][j] = CA1[i][j];
                cout << CA1[i][j];
                if (j == (colCA - 1)) {
                    cout << "\n";
                }
            }
        }
        cout << "\n\n";
        t++;
    }
    return 0;
}


/*
float r = rand() % 2;
if (r == 0) {
    CA0[i][j] = alive;
    CA1[i][j] = alive;
} else {
    CA0[i][j] = dead;
    CA1[i][j] = dead;
}
 */
