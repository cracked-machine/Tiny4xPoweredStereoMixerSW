#include <dac7718.hpp>

namespace DAC7718 
{

/**
 * @brief Explicit specialization of constructor for Configuration Register message
 * 
 * @tparam  Set to Field. See Alias Template: ConfigPacket
 * @param rw The read write bit
 */
template<> ConfigPacket::Packet(bool rw, Config::Reg data)
{
    m_rwbit = rw;
    m_addr = AddressType::Reg::CONFIG;
    m_data = std::move(data);

}

template<> MonitorPacket::Packet(bool rw, Monitor::Data data)
{
    m_rwbit = rw;
    m_addr = AddressType::Reg::MONITOR;
    m_data = std::move(data);
}

} // namespace DAC7718