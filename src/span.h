#ifndef MARLON_UTIL_SPAN_H
#define MARLON_UTIL_SPAN_H

#include "size.h"

namespace marlon::util {
template <typename T> class Span {
public:
  constexpr Span(T *begin, T *end) noexcept
      : _begin{begin}, _end{end} {}

  constexpr T *begin() const noexcept {
    return _begin;
  }

  constexpr T *end() const noexcept {
    return _end;
  }

  constexpr Size size() const noexcept {
    return _end - _begin;
  }

  constexpr Usize usize() const noexcept {
    return static_cast<Usize>(size());
  }

private:
  T *_begin;
  T *_end;
};
} // namespace marlon::util

#endif
