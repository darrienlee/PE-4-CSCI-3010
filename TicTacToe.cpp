// Darrien Lee CSCI 3010 PE 4

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// create an "empty" 3x3 matrix (you can decide what type you want this matrix contain, and if you'll represent it with a 2-dimensional array, vector, or something else)
vector<vector<char>> CreateBoard() {
    vector<vector<char>> new_board {{'+', '+', '+'}, {'+', '+', '+'}, {'+', '+', '+'}};
    return new_board;
}

// Displays the board
void DisplayBoard(vector<vector<char>> b1) {
    unsigned int size = b1.size();
    for(unsigned int i = 0; i < size; i++) {
        for(unsigned int j = 0; j < size; j++) {
            cout << b1[i][j] << " ";
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
vector<vector<char>> PlaceMarker(vector<vector<char>> b1, vector<int> loc, int player_marker) {
    b1[loc[0]][loc[1]] = player_marker;
    return b1;
}

// checks if there is a winner, true if there is a winner, false if there is not yet a winner
bool IsWinner(vector<vector<char>> b1){
    // top row
    if(b1[0][0] == b1[0][1]) {
        if(b1[0][1] == b1[0][2]) {
            if(b1[0][0] != '+'){
                return true;
            }
        }
    }
    // middle row
    if(b1[1][0] == b1[1][1]) {
        if(b1[1][1] == b1[1][2]) {
            if(b1[1][0] != '+'){
                return true;
            }
        }
    }
    // bottom row
    if(b1[2][0] == b1[2][1]) {
        if(b1[2][1] == b1[2][2]) {
            if(b1[2][0] != '+'){
                return true;
            }
        }
    }
    
    // left col
    if(b1[0][0] == b1[1][0]) {
        if(b1[1][0] == b1[2][0]) {
            if(b1[0][0] != '+'){
                return true;
            }
        }
    }
    // middle col
    if(b1[0][1] == b1[1][1]) {
        if(b1[1][1] == b1[2][1]) {
            if(b1[0][1] != '+'){
                return true;
            }
        }
    }
    // right col
    if(b1[0][2] == b1[1][2]) {
        if(b1[1][2] == b1[2][2]) {
            if(b1[0][2] != '+'){
                return true;
            }
        }
    }
    
    // diagonal down right
    if(b1[0][0] == b1[1][1]) {
        if(b1[1][1] == b1[2][2]) {
            if(b1[0][0] != '+'){
                return true;
            }
        }
    }
    // diagonal down left
    if(b1[0][2] == b1[1][1]) {
        if(b1[1][1] == b1[2][0]) {
            if(b1[0][2] != '+') {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    vector<vector<char>> new_board = CreateBoard();
    int turns = 0;
    bool won = false;
    
    while(turns < 9 && !won) {
        int player = turns%2;
        char marker;
        vector<int> choice;
        
        DisplayBoard(new_board);
        if(player == 0){
            cout << "Player 1's turn (X)" << endl;
            marker = 'X';
        }
        else{
            cout << "Player 2's turn (O)" << endl;
            marker = 'O';
        }
        choice = GetPlayerChoice();
        new_board = PlaceMarker(new_board, choice, marker);
        
        won = (IsWinner(new_board));
        if((player == 0) && won){
            cout << "Player 1 (X) Wins!" << endl;
        }
        if((player != 0) && won){
            cout << "Player 2 (O) Wins!" << endl;
        }
        turns++;
    }
    
    return 0;
}