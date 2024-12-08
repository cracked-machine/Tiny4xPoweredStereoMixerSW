#ifndef __DAC7718_ABSTRACT_VALUE_REGISTER_HPP__
#define __DAC7718_ABSTRACT_VALUE_REGISTER_HPP__

#include <abstract_register.hpp>

namespace DAC7718 {
namespace Internal {

/**
 * @brief Abstract class for value register. Do not use this type directly.
 * 
 */
class AbstractValueRegister : public AbstractDataRegister
{
public: 
    AbstractValueRegister() = default;
    AbstractValueRegister(std::bitset<WIDTH> val) { m_bits = std::move(val); }

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
};

} // namespace Internal 
} // namespace DAC7718



#endif // __DAC7718_ABSTRACT_VALUE_REGISTER_HPP__