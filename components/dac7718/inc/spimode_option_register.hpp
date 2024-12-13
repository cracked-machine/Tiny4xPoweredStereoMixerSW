#ifndef __SPIMODE_OPTION_REGISTER_HPP__
#define __SPIMODE_OPTION_REGISTER_HPP__

#include <abstract_register.hpp>

namespace DAC7718 {
namespace Register {

class SpiMode : public Internal::AbstractDataRegister
{
public:

    // The list of Registers
    enum class Preset 
    { 
        NORMAL,
        SLEEP
    };

    SpiMode(Preset preset = Preset::NORMAL);
    
    std::bitset<WIDTH> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }
};

} // namespace Register
} // namespace DAC7718



#endif // __SPIMODE_OPTION_REGISTER_HPP__