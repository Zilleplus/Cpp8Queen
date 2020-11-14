#include<string>
#include<optional>
#include<iostream>
#include<optional>
#include<sstream>
#include<type_traits>

namespace qn{
#include "board.hpp"
#include "boardOperations.hpp"
#include "moveGenerator.hpp"
#include "views.hpp"
#include "applier.hpp"
#include "algo.hpp"
#include "solver.hpp"
}

template<typename TBoard,int size = std::remove_reference_t<TBoard>::size>
void print(const TBoard& board)
{
    for (int i=0;i<size;++i)
    {
        for (int j=0;j<size;++j)
        {
            if(qn::hasQueen(board,i,j))
            {
                std::cout << "x";
            }
            else
            {
                std::cout << ".";
            }
        } 
        std::cout << std::endl;
    }
}

int main(){
    std::cout << "Running 8 queens demo: steepest descent" << std::endl;
    using TBoard = typename qn::Board<8>;
    TBoard b{
        qn::Queen{0,0},
        qn::Queen{1,0},
        qn::Queen{2,0},
        qn::Queen{3,0},
        qn::Queen{4,0},
        qn::Queen{5,0},
        qn::Queen{6,0},
        qn::Queen{7,0}
    };

    bool cont = true;
    constexpr int maxSteps = 1000;
    int i = 0;
    while(cont && i < maxSteps)
    {
        auto step = qn::Solver::SolveOneStep(b);
        i++;
        if(step.has_value())
        {
            auto bestMove = *step;
            qn::View<TBoard, decltype(bestMove)> newBoard(b, bestMove);

            std::cout << "Selected new move improving the cost from:"
                << std::to_string(cost(b)) 
                << " to: " 
                << std::to_string(cost(newBoard))
                << std::endl;
            qn::Applier<TBoard, qn::MoveOperation>::apply(b, bestMove);
        }
    }
    cont = false;

    print(b);
}
