#ifndef __DAC7718_OFFSET_DATA_REGISTER_HPP__
#define __DAC7718_OFFSET_DATA_REGISTER_HPP__

#include <base_data_register.hpp>

namespace DAC7718 {
namespace OffsetDac {

class Reg : public BaseDataRegister
{
public: 
    Reg() = default;
    Reg(std::bitset<WIDTH> val) { m_bits = std::move(val); }

    static constexpr size_t MAX = (2 << (WIDTH-1)) ; // 4096

    uint16_t value() { return static_cast<uint16_t>(m_bits.to_ulong()); }

    std::bitset<WIDTH> get() const { return m_bits; }

    bool test(size_t pos) const { return m_bits.test(pos); }

    void operator++(int) 
    {
        // prevent integer underflow from 4095 to 0!
        if (value() == (MAX - 1)) { return; }
        //  add 1 to each value, and if it was 1 already, carry the 1 to the next.
        for ( size_t i = 0; i < WIDTH; ++i ) {
            if ( m_bits[i] == 0 ) 
            {
                // There will be no carry
                m_bits[i] = 1;
                break;
            }
            // This entry was 1; set to zero and carry the 1
            m_bits[i] = 0;  
        }        
    }

};

} // OffsetDac
} // DAC7718



#endif // __DAC7718_OFFSET_DATA_REGISTER_HPP__