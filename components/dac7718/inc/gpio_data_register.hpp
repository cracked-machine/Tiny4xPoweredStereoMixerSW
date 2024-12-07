#ifndef __DAC7718_GPIO_DATA_REGISTER_HPP__
#define __DAC7718_GPIO_DATA_REGISTER_HPP__

#include <base_data_register.hpp>

namespace DAC7718 {
namespace GPIO {
namespace Bit {

enum class GPIO0 { 
    HIGH = 1,  // hi-z in when write bit is set, default
    LOW = 0
};

enum class GPIO1 { 
    HIGH = 1,  // hi-z in when write bit is set, default
    LOW = 0
};

enum class GPIO2 { 
    HIGH = 1,  // hi-z in when write bit is set, default
    LOW = 0
};


} // namespace Bit

class Reg : public BaseDataRegister
{
public: 
    Reg(Bit::GPIO2 gpio_2 = Bit::GPIO2::HIGH, 
        Bit::GPIO1 gpio_1 = Bit::GPIO1::HIGH, 
        Bit::GPIO0 gpio_0 = Bit::GPIO0::HIGH)
    {
        m_bits.set( 11, static_cast<bool>(gpio_2) );        // DB15
        m_bits.set( 10, static_cast<bool>(gpio_1) );        // DB14
        m_bits.set( 9, static_cast<bool>(gpio_0) );        // DB13        
    }

    std::bitset<WIDTH> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }

    // data bit mutators
    void set(Bit::GPIO2 opt) { m_bits.set( 11, static_cast<bool>(opt) ); }
    void set(Bit::GPIO1 opt) { m_bits.set( 10, static_cast<bool>(opt) ); }
    void set(Bit::GPIO0 opt) { m_bits.set( 9, static_cast<bool>(opt) ); }

};

} // namespace GPIO
} // namespace DAC7718

#endif //__DAC7718_GPIO_DATA_REGISTER_HPP__