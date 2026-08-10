#include "headers.hpp"
// std::vector<int> find_moves(std::vector<std::vector<int>> chess_board,int position,int type);
std::vector<int> find_moves(std::vector<std::vector<int>> &chess_board, int position, int type)
{
    int i = position / 10;
    int j = position % 10;
    std::vector<int> allowed_moves;

    if (type == 12)
    {
        i++;
        if (i > 0 && (chess_board[i][j] % 10) == 0)
            allowed_moves.push_back(((i * 10) + j));

        i++;
        if (i - 2 == 1 && ((chess_board[i][j] % 10) == 0))
            allowed_moves.push_back(((i * 10) + j));
    }
    if (type == 11)
    {
        i--;
        if (i < 8 && (chess_board[i - 1][j] % 10) == 0)
            allowed_moves.push_back(((i * 10) + j));
        i--;
        if (i + 2 == 6 && ((chess_board[i - 1][j] % 10) == 0))
            allowed_moves.push_back(((i * 10) + j));
    }

    if (type == 42 || type == 41)
    {
        i += 1;
        j += 1;
        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
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
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 2;
        j -= 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 2;
        j += 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 2;
        j -= 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j += 2;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j += 2;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j -= 2;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j -= 2;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));
    }

    if (type == 22 || type == 21)
    {
        i += 1;
        while (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
        {
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
            if ((chess_board[i][j] % 10) != type % 10 && chess_board[i][j] % 10 != 0)
            {
                allowed_moves.push_back(((i * 10) + j));
                break;
            }
            allowed_moves.push_back(((i * 10) + j));
            j -= 1;
        }
    }

    if (type == 52 || type == 51)
    {
        std::vector<int> inserted_moves = find_moves(chess_board, ((i * 10) + j), 22);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
        inserted_moves = find_moves(chess_board, ((i * 10) + j), 42);
        allowed_moves.insert(allowed_moves.end(), inserted_moves.begin(), inserted_moves.end());
    }

    if (type == 62 || type == 61)
    {
        i += 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        j += 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        j -= 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j += 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j += 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i += 1;
        j -= 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));

        i = position / 10;
        j = position % 10;
        i -= 1;
        j -= 1;
        if (i < 8 && j < 8 && i >= 0 && j >= 0 && ((chess_board[i][j] % 10) != type % 10))
            allowed_moves.push_back(((i * 10) + j));
    }
    return allowed_moves;
}

void check(std::unordered_map<int, std::vector<int>> &allowed_white_moves, std::unordered_map<int, std::vector<int>> &allowed_black_moves, std::vector<std::vector<int>> &chess_board)
{
    for (int i = 0; i < chess_board.size(); i++)
    {
        for (int j = 0; j < chess_board[0].size(); j++)
        {
            if (chess_board[i][j] == 0)
                continue;

            else if (chess_board[i][j] % 10 == 2)
                allowed_black_moves[chess_board[i][j]] = find_moves(chess_board, ((i * 10) + j), (chess_board[i][j]));
            else if (chess_board[i][j] % 10 == 1)
                allowed_white_moves[chess_board[i][j]] = find_moves(chess_board, ((i * 10) + j), (chess_board[i][j]));
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