#ifndef __DAC7718_FIELDS_HPP__
#define __DAC7718_FIELDS_HPP__

#include <bitset>
#include <array>

#include <dac7718_iter.hpp>

namespace DAC7718 
{


// Singleton class provides forward/reverse lookup
// on member enum Reg/value
class AddressType
{
public:
    static const size_t SIZE{5};
    static const size_t OFFSET{16};

    // The list of Registers
    enum class Reg 
    { 
        CONFIG,
        MONITOR,
        GPIO,
        OFFSET_DAC_A,
        OFFSET_DAC_B,
        SPI_MODE,
        BROADCAST,
        DAC_0_DATA,
        DAC_1_DATA,
        DAC_2_DATA,
        DAC_3_DATA,
        DAC_4_DATA,
        DAC_5_DATA,
        DAC_6_DATA,
        DAC_7_DATA,
        ZERO_0,
        GAIN_0,
        ZERO_1,
        GAIN_1,
        ZERO_2,
        GAIN_2,
        ZERO_3,
        GAIN_3,
        ZERO_4,
        GAIN_4,
        ZERO_5,
        GAIN_5,
        ZERO_6,
        GAIN_6,
        ZERO_7,
        GAIN_7,
    };
    // Iterator needs to be given begin/end points, so you have to 
    // sync this end limit with the last entry in AddressType::Reg
    typedef EnumIterator<Reg, static_cast<Reg>(0), Reg::GAIN_7> Iter;

    static std::bitset<AddressType::SIZE> getval(Reg k) 
    { 
        // guarantee singleton creation
        [[maybe_unused]] static AddressType instance;

        switch(k)
        {
            case Reg::CONFIG:
                return std::bitset<AddressType::SIZE>{0b00000};
            case Reg::MONITOR:
                return std::bitset<AddressType::SIZE>{0b00001};
            case Reg::GPIO:
                return std::bitset<AddressType::SIZE>{0b00010};
            case Reg::OFFSET_DAC_A:
                return std::bitset<AddressType::SIZE>{0b00011};
            case Reg::OFFSET_DAC_B:
                return std::bitset<AddressType::SIZE>{0b00100};
            case Reg::SPI_MODE:
                return std::bitset<AddressType::SIZE>{0b00110};
            case Reg::BROADCAST:
                return std::bitset<AddressType::SIZE>{0b00111};
            case Reg::DAC_0_DATA:
                return std::bitset<AddressType::SIZE>{0b01000};
            case Reg::DAC_1_DATA:
                return std::bitset<AddressType::SIZE>{0b01001};
            case Reg::DAC_2_DATA:
                return std::bitset<AddressType::SIZE>{0b01010};
            case Reg::DAC_3_DATA:
                return std::bitset<AddressType::SIZE>{0b01011};
            case Reg::DAC_4_DATA:
                return std::bitset<AddressType::SIZE>{0b01100};
            case Reg::DAC_5_DATA:
                return std::bitset<AddressType::SIZE>{0b01101};
            case Reg::DAC_6_DATA:
                return std::bitset<AddressType::SIZE>{0b01110};
            case Reg::DAC_7_DATA:
                return std::bitset<AddressType::SIZE>{0b01111};
            case Reg::ZERO_0:
                return std::bitset<AddressType::SIZE>{0b10000};
            case Reg::GAIN_0:
                return std::bitset<AddressType::SIZE>{0b11000};
            case Reg::ZERO_1:
                return std::bitset<AddressType::SIZE>{0b10001};
            case Reg::GAIN_1:
                return std::bitset<AddressType::SIZE>{0b11001};
            case Reg::ZERO_2:
                return std::bitset<AddressType::SIZE>{0b10010};
            case Reg::GAIN_2:
                return std::bitset<AddressType::SIZE>{0b11010};
            case Reg::ZERO_3:
                return std::bitset<AddressType::SIZE>{0b10011};
            case Reg::GAIN_3:
                return std::bitset<AddressType::SIZE>{0b11011};
            case Reg::ZERO_4:
                return std::bitset<AddressType::SIZE>{0b10100};
            case Reg::GAIN_4:
                return std::bitset<AddressType::SIZE>{0b11100};
            case Reg::ZERO_5:
                return std::bitset<AddressType::SIZE>{0b10101};
            case Reg::GAIN_5:
                return std::bitset<AddressType::SIZE>{0b11101};
            case Reg::ZERO_6:
                return std::bitset<AddressType::SIZE>{0b10110};
            case Reg::GAIN_6:
                return std::bitset<AddressType::SIZE>{0b11110};
            case Reg::ZERO_7:
                return std::bitset<AddressType::SIZE>{0b10111};
            case Reg::GAIN_7:
                return std::bitset<AddressType::SIZE>{0b11111};
            default:
                // this line can never be called but keeps compiler warning quiet
                 __builtin_unreachable();
        } 
        // this line can never be called but keeps compiler warning quiet
        __builtin_unreachable();
    } 
    // Return a Reg depending on the U16 value given
    static Iter getReg(std::bitset<AddressType::SIZE> val)
    {
        // guarantee singleton creation
        [[maybe_unused]] static AddressType instance;

        // iterate the enum and check values against the arg
        for (auto k: Iter())  { if (getval(k) == val) { return k; } }
        return Iter().end();
    }

private:
    AddressType() {}
};

} // namespace DAC7718

#endif // __DAC7718_FIELDS_HPP__