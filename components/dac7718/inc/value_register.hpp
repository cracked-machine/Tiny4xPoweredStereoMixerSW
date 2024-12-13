#ifndef __DAC7718_ABSTRACT_VALUE_REGISTER_HPP__
#define __DAC7718_ABSTRACT_VALUE_REGISTER_HPP__

#include <abstract_register.hpp>

namespace DAC7718 {
namespace Register {

/**
 * @brief Abstract class for value register. Do not use this type directly.
 * 
 */
class RawValue : public Internal::AbstractDataRegister
{
public: 
    RawValue(std::bitset<WIDTH> val = 0x0) { m_bits = std::move(val); }

    static constexpr size_t MAX = (2 << (WIDTH-1)) ; // 4096

    uint16_t value() { return static_cast<uint16_t>(m_bits.to_ulong()); }

    void operator++(int);

    /**
     * @brief Decrement by inverting all bits up to the first "1" LSB.
     * 
     */
    void operator--(int);

    void increase_3db();

    void decrease_3db();

    std::bitset<WIDTH> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }
};

} // namespace Register 
} // namespace DAC7718



#endif // __DAC7718_ABSTRACT_VALUE_REGISTER_HPP__