template <typename TBoard, typename TMove>
class View;

template <typename TBoard>
class View<TBoard, MoveOperation> {
    const TBoard& board;  // unmodified board
    const MoveOperation& move;

   public:
    static constexpr int size = TBoard::size;

    constexpr View(const TBoard& board, const MoveOperation& move)
        : board(board), move(move) {}

    constexpr Queen operator[](int index) const {
        if (index == move.queenIndex) {
            return Queen{move.x, move.y};
        }
        return board[index];
    }
};
