#include <dac7718.hpp>
#include <iostream>

namespace DAC7718 
{

Packet::Packet(bool rw, AddressField addr, DataField data) :
    m_rwbit(rw),
    m_addr(std::move(addr)),
    m_data(std::move(data))
{ 
}

std::pair<ShiftRegisterBytes, ShiftRegisterBits> Packet::serialize() const
{
    ShiftRegisterBytes packet_bytes{0x00, 0x00, 0x00};
    ShiftRegisterBits packet_bits;

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
void Packet::serialize(ShiftRegisterBits &packet_bits) const
{
    packet_bits.reset();
    for (size_t idx = 0; idx < m_data.get().size(); idx++)
    {
        (m_data.test(idx)) ?
            packet_bits[m_data.m_offset + idx] = true :
            packet_bits[m_data.m_offset + idx] = false;
    }    
    for (size_t idx = 0; idx < m_addr.size(); idx++)
    {
        (m_addr.test(idx)) ?
            packet_bits[m_addr.m_offset + idx] = true :
            packet_bits[m_addr.m_offset + idx] = false;
    }    
    packet_bits[packet_bits.size() - 1] = m_rwbit[0];
}

} // namespace DAC7718