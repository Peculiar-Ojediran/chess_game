#include "headers.hpp"
bool is_white_king_safe(int start, int stop, std::vector<std::vector<int>> chess_board);
bool is_black_king_safe(int start, int stop, std::vector<std::vector<int>> chess_board);
int en_passant_position = 99;
int possible_en_passant_pawn1 = 99;
int possible_en_passant_pawn2 = 99;
std::vector<int> find_Pawn_moves(std::vector<std::vector<int>> &chess_board, int position, int type, bool king_eval)
{
    int i = position / 10;
    int j = position % 10;
    std::vector<int> allowed_moves;

    if (type == 12)
    {
        if (position == possible_en_passant_pawn1 || position == possible_en_passant_pawn2)
        {
            if (en_passant_position % 10 < j)
            {
                if (i > 0 && (chess_board[i][j] % 10) == 0 && king_eval && is_black_king_safe(position, (((i + 1) * 10) + (j - 1)), chess_board))
                {

                    allowed_moves.push_back((((i + 1) * 10) + (j - 1)));
                }
            }
            else if (en_passant_position % 10 > j)
            {
                if (i > 0 && (chess_board[i][j] % 10) == 0 && king_eval && is_black_king_safe(position, (((i + 1) * 10) + (j + 1)), chess_board))
                {
                    allowed_moves.push_back((((i + 1) * 10) + (j + 1)));
                }
            }
        }
         if (i + 1 <8 && j + 1 < 8 && king_eval)
        {

            if (chess_board[i + 1][j + 1] % 10 == 1 && is_black_king_safe(position, (((i + 1) * 10) + (j + 1)), chess_board)){
                allowed_moves.push_back((((i + 1) * 10) + (j + 1)));

            }
        }
        if (i + 1 <8 && j - 1 >=0 && king_eval)
        {

           if (chess_board[i + 1][j - 1] % 10 == 1 && is_black_king_safe(position, (((i + 1) * 10) + (j - 1)), chess_board)){
                allowed_moves.push_back((((i + 1) * 10) + (j - 1)));
           }
            
        }
         if (i + 1 <8 && j + 1 < 8 && !king_eval)
        {

            allowed_moves.push_back((((i + 1) * 10) + (j + 1)));

        
        }
        if (i + 1 <8 && j - 1 >=0 && !king_eval)
        {

           
            allowed_moves.push_back((((i + 1) * 10) + (j - 1)));

            
        }
        i++;
        if (i >= 0 && i < 8 && (chess_board[i][j] % 10) == 0 && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
        

        i++;
        if (i - 2 == 1 && ((chess_board[i][j] % 10) == 0) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
       
    }

    if (type == 11)
    {
        if (position == possible_en_passant_pawn1 || position == possible_en_passant_pawn2)
        {
            if (en_passant_position % 10 < j)
            {

                

                if (i > 0 && king_eval && is_white_king_safe(position, (((i - 1) * 10) + (j - 1)), chess_board))
                {
                    allowed_moves.push_back((((i - 1) * 10) + (j - 1)));
                }
            }
            else if (en_passant_position % 10 > j)
            {

                

                if (i > 0 && king_eval && is_white_king_safe(position, (((i - 1) * 10) + (j + 1)), chess_board))
                {
                    allowed_moves.push_back((((i - 1) * 10) + (j + 1)));
                    std::cout << "stuff" << std::endl;
                }
            }
        }
        if (i - 1 >= 0 && j + 1 < 8 && king_eval)
        {

            if (chess_board[i - 1][j + 1] % 10 == 2 && is_white_king_safe(position, (((i - 1) * 10) + (j + 1)), chess_board)){
                allowed_moves.push_back((((i - 1) * 10) + (j + 1)));

            }
        }
        if (i - 1 >= 0 && j - 1 >=0 && king_eval)
        {

            if (chess_board[i - 1][j - 1] % 10 == 2 && is_white_king_safe(position, (((i - 1) * 10) + (j - 1)), chess_board)){
                allowed_moves.push_back((((i - 1) * 10) + (j - 1)));

            }
        }
        if (i - 1 >= 0 && j + 1 < 8 && !king_eval)
        {

          
            allowed_moves.push_back((((i - 1) * 10) + (j + 1)));

            
        }
        if (i - 1 >= 0 && j - 1 >=0 && !king_eval)
        {

            
            allowed_moves.push_back((((i - 1) * 10) + (j - 1)));

            
        }
        i--;
        if (i >= 0 && i < 8 && (chess_board[i][j] % 10) == 0 && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
       
        i--;
        if (i + 2 == 6 && ((chess_board[i][j] % 10) == 0) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
       
    }
    return allowed_moves;
}
std::vector<int> find_Rook_moves(std::vector<std::vector<int>> &chess_board, int position, int type, bool king_eval)
{
    int i = position / 10;
    int j = position % 10;
    std::vector<int> allowed_moves;
    if (type == 22 || type == 21)
    {

        i += 1;
        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 22)
            {
                if (king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 21)
            {
                if (king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            i += 1;
        }

        i = position / 10;
        j = position % 10;
        i -= 1;

        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 22)
            {
                if (king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 21)
            {
                if (king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            i -= 1;
        }

        i = position / 10;
        j = position % 10;
        j += 1;

        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 22)
            {
                if (king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 21)
            {
                if (king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            j += 1;
        }

        i = position / 10;
        j = position % 10;
        j -= 1;

        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 22)
            {
                if (king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 21)
            {
                if (king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            j -= 1;
        }
    }
    return allowed_moves;
}
std::vector<int> find_Knigth_moves(std::vector<std::vector<int>> &chess_board, int position, int type, bool king_eval)
{
    int i = position / 10;
    int j = position % 10;
    std::vector<int> allowed_moves;
    if (type == 31 || type == 32)
    {

        i += 2;
        j += 1;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 2;
        j -= 1;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
            ;
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 2;
        j += 1;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 2;
        j -= 1;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j += 2;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j += 2;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
            ;
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j -= 2;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j -= 2;
        if (type == 32)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 31)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));
    }
    return allowed_moves;
}
std::vector<int> find_Bishop_moves(std::vector<std::vector<int>> &chess_board, int position, int type, bool king_eval)
{
    int i = position / 10;
    int j = position % 10;
    std::vector<int> allowed_moves;
    if (type == 42 || type == 41)
    {

        i += 1;
        j += 1;
        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 42 && king_eval)
            {
                if (is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 41 && king_eval)
            {
                if (is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            i += 1;
            j += 1;
        }
        i = position / 10;
        j = position % 10;
        i -= 1;
        j += 1;
        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 42 && king_eval)
            {
                if (is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 41 && king_eval)
            {
                if (is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            i -= 1;
            j += 1;
        }
        i = position / 10;
        j = position % 10;
        i += 1;
        j -= 1;
        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 42 && king_eval)
            {
                if (is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 41 && king_eval)
            {
                if (is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            i += 1;
            j -= 1;
        }
        i = position / 10;
        j = position % 10;
        i -= 1;
        j -= 1;
        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
            if (type == 42 && king_eval)
            {
                if (is_black_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if (type == 41 && king_eval)
            {
                if (is_white_king_safe(position, ((i * 10) + j), chess_board))
                    ;
                else
                    break;
            }
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            i -= 1;
            j -= 1;
        }
    }
    return allowed_moves;
}
std::vector<int> find_Queen_moves(std::vector<std::vector<int>> &chess_board, int position, int type, bool king_eval)
{
    int i = position / 10;
    int j = position % 10;
    std::vector<int> allowed_moves;
    if (type == 52)
    {
        std::vector<int> inserted_moves = find_Rook_moves(chess_board, ((i * 10) + j), 22, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
        inserted_moves = find_Bishop_moves(chess_board, ((i * 10) + j), 42, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
    }
    if (type == 51)
    {
        std::vector<int> inserted_moves = find_Rook_moves(chess_board, ((i * 10) + j), 21, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
        inserted_moves = find_Bishop_moves(chess_board, ((i * 10) + j), 41, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
    }
    return allowed_moves;
}
std::vector<int> find_King_moves(std::vector<std::vector<int>> &chess_board, int position, int type, bool king_eval)
{
    int i = position / 10;
    int j = position % 10;
    std::vector<int> allowed_moves;

    if (type == 62 || type == 61)
    {
        i += 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        j += 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        j -= 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j += 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j += 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j -= 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j -= 1;
        if (type == 62)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (type == 61)
        {
            if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
                allowed_moves.push_back(((i * 10) + j));
        }
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));
    }
    return allowed_moves;
}