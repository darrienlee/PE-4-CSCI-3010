// Darrien Lee CSCI 3010 PE 4

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// create an "empty" 3x3 matrix (you can decide what type you want this matrix contain, and if you'll represent it with a 2-dimensional array, vector, or something else)
vector<vector<char>> CreateBoard() {
    vector<vector<char>> new_board {{+, +, +}, {+, +, +}, {+, +, +}};
    return new_board;
}

void DisplayBoard(vector<vector<char> b1) {
    unsigned int size = b1.size();
    for(unsigned int i = 0; i < size; i++) {
        for(unsigned int j = 0; j < size; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    CreateBoard();
    
    return 0;
}