#include <algorithm>
#include <vector>
#include <iostream>

void display(std::vector<std::vector<int>> vects) {
	//display 2D-Array after manipulation
	for (auto vect : vects) {
		std::copy(vect.begin(), vect.end(), std::ostream_iterator<long>(std::cout, "\t"));
		std::cout << std::endl;
	}
	std::cout << "\n\n\n";
}

void display(std::vector<long> vect) {
	std::copy(vect.begin(), vect.end(), std::ostream_iterator<long>(std::cout, "\t"));
}

long long int arrayManipulation(int n, std::vector<std::vector<int>> queries) {
	std::vector<long long int> result(n + 1);
	for (auto q : queries) {
		if (q.size() > 2) {

			auto a = *q.begin() - 1;
			auto b = *(q.begin() + 1);
			auto k = *(q.begin() + 2);

			*(result.begin() + a) += k;
			*(result.begin() + b) += -k;
		}
	}

	for (auto index = 1; index <= n; index++)
		result.at(index) += result.at(index - 1);

	return *max_element(result.begin(), result.end());
}

int main() {
	std::vector<std::vector<int>> queries{
		{ 5 , 3 },
		{ 1 , 2 , 100 },
		{ 2 , 5 , 100 },
		{ 3 , 4 , 100 }
	};

	std::cout << "Result : " << arrayManipulation(queries.at(0).at(0), queries) << std::endl;
	
	return 0;
}
