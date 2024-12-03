#ifndef __DAC7718_CONFIG_DATA_FIELD_HPP__
#define __DAC7718_CONFIG_DATA_FIELD_HPP__

#include <data_field.hpp>

namespace DAC7718 {
namespace Config {
namespace Bit {
enum class InputRegister{ 
    INPUT_DATA_REGISTER = 0, 
    DAC_DATA_REGISTER = 1 //default
};
enum class LatchData{ 
    NORMAL = 0, // default
    UPDATE = 1 
};
enum class Reset{ 
    NORMAL = 0, // default
    POR = 1 
};
enum class PowerDownGroupA{ 
    PWRON = 0, // default
    PWROFF = 1
};
enum class PowerDownGroupB{ 
    PWRON = 0, // default
    PWROFF = 1
};
enum class SystemCallibration{ 
    DISABLED = 0, // default
    ENABLED = 1
};
enum class GainGroupA{ 
    X6 = 0, // default
    x4 = 1
};
enum class GainGroupB{ 
    X6 = 0, // default
    x4 = 1
};
enum class SDO{ 
    ENABLED = 0, // default
    DISABLED = 1
};
enum class NoOpWrite{ 
    DISABLED = 0, // default
    ENABLED = 1
};
enum class AuxWakeupPin{ 
    DISABLED = 0, // default
    CSPIN = 1
};
} // namespace Bit

class Reg : public DataField
{
public: 
    /**
     * @brief Construct a new DataField for Configuration Register packets.
     * 
     * @param ab Which input data register is read. Default: DAC_DATA_REGISTER.
     * @param ld When LDAC pin is tied high, update the data register using LatchData::UPDATE
     * @param rst Soft reset the device
     * @param pda Power-down bit for Group A (DAC-0, DAC-1, DAC-2, and DAC-3).
     * @param pdb Power-down bit for Group B (DAC-4, DAC-5, DAC-6, and DAC-7).
     * @param sce Disable/Enable correction engine. Default: Disabled.
     * @param gaina Gain bit for Group A (DAC-0, DAC-1, DAC-2, and DAC-3). Default: X6.
     * @param gainb Gain bit for Group B (DAC-4, DAC-5, DAC-6, and DAC-7). Default: X6.
     * @param dsdo Disable SDO bit. Default: Enabled.
     * @param nopwrite Force a NOOP on the next write operation. Default: OFF.
     * @param w2 If the WAKEUP pin is tied high, configure CS pin to be used as WAKEUP pin. Default: DISABLED
     */
    Reg(
        Bit::InputRegister ab = Bit::InputRegister::DAC_DATA_REGISTER,
        Bit::LatchData ld = Bit::LatchData::NORMAL,
        Bit::Reset rst = Bit::Reset::NORMAL,
        Bit::PowerDownGroupA pda = Bit::PowerDownGroupA::PWRON,
        Bit::PowerDownGroupB pdb = Bit::PowerDownGroupB::PWRON,
        Bit::SystemCallibration sce = Bit::SystemCallibration::DISABLED,
        Bit::GainGroupA gaina = Bit::GainGroupA::X6,
        Bit::GainGroupB gainb = Bit::GainGroupB::X6,
        Bit::SDO dsdo = Bit::SDO::ENABLED,
        Bit::NoOpWrite nopwrite = Bit::NoOpWrite::DISABLED,
        Bit::AuxWakeupPin w2 = Bit::AuxWakeupPin::DISABLED
    ) 
    {
        m_bits.set( 11, static_cast<bool>(ab) );        // DB15
        m_bits.set( 10, static_cast<bool>(ld) );        // DB14
        m_bits.set( 9, static_cast<bool>(rst) );        // DB13
        m_bits.set( 8, static_cast<bool>(pda) );        // DB12
        m_bits.set( 7, static_cast<bool>(pdb) );        // DB11
        m_bits.set( 6, static_cast<bool>(sce) );        // DB10
                                                        // DB9 is reserved
        m_bits.set( 4, static_cast<bool>(gaina) );      // DB8
        m_bits.set( 3, static_cast<bool>(gainb) );      // DB7
        m_bits.set( 2, static_cast<bool>(dsdo) );       // DB6
        m_bits.set( 1, static_cast<bool>(nopwrite) );   // DB5
        m_bits.set( 0, static_cast<bool>(w2) );         // DB4
    }

    std::bitset<SIZE> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }
    
    // data bit mutators
    void set(Bit::InputRegister opt) { m_bits.set( 11, static_cast<bool>(opt) ); }
    void set(Bit::LatchData opt) { m_bits.set( 10, static_cast<bool>(opt) ); }
    void set(Bit::Reset opt) { m_bits.set( 9, static_cast<bool>(opt) ); }
    void set(Bit::PowerDownGroupA opt) { m_bits.set( 8, static_cast<bool>(opt) ); }
    void set(Bit::PowerDownGroupB opt) { m_bits.set( 7, static_cast<bool>(opt) ); }
    void set(Bit::SystemCallibration opt) { m_bits.set( 6, static_cast<bool>(opt) ); }
    void set(Bit::GainGroupA opt) { m_bits.set( 4, static_cast<bool>(opt) ); }
    void set(Bit::GainGroupB opt) { m_bits.set( 3, static_cast<bool>(opt) ); }
    void set(Bit::SDO opt) { m_bits.set( 2, static_cast<bool>(opt) ); }
    void set(Bit::NoOpWrite opt) { m_bits.set( 1, static_cast<bool>(opt) ); }
    void set(Bit::AuxWakeupPin opt) { m_bits.set( 0, static_cast<bool>(opt) ); }
};

} // namespace Config
} // namespace DAC7718


#endif // __DAC7718_CONFIG_DATA_FIELD_HPP__