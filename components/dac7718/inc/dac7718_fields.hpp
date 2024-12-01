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
    // sync this end limit with the last entry in EncapsulatedEnum::Reg
    typedef EnumIterator<Reg, static_cast<Reg>(0), Reg::GAIN_7> Iter;
    // Return a U16 value depending on the Reg given
    static std::bitset<5> getval(Reg k) 
    { 
        // guarantee singleton creation
        [[maybe_unused]] static AddressType instance;

        switch(k)
        {
            case Reg::CONFIG:
                return std::bitset<5>{"00000"};
            case Reg::MONITOR:
                return std::bitset<5>{"00001"};
            case Reg::GPIO:
                return std::bitset<5>{"00010"};
            case Reg::OFFSET_DAC_A:
                return std::bitset<5>{"00011"};
            case Reg::OFFSET_DAC_B:
                return std::bitset<5>{"00100"};
            case Reg::SPI_MODE:
                return std::bitset<5>{"00110"};
            case Reg::BROADCAST:
                return std::bitset<5>{"00111"};
            case Reg::DAC_0_DATA:
                return std::bitset<5>{"01000"};
            case Reg::DAC_1_DATA:
                return std::bitset<5>{"01001"};
            case Reg::DAC_2_DATA:
                return std::bitset<5>{"01010"};
            case Reg::DAC_3_DATA:
                return std::bitset<5>{"01011"};
            case Reg::DAC_4_DATA:
                return std::bitset<5>{"01100"};
            case Reg::DAC_5_DATA:
                return std::bitset<5>{"01101"};
            case Reg::DAC_6_DATA:
                return std::bitset<5>{"01110"};
            case Reg::DAC_7_DATA:
                return std::bitset<5>{"01111"};
            case Reg::ZERO_0:
                return std::bitset<5>{"10000"};
            case Reg::GAIN_0:
                return std::bitset<5>{"11000"};
            case Reg::ZERO_1:
                return std::bitset<5>{"10001"};
            case Reg::GAIN_1:
                return std::bitset<5>{"11001"};
            case Reg::ZERO_2:
                return std::bitset<5>{"10010"};
            case Reg::GAIN_2:
                return std::bitset<5>{"11010"};
            case Reg::ZERO_3:
                return std::bitset<5>{"10011"};
            case Reg::GAIN_3:
                return std::bitset<5>{"11011"};
            case Reg::ZERO_4:
                return std::bitset<5>{"10100"};
            case Reg::GAIN_4:
                return std::bitset<5>{"11100"};
            case Reg::ZERO_5:
                return std::bitset<5>{"10101"};
            case Reg::GAIN_5:
                return std::bitset<5>{"11101"};
            case Reg::ZERO_6:
                return std::bitset<5>{"10110"};
            case Reg::GAIN_6:
                return std::bitset<5>{"11110"};
            case Reg::ZERO_7:
                return std::bitset<5>{"10111"};
            case Reg::GAIN_7:
                return std::bitset<5>{"11111"};
            default:
                // this line can never be called but keeps compiler warning quiet
                 __builtin_unreachable();
        } 
        // this line can never be called but keeps compiler warning quiet
        __builtin_unreachable();
    } 
    // Return a Reg depending on the U16 value given
    static Iter getReg(std::bitset<5> val)
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


class AddressField
{
public:
    AddressField() = default; 
    /**
     * @brief Construct a new Field object
     * 
     * @param data MSB <--- LSB
     */
    AddressField(AddressType::Reg reg):  m_reg(std::move(reg)) { };
    AddressType::Reg get() const { return m_reg; }
    constexpr size_t size() const { return 5; }
    bool test(size_t pos) const { return AddressType::getval(m_reg).test(pos); }
    const uint16_t m_offset{16};
private:
    AddressType::Reg m_reg;
};


class DataField
{
public:
    DataField() = default; 
    /**
     * @brief Construct a new Field object
     * 
     * @param data MSB <--- LSB
     */
    DataField(std::bitset<12> bits):  m_bits(std::move(bits)) { };
    std::bitset<12> get() const { return m_bits; }
    constexpr size_t size() const { return m_bits.size(); }
    bool test(size_t pos) const { return m_bits.test(pos); }
    const uint16_t m_offset{4};
private:
    std::bitset<12> m_bits;
};

/**
 * @brief Alias Template for Data field in shift register
 *        width = 12, offset = 4
 * 
 */
// using DataField = typename DAC7718::Field<12, 4>;
/**
 * @brief Alias Template for Address field in shift register
 *        width = 5, offset = 16
 */
// using AddressField = typename DAC7718::Field<5, 16>;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


} // namespace DAC7718



#endif // __DAC7718_FIELDS_HPP__