#include <InitialRosterManager.hpp>
#include <Objective.hpp>
#include <MoveGenerator.hpp>

#include <iostream>
#include <list>
#include <algorithm>
#include <execution>

using namespace Rosterer;

int main(int argc, char** argv) {
    std::list<Solution*> tabuList = std::list<Solution*>();

    Solution bestSolution = InitialRosterManager::instance().getInitialSolution();
    Solution bestCandidate = InitialRosterManager::instance().getInitialSolution();

    tabuList.push_back(&bestCandidate);

    for (int day = 0; day < InitialRosterManager::instance().getNbrDaysOptimized(); day++) {
        std::cout << "Day " << day << ": daytime: " << InitialRosterManager::instance().getAllStaff().at(bestSolution.getDaytimeRoster().at(day)) << ", nighttime: " << InitialRosterManager::instance().getAllStaff().at(bestSolution.getNighttimeRoster().at(day)) << std::endl;
    }

    std::cout << "initial cost: " << bestSolution.getCost() <<  std::endl;

    int maxIterations = 50;
    int iterations = 0;
    while(iterations < maxIterations) {
        std::vector<Solution> neighborhood = MoveGenerator::generateNeighborhood(bestCandidate);
        std::cout << "neighborhood size: " << neighborhood.size() << ", best cost: ";
        bestCandidate = neighborhood.front();
   
        std::vector<Solution*> nonTabuNeighborhood = std::vector<Solution*>();
        for (std::vector<Solution>::iterator candidateIt = neighborhood.begin(); candidateIt != neighborhood.end(); ++candidateIt) {
            bool candidateTabu = false;
            for (std::list<Solution*>::const_iterator tabuIt = tabuList.begin(); tabuIt != tabuList.end(); ++tabuIt) {
                if ((*tabuIt)->getID() == candidateIt->getID()) {
                    candidateTabu = true;
                    break;
                }
            }
            if (!candidateTabu) {
                nonTabuNeighborhood.push_back(&*candidateIt);
            }
        }

        if (nonTabuNeighborhood.size() == 0) {
            std::cout << "N/A - All solutions tabu. Exiting." << std::endl;
            break;
        }

        std::vector<Solution*> nonTabuCostedNeighborhood = std::vector<Solution*>(nonTabuNeighborhood.size(), NULL);
        std::transform(std::execution::par_unseq, nonTabuNeighborhood.begin(), nonTabuNeighborhood.end(), nonTabuCostedNeighborhood.begin(), [](Solution* sol) {
            sol->getCost();
            return sol;
        });

        std::sort(std::execution::par_unseq, nonTabuNeighborhood.begin(), nonTabuNeighborhood.end(), [](Solution* left, Solution* right) {
            return left->getCost() > right->getCost();
        });

        if (nonTabuNeighborhood.back()->getCost() < bestCandidate.getCost()) {
            bestCandidate = *nonTabuNeighborhood.back();
        }

        if (bestCandidate.getCost() < bestSolution.getCost()) {
            bestSolution = bestCandidate;
        }

        tabuList.push_back(&bestCandidate);

        if (tabuList.size() > 5) {
            tabuList.pop_front();
        }

        std::cout << bestSolution.getCost() << std::endl;

        iterations++;
    }

    for (int day = 0; day < InitialRosterManager::instance().getNbrDaysOptimized(); day++) {
        std::cout << "Day " << day << ": daytime: " << InitialRosterManager::instance().getAllStaff().at(bestSolution.getDaytimeRoster().at(day)) << ", nighttime: " << InitialRosterManager::instance().getAllStaff().at(bestSolution.getNighttimeRoster().at(day)) << std::endl;
    }
}