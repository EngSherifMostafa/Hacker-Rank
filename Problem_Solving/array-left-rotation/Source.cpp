#include <iostream>
#include <vector>

std::vector<int> rotateLeft(int d, std::vector<int> arr) {
	while (d != 0) {
		arr.resize(arr.size() + 1);
		arr.back() = arr.front();
		arr.erase(arr.begin());
		d--;
	}

	return arr;
}

int main() {
	auto result = rotateLeft(2, { 1 , 2 , 3 , 4 , 5 });

	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, "\n"));

	return 0;
}