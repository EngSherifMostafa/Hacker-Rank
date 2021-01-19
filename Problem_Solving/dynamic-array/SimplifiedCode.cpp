#include <iostream>
#include <vector>
#include <iterator>
void queryOne(const int, const int, const int, std::vector<std::vector<int>>&, const int);
int queryTwo(const int, int&, const int, const std::vector<std::vector<int>>, const int);
std::vector<int> dynamicArray(int, std::vector<std::vector<int>>);

int calIndex(int x, int lastAnswer, int n) {
	return ((x ^ lastAnswer) % n);
}

void queryOne(const int x, const int lastAnswer, const int n, std::vector<std::vector<int>>& seqList, const int y) {
	int index = calIndex(x, lastAnswer, n);
	seqList.at(index).push_back(y);
}

int queryTwo(const int x, int& lastAnswer, const int n, const std::vector<std::vector<int>> seqList, const int y) {
	int outerIndex = calIndex(x, lastAnswer, n);

	int innerIndex = (y % seqList.at(outerIndex).size());

	lastAnswer = seqList.at(outerIndex).at(innerIndex);

	return lastAnswer;
}

std::vector<int> dynamicArray(int n, std::vector<std::vector<int>> queries) {
	int lastAnswer = 0;
	int x = 0, y = 0;
	std::vector<int> result;
	std::vector<std::vector<int>> seqList(n);

	for (auto seq : queries)
	{
		if (seq.size() > 2)
		{
			auto queryType = seq.front();
			x = *(seq.begin() + 1);
			y = seq.back();

			if (queryType == 1)
				queryOne(x, lastAnswer, n, seqList, y);

			else if (queryType == 2)
				result.push_back(queryTwo(x, lastAnswer, n, seqList, y));
		}
	}
	return result;
}

int main() {
    int n = 2;
    std::vector<std::vector<int>> queries{
        { 2 , 5 },
        { 1 , 0 , 5 },
        { 1 , 1 , 7 },
        { 1 , 0 , 3 },
        { 2 , 1 , 0 },
        { 2 , 1 , 1 }
    };

    auto result = dynamicArray(n, queries);

    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
}