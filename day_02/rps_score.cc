#include <iostream>
#include <map>

std::map<char, int> score_self = {
    {'R', 1},
    {'P', 2},
    {'S', 3}
};

std::map<char, char> move_A = {
    {'A', 'R'},
    {'B', 'P'},
    {'C', 'S'}
};

std::map<char, char> move_B = {
    {'X', 'R'},
    {'Y', 'P'},
    {'Z', 'S'}
};

std::map<char, char> pred_B = {
    {'X', 'L'},
    {'Y', 'D'},
    {'Z', 'W'}
};

std::map<std::pair<char, char>, char> take_move = {
    {{'R','L'}, 'S'},
    {{'R','D'}, 'R'},
    {{'R','W'}, 'P'},
    {{'P','L'}, 'R'},
    {{'P','D'}, 'P'},
    {{'P','W'}, 'S'},
    {{'S','L'}, 'P'},
    {{'S','D'}, 'S'},
    {{'S','W'}, 'R'}
};

std::map<std::pair<char, char>, int> score_matrix = {
    {{'R','R'}, 1},
    {{'R','P'}, 2},
    {{'R','S'}, 0},
    {{'P','R'}, 0},
    {{'P','P'}, 1},
    {{'P','S'}, 2},
    {{'S','R'}, 2},
    {{'S','P'}, 0},
    {{'S','S'}, 1}
};

int main() {
    int score_normal = 0;
    int score_predictive = 0;

    char player_A;
    char player_B;
    while (std::cin >> player_A >> player_B) {
        score_normal += score_self[move_B[player_B]]
                    + 3*score_matrix[{move_A[player_A], move_B[player_B]}];

        char player_B_pred = take_move[{move_A[player_A], pred_B[player_B]}];
        score_predictive += score_self[player_B_pred]
                        + 3*score_matrix[{move_A[player_A], player_B_pred}];
    }

    std::cout << score_normal << std::endl;
    std::cout << score_predictive << std::endl;
}
