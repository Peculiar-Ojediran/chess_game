#include "allowed_moves.hpp"

int main()
{
    std::unordered_map<int, std::string> chess_pieces;
    std::unordered_map<int, std::vector<int>> allowed_white_moves;
    std::unordered_map<int, std::vector<int>> allowed_black_moves;

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
        {00, 00, 00, 00, 12, 11, 11, 00}, // 3
        {00, 00, 00, 00, 00, 00, 00, 00}, // 4
        {00, 00, 00, 11, 00, 00, 42, 00}, // 5
        {11, 11, 11, 11, 11, 11, 11, 11}, // 6
        {21, 31, 41, 51, 61, 41, 31, 21}  // 7
    };

    // std::cout<<allowed_moves.size();
    int start = 0;
    int stop = 0;
    while (start != 99 && stop != 99)
    {
        for (int i = 0; i < chess_board.size(); i++)
        {
            for (int j = 0; j < chess_board[0].size(); j++)
            {
                if (chess_board[i][j] == 0)
                {
                    std::cout << "00 ";
                    continue;
                }
                std::cout << chess_board[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cin >> start >> stop;
        std::vector<int> selected_moves;
        if (chess_board[start / 10][start % 10] / 10 == 1)
            selected_moves = find_Pawn_moves(chess_board, start, chess_board[start / 10][start % 10], true);
        if (chess_board[start / 10][start % 10] / 10 == 2)
            selected_moves = find_Rook_moves(chess_board, start, chess_board[start / 10][start % 10], true);
        if (chess_board[start / 10][start % 10] / 10 == 3)
            selected_moves = find_Knigth_moves(chess_board, start, chess_board[start / 10][start % 10], true);
        if (chess_board[start / 10][start % 10] / 10 == 4)
            selected_moves = find_Bishop_moves(chess_board, start, chess_board[start / 10][start % 10], true);
        if (chess_board[start / 10][start % 10] / 10 == 5)
            selected_moves = find_Queen_moves(chess_board, start, chess_board[start / 10][start % 10], true);
        if (chess_board[start / 10][start % 10] / 10 == 6)
            selected_moves = find_King_moves(chess_board, start, chess_board[start / 10][start % 10], true);
        for (auto &at : selected_moves)
            std::cout << at;
        std::cout << std::endl;
        auto it = std::find(selected_moves.begin(), selected_moves.end(), stop);
        if (it != selected_moves.end())
        {
            is_pawn_en_passant(start, stop, selected_moves, chess_board);
            if (start == white_king_position)
            {
                white_king_position = stop;
                std::cout << "white king has been moved" << std::endl;
            }
            if (start == black_king_position)
            {
                black_king_position = stop;
                std::cout << "black king has been moved" << std::endl;
            }
            move_piece(chess_board, start, stop);
            check_only_white_moves(allowed_white_moves, chess_board);
            check_only_black_moves(allowed_black_moves, chess_board);
            // for(auto& at:allowed_black_moves)std::cout<<at;
            if (is_black_checked(black_king_position, allowed_white_moves))
                std::cout << "black is in check" << std::endl;
            if (is_white_checked(white_king_position, allowed_black_moves))
                std::cout << "white is in check" << std::endl;
        }
        else
        {
            std::cout << "attempted and illegal move";
        }
        std::cout << "enpassant: " << en_passant_position << std::endl;
        std::cout << "enpassant_pawn_1: " << possible_en_passant_pawn1 << std::endl;
        std::cout << "enpassant_pawn_2: " << possible_en_passant_pawn2 << std::endl;
        Sleep(5000);
        system("cls");
    }
}
