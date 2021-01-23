#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

void get_input(std::vector<std::vector<int>> &input) {
    int N = 0, M = 0;
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
    for(auto array_index = 0 ; array_index < N ; array_index++)
        std::cin >> input.at(1).at(array_index);
    
    //queries vectors -> M at vector(2)
    for(auto query_index = 2 ; query_index < M + 2 ; query_index++) {
        input.at(query_index).resize(3);
        std::cin >> input.at(query_index).at(0); //query type
        std::cin >> input.at(query_index).at(1); //start range i
        std::cin >> input.at(query_index).at(2); //end range j
    }
}

void display(std::vector<std::vector<int>> towD_vector) {
    //display 2D-vector after input
	for(auto vect : towD_vector) {
		std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout));
		std::cout << std::endl;
	}
}


int main() {
    std::vector<std::vector<int>> input;
    
    get_input(input);
    display(input);




    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}