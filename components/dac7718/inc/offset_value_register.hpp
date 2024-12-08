#ifndef __DAC7718_OFFSET_DAC_REGISTER_HPP__
#define __DAC7718_OFFSET_DAC_REGISTER_HPP__

#include <abstract_value_register.hpp>

namespace DAC7718 {
namespace Register {

class OffsetDac : public Internal::AbstractValueRegister
{
public: 
    OffsetDac() = default;
    OffsetDac(std::bitset<WIDTH> val) { m_bits = std::move(val); }

    std::bitset<WIDTH> get() const { return m_bits; }
    bool test(size_t pos) const { return m_bits.test(pos); }
};

} // namespace Register
} // namespace DAC7718


#endif // __DAC7718_OFFSET_DAC_REGISTER_HPP__