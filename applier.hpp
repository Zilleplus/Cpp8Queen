template <typename TBoard, typename TMoveOperation>
struct Applier;

template <typename TBoard>
struct Applier<TBoard, qn::MoveOperation> {
    static void apply(TBoard& board, qn::MoveOperation& move) {
        board.setQueen(move.queenIndex, move.x, move.y);
    }
};

