#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
    public:
        Data();
        Data(std::string str, int value);
        ~Data();
        Data(Data const &src);
        Data &operator=(Data const &rhs);
        std::string getStr() const;
        int getVal() const;
    private:
        std::string _str;
        int _value;
    
};

#endif