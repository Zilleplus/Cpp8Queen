#ifndef STEEPESTDESCENT_H
#define STEEPESTDESCENT_H

#include "variantOverload.hpp"
#include<optional>

struct SteepestDescent{
        template<typename TMoveIterator,typename TBoard>
        auto static FindLowest(TBoard&& board, TMoveIterator begin, TMoveIterator end)
        {
            using outputType = typename std::optional<decltype(*begin)>;

            auto bestSolution = outputType{};
            auto bestCost = cost(board);

            // This while loop could be done paralel
            while(!(begin==end))
            {
                auto potentialSolution = *begin;
                auto potentialBestCost = cost(potentialSolution);
                if(potentialBestCost < bestCost)
                {
                    bestSolution = outputType{potentialSolution};
                    bestCost = bestCost;
                }
                ++begin;
            }

            return bestSolution;
        }
};

#endif 

