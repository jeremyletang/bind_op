# bind_op
Kind of monadic bind operator for C++

Just have fun with some kind of C++ bind operator from Haskell

The bind operator allow you to apply a function to a monad. For example, Haskell have
the Maybe monad which can be in two different states: `Just` with a value or Nothing
which represent the absence of value.

Recently C++ added `std::optional` to the standard (C++17/1z), you can found it
in `std::experimental::optional` for recent versions of C++14. `std::optional` is really
similar to Haskell's `Maybe` monad, that's why I wrote this function.

The Bind operator allow you to apply a function to the monad in the case this one contains
a value, or return nullopt in the case it contains nothing.

Enough speaking, here is a simple example (let's assume this is C++17):

```c++
#include <bind_op>
#include <cassert>
#include <iostream>
#include <optional>

int main() {
  auto opt_1 = std::make_optional(42);
  auto opt_2 = std::make_optional(21);
  auto opt_result = opt_1 >>= [&](const auto& x) {
    return opt_2 >> [&](const auto& y) {
      return (y + x);
    };
  };
  assert(**opt_result == 63);
}
```
