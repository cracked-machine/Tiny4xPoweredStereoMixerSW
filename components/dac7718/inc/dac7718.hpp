#ifndef __DAC7718_HPP__
#define __DAC7718_HPP__

#include <bitset>
#include <array>

#include <address_register.hpp>
#include <config_option_register.hpp>
#include <monitor_option_register.hpp>
#include <gpio_option_register.hpp>
#include <offset_value_register.hpp>

namespace DAC7718 {
namespace Types {

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

} // Types

// Abstract types. Do not use Directly.
namespace Internal {

/**
 * @brief 
 Class template for constructing and serializing 
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
template <class DATATYPE>
class Packet
{
public:
    /**
     * @brief Construct a new Packet object. Should be explicitly specialized
     * 
     * @param rw The read write bit
     * @param data The data field type. Implicitly uses the type's constructor defaults.
     */
    Packet(bool rw, DATATYPE data = DATATYPE());

    /**
     * @brief Serialize 24-bit sequence into a 3-byte array and return both
     * 
     * @return std::pair<ShiftRegisterBytes, ShiftRegisterBits> 
     */
    std::pair<Types::ShiftRegisterBytes, Types::ShiftRegisterBits> serialize() const
    {
        Types::ShiftRegisterBytes packet_bytes{0x00, 0x00, 0x00};
        Types::ShiftRegisterBits packet_bits;

        serialize(packet_bits);

        int bitpos = 0;
        for(int idx = 0; idx < 8; idx++) 
        {
            packet_bytes[2] |= packet_bits[bitpos] << idx;
            bitpos++;
        }
        for(int idx = 0; idx < 8; idx++) 
        {
            packet_bytes[1] |= packet_bits[bitpos] << idx;
            bitpos++;
        }
        for(int idx = 0; idx < 8; idx++) 
        {
            packet_bytes[0] |= packet_bits[bitpos] << idx;
            bitpos++;
        }  

        return { packet_bytes, packet_bits };
    }
    
    DATATYPE& data() { return m_data; }
    
private:
    /**
     * @brief Serialize this class into a 24-bit sequence and return it
     * 
     * @param packet_bits The serialized bit sequence
     */
    void serialize(Types::ShiftRegisterBits &packet_bits) const
    {
        packet_bits.reset();
        for (size_t idx = 0; idx < DATATYPE::WIDTH; idx++)
        {
            (m_data.test(idx)) ?
                packet_bits[DATATYPE::OFFSET + idx] = true :
                packet_bits[DATATYPE::OFFSET + idx] = false;
        }    
        for (size_t idx = 0; idx < AddressType::WIDTH; idx++)
        {
            (AddressType::getval(m_addr).test(idx)) ?
                packet_bits[AddressType::OFFSET + idx] = true :
                packet_bits[AddressType::OFFSET + idx] = false;
        }    
        packet_bits[packet_bits.size() - 1] = m_rwbit[0];
    }

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
     * @brief 12 bits of Data. (DB15:DB4)
     * See `dac7718_data_fields.hpp` for types
     | MSB  .......................................... LSB |
     | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 |
     * 
     */
    DATATYPE m_data;

    /**
     * @brief 4 bits of padding (DB3:DB0)
     | MSB       LSB |
     | 3 | 2 | 1 | 0 |
     * 
     */
    std::bitset<4> m_lsbpadding;

};

} // namespace Internal

/**
 * @brief Type alias for Configuraion packets
 * 
 */
using ConfigPacket = Internal::Packet<Register::Config>;

/**
 * @brief Type alias for GPIO packets
 * 
 */
using GeneralPurposeIOPacket = Internal::Packet<Register::GeneralPurposeIO>;

/**
 * @brief Type alias for Monitor packets
 * 
 */
using MonitorPacket = Internal::Packet<Register::Monitor>;

/**
 * @brief Type alias for OffsetDac packets
 * 
 */
using OffsetDacAPacket = Internal::Packet<Register::OffsetDac>;

} // namespace DAC7718

#endif // __DAC7718_HPP__