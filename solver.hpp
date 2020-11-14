struct Solver {
    template <typename TBoard>
    auto static SolveOneStep(const TBoard& board) {
        auto currentCost = cost(board);

        SteepestDescent<MoveOperation, TBoard> algo(currentCost, board);

        MoveGenerator gen(board);

        gen.generate(algo);

        return algo.move();
    }
};
