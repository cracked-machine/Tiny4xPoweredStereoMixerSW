#include <dac7718.hpp>
#include <iostream>

namespace DAC7718 
{

/**
 * @brief Explicit specialization of constructor for Configuration Register message
 * 
 * @tparam  Set to ConfigDataField. See Alias Template: ConfigPacket
 * @param rw The read write bit
 */
template<> ConfigPacket::Packet(bool rw, ConfigData::ConfigDataField data)
{
    m_rwbit = rw;
    m_addr = AddressType::Reg::CONFIG;
    m_data = std::move(data);

}

} // namespace DAC7718