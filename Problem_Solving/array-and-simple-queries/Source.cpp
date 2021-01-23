#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void display(const std::vector<std::vector<int>>& towD_vector) {
    //display 2D-vector after input
    for (auto vect : towD_vector) {
        std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout));
        std::cout << std::endl;
    }
}

void display(const std::vector<int>& arr) {
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
}

void get_input(std::vector<std::vector<int>>& input) {
	auto N = 0, M = 0;
    std::cin >> N; //N as number of elements in array at vector(1)
    std::cin >> M; //M as number of queries from vector(2) to vector(M + 2)

    //M + 2 -> number of queries + first vector of (N , M) & second vector of array elements
    input.resize(M + 2);

    input.at(0).resize(2);
    input.at(1).resize(N);

    //set N & M at vector(0)
    input.at(0).at(0) = N;
    input.at(0).at(1) = M;

    //array elements -> N at vector(1)
    for (auto array_index = 0; array_index < N; array_index++)
        std::cin >> input.at(1).at(array_index);

    //queries vectors -> M at vector(2)
    for (auto query_index = 2; query_index < M + 2; query_index++) {
        input.at(query_index).resize(3);
        std::cin >> input.at(query_index).at(0); //query type
        std::cin >> input.at(query_index).at(1); //start range i
        std::cin >> input.at(query_index).at(2); //end range j
    }
}

//remove from i to j and add them at front
//index start from 1
//range is inclusive
void query_one(std::vector<int>& arr, const int& i, const int& j, const int& arr_size) {
    auto start = i - 1;
    auto stop = j - 1;
    auto swap_at = 1;
    arr.resize(arr.size() + start, -1);

	//send all elements after end_rng to new space at end of arr
    for (auto to_end = arr_size - 1; to_end > stop; to_end--, swap_at++)
        std::swap(arr.at(to_end), *(arr.end() - swap_at));

    //send all elements start from index 0 to index (start - 1) to after start index
    swap_at = 1;
    for (auto spec_index = 0; spec_index < start; spec_index++, swap_at++)
        std::swap(arr.at(spec_index), arr.at(stop + swap_at));

    for (auto itr = arr.begin(); itr != arr.end();) {
        if (*itr != -1) break;
        arr.erase(itr);
        itr = arr.begin();
    }
}

//remove from i to j and add them at back
//index start from 1
//range is inclusive
void query_two(std::vector<int>& arr, const int& i, const int& j) {
    for (auto start = i - 1; start < j; start++) {
        arr.emplace_back(arr.at(start));
        arr.at(start) = -1;
    }

    for (auto itr = arr.begin(); itr != arr.end();) {
        if (*itr != -1) {
            ++itr;
            continue;
        }
	
        arr.erase(itr);
        itr = arr.begin();
    }
}

int main() {
    std::vector<std::vector<int>> input
    {
        { 8 , 4 },
        { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 },
        { 1 , 2 , 4 },
        { 2 , 3 , 5 },
    	{ 1 , 4 , 7 },
    	{ 2 , 1 , 4 }
    };

    //get_input(input);

    for (unsigned int vect_index = 2; vect_index < input.size(); vect_index++) {
        //apply query one
        if (input.at(vect_index).at(0) == 1)
            query_one(input.at(1), input.at(vect_index).at(1), input.at(vect_index).at(2), input.at(1).size());

        //apply query two
        else if (input.at(vect_index).at(0) == 2)
            query_two(input.at(1), input.at(vect_index).at(1), input.at(vect_index).at(2));

        else
            break;
    }

    std::cout << abs(input.at(1).front() - input.at(1).back()) << std::endl;
	display(input.at(1));

    return 0;
}
