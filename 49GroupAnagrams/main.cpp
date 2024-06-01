#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string getKey(std::string str);

int main(){

    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat","better"};
    std::unordered_map<std::string,std::vector<std::string>> m;

    for(int i = 0;i<strs.size();i++)
    {
        std::string key = getKey(strs[i]);
        m[key].push_back(strs[i]);
    }

    std::vector<std::vector<std::string>> result;
    for(auto it = m.begin();it != m.end();it++)
    {
        result.push_back(it->second);
    }
    
    //printing theh contents of the essentially a 2d vector
    for (const auto& row : result) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

std::string getKey(std::string str)
{
    
    //the vector count represents the alphabet
    std::vector<int> count(26);

    //run through the length of the string passed in
    //for each letter the string passed in contains
    //the number of those letters is increased by 1
    for(int j = 0;j<str.size();j++)
    {
        count[str[j] - 'a']++;
    }

    std::string key = "";

    //for loop to build the key
    //if the letter occurs atleast once, it is added to the key
    //count[i] will hold the number of times that letter
    //occurs in the string that is passed in
    //while (char)('a'+i) typecasts to the corresponding letter
    for(int i = 0;i<count.size();i++)
    {
        if (count[i] > 0) 
        {
            key += std::to_string(count[i]) + (char)('a' + i);
        }
        
    }
    return key;
}