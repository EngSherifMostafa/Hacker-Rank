#include <iostream>
#include <vector>

std::vector<int> reverseArray(std::vector<int> a) {

	reverse(a.begin(), a.end());
	return a;
}

int main() {

	auto result = reverseArray({ 1 , 2 , 3 , 4 });

	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout));
	return 0;
}