#include "piece_moves.hpp"
// std::vector<int> find_moves(std::vector<std::vector<int>> chess_board,int position,int type);






void check_only_black_moves(std::unordered_map<int, std::vector<int>> &allowed_black_moves, std::vector<std::vector<int>> &chess_board)
{
    allowed_black_moves.clear();

    for (int i = 0; i < chess_board.size(); i++)
    {
        for (int j = 0; j < chess_board[0].size(); j++)
        {
            if (chess_board[i][j] == 0)
                continue;

            else if (chess_board[i][j] % 10 == 2){
                if(chess_board[i][j]/10==1)allowed_black_moves[(i * 10) + j] = find_Pawn_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==2)allowed_black_moves[(i * 10) + j] = find_Rook_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==3)allowed_black_moves[(i * 10) + j] = find_Knigth_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==4)allowed_black_moves[(i * 10) + j] = find_Bishop_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==5)allowed_black_moves[(i * 10) + j] = find_Queen_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                
            }
                
                

        }
    }
}

void check_only_white_moves(std::unordered_map<int, std::vector<int>> &allowed_white_moves, std::vector<std::vector<int>> &chess_board)
{
    allowed_white_moves.clear();

    for (int i = 0; i < chess_board.size(); i++)
    {
        for (int j = 0; j < chess_board[0].size(); j++)
        {
            if (chess_board[i][j] == 0)
                continue;

            else if (chess_board[i][j] % 10 == 1){
                if(chess_board[i][j]/10==1)allowed_white_moves[(i * 10) + j] = find_Pawn_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==2)allowed_white_moves[(i * 10) + j] = find_Rook_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==3)allowed_white_moves[(i * 10) + j] = find_Knigth_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==4)allowed_white_moves[(i * 10) + j] = find_Bishop_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==5)allowed_white_moves[(i * 10) + j] = find_Queen_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
                if(chess_board[i][j]/10==6)allowed_white_moves[(i * 10) + j] = find_King_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
            }

        }
    }
}

void move_piece(std::vector<std::vector<int>> &chess_board, int start, int stop)
{
    chess_board[stop / 10][stop % 10] = chess_board[start / 10][start % 10];
    chess_board[start / 10][start % 10] = 00;
}

bool is_black_checked(int black_king_position, std::unordered_map<int, std::vector<int>> &allowed_white_moves)
{
    for (const auto &pair : allowed_white_moves)
    {
        auto it = std::find(allowed_white_moves[pair.first].begin(), allowed_white_moves[pair.first].end(), black_king_position);
        if (it != allowed_white_moves[pair.first].end())
            return true;
    }
    return false;
}
bool is_white_checked(int white_king_position, std::unordered_map<int, std::vector<int>> &allowed_black_moves)
{
    for (const auto &pair : allowed_black_moves)
    {
        auto it = std::find(allowed_black_moves[pair.first].begin(), allowed_black_moves[pair.first].end(), white_king_position);
        if (it != allowed_black_moves[pair.first].end())
            return true;
    }
    return false;
}

bool is_white_king_safe(int start, int stop, std::vector<std::vector<int>> chess_board)
{
    // std::cout << "s";
    move_piece(chess_board, start, stop);
    int king_position = white_king_position;
    std::unordered_map<int, std::vector<int>> allowed_black_moves;
    check_only_black_moves(allowed_black_moves, chess_board);
    if (is_white_checked(king_position, allowed_black_moves))
        return false;
    return true;
}

bool is_black_king_safe(int start, int stop, std::vector<std::vector<int>> chess_board)
{
    // std::cout << "a";
    move_piece(chess_board, start, stop);
    int king_position = black_king_position;
    std::unordered_map<int, std::vector<int>> allowed_white_moves;
    check_only_white_moves(allowed_white_moves, chess_board);
    if (is_black_checked(king_position, allowed_white_moves))
        return false;
    return true;
}

void is_pawn_en_passant(int start, int stop, std::vector<int> selected_moves, std::vector<std::vector<int>> &chess_board)
{
    int i = start / 10;
    int j = start % 10;
    if (chess_board[i][j] == 12)
    {
        if ((((i + 2) * 10) + (j)) == stop)
        {
            en_passant_position = stop;
            if (j + 1 < 8)
            {
                int a = stop / 10;
                int b = stop % 10;
                b++;

                if (chess_board[a][b] % 10 != chess_board[i][j] % 10 && chess_board[a][b] / 10 == 1)
                {

                    possible_en_passant_pawn1 = ((a * 10) + (b));
                }
            }
            if (j - 1 >= 0)
            {
                int a = stop / 10;
                int b = stop % 10;
                b -= 1;

                if (chess_board[a][b] % 10 != chess_board[i][j] % 10 && chess_board[a][b] / 10 == 1)
                {
                    possible_en_passant_pawn2 = ((a * 10) + (b));
                }
            }
        }
        int a = stop / 10;
        int b = stop % 10;
        if (start == possible_en_passant_pawn1 || start == possible_en_passant_pawn2)
        {
            if (stop / 10 == (en_passant_position / 10 + 1) && stop % 10 == en_passant_position % 10)
            {
                chess_board[en_passant_position / 10][en_passant_position % 10] = 00;
                en_passant_position = 99;
                possible_en_passant_pawn1 = 99;
                possible_en_passant_pawn2 = 99;
            }
        }
    }
    if (chess_board[i][j] == 11)
    {
        if ((((i - 2) * 10) + (j)) == stop)
        {
            en_passant_position = stop;
            if (j + 1 < 8)
            {
                int a = stop / 10;
                int b = stop % 10;
                b++;

                if (chess_board[a][b] % 10 != chess_board[i][j] % 10 && chess_board[a][b] / 10 == 1)
                {

                    possible_en_passant_pawn1 = ((a * 10) + (b));
                }
            }
            if (j - 1 >= 0)
            {
                int a = stop / 10;
                int b = stop % 10;
                b -= 1;

                if (chess_board[a][b] % 10 != chess_board[i][j] % 10 && chess_board[a][b] / 10 == 1)
                {
                    possible_en_passant_pawn2 = ((a * 10) + (b));
                }
            }
        }
        int a = stop / 10;
        int b = stop % 10;
        if (start == possible_en_passant_pawn1 || start == possible_en_passant_pawn2)
        {
            if (stop / 10 == (en_passant_position / 10 - 1) && stop % 10 == en_passant_position % 10)
            {
                std::cout << "switch" << std::endl;
                chess_board[en_passant_position / 10][en_passant_position % 10] = 00;
                en_passant_position = 99;
                possible_en_passant_pawn1 = 99;
                possible_en_passant_pawn2 = 99;
            }
        }
    }
}