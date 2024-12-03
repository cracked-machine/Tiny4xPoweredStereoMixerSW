#ifndef __DAC7718_MONITOR_DATA_REGISTER_HPP__
#define __DAC7718_MONITOR_DATA_REGISTER_HPP__

#include <base_data_register.hpp>

namespace DAC7718 {
namespace Monitor {

class Data : public BaseDataRegister
{
public:
    enum class Reg
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
    Data() { m_bits = std::bitset<SIZE>{0b000000000000}; }
    Data(Reg reg) 
    {
        switch(reg)
        {
            case Reg::DISABLED:
                m_bits = std::bitset<SIZE>{0b000000000000};
                break;
            case Reg::REFB_BUFFER:
                m_bits = std::bitset<SIZE>{0b000000000001};
                break;
            case Reg::REFA_BUFFER:
                m_bits = std::bitset<SIZE>{0b000000000010};
                break;
            case Reg::OFFSET_DACB:
                m_bits = std::bitset<SIZE>{0b000000000101};
                break;
            case Reg::OFFSET_DACA:
                m_bits = std::bitset<SIZE>{0b000000000110};
                break;
            case Reg::AIN0:
                m_bits = std::bitset<SIZE>{0b000000000100};
                break;
            case Reg::AIN1:
                m_bits = std::bitset<SIZE>{0b000000001000};
                break;
            case Reg::DAC0:
                m_bits = std::bitset<SIZE>{0b000000010000};
                break;
            case Reg::DAC1:
                m_bits = std::bitset<SIZE>{0b000000100000};
                break;
            case Reg::DAC2:
                m_bits = std::bitset<SIZE>{0b000001000000};
                break;
            case Reg::DAC3:
                m_bits = std::bitset<SIZE>{0b000010000000};
                break;
            case Reg::DAC4:
                m_bits = std::bitset<SIZE>{0b000100000000};
                break;
            case Reg::DAC5:
                m_bits = std::bitset<SIZE>{0b001000000000};
                break;
            case Reg::DAC6:
                m_bits = std::bitset<SIZE>{0b010000000000};
                break;
            case Reg::DAC7:
                m_bits = std::bitset<SIZE>{0b100000000000};
                break;
        };
    }
    std::bitset<SIZE> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }
};

} // namespace MonitorData
} // namespace DAC7718

#endif // __DAC7718_MONITOR_DATA_REGISTER_HPP__