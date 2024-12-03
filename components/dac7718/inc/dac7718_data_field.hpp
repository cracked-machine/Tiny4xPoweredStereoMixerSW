#ifndef __DAC7718_DATA_FIELD_HPP__
#define __DAC7718_DATA_FIELD_HPP__

#include <bitset>

namespace DAC7718 
{

/**
 * @brief Base class for data field in shift register
 *        width = 5, offset = 16
 */
class DataField
{
public:
    DataField() = default; 
    DataField& operator=(const DataField &other) 
    { 
        m_bits = other.m_bits;
        return *this;
    }

    /**
     * @brief Construct a new Field object
     * 
     * @param bits MSB <--- LSB
     */
    DataField(std::bitset<12> bits):  
        m_bits(std::move(bits)) 
    { 
    };

    virtual std::bitset<12> get() const = 0;
    virtual size_t size() const = 0;
    virtual bool test(size_t pos) const = 0;
    const uint16_t m_offset{4};
protected:
    std::bitset<12> m_bits;
};

namespace ConfigData {

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

class ConfigDataField : public DataField
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
    ConfigDataField(
        InputRegister ab = InputRegister::DAC_DATA_REGISTER,
        LatchData ld = LatchData::NORMAL,
        Reset rst = Reset::NORMAL,
        PowerDownGroupA pda = PowerDownGroupA::PWRON,
        PowerDownGroupB pdb = PowerDownGroupB::PWRON,
        SystemCallibration sce = SystemCallibration::DISABLED,
        GainGroupA gaina = GainGroupA::X6,
        GainGroupB gainb = GainGroupB::X6,
        SDO dsdo = SDO::ENABLED,
        NoOpWrite nopwrite = NoOpWrite::DISABLED,
        AuxWakeupPin w2 = AuxWakeupPin::DISABLED
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

    std::bitset<12> get() const { return m_bits; }
    size_t size() const { return m_bits.size(); }
    bool test(size_t pos) const { return m_bits.test(pos); }

    // data bit mutators
    void set_input_register(InputRegister opt) { m_bits.set( 11, static_cast<bool>(opt) ); }
    void set_latch_data(LatchData opt) { m_bits.set( 10, static_cast<bool>(opt) ); }
    void set_reset(Reset opt) { m_bits.set( 9, static_cast<bool>(opt) ); }
    void set_powerdown_groupa(PowerDownGroupB opt) { m_bits.set( 8, static_cast<bool>(opt) ); }
    void set_powerdown_groupb(PowerDownGroupA opt) { m_bits.set( 7, static_cast<bool>(opt) ); }
    void set_callibration(SystemCallibration opt) { m_bits.set( 6, static_cast<bool>(opt) ); }
    void set_gain_groupa(GainGroupA opt) { m_bits.set( 4, static_cast<bool>(opt) ); }
    void set_gain_groupb(GainGroupB opt) { m_bits.set( 3, static_cast<bool>(opt) ); }
    void set_dsdo(SDO opt) { m_bits.set( 2, static_cast<bool>(opt) ); }
    void set_noopwrite(NoOpWrite opt) { m_bits.set( 1, static_cast<bool>(opt) ); }
    void set_aux_wakeup(AuxWakeupPin opt) { m_bits.set( 0, static_cast<bool>(opt) ); }
};

} // namespace Config
} // namespace DAC7718

#endif // __DAC7718_DATA_FIELD_HPP__