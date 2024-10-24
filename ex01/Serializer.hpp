#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <cstdint>
#include "Data.hpp"

class Serializer{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& rhs);

        Serializer& operator=(const Serializer& rhs);
    public:
        static uintptr_t	serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};
#endif