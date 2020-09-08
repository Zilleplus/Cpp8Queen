#include"board.hpp"
#include<type_traits>

#ifndef BOARDOPERATIONS_H
#define BOARDOPERATIONS_H

namespace qn{
    struct MoveOperation
    {
        const int queenIndex;
        const int x;
        const int y;
        MoveOperation(int queenIndex, int x,int y) :
            queenIndex(queenIndex) ,
            x(x),
            y(y)
        {}
    };

    template<typename TBoard>
    class QueenMove{
        TBoard board;
        const MoveOperation move;

        public:
            static constexpr int size = std::remove_reference_t<TBoard>::size;

            QueenMove(TBoard&& board,MoveOperation move) 
                : board(board), move(move) {}

            Queen operator[](int index) const
            {
                if(index == move.queenIndex)
                {
                    return Queen{move.x,move.y};
                }
                return board[index];
            }
    };

    template<
        typename TBoard, 
        int size = std::remove_reference_t<TBoard>::size>
    auto operator|(TBoard&& board, const MoveOperation op)
    {
        return QueenMove<TBoard>(board,op);
    }
}

#endif
