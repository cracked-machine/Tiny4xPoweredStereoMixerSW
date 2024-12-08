#include <dac7718.hpp>
#include <config_option_register.hpp>

namespace DAC7718 {

/**
 * @brief Explicit specialization of constructor for Configuration Packet
 * 
 * @tparam  The data register type
 * @param rw The read write bit
 */
template<> ConfigPacket::Packet(bool rw, Register::Config data)
{
    m_rwbit = rw;
    m_addr = AddressType::Reg::CONFIG;
    m_data = std::move(data);

}

namespace Register {

Config::Config(InputRegisterBit ab, LatchDataBit ld, ResetBit rst, PowerDownGroupABit pda, PowerDownGroupBBit pdb, 
               SystemCallibrationBit sce, GainGroupABit gaina, GainGroupBBit gainb, SDOBit dsdo, NoOpWriteBit nopwrite, 
               AuxWakeupPinBit w2
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

void Config::set(InputRegisterBit opt) { m_bits.set( 11, static_cast<bool>(opt) ); }
void Config::set(LatchDataBit opt) { m_bits.set( 10, static_cast<bool>(opt) ); }
void Config::set(ResetBit opt) { m_bits.set( 9, static_cast<bool>(opt) ); }
void Config::set(PowerDownGroupABit opt) { m_bits.set( 8, static_cast<bool>(opt) ); }
void Config::set(PowerDownGroupBBit opt) { m_bits.set( 7, static_cast<bool>(opt) ); }
void Config::set(SystemCallibrationBit opt) { m_bits.set( 6, static_cast<bool>(opt) ); }
void Config::set(GainGroupABit opt) { m_bits.set( 4, static_cast<bool>(opt) ); }
void Config::set(GainGroupBBit opt) { m_bits.set( 3, static_cast<bool>(opt) ); }
void Config::set(SDOBit opt) { m_bits.set( 2, static_cast<bool>(opt) ); }
void Config::set(NoOpWriteBit opt) { m_bits.set( 1, static_cast<bool>(opt) ); }
void Config::set(AuxWakeupPinBit opt) { m_bits.set( 0, static_cast<bool>(opt) ); }

} // namespace Register
} // namespace DAC7718 