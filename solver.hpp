#ifndef SOLVER_H
#define SOLVER_H

#include "SteepestDescent.hpp"
#include "moveGenerator.hpp"

struct Solver{
    template<typename TBoard>
    auto static constexpr SolveOneStep(TBoard&& board)
    {
        auto moves = GenerateMoves(board);
        using outputType = typename std::optional<decltype(*(moves.begin))>;

        return SteepestDescent::FindLowest(
                board,
                moves.begin,
                moves.end);
    }
};

#endif
