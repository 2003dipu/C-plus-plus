// implementing a minimax algorithm in C++ is a daunting task, however I didn't put in much time there

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Player {
public:
    char letter;

    Player(char _letter) : letter(_letter) {}

    virtual int get_move(const std::vector<char>& board) {
        return -1; // Placeholder value
    }
};

class RandomComputerPlayer : public Player {
public:
    RandomComputerPlayer(char _letter) : Player(_letter) {}

    int get_move(const std::vector<char>& board) override {
        std::vector<int> available_moves;
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                available_moves.push_back(i);
            }
        }
        if (!available_moves.empty()) {
            int random_index = rand() % available_moves.size();
            return available_moves[random_index];
        }
        return -1; // No available moves
    }
};

class HumanPlayer : public Player {
public:
    HumanPlayer(char _letter) : Player(_letter) {}

    int get_move(const std::vector<char>& board) override {
        int move;
        do {
            std::cout << "Enter your move (0-8): ";
            std::cin >> move;
        } while (move < 0 || move > 8 || board[move] != ' ');

        return move;
    }
};

class TicTacToe {
public:
    std::vector<char> board;
    char current_winner;

    TicTacToe() : board(9, ' '), current_winner(' ') {}

    void print_board() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << "|" << board[i * 3 + j];
            }
            std::cout << "|\n";
        }std::cout << "\n";
    }

    std::vector<int> available_moves() const {
        std::vector<int> moves;
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                moves.push_back(i);
            }
        }
        return moves;
    }

    bool make_move(int square, char letter) {
        if (square < 0 || square >= 9 || board[square] != ' ') {
            return false;
        }
        board[square] = letter;
        return true;
    }

    bool is_winner(char letter) const {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            if ((board[i] == letter && board[i + 3] == letter && board[i + 6] == letter) || // Check columns
                (board[i * 3] == letter && board[i * 3 + 1] == letter && board[i * 3 + 2] == letter)) { // Check rows
                return true;
            }
        }

        // Check diagonals
        if ((board[0] == letter && board[4] == letter && board[8] == letter) ||
            (board[2] == letter && board[4] == letter && board[6] == letter)) {
            return true;
        }

        return false;
    }

    bool is_board_full() const {
        for (char cell : board) {
            if (cell == ' ') {
                return false;
            }
        }
        return true;
    }
};

void play_game(TicTacToe& game, Player& player1, Player& player2) {
    char current_player = 'X';

    while (true) {
        game.print_board();

        if (current_player == 'X') {
            int move = player1.get_move(game.board);
            game.make_move(move, 'X');

            if (game.is_winner('X')) {
                game.print_board();
                std::cout << "Player X wins!\n";
                break;
            }
            if (game.is_board_full()) {
                game.print_board();
                std::cout << "It's a tie!\n";
                break;
            }
            current_player = 'O';
        } else {
            int move = player2.get_move(game.board);
            game.make_move(move, 'O');

            if (game.is_winner('O')) {
                game.print_board();
                std::cout << "Player O wins!\n";
                break;
            }
            if (game.is_board_full()) {
                game.print_board();
                std::cout << "It's a tie!\n";
                break;
            }
            current_player = 'X';
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    HumanPlayer player1('X');
    RandomComputerPlayer player2('O');
    TicTacToe game;

    play_game(game, player1, player2);

    return 0;
}
