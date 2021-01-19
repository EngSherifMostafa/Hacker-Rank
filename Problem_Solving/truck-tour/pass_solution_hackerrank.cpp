#include <iostream>
#include <vector>

/*
 * Complete the truckTour function below.
 */
int truckTour(vector<vector<int>> petrolpumps) {
    auto acc_fuel = 0;
    auto position = 0;

    for (auto i = 0; i < petrolpumps.size(); i++) {
        acc_fuel += petrolpumps.at(i).at(0) - petrolpumps.at(i).at(1);

        if (acc_fuel < 0) {
            acc_fuel = 0;
            position = i + 1;
        }
    }
    return position;
}