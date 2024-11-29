#include <dac7718.hpp>
#include <iostream>

namespace DAC7718 
{

Packet::Packet(DataField &data, AddressField &addr, bool rw)
{
    m_data = data;
    m_addr = addr;
    m_rwbit.set(0, rw);        
}
void Packet::serialize(ShiftRegisterBits &packet_bits) const
{
    for (size_t idx = 0; idx < m_data.get().size(); idx++)
    {
        (m_data.test(idx)) ?
            packet_bits[m_data.m_offset + (m_data.size() - 1) - idx] = true :
            packet_bits[m_data.m_offset + (m_data.size() - 1) - idx] = false;
    }    
    for (size_t idx = 0; idx < m_addr.get().size(); idx++)
    {
        (m_addr.test(idx)) ?
            packet_bits[m_addr.m_offset + (m_addr.size() - 1) - idx] = true :
            packet_bits[m_addr.m_offset + (m_addr.size() - 1) - idx] = false;
    }    
}


void Packet::run()
{
    std::cout << "hello DAC7718!";
}


} // namespace DAC7718