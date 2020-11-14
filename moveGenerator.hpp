template <typename TBoard>
class MoveGenerator {
    static constexpr int sizeBoard = TBoard::size;
    const TBoard& board;
    //TAlgo& algo;

   public:
    MoveGenerator(const TBoard& board)
        : board(board){}

    static constexpr int maxEmptySpotIndex =
        (sizeBoard * sizeBoard) - sizeBoard;
    // call's the picker with potential moves
    template<typename TAlgo>
    void generate(TAlgo& algo) const {
        for (auto queenIndex = 0; queenIndex < sizeBoard; ++queenIndex) {
            for (auto spotIndex = 0; spotIndex < sizeBoard; ++spotIndex) {
                auto queenCollumn =
                    queenIndex;  // Keep all the queens on their own collumn.
                auto move = MoveOperation(queenIndex, queenCollumn, spotIndex);
                algo.take(move);
            }
        }
    }
};
