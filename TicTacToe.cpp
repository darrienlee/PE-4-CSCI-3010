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

// Displays the board
void DisplayBoard(vector<vector<char> b1) {
    unsigned int size = b1.size();
    for(unsigned int i = 0; i < size; i++) {
        for(unsigned int j = 0; j < size; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// gets player's row and column number that they wish to place their marker on
vector<int> GetPlayerChoice() {
    int i;
    int j;
    
    cout << "Please enter row number (1 - 3): ";
    cin >> i;
    i = i - 1;
    
    cout << "Please enter column number (1 - 3): ";
    cin >> j;
    j = j - 1;
    
    vector<int> temp{i,j};
    return temp;
}

// places player marker on board and return modified board
vector<vector<int>> PlaceMarker(vector<vector<int>> board, vector<int> location, int player_marker) {
    board[location[0]][location[1]] = player_marker;
    return board;
}


int main() {
    CreateBoard();
    
    return 0;
}