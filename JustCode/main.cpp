#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include "speedTest.hpp"
using namespace std;

void print_diagonal_values(const vector<int>& diagonal, vector<int*> letters) {
    for (int i : diagonal) {
        cout << *letters[i] << " ";
    }
    cout << endl;
}

int checkSumOfDiagonal(const vector<int>& diagonal, vector<int*> letters) {
    int sumOfDiagonal = 0;
    for (int i : diagonal) {
		sumOfDiagonal += *letters[i];
	}
    return sumOfDiagonal;
}

bool checkAllDiagonals(const vector<vector<int>>& all_diagonals, vector<int*> letters) {
    for (int i = 0; i < 15; i++) {
        if (checkSumOfDiagonal(all_diagonals[i], letters) != 38) {
            return false;
        }
    }
    return true;
}



void fillLetter(vector<int*> letters, linkedList<int>& choicePoolList, linkedList<int>& letterOrderList, linkedList<int>& letterOrderListRemoved, int offset) {
    int removed = letterOrderList.removeFirst();
    letterOrderListRemoved.insertFirst(removed);
    *letters[removed] = choicePoolList.removeAt(offset);
}

void putLetterBack(vector<int*> letters, linkedList<int>& choicePoolList, linkedList<int>& letterOrderList, linkedList<int>& letterOrderListRemoved) {
    int removed = letterOrderListRemoved.removeFirst();
    letterOrderList.insertFirst(removed);
    choicePoolList.insertOrdered(*letters[removed]);
    *letters[removed] = 0;
}

string entireLettersToString(vector<int*> letters, int valueWanted, long long duration) {
    string result = "";
    result += "    ";
    for (int j = 0; j < 3; j++) {
        result += to_string(*letters[j]);
        if (*letters[j] < 10) {
            result += "  ";
        }
        if (*letters[j] >= 10)
        {
            result += " ";
        }
    }
    result += "\n";
    result += "   ";
    for (int j = 0; j < 4; j++) {
        result += to_string(*letters[j+3]);
        if (*letters[j + 3] < 10) {
            result += "  ";
        }
        if (*letters[j + 3] >= 10)
        {
            result += " ";
        }
    }
    result += "\n";
    result += "  ";
    for (int j = 0; j < 5; j++) {
        result += to_string(*letters[j+3+4]);
        if (*letters[j + 3 + 4] < 10) {
            result += "  ";
        }
        if (*letters[j + 3 + 4] >= 10)
        {
            result += " ";
        }
    }
    result += "\n";
    result += "   ";
    for (int j = 0; j < 4; j++) {
        result += to_string(*letters[j+3+4+5]);
        if (*letters[j + 3 + 4 + 5] < 10) {
            result += "  ";
        }
        if (*letters[j + 3 + 4 + 5] >= 10)
        {
            result += " ";
        }
    }
    result += "\n";
    result += "    ";
    for (int j = 0; j < 3; j++) {
        result += to_string(*letters[j+3+4+5+4]);
        if (*letters[j + 3 + 4 + 5 + 4] < 10) {
            result += "  ";
        }
        if (*letters[j + 3 + 4 + 5 + 4] >= 10)
        {
            result += " ";
        }
    }
    result += "\n";
    result += "Value wanted: " + to_string(valueWanted) + "\n";
    result += "Time it took to run: " + to_string(duration / 1000.0) + " seconds" + "\n" + "\n" + "\n";
    return result;
}

void printEntireLetters(vector<int*> letters, int valueWanted, long long duration) {
    cout << entireLettersToString(letters, valueWanted, duration);
}

void saveEntireLettersToFile(vector<int*> letters, int valueWanted, long long duration) {
    // Append to the file
    ofstream file("output.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file for writing." << endl;
        return;
    }
    file << entireLettersToString(letters, valueWanted, duration);
    if (file.fail()) {
        cerr << "Error: Failed to write to the file." << endl;
    }
    file.close();
    if (file.fail()) {
        cerr << "Error: Failed to close the file." << endl;
    }
}


vector<int> getDiagonalFromStage(int stage, const vector<vector<int>>& all_diagonals_ordered) {
    stage--;
    if (stage - 1 < 0) {
        stage = 0;
    }
    return all_diagonals_ordered[stage];
}

int calcLast(const vector<int>& diagonal, vector<int*> letters, linkedList<int>& choicePoolList, int sumWanted, linkedList<int>& letterOrderList, linkedList<int>& letterOrderListRemoved) {
    int have = checkSumOfDiagonal(diagonal, letters);
    int need = sumWanted - have;
    if (need > 19)
    {
        return -1;
    }
    if (need < 1)
    {
        return 0;
    }
    int worked = choicePoolList.removeFoundElement(need);
    if (worked != -1) {
        int removed = letterOrderList.removeFirst();
        letterOrderListRemoved.insertFirst(removed);
        *letters[removed] = worked;
        return 1;
    }
    return 0;
}

int main() {
    speedTest(10000);
    int wantedSum = 38;
    bool debugPrinting = false;
    int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, J = 0, K = 0, L = 0, M = 0, N = 0, O = 0, P = 0, Q = 0, R = 0, S = 0;
    vector<int*> letters = { &A, &B, &C, &D, &E, &F, &G, &H, &I, &J, &K, &L, &M, &N, &O, &P, &Q, &R, &S };
    vector<int> offSet = { 0,0,0,0,0,0,0,0,0,0,0 };

    linkedList<int> choicePoolList; // insertOrdered, removeFirst
    linkedList<int> letterOrderList; //insertFirst, removeFirst
    linkedList<int> letterOrderListRemoved; //insertFirst, removeFirst
    int letterOrder[19] = { 2, 1, 0, 3, 7, 12, 16, 4, 8, 13, 17, 18, 9, 14, 5, 6, 11, 10, 15 };
    //                   so C, B, A, D, H, M, Q, E, I, N, R, S, J, O, F, G, L, K, P


    for (int i = 1; i <= 19; i++) {
        choicePoolList.insertFirst(i);
        letterOrderList.insertLast(letterOrder[i - 1]);
    }

    // Diagonal, 0 is A, 1 is B, etc etc.. 18 is S
    vector<int> diagonal_1 = { 0, 3, 7 };
    vector<int> diagonal_2 = { 1, 4, 8, 12 };
    vector<int> diagonal_3 = { 2, 5, 9, 13, 16 };
    vector<int> diagonal_4 = { 6, 10, 14, 17 };
    vector<int> diagonal_5 = { 11, 15, 18 };

    // \ Diagonal
    vector<int> diagonal_6 = { 2, 6, 11 };
    vector<int> diagonal_7 = { 1, 5, 10, 15 };
    vector<int> diagonal_8 = { 0, 4, 9, 14, 18 };
    vector<int> diagonal_9 = { 3, 8, 13, 17 };
    vector<int> diagonal_10 = { 7, 12, 16 };

    // - Diagonal
    vector<int> diagonal_11 = { 0, 1, 2 };
    vector<int> diagonal_12 = { 3, 4, 5, 6 };
    vector<int> diagonal_13 = { 7, 8, 9, 10, 11 };
    vector<int> diagonal_14 = { 12, 13, 14, 15 };
    vector<int> diagonal_15 = { 16, 17, 18 };
    // { 18,17,14,11,10,8, 7, 5, 4, 2, 1, 0 }; worked from 12 to 11 perfect
    vector<int> max_offset_per_stage = { 18,17,15,13,11,9, 7, 6, 4, 3, 1 };
    // 18  17   15    13  11  9  7  6   4  3   1 


    // Vector holding all diagonals
    vector<vector<int>> all_diagonals = {
        diagonal_1, diagonal_2, diagonal_3, diagonal_4, diagonal_5,
        diagonal_6, diagonal_7, diagonal_8, diagonal_9, diagonal_10,
        diagonal_11, diagonal_12, diagonal_13, diagonal_14, diagonal_15
    };

    // Vector holding the order the diagonals go in. 
    vector<vector<int>> all_diagonals_ordered = {
        diagonal_11, diagonal_1, diagonal_10, diagonal_2, diagonal_9, diagonal_15, diagonal_8, diagonal_3, diagonal_6, diagonal_4, diagonal_5
    };

    auto start = chrono::high_resolution_clock::now();
    int stage = 0;
    bool keepGoing = true;
    bool reset = false;
    int actualStage = 0;
    float counter = 0;
    int moveCounter = 0;
    int printEveryX = 0;

    while (keepGoing) {
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        printEveryX++;
        if (debugPrinting == true) {
            if (printEveryX > 1000)
            {
                printEveryX = 0;
                system("cls");
                printEntireLetters(letters, wantedSum, duration);
                cout << "Time taken: " << duration / 1000.0 << " seconds with debugger on" << endl;
                cout << "Stage: " << actualStage << endl;
                cout << "offSet: " << offSet[actualStage] << endl;

            }
        }
        
        switch (stage) {
            // 11 cases
        case 0: // start
        {
            if (reset) {
                putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
                reset = false;
            }
            moveCounter++;
            fillLetter(letters, choicePoolList, letterOrderList, letterOrderListRemoved, offSet[stage]); // A
            offSet[stage]++;
            stage++;
            actualStage = stage;
            break;
        }

        case -2:
        {
            if (reset) {
                reset = false;
                putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
                putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
            }

            moveCounter++;

            vector<int> diagHere = getDiagonalFromStage(actualStage, all_diagonals_ordered);

            fillLetter(letters, choicePoolList, letterOrderList, letterOrderListRemoved, offSet[actualStage]);
            offSet[actualStage]++;
            int worked = calcLast(diagHere, letters, choicePoolList, wantedSum, letterOrderList, letterOrderListRemoved);
            if (worked == -1)
            {
                putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
                offSet[actualStage] = 0;
                stage = actualStage - 1;
                reset = true;
                break;

            }
            if (worked == 0) {
                putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
            }
            if (offSet[actualStage] > max_offset_per_stage[actualStage]) {
                if (worked == 1) {
                    putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
                    putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
                }
                stage = actualStage - 1;
                offSet[actualStage] = 0;
                reset = true;
                break;
            }
            if (worked == 1) {
                stage = actualStage + 1;
                break;
            }
            break;
        }
        case -1:
        {
            if (reset) {
                putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
                stage = actualStage - 1;
                break;
            }
            moveCounter++;

            vector<int> diagHere = getDiagonalFromStage(actualStage, all_diagonals_ordered);
            int worked = calcLast(diagHere, letters, choicePoolList, wantedSum, letterOrderList, letterOrderListRemoved);
            if (worked == 1) {
                stage = actualStage + 1;
                offSet[actualStage] = 0;
                break;
            }
            else {
                stage = actualStage - 1;
                offSet[actualStage] = 0;
                reset = true;
                break;
            }
            break;
        }
        case 1:
        {
            actualStage = stage;
            stage = -2;
            break;
        }
        case 2:
        {
            actualStage = stage;
            stage = -2;
            break;
        }
        case 3:
        {
            actualStage = stage;
            stage = -2;
            break;
        }
        case 4:
        {
            actualStage = stage;
            stage = -2;
            break;
        }
        case 5:
        {
            actualStage = stage;
            stage = -2;
            break;
        }
        case 6:
        {
            actualStage = stage;
            stage = -1;
            break;
        }
        case 7:
        {
            actualStage = stage;
            stage = -2;
            break;
        }
        case 8:
        {
            actualStage = stage;
            stage = -1;
            break;
        }
        case 9:
        {
            actualStage = stage;
            stage = -2;
            break;
        }
        case 10:
        {
            actualStage = stage;
            stage = -1;
            break;
        }
        case 11:
        {
            fillLetter(letters, choicePoolList, letterOrderList, letterOrderListRemoved, 0); // last letter
            bool allCheckGood = checkAllDiagonals(all_diagonals, letters);
            if (allCheckGood)
            {
                auto endForever = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(endForever - start).count();
                printEntireLetters(letters, wantedSum,duration);
                cout << "Time taken: " << duration / 1000.0 << " seconds" << endl;
                cout << "offSet: " << offSet[actualStage] << endl;
                cout << "Stage: " << actualStage << endl;
                saveEntireLettersToFile(letters, wantedSum,duration);
                cout << "^ Verified solution above ^" << endl;
                cout << "number of Moves: " << moveCounter;
                keepGoing = false;
                break;
            }
            else
            {
                reset = true;
                stage = 10;
                actualStage = 10;

                putLetterBack(letters, choicePoolList, letterOrderList, letterOrderListRemoved);
            }



            break;
        }

        }
    }

    

    return 0;
}