#include "headers.hpp"
// std::vector<int> find_moves(std::vector<std::vector<int>> chess_board,int position,int type);
bool is_white_king_safe(int start, int stop, std::vector<std::vector<int>> chess_board);
bool is_black_king_safe(int start, int stop, std::vector<std::vector<int>> chess_board);
int en_passant_position = 99;
int possible_en_passant_pawn1 = 99;
int possible_en_passant_pawn2 = 99;
std::vector<int> find_moves(std::vector<std::vector<int>> &chess_board, int position, int type, bool king_eval)
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
                    std::cout << "stuff" << std::endl;
                    allowed_moves.push_back((((i + 1) * 10) + (j - 1)));
                }
            }
            else if (en_passant_position % 10 > j)
            {
                if (i > 0 && (chess_board[i][j] % 10) == 0 && king_eval && is_black_king_safe(position, (((i + 1) * 10) + (j + 1)), chess_board))
                {
                    allowed_moves.push_back((((i + 1) * 10) + (j + 1)));
                    std::cout << "stuff" << std::endl;
                }
            }
        }
        i++;
        if (i > 0 && (chess_board[i][j] % 10) == 0 && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
        if (i > 0 && (chess_board[i][j] % 10) == 0 && !king_eval)
            allowed_moves.push_back(((i * 10) + j));

        i++;
        if (i - 2 == 1 && ((chess_board[i][j] % 10) == 0) && king_eval && is_black_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
        if (i - 2 == 1 && ((chess_board[i][j] % 10) == 0) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));
    }

    if (type == 11)
    {
        if (position == possible_en_passant_pawn1 || position == possible_en_passant_pawn2)
        {
            if (en_passant_position % 10 < j)
            {
                std::cout << "move" << std::endl;
                bool bullshit = is_black_king_safe(position, (((i - 1) * 10) + (j - 1)), chess_board);

                if (i > 0 && king_eval && is_black_king_safe(position, (((i - 1) * 10) + (j - 1)), chess_board))
                {
                    allowed_moves.push_back((((i - 1) * 10) + (j - 1)));
                    std::cout << "stuff" << std::endl;
                }
            }
            else if (en_passant_position % 10 > j)
            {
                std::cout << "move" << std::endl;
                bool bullshit = is_black_king_safe(position, (((i - 1) * 10) + (j - 1)), chess_board);

                if (i > 0 && king_eval && is_black_king_safe(position, (((i - 1) * 10) + (j + 1)), chess_board))
                {
                    allowed_moves.push_back((((i - 1) * 10) + (j + 1)));
                    std::cout << "stuff" << std::endl;
                }
            }
        }
        i--;
        if (i < 8 && (chess_board[i][j] % 10) == 0 && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
        if (i < 8 && (chess_board[i][j] % 10) == 0 && !king_eval)
            allowed_moves.push_back(((i * 10) + j));
        i--;
        if (i + 2 == 6 && ((chess_board[i][j] % 10) == 0) && king_eval && is_white_king_safe(position, ((i * 10) + j), chess_board))
            allowed_moves.push_back(((i * 10) + j));
        if (i + 2 == 6 && ((chess_board[i][j] % 10) == 0) && !king_eval)
            allowed_moves.push_back(((i * 10) + j));
    }

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

    if (type == 52)
    {
        std::vector<int> inserted_moves = find_moves(chess_board, ((i * 10) + j), 22, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
        inserted_moves = find_moves(chess_board, ((i * 10) + j), 42, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
    }
    if (type == 51)
    {
        std::vector<int> inserted_moves = find_moves(chess_board, ((i * 10) + j), 21, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
        inserted_moves = find_moves(chess_board, ((i * 10) + j), 41, king_eval);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
    }

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

void check_only_black_moves(std::unordered_map<int, std::vector<int>> &allowed_black_moves, std::vector<std::vector<int>> &chess_board)
{
    allowed_black_moves.clear();

    for (int i = 0; i < chess_board.size(); i++)
    {
        for (int j = 0; j < chess_board[0].size(); j++)
        {
            if (chess_board[i][j] == 0)
                continue;

            else if (chess_board[i][j] % 10 == 2)
                allowed_black_moves[(i * 10) + j] = find_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
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

            else if (chess_board[i][j] % 10 == 1)
                allowed_white_moves[(i * 10) + j] = find_moves(chess_board, ((i * 10) + j), (chess_board[i][j]), false);
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
            if (j + 1 < 8 )
            {
                int a = stop / 10;
                int b = stop % 10;
                b++;

                if (chess_board[a][b] % 10 != chess_board[i][j] % 10 && chess_board[a][b] / 10 == 1)
                {

                    possible_en_passant_pawn1 = ((a * 10) + (b));
                }
                
            }
            if (j - 1 >= 0){
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
            if (j + 1 < 8 )
            {
                int a = stop / 10;
                int b = stop % 10;
                b++;

                if (chess_board[a][b] % 10 != chess_board[i][j] % 10 && chess_board[a][b] / 10 == 1)
                {

                    possible_en_passant_pawn1 = ((a * 10) + (b));
                }
                
            }
            if (j - 1 >= 0){
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