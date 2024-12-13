#ifndef __DAC7718_GPIO_DATA_REGISTER_HPP__
#define __DAC7718_GPIO_DATA_REGISTER_HPP__

#include <abstract_register.hpp>

namespace DAC7718 {
namespace Register {

class GeneralPurposeIO : public Internal::AbstractDataRegister
{
public:
    enum class Gpio0Bit { 
        HIGH = 1,  // hi-z in when write bit is set, default
        LOW = 0
    };

    enum class Gpio1Bit { 
        HIGH = 1,  // hi-z in when write bit is set, default
        LOW = 0
    };

    enum class Gpio2Bit { 
        HIGH = 1,  // hi-z in when write bit is set, default
        LOW = 0
    };

    GeneralPurposeIO(Gpio2Bit gpio_2 = Gpio2Bit::HIGH, 
                     Gpio1Bit gpio_1 = Gpio1Bit::HIGH, 
                     Gpio0Bit gpio_0 = Gpio0Bit::HIGH);

    std::bitset<WIDTH> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }

    // data bit mutators
    void set(Gpio2Bit opt);
    void set(Gpio1Bit opt);
    void set(Gpio0Bit opt);

};

} // namespace Register
} // namespace DAC7718

#endif //__DAC7718_GPIO_DATA_REGISTER_HPP__