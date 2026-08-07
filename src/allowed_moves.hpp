#include "headers.hpp"

void check(std::unordered_map<int, std::vector<int>> &allowed_moves, std::vector<std::vector<int>> chess_board){
    for(int i=0;i<chess_board.size();i++){
        for(int j=0;j<chess_board[0].size();j++){
            if(chess_board[i][j]==0)continue;
            find_moves(allowed_moves, chess_board,((i*10)+j),(chess_board[i][j]));
        }
    }

}

void find_moves(std::vector<int> &allowed_moves, std::vector<std::vector<int>> chess_board,int position,int type){
        int i=position/10;
        int j=position%10;

        if(type==10){
            if(i>0)i++;
            allowed_moves.push_back(((i*10)+j));
        }
        if(type==11){
            if(i<8)i--;
            allowed_moves.push_back(((i*10)+j));
        }

        if( type==40 || type== 41){
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                i+=1;
                j+=1;
                allowed_moves.push_back(((i*10)+j));
            }
            i=position/10;
            j=position%10;
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                i-=1;
                j+=1;
                allowed_moves.push_back(((i*10)+j));
            }
            i=position/10;
            j=position%10;
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                i+=1;
                j-=1;
                allowed_moves.push_back(((i*10)+j));
            }
            i=position/10;
            j=position%10;
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                i-=1;
                j-=1;
                allowed_moves.push_back(((i*10)+j));
            }
        }

        if( type==30 || type== 31){
            i+=2;
            j+=1;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));


            i=position/10;
            j=position%10;
            i+=2;
            j-=1;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));


            i=position/10;
            j=position%10;
            i-=2;
            j+=1;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));


            i=position/10;
            j=position%10;
            i-=2;
            j-=1;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));


            i=position/10;
            j=position%10;
            i+=1;
            j+=2;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));


            i=position/10;
            j=position%10;
            i-=1;
            j+=2;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));


            i=position/10;
            j=position%10;
            i+=1;
            j-=2;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));


            i=position/10;
            j=position%10;
            i-=1;
            j-=2;
            if(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10))allowed_moves.push_back(((i*10)+j));

        }

        if( type==20 || type== 21){
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                i+=1;
                allowed_moves.push_back(((i*10)+j));
            }
            i=position/10;
            j=position%10;
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                i-=1;
                allowed_moves.push_back(((i*10)+j));
            }
            i=position/10;
            j=position%10;
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                j+=1;
                allowed_moves.push_back(((i*10)+j));
            }
            i=position/10;
            j=position%10;
            while(i<8 && i<8 && i>0 && j>0 && ((chess_board[i][j]%10)!=type%10)){
                j-=1;
                allowed_moves.push_back(((i*10)+j));
            }
        }

        if(type==50 || type== 51){
            find_moves();
        }
}