/**
 * Takes a list of integers and a desired sum of two integers from the list. 
 * Returns the index of the numbers that add up to the desired number.
 * 
 * @author Arsalan Azmi
 * @version 1.0 16th April 2019
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//taks a vector of ints and an integer, returns a vector with the indices of the two numbers whose sum equals the target
vector<int> two_sum(vector<int>& numbers, int target)
{
    unordered_map<int, int> integer_map;
    vector<int> result;
    //check for each number
    for (unsigned int i = 0; i < numbers.size(); i++){
        //if the required number to make the sum is found in the hash
        if(integer_map.find(target - numbers[i]) != integer_map.end()){
            //push the indices
            result.push_back(integer_map[target - numbers[i]]);
            result.push_back(i);
            return result;
        }
        //add the number to the hash
        integer_map[numbers.at(i)] = i;
    }
    //return -1 if there is no such pair
    return {-1, -1};
}

int main(){
    vector<int> input = {11, -9 , 20 , 19 , 10 , 18};
    vector<int> result = two_sum(input, 9);
    cout << result.at(0) << "," << result.at(1);
}
