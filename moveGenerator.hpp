#include"BoardOperations.hpp"

namespace qn{

    template<typename TBoard, int sizeBoard = std::remove_reference_t<TBoard>::size>
    class MoveForwardIterator{
        TBoard board;
        int queenIndex;
        int emptySpotIndex;

        public:
            static constexpr int maxEmptySpotIndex = (sizeBoard* sizeBoard) - sizeBoard;
            MoveForwardIterator(TBoard&& board) : board(board), queenIndex(0),emptySpotIndex(0)
            {
            }

            MoveForwardIterator(TBoard&& board, int queenIndex,int emptySpotIndex) 
                : board(board), queenIndex(queenIndex),emptySpotIndex(emptySpotIndex)
            {
            }

            MoveForwardIterator(MoveForwardIterator<TBoard> other) :
                board(other.board),
                queenIndex(other.queenIndex),
                emptySpotIndex(other.emptySpotIndex)
            {
            }

            bool operator==(const MoveForwardIterator<TBoard> other)
            {
                return other.emptySpotIndex == emptySpotIndex
                    && other.queenIndex == queenIndex;
            }


            auto operator*()
            {
                auto x = emptySpotIndex % sizeBoard;
                auto y = emptySpotIndex / sizeBoard;
                return board | MoveOperation(queenIndex,x,y);
            }

            void operator++()
            {
                emptySpotIndex++;
                if(emptySpotIndex == maxEmptySpotIndex)
                {
                    emptySpotIndex = 0;
                    queenIndex++;
                }
            }
    };

    template<typename TBoard>
    struct MoveIteratorPair{
        MoveForwardIterator<TBoard> begin;
        MoveForwardIterator<TBoard> end;
    };

    template<
         typename TBoard,
         int sizeBoard = std::remove_reference_t<TBoard>::size>
    static constexpr auto GenerateMoves(TBoard&& board)
    {
        return MoveIteratorPair<TBoard>{
                MoveForwardIterator<TBoard>(board),
                MoveForwardIterator<TBoard>(board,sizeBoard,0)};
    }
}
