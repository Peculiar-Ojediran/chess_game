#include "headers.hpp"

int main(){
    std::unordered_map<int,std::string> chess_pieces;
    chess_pieces [1] = "pawns";
    chess_pieces [2] = "Rook";
    chess_pieces [3] = "knigth";
    chess_pieces [4] = "bishop";
    chess_pieces [5] = "queen";
    chess_pieces [6] = "king";

    std::vector<std::vector<int>> chess_board ={{20,30,40,50,60,40,30,20},
                                                {10,10,10,10,10,10,10,10},
                                                {00,00,00,00,00,00,00,00},
                                                {00,00,00,00,00,00,00,00},
                                                {00,00,00,00,00,00,00,00},
                                                {00,00,00,00,00,00,00,00},
                                                {11,11,11,11,11,11,11,11},
                                                {21,31,41,51,61,41,31,21}
                                                };
    
    for(int i=0;i<chess_board.size();i++){
        for(int j=0;j<chess_board[0].size();j++){
            std::cout<<chess_board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }


}