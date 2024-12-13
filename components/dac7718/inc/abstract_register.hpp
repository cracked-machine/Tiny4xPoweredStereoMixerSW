#ifndef __DAC7718_ABSTRACT_DATA_REGISTER_HPP__
#define __DAC7718_ABSTRACT_DATA_REGISTER_HPP__

#include <bitset>

namespace DAC7718 {
namespace Internal {

/**
 * @brief Abstract base class for data register. Do NOT use this type directly.
 */
class AbstractDataRegister
{
public:
    static const size_t WIDTH{12};
    static const size_t OFFSET{4};

    AbstractDataRegister() = default; 

    /**
     * @brief Construct a new Register object
     * 
     * @param bits MSB ... LSB
     */
    AbstractDataRegister(std::bitset<WIDTH> bits):  
        m_bits(std::move(bits)) 
    { 
    };

    virtual std::bitset<WIDTH> get() const = 0;
    virtual bool test(size_t pos) const = 0;
    
protected:
    std::bitset<WIDTH> m_bits;
};

} // namespace Internal
} // namespace DAC7718

#endif // __DAC7718_ABSTRACT_DATA_REGISTER_HPP__