#include <dac7718.hpp>
#include <monitor_option_register.hpp>

namespace DAC7718 {

template<> MonitorPacket::Packet(bool rw, Register::Monitor data)
{
    m_rwbit = rw;
    m_addr = AddressType::Reg::MONITOR;
    m_data = std::move(data);
}

namespace Register {

Monitor::Monitor() { m_bits = std::bitset<WIDTH>{0b000000000000}; }

Monitor::Monitor(Preset reg) 
{
    switch(reg)
    {
        case Preset::DISABLED:
            m_bits = std::bitset<WIDTH>{0b000000000000};
            break;
        case Preset::REFB_BUFFER:
            m_bits = std::bitset<WIDTH>{0b000000000001};
            break;
        case Preset::REFA_BUFFER:
            m_bits = std::bitset<WIDTH>{0b000000000010};
            break;
        case Preset::OFFSET_DACB:
            m_bits = std::bitset<WIDTH>{0b000000000101};
            break;
        case Preset::OFFSET_DACA:
            m_bits = std::bitset<WIDTH>{0b000000000110};
            break;
        case Preset::AIN0:
            m_bits = std::bitset<WIDTH>{0b000000000100};
            break;
        case Preset::AIN1:
            m_bits = std::bitset<WIDTH>{0b000000001000};
            break;
        case Preset::DAC0:
            m_bits = std::bitset<WIDTH>{0b000000010000};
            break;
        case Preset::DAC1:
            m_bits = std::bitset<WIDTH>{0b000000100000};
            break;
        case Preset::DAC2:
            m_bits = std::bitset<WIDTH>{0b000001000000};
            break;
        case Preset::DAC3:
            m_bits = std::bitset<WIDTH>{0b000010000000};
            break;
        case Preset::DAC4:
            m_bits = std::bitset<WIDTH>{0b000100000000};
            break;
        case Preset::DAC5:
            m_bits = std::bitset<WIDTH>{0b001000000000};
            break;
        case Preset::DAC6:
            m_bits = std::bitset<WIDTH>{0b010000000000};
            break;
        case Preset::DAC7:
            m_bits = std::bitset<WIDTH>{0b100000000000};
            break;
    };
}

} // namespace Register
} // namespace DAC7718 