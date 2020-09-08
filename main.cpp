#include<string>
#include<iostream>
#include"board.hpp"
#include"BoardOperations.hpp"
#include"SteepestDescent.hpp"
#include"solver.hpp"

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

void DemoMove()
{
    qn::Board<3> b{qn::Queen{0,0},qn::Queen{1,1},qn::Queen{2,2}};
    print(b);
    std::cout << "move the second queen to [0,1]" << std::endl;
    auto moveBoard = b | qn::MoveOperation(1,0,1);
    print(moveBoard);
}

int main(){

    std::cout << "Running 3 queens demo: steepest descent" << std::endl;
    qn::Board<3> b{qn::Queen{0,0},qn::Queen{1,1},qn::Queen{2,2}};
    auto solution = Solver::SolveOneStep(b);

    print(b);
}
