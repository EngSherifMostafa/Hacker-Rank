#include <iostream>
#include <vector>

int truckTour(std::vector<std::vector<int>> petrolpumps) {
    auto acc_fuel = 0;
    auto position = 0;

    for (auto i = 1; i < petrolpumps.size(); i++) {
        acc_fuel += petrolpumps.at(i).at(0) - petrolpumps.at(i).at(1);

        if (acc_fuel < 0) {
            acc_fuel = 0;
            position = i;
        }
    }
    return position;
}


int main() {
	// ( amount of petrol , distance from that petrol pump )  
	const std::vector<std::vector<int>> petrolpumps{
			{ 3 },
			{ 1 , 5 },
			{ 10 , 3 },
			{ 3 , 4 }
    };

    std::cout << "Start tour from pump : " << truckTour(petrolpumps) << std::endl;
    return 0;
}