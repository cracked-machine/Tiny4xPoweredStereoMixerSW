#include <dac7718.hpp>
#include <gpio_option_register.hpp>

namespace DAC7718 {
namespace Register {

GeneralPurposeIO::GeneralPurposeIO(Gpio2Bit gpio_2, Gpio1Bit gpio_1, Gpio0Bit gpio_0)
{
    m_bits.set( 11, static_cast<bool>(gpio_2) );        // DB15
    m_bits.set( 10, static_cast<bool>(gpio_1) );        // DB14
    m_bits.set( 9, static_cast<bool>(gpio_0) );        // DB13        
}

// data bit mutators
void GeneralPurposeIO::set(Gpio2Bit opt) { m_bits.set( 11, static_cast<bool>(opt) ); }
void GeneralPurposeIO::set(Gpio1Bit opt) { m_bits.set( 10, static_cast<bool>(opt) ); }
void GeneralPurposeIO::set(Gpio0Bit opt) { m_bits.set( 9, static_cast<bool>(opt) ); }

} // Register
} // namespace DAC7718 
