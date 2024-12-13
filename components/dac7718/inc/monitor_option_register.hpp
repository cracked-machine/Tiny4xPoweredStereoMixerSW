#ifndef __DAC7718_MONITOR_DATA_REGISTER_HPP__
#define __DAC7718_MONITOR_DATA_REGISTER_HPP__

#include <abstract_register.hpp>

namespace DAC7718 {
namespace Register {

class Monitor : public Internal::AbstractDataRegister
{
public:
    enum class Preset
    {
        DISABLED,
        REFB_BUFFER,
        REFA_BUFFER,
        OFFSET_DACB,
        OFFSET_DACA,
        AIN0,
        AIN1,
        DAC0,
        DAC1,
        DAC2,
        DAC3,
        DAC4,
        DAC5,
        DAC6,
        DAC7,
    };
    Monitor(Preset reg = Preset::DISABLED);
    
    std::bitset<WIDTH> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }
};

} // namespace Register
} // namespace DAC7718

#endif // __DAC7718_MONITOR_DATA_REGISTER_HPP__