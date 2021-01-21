#include <iostream>
#include <vector>

std::vector<int> matchingStrings(std::vector<std::string> strings, std::vector<std::string> queries) {
	std::vector<int> result;
	auto count = 0;
	
	for (auto query : queries) {
		for (auto str : strings) {
			if (query == str)
				count++;
		}
			result.push_back(count);
			count = 0;
	}

	return result;
}


int main() {
	std::vector<std::string> strings{
		{ "aba"  },
		{ "baba" },
		{ "aba"  },
		{ "xzxb" }
	};

	std::vector<std::string> queries{
		{ "aba"  },
		{ "xzxb" },
		{ "ab"   }
	};

	auto result = matchingStrings(strings, queries);

	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, "\n"));
	
	return 0;
}