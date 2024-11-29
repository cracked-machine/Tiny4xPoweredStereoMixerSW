#ifndef __DAC7718_HPP__
#define __DAC7718_HPP__

#include <bitset>
#include <array>

namespace DAC7718 
{

template <size_t FIELDWIDTH, size_t OFFSET>
class Field
{
public:
    Field() = default;
    Field(uint16_t offset) : m_offset(offset) {} 
    Field(std::bitset<FIELDWIDTH> &data) { m_bits = data; };
    std::bitset<FIELDWIDTH> get() const { return m_bits; }
    constexpr size_t size() const { return m_bits.size(); }
    bool test(size_t pos) const { return m_bits.test(pos); }
    uint16_t m_offset{OFFSET};
private:
    std::bitset<FIELDWIDTH> m_bits;
};


using DataField = typename DAC7718::Field<12, 3>;
using AddressField = typename DAC7718::Field<5, 15>;

#ifdef __cplusplus
extern "C" {
#endif

using ShiftRegisterBits = std::bitset<24>;
using ShiftRegisterBytes = std::array<uint8_t, 3>;



// class DataField
// {
// public:
//     DataField() = default;
//     DataField(std::bitset<12> &data) { m_bits = data; };
//     std::bitset<12> get() const { return m_bits; }
//     constexpr size_t size() const { return m_bits.size(); }
//     bool test(size_t pos) const { return m_bits.test(pos); }
//     uint16_t m_offset{3};
// private:
//     std::bitset<12> m_bits{0};
// };

// class AddressField
// {
// public:
//     AddressField() = default;
//     AddressField(const std::bitset<5> &data) { m_bits = data; };
//     std::bitset<5> get() const { return m_bits; }
//     uint16_t m_offset{15};
//     size_t size() const { return m_bits.size(); }
//     bool test(size_t pos) const { return m_bits.test(pos); }
// private:
//     std::bitset<5> m_bits{0};
// };

/**
 * @brief 
 Class for constructing and serializing 
 bytes sequences for DAC7718 shift register.
 Packet structure is as follows:
 
    | MSB                               LSB |
    | RW | Padding |         Address        |
    | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 | 

    | MSB                               LSB |
    |                 Data                  | 
    | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |

    | MSB                               LSB |
    |       Data        |      Padding      |
    | 7  | 6  | 5  | 4  | 3  | 2  | 1  | 0  | 
 * 
 */
class Packet
{
public:
    Packet() = default;
    Packet(DataField &data, AddressField &addr, bool rw);
    void run();

    void serialize(ShiftRegisterBytes &packet_bytes) const;
private:
    void serialize(ShiftRegisterBits &packet_bytes) const;

    /**
     * @brief 1 bit Read/Write Bit
     | MSB ... LSB |
     |      23     |
     * 
     */
    std::bitset<1> m_rwbit;  

    /**
     * @brief 2 bits of padding (DB22:DB21)
     | MSB ... LSB |
     |  22  |  21  |
     * 
     */
    std::bitset<2> m_msbpadding;

    /**
     * @brief 5 bit address (DB20:DB16)
     | MSB    .......     LSB |
     | 20 | 19 | 18 | 17 | 16 |
     * 
     */
    AddressField m_addr;

    /**
     * @brief 12 bits Data bits (DB15:DB4)
     | MSB  .......................................... LSB |
     | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 |
     * 
     */
    DataField m_data{3};

    /**
     * @brief 4 bits of padding (DB3:DB0)
     | MSB       LSB |
     | 3 | 2 | 1 | 0 |
     * 
     */
    std::bitset<4> m_lsbpadding;

};

} // namespace DAC7718

#ifdef __cplusplus
}
#endif

#endif // __DAC7718_HPP__