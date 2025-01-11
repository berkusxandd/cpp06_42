#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>
#include "Data.hpp"
class Serializer
{
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t rawData);
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &rhs);
    
};

#endif