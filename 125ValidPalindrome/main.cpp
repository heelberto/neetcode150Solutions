#include <iostream>
#include <string>
#include <algorithm>

bool alNum(char &c);

int main()
{

    std::string s = "A man, a plan, a canal: Panama";
    std::string cleanString = "";
    std::string reverseString = "";

    // create cleanString with new memory
    /*
    for (int i = 0; i < s.size(); i++)
    {
        if (alNum(s[i]))
            cleanString += tolower(s[i]);
    }
    */

    // reverse the string manually
    /*
    for (int i = s.size(); i > 0; i--)
    {
        reverseString += cleanString[i];
    }
    */

    /*
    // reverse the string using .reverse()
    // here we reverse cleanString w/o taking up any new memory
    // therefore cleanstring will hold the string in reverse
    // and reversestring will hold the initial correct way string
    reverseString = cleanString;
    std::reverse(cleanString.begin(), cleanString.end());
    */

    char *leftPointer = &s[0];
    char *rightPointer = &s[s.size()];

    while (leftPointer < rightPointer)
    {
        while ((leftPointer < rightPointer) && (!alNum(*leftPointer)))
        {
            leftPointer++;
        }
        while ((rightPointer > leftPointer) && (!alNum(*rightPointer)))
        {
            rightPointer--;
        }
        if ((tolower(*leftPointer)) != (tolower(*rightPointer)))
        {
            std::cout << "Not a Palindrome" << std::endl;
            return 1;
        }
        leftPointer++;
        rightPointer--;
    }
    std::cout << "Is a Palindrome" << std::endl;

    /*
    // palindrome test
    if (cleanString == reverseString)
        std::cout << "True is a palindrome";
    else
        std::cout << "Not a palindrome";
    */

    return 0;
}

bool alNum(char &c)
{
    return ((int('A') <= int(c) && int(c) <= int('Z')) ||
            (int('a') <= int(c) && int(c) <= int('z')) ||
            (int('0') <= int(c) && int(c) <= int('9')));
}