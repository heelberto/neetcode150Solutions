#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

bool isValid(std::string s);

int main()
{

    std::vector<std::string> inputStrings{"()", "(){}[]", "(]"};

    std::cout << std::boolalpha; // turns printed bool values into 'true/false' instead of 0/1
    for (int i = 0; i < inputStrings.size(); i++)
    {
        std::cout << "isValid(" << inputStrings[i] << ") returns: " << isValid(inputStrings[i]) << std::endl;
    }

    return 0;
}

bool isValid(std::string s)
{
    std::map<char, char> closeToOpen{
        {')', '('},
        {'}', '{'},
        {']', '['}};
    std::stack<char, std::vector<char>> stack;

    for (char c : s)
    {
        if (auto search = closeToOpen.find(c); search != closeToOpen.end())
        {
            if (!stack.empty() && stack.back())
        }
        else
        {
        }
    }
}