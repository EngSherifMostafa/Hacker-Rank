#include <iostream>
#include <vector>

std::vector<int> dynamicArray(int n, std::vector<std::vector<int>> queries) {

    int lastAnswer = 0;
    int x = 0, y = 0;
    std::vector<int> result;
    std::vector<std::vector<int>> seqList(n);

    for (auto seq : queries) {
        if (seq.size() > 2) {
            auto queryType = seq.front();
            x = *(seq.begin() + 1);
            y = seq.back();

            if (queryType == 1)
                seqList.at(((x ^ lastAnswer) % n)).push_back(y);

            else if (queryType == 2) {
                result.push_back(seqList.at(((x ^ lastAnswer) % n)).at((y % seqList.at(((x ^ lastAnswer) % n)).size())));
                lastAnswer = seqList.at(((x ^ lastAnswer) % n)).at((y % seqList.at(((x ^ lastAnswer) % n)).size()));
            }
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