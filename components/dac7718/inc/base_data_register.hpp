#ifndef __DAC7718_BASE_DATA_REGISTER_HPP__
#define __DAC7718_BASE_DATA_REGISTER_HPP__

#include <bitset>

namespace DAC7718 
{

/**
 * @brief Base class for data field in shift register
 */
class BaseDataRegister
{
public:
    static const size_t SIZE{12};
    static const size_t OFFSET{4};

    BaseDataRegister() = default; 
    BaseDataRegister& operator=(const BaseDataRegister &other) 
    { 
        m_bits = other.m_bits;
        return *this;
    }

    /**
     * @brief Construct a new Field object
     * 
     * @param bits MSB <--- LSB
     */
    BaseDataRegister(std::bitset<SIZE> bits):  
        m_bits(std::move(bits)) 
    { 
    };

    virtual std::bitset<SIZE> get() const = 0;
    // virtual size_t size() const = 0;
    virtual bool test(size_t pos) const = 0;
    // const uint16_t m_offset{4};


protected:
    std::bitset<SIZE> m_bits;
};

} // namespace DAC7718

#endif // __DAC7718_BASE_DATA_REGISTER_HPP__