#include <iostream>
#include <string>
#include <cstdlib>
int main()
{
    std::string str = "42.2f";
    char *floatRes;
    float a = strtof(str.c_str(), &floatRes);

    std::cout << a << std::endl;
    std::cout << floatRes << std::endl;
}