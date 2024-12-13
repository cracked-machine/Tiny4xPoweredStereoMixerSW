#include <value_register.hpp>

namespace DAC7718 {
namespace Register {

void RawValue::operator++(int) 
{
    // prevent wrap around to 0x0
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

/**
 * @brief Decrement by inverting all bits up to the first "1" LSB.
 * 
 */
void RawValue::operator--(int) 
{
    // prevent wrap around to 0xFFF
    if (value() == 0) { return; }

    // beginning with the LSB
    for ( size_t i = 0; i < WIDTH; ++i ) 
    {
        // invert each "0" bit.
        if (m_bits[i] == 0) {  m_bits[i] = 1; }
        // until a "1" bit is encountered
        else 
        { 
            // then insert that "1" to "0" and stop
            m_bits[i] = 0; 
            // All bits beyond the first "1" bit remain unchanged.
            break; 
        }
    }
}

void RawValue::increase_3db()
{
    // multiplying zero does nothing so set to 0x1
    if (m_bits.none()) { m_bits[0] = 1; } 
    // avoid wrap around to 0x0, set to 0xFFF
    else if ((m_bits << 1 == 0x0) || (m_bits.all())) {m_bits = 0xFFF; }
    // otherwise double the bit set value
    else { m_bits <<= 1; }
}

void RawValue::decrease_3db()
{
    m_bits >>= 1;
}

} // namespace Register
} // namespace DAC7718 