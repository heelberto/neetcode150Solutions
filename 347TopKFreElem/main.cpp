#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> nums = {1,1,1,2,2,3};

std::vector<int> topKFreqElem(std::vector<int> &nums, int k);

int main(){

    std::vector<int> vec;
    vec = topKFreqElem(nums,2);

    return 0;
}

std::vector<int> topKFreqElem(std::vector<int> &nums, int k){

    //first create an unordered map with the key being the value
    //and the value for that key corresponding to the count/amount of times
    //that key occurs
    std::unordered_map<int,int> m;
    for(int i = 0;i<nums.size();i++){
        m[nums[i]]++;
    }

    //now we bucket the elements by frequency 
    //we have a for loop through the map
    //remember the m{value,value's count}
    //it->second would keep a list of the values that occurs that amount of times
    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for(auto it = m.begin();it != m.end();it++){
        buckets[it->second].push_back(it->first);
    }

    //then we build the result vector
    //the for loop is running the length of the input array
    //since even if each value in the input array is distinct
    //the most amount of occurences for that one distinct value
    //is the size of the input array. we also work back to front
    //since we want the 'top k' occurences
    //
    //once our results vector is >= k then we can break out of the 
    //for loop and return it
    //
    //if we haven't gotten the top k occurences, and the current bucket we are
    //looking at is not empty, we will insert to the end of the result vector
    //the list of values that occur that amount of times
    std::vector<int> result;
    for(int i =nums.size(); i>=0;i--){
        if(result.size() >= k)
            break;
        if(!buckets[i].empty()){
            result.insert(result.end(),buckets[i].begin(),buckets[i].end());
        }
    }

    return result;


    /*
    //printing out map that holds the num of occurences for each count
    for(const auto& pair:m){
        std::cout<<"the value: " << pair.first << " occurs: " << pair.second << " times" << std::endl;
    }
    */
}