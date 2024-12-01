#ifndef __DAC7718_HPP__
#define __DAC7718_HPP__

#include <bitset>
#include <array>

#include <dac7718_address_type.hpp>
#include <dac7718_data_field.hpp>

namespace DAC7718 
{

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Type Alias for 3 byte shift register. 
 *        MSB [2] ... LSB [0]
 * 
 */
using ShiftRegisterBytes = std::array<uint8_t, 3>;

/**
 * @brief Type Alias for 24 bit shift register.
 *        Right position in string representation is the LSB
 */
using ShiftRegisterBits = std::bitset<24>;

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
    Packet(bool rw, AddressType::Reg addr, DataField data);
    std::pair<ShiftRegisterBytes, ShiftRegisterBits> serialize() const;
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
    AddressType::Reg m_addr;

    /**
     * @brief 12 bits Data bits (DB15:DB4)
     | MSB  .......................................... LSB |
     | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 |
     * 
     */
    DataField m_data;

    /**
     * @brief 4 bits of padding (DB3:DB0)
     | MSB       LSB |
     | 3 | 2 | 1 | 0 |
     * 
     */
    std::bitset<4> m_lsbpadding;

};

class ConfigPacket: public Packet
{
public:
    ConfigPacket(bool rw, ConfigDataField data = ConfigDataField{}) :
        Packet(rw, AddressType::Reg::CONFIG, data)
    {
    }
};

} // namespace DAC7718

#ifdef __cplusplus
}
#endif

#endif // __DAC7718_HPP__