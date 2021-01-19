#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<int> reverseArray(std::vector<int> a) {
	std::reverse(a.begin(), a.end());
	return a;
}

int main() {
	auto result = reverseArray({ 1 , 2 , 3 , 4 });

	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout));
	return 0;
}