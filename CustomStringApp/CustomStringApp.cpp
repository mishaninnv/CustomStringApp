#include <iostream>
#include <vector>
#include <algorithm>
#include "string.h"

int main()
{
    std::vector<Custstr::String> strings;

    std::cout << "Enter a list of strings (one word no more than 100 characters) (type 'end' to finish):" << std::endl;

    char input[100];
    while (true) {
        std::cin.getline(input, sizeof(input));
        if (strcmp(input, "end") == 0) {
            break;
        }
        strings.push_back(Custstr::String(input));
    }

    std::sort(strings.begin(), strings.end(), [](const Custstr::String& str1, const Custstr::String& str2) {
        char lowerStr1[100];
        char lowerStr2[100];
        strcpy_s(lowerStr1, str1.Length() + 1, str1.CStr());
        strcpy_s(lowerStr2, str2.Length() + 1, str2.CStr());
        for (int i = 0; i < strlen(lowerStr1); ++i) {
            lowerStr1[i] = tolower(lowerStr1[i]);
        }
        for (int i = 0; i < strlen(lowerStr2); ++i) {
            lowerStr2[i] = tolower(lowerStr2[i]);
        }
        return strcoll(lowerStr1, lowerStr2) > 0;
        });

    std::cout << "The strings in reverse lexicographical order are:" << std::endl;
    for (const auto& str : strings) {
        std::cout << str.CStr() << std::endl;
    }

    return 0;
}