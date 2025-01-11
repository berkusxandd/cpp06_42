#include <string>
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"
int main()
{
    Data *data = new Data("dataStr", 42);
    std::cout << "Data initialized with" << std::endl << "string: " << data->getStr() <<std::endl << "value: " << data->getVal() << std::endl << std::endl;
    uintptr_t rawData = Serializer::serialize(data);
    std::cout << "Raw data: " << rawData << std::endl;
    Data *deserializedData = Serializer::deserialize(rawData);
    if (deserializedData == data)
        std::cout << "Serialization is succesful" << std::endl << std::endl;
    else
        std::cout << "Serialization failed" << std::endl << std::endl;

    std::cout << "Deserialized data string : " << deserializedData->getStr() << " value : " << deserializedData->getVal() << std::endl;
    delete data;
}