#include <MoveGenerator.hpp>

#include <InitialRosterManager.hpp>

using namespace Rosterer;

std::vector<Solution> MoveGenerator::generateNeighborhood(const Solution& startSolution) {
    std::vector<Solution> generatedNeighborhood = std::vector<Solution>();

    // generate swaps of full weeks
    int firstMondayIdx = InitialRosterManager::instance().getFirstSundayIdx() + 1;

    int week1Offs = 0;
    for (int monday1Idx = InitialRosterManager::instance().getFirstSundayIdx() + 1; monday1Idx < InitialRosterManager::instance().getNbrDaysOptimized(); monday1Idx += 7) {
        int week2Offs = 0;
        for (int monday2Idx = InitialRosterManager::instance().getFirstSundayIdx() + 1; monday2Idx < InitialRosterManager::instance().getNbrDaysOptimized(); monday2Idx += 7) {
            std::vector<int> nextNighttimeRoster = startSolution.getNighttimeRoster();
            std::vector<int> nextDaytimeRoster = startSolution.getDaytimeRoster();

            swapWeeks(nextNighttimeRoster, week1Offs, week2Offs, firstMondayIdx);
            swapWeeks(nextDaytimeRoster, week1Offs, week2Offs, firstMondayIdx);

            Solution nextSolution = Solution(std::move(nextNighttimeRoster), std::move(nextDaytimeRoster));

            // TODO check infeasibilities

            generatedNeighborhood.push_back(nextSolution);

            week2Offs++;
        }
        week1Offs++;
    }

    return generatedNeighborhood;
}

void MoveGenerator::swapWeeks(std::vector<int>& roster, int week1Offs, int week2Offs, int initSkip) {
    for (int dayOffs = 0; dayOffs < 7; dayOffs++) {
        swapDays(roster, dayOffs, week1Offs, week2Offs, initSkip);
    }
}

void MoveGenerator::swapDays(std::vector<int>& roster, int dayOffs, int week1Offs, int week2Offs, int initSkip) {
    std::swap(roster.at(initSkip + (week1Offs * 7) + dayOffs), roster.at(initSkip + (week2Offs * 7) + dayOffs));
}