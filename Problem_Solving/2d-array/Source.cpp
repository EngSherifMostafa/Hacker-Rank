#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int hourglassSum(std::vector<std::vector<int>> arr) {
	auto index = 0;
	std::vector<int> hourglass(16);

	for (auto row = 0; row < 4; row++) {
		for (auto col = 0; col < 4; col++) {
			hourglass.at(index) =
				arr[row][col] + arr[row][col + 1] + arr[row][col + 2] +
				arr[row + 1][col + 1] +
				arr[row + 2][col] + arr[row + 2][col + 1] + arr[row + 2][col + 2];
			index++;
		}
	}

	sort(hourglass.begin(), hourglass.end(), std::greater<int>());

	return hourglass[0];
}

int main() {
	std::vector<std::vector<int>> arr = {
		{ -9 , -9 , -9 , 1 , 1 , 1 },
		{  0 , -9 ,  0 , 4 , 3 , 2 },
		{ -9 , -9 , -9 , 1 , 2 , 3 },
		{  0 ,  0 ,  8 , 6 , 6 , 0 },
		{  0 ,  0 ,  0 ,-2 , 0 , 0 },
		{  0 ,  0 ,  1 , 2 , 4 , 0 }
	};

	for (auto row = 0; row < 6; row++)
	{
		for (auto col = 0; col < 6; col++)
			std::cout << std::setw(4) << arr[row][col];
		std::cout << std::endl;
	}

	std::cout << "\nLargest hourglass = " << hourglassSum(arr) << std::endl;

	return 0;
}