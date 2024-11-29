#ifndef __BITHELPER_HPP__
#define __BITHELPER_HPP__

#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

class BitHelper
{
public:
    BitHelper() = default;
    void run()
    {
        std::cout << "hello Bithelper!";
    }
};

#ifdef __cplusplus
}
#endif

#endif // __BITHELPER_HPP__