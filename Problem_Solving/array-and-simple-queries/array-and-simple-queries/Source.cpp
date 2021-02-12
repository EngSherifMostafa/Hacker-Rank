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
    //resize vector(0) { N , M }
	input.at(0).resize(2);
	
    std::cin >> input.at(0).at(0); //N as number of elements in array at vector(1)
    std::cin >> input.at(0).at(1); //M as number of queries from vector(2) to vector(M + 2)

	//resize vector(1) { array elements }
    input.at(1).resize(input.at(0).at(0));
	
    //input.at(0).at(1) + 2 -> number of queries ( M ) + vector(0) of { N , M } & vector(1) of  { array elements }
    input.resize(input.at(0).at(1) + 2);

    //array elements -> N at vector(1)
    for (auto array_index = 0; array_index < input.at(0).at(0); array_index++)
        std::cin >> input.at(1).at(array_index);

    //queries vectors -> M at vector(2)
    for (auto query_index = 2; query_index < input.at(0).at(1) + 2; query_index++) {
        input.at(query_index).resize(3);
        std::cin >> input.at(query_index).at(0); //query type
        std::cin >> input.at(query_index).at(1); //start range i
        std::cin >> input.at(query_index).at(2); //end range j
    }
}

//remove from i to j and add them at front
//index start from 1
//range is inclusive
void query_one(std::vector<int>& arr, const int& i, const int& j) {
    //elements already at begin
    if (i == 1) return;

	auto step = 0;
	std::vector<int> temp(arr.size());

	//assign elements in first position
    for (auto start = i - 1; start < j; start++, step++)
        *(temp.begin() + step) = arr.at(start);

	//assign elements in middel position
    for (auto b_start = 0; b_start < i - 1; b_start++, step++)
        *(temp.begin() + step) = arr.at(b_start);

	//assign elements at last position
    for (auto a_start = j; a_start < arr.size(); a_start++, step++)
        *(temp.begin() + step) = arr.at(a_start);

	//assign temp to original array
    arr = temp;	
}

//remove from i to j and add them at back
//index start from 1
//range is inclusive
void query_two(std::vector<int>& arr, const int& i, const int& j) {
    //elements already at end
	if (j == arr.size()) return;

	for (auto start = i - 1; start < j; start++)
        arr.emplace_back(arr.at(start));

	//remove elements from i to j Note: second parameter in erase method will not deleted
    arr.erase(arr.begin() + i - 1, arr.begin() + j);
}

int main() {
    std::vector<std::vector<int>> input(2);
    //{
    //    { 8 , 4 },
    //    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 },
    //    { 1 , 2 , 4 },
    //    { 2 , 3 , 5 },
    //	{ 1 , 4 , 7 },
    //	{ 2 , 1 , 4 }
    //};

    get_input(input);

    for (unsigned int vect_index = 2; vect_index < input.size(); vect_index++) {
        //apply query one
        if (input.at(vect_index).at(0) == 1)
            query_one(input.at(1), input.at(vect_index).at(1), input.at(vect_index).at(2));

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