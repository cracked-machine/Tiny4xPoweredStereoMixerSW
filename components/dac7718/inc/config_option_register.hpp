#ifndef __DAC7718_CONFIG_DATA_REGISTER_HPP__
#define __DAC7718_CONFIG_DATA_REGISTER_HPP__

#include <abstract_register.hpp>

namespace DAC7718 {
namespace Register {

class Config : public Internal::AbstractDataRegister
{
public: 
    enum class InputRegisterBit{ 
        INPUT_DATA_REGISTER = 0, 
        DAC_DATA_REGISTER = 1 //default
    };
    enum class LatchDataBit{ 
        NORMAL = 0, // default
        UPDATE = 1 
    };
    enum class ResetBit{ 
        NORMAL = 0, // default
        POR = 1 
    };
    enum class PowerDownGroupABit{ 
        PWRON = 0, // default
        PWROFF = 1
    };
    enum class PowerDownGroupBBit{ 
        PWRON = 0, // default
        PWROFF = 1
    };
    enum class SystemCallibrationBit{ 
        DISABLED = 0, // default
        ENABLED = 1
    };
    enum class GainGroupABit{ 
        X6 = 0, // default
        x4 = 1
    };
    enum class GainGroupBBit{ 
        X6 = 0, // default
        x4 = 1
    };
    enum class SDOBit{ 
        ENABLED = 0, // default
        DISABLED = 1
    };
    enum class NoOpWriteBit{ 
        DISABLED = 0, // default
        ENABLED = 1
    };
    enum class AuxWakeupPinBit{ 
        DISABLED = 0, // default
        CSPIN = 1
    };

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
    Config(
        InputRegisterBit ab = InputRegisterBit::DAC_DATA_REGISTER,
        LatchDataBit ld = LatchDataBit::NORMAL,
        ResetBit rst = ResetBit::NORMAL,
        PowerDownGroupABit pda = PowerDownGroupABit::PWRON,
        PowerDownGroupBBit pdb = PowerDownGroupBBit::PWRON,
        SystemCallibrationBit sce = SystemCallibrationBit::DISABLED,
        GainGroupABit gaina = GainGroupABit::X6,
        GainGroupBBit gainb = GainGroupBBit::X6,
        SDOBit dsdo = SDOBit::ENABLED,
        NoOpWriteBit nopwrite = NoOpWriteBit::DISABLED,
        AuxWakeupPinBit w2 = AuxWakeupPinBit::DISABLED
    );

    std::bitset<WIDTH> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }
    
    // data bit mutators
    void set(InputRegisterBit opt);
    void set(LatchDataBit opt);
    void set(ResetBit opt);
    void set(PowerDownGroupABit opt);
    void set(PowerDownGroupBBit opt);
    void set(SystemCallibrationBit opt);
    void set(GainGroupABit opt);
    void set(GainGroupBBit opt);
    void set(SDOBit opt);
    void set(NoOpWriteBit opt);
    void set(AuxWakeupPinBit opt);
};

} // namespace Register


} // namespace DAC7718


#endif // __DAC7718_CONFIG_DATA_REGISTER_HPP__