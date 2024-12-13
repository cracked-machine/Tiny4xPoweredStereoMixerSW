#ifndef __DAC7718_HPP__
#define __DAC7718_HPP__

#include <bitset>
#include <array>

#include <address_register.hpp>
#include <config_option_register.hpp>
#include <monitor_option_register.hpp>
#include <gpio_option_register.hpp>
#include <value_register.hpp>
#include <spimode_option_register.hpp>

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
    Packet(bool rw, Internal::AddressType::Reg addr_type, DATATYPE data = DATATYPE())
    {
        m_rwbit = rw;
        m_addr = addr_type;
        m_data = std::move(data);
    }

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
 * @brief Configuraion packet class
 * 
 */
class ConfigPacket : public Internal::Packet<Register::Config>
{
public:
    ConfigPacket(bool rw, Register::Config data = Register::Config{})
    : Packet(rw, Internal::AddressType::Reg::CONFIG, data)
    {
    }
};

/**
 * @brief GPIO packet class
 * 
 */
class GeneralPurposeIOPacket : public Internal::Packet<Register::GeneralPurposeIO>
{
public:
    GeneralPurposeIOPacket(bool rw, Register::GeneralPurposeIO data = Register::GeneralPurposeIO{})
    : Packet(rw, Internal::AddressType::Reg::GPIO, data)
    {
    }
};

/**
 * @brief Monitor packet class
 * 
 */
class MonitorPacket : public Internal::Packet<Register::Monitor>
{
public:
    MonitorPacket(bool rw, Register::Monitor data = Register::Monitor{})
    : Packet(rw, Internal::AddressType::Reg::MONITOR, data)
    {
    }
};

/**
 * @brief OffsetDacA packet class
 * 
 */
class OffsetDacAPacket : public Internal::Packet<Register::RawValue>
{
public:
    OffsetDacAPacket(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::OFFSET_DAC_A, std::move(data))
    {
    }
};

/**
 * @brief OffsetDacB packet class
 * 
 */
class OffsetDacBPacket : public Internal::Packet<Register::RawValue>
{
public:
    OffsetDacBPacket(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::OFFSET_DAC_B, std::move(data))
    {
    }
};

/**
 * @brief SpiMode packet class
 * 
 */
class SpiModePacket : public Internal::Packet<Register::SpiMode>
{
public:
    SpiModePacket(bool rw, Register::SpiMode data = Register::SpiMode())
    : Packet(rw, Internal::AddressType::Reg::SPI_MODE, std::move(data))
    {
    }
};

class BroadcastPacket : public Internal::Packet<Register::RawValue>
{
public:
    BroadcastPacket(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::BROADCAST, std::move(data))
    {
    }
};

class InputData0Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData0Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_0_DATA, std::move(data))
    {
    }
};

class InputData1Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData1Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_1_DATA, std::move(data))
    {
    }
};

class InputData2Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData2Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_2_DATA, std::move(data))
    {
    }
};

class InputData3Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData3Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_3_DATA, std::move(data))
    {
    }
};

class InputData4Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData4Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_4_DATA, std::move(data))
    {
    }
};

class InputData5Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData5Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_5_DATA, std::move(data))
    {
    }
};

class InputData6Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData6Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_6_DATA, std::move(data))
    {
    }
};

class InputData7Packet : public Internal::Packet<Register::RawValue>
{
public:
    InputData7Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::DAC_7_DATA, std::move(data))
    {
    }
};

class ZeroData0Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData0Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_0, std::move(data))
    {
    }
};

class ZeroData1Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData1Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_1, std::move(data))
    {
    }
};

class ZeroData2Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData2Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_2, std::move(data))
    {
    }
};

class ZeroData3Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData3Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_3, std::move(data))
    {
    }
};

class ZeroData4Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData4Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_4, std::move(data))
    {
    }
};

class ZeroData5Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData5Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_5, std::move(data))
    {
    }
};

class ZeroData6Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData6Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_6, std::move(data))
    {
    }
};

class ZeroData7Packet : public Internal::Packet<Register::RawValue>
{
public:
    ZeroData7Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::ZERO_7, std::move(data))
    {
    }
};


class GainData0Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData0Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_0, std::move(data))
    {
    }
};

class GainData1Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData1Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_1, std::move(data))
    {
    }
};

class GainData2Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData2Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_2, std::move(data))
    {
    }
};

class GainData3Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData3Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_3, std::move(data))
    {
    }
};

class GainData4Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData4Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_4, std::move(data))
    {
    }
};

class GainData5Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData5Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_5, std::move(data))
    {
    }
};

class GainData6Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData6Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_6, std::move(data))
    {
    }
};

class GainData7Packet : public Internal::Packet<Register::RawValue>
{
public:
    GainData7Packet(bool rw, Register::RawValue data = Register::RawValue())
    : Packet(rw, Internal::AddressType::Reg::GAIN_7, std::move(data))
    {
    }
};

} // namespace DAC7718

#endif // __DAC7718_HPP__