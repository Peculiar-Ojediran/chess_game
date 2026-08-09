#include "allowed_moves.hpp"

int main()
{
    std::unordered_map<int, std::string> chess_pieces;
    std::unordered_map<int, std::vector<int>> allowed_moves;
    chess_pieces[1] = "pawns";
    chess_pieces[2] = "Rook";
    chess_pieces[3] = "knigth";
    chess_pieces[4] = "bishop";
    chess_pieces[5] = "queen";
    chess_pieces[6] = "king";
    
    std::vector<std::vector<int>> chess_board = {
    //   0   1   2   3   4   5   6   7
        {22, 32, 42, 52, 62, 42, 32, 22}, // 0
        {12, 12, 12, 12, 12, 12, 12, 12}, // 1
        {00, 00, 00, 00, 00, 00, 00, 00}, // 2
        {00, 00, 00, 52, 00, 00, 00, 00}, // 3
        {00, 00, 00, 00, 00, 00, 00, 00}, // 4
        {00, 00, 00, 00, 00, 00, 00, 00}, // 5
        {11, 11, 11, 11, 11, 11, 11, 11}, // 6
        {21, 31, 41, 51, 61, 41, 31, 21}  // 7
    };

    for (int i = 0; i < chess_board.size(); i++)
    {
        for (int j = 0; j < chess_board[0].size(); j++)
        {
            std::cout << chess_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // std::cout<<allowed_moves.size();
    check(allowed_moves, chess_board);
    std::cout << allowed_moves.size();
    // for(auto &p : allowed_moves[31])std::cout<< p<< " "<<std::endl;
}