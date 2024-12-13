#include <spimode_option_register.hpp>

namespace DAC7718 {
namespace Register {

SpiMode::SpiMode(Preset preset)
{
    switch(preset)
    {
        case Preset::NORMAL:
            m_bits = std::bitset<SpiMode::WIDTH>{0b000000000000};
            break;
        case Preset::SLEEP:
            m_bits = std::bitset<SpiMode::WIDTH>{0b100000000000};
            break;
    };
}

} // namespace Registers
} // namespace DAC7718