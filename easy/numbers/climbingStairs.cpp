/**
 * 70. Climbing Stairs
 * 
 * You are climbing a staircase. It takes 'p_steps' steps to reach the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 */

#include <unordered_map>
#include <iostream>

void fillStairsMap(std::unordered_map<int, int>& p_stairsMap, int p_currentStep, int p_steps)
{
    // makes current step, key for map entry
    std::pair<int, int> mapEntry;
    mapEntry.first = p_currentStep;

    // base cases
    if (p_currentStep == 0 || p_currentStep == 1) {
        mapEntry.second = 1;
    }
    // makes sum of previous two entrys, value for map entry
    else {
        mapEntry.second = p_stairsMap.at(p_currentStep - 1) + p_stairsMap.at(p_currentStep - 2);
    }

    p_stairsMap.insert(mapEntry);

    // next step
    if (p_currentStep + 1 <= p_steps) {
        fillStairsMap(p_stairsMap, p_currentStep + 1, p_steps);
    }
}

int climbStairs(int p_steps)
{
    // sets up map with base cases
    std::unordered_map<int, int> p_stairsMap = { { 0, 1 }, { 1, 1 } };
    fillStairsMap(p_stairsMap, 0, p_steps);
    return p_stairsMap.at(p_steps);
}

int main(void)
{
    std::cout << climbStairs(2) << "\n";
    std::cout << climbStairs(3) << "\n";
}
