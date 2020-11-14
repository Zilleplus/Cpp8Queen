template <typename TMove, typename TBoard>
class SteepestDescent {
    std::optional<TMove> bestMove;
    double bestCost = std::numeric_limits<double>::infinity(); // this should be last cost
    const TBoard& board;

    public:
    SteepestDescent(
            double lastCost,
            const TBoard& board)
        :board(board), bestCost(lastCost){}
    
    bool take(const TMove& move) noexcept
    {
        // Check if the move is accepted as final move.
        auto viewNewMove = View<TBoard, TMove>(board , move);

        auto newCost = cost(viewNewMove);
        if( newCost < bestCost)
        {
            bestMove = std::optional<TMove>(move);
            bestCost = newCost;
        }
        return false; // keep searching for the best solution.
    }

    std::optional<TMove> move() const {return bestMove;}
};
