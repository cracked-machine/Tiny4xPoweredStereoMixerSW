#include <dac7718.hpp>

namespace DAC7718 {

template<> OffsetDacAPacket::Packet(bool rw, Register::OffsetDac data)
{
    m_rwbit = rw;
    m_addr = AddressType::Reg::OFFSET_DAC_A;
    m_data = std::move(data);
}

} // namespace DAC7718