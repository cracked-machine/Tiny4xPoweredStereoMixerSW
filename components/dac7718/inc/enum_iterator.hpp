#ifndef __DAC7718_ENUM_ITERATOR_HPP__
#define __DAC7718_ENUM_ITERATOR_HPP__

namespace DAC7718 
{

// iterator for use with enums
template < typename ENUM, ENUM beginVal, ENUM endVal>
class EnumIterator {
  typedef typename std::underlying_type<ENUM>::type val_t;
  int val;
public:
  EnumIterator(const ENUM &f) : val(static_cast<val_t>(f)) {}
  EnumIterator() : val(static_cast<val_t>(beginVal)) {}
  EnumIterator operator++() {
    ++val;
    return *this;
  }
  ENUM operator*() { return static_cast<ENUM>(val); }
  EnumIterator begin() { return *this; } //default ctor is good
  EnumIterator end() {
      static const EnumIterator endIter = ++EnumIterator(endVal); // cache it
      return endIter;
  }
  bool operator!=(const EnumIterator& i) { return val != i.val; }
};


} // namespace DAC7718

#endif // __DAC7718_ENUM_ITERATOR_HPP__