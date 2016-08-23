// Copyright 2016 Jeremy Letang.
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.

#include <bind_op>
#include <iostream>
#include <list>
#include <array>

#if __cplusplus >= 201402L
# include <experimental/optional>
#elif __cplusplus >= 201701L
# include <optional>
#endif

using namespace bind_op;

int f(const int& i) {
  return i * 100;
}

int main() {
  auto o = _std_opt::make_optional(42);
  auto o2 = _std_opt::make_optional(5);
  auto l = std::list<int>{1,2,3,4,5,6,7};
  std::string s = "hello world";
  auto a = std::array<int, 3>{{10,20,30}};

  auto i = (((o >>= [](const auto& i) {std::cout << 1 << std::endl; return i*2;})
              >>= [](const auto& i) { std::cout << 2 << std::endl; return i*10; })
              >>= f);
  auto i2 = o >>= [o2](const auto& i) {
    return o2 >>= [i](const auto& i2) {
      return i*i2;
    };
  };
  std::list<float> l2 = l >>= [](const auto& i) { return static_cast<float>(i*2); };
  std::string s2 = s >>= [](const auto& c) -> char { return c + 1; };
  auto a2 = a >>= [](const auto& i) { return i*10; };

  std::cout << *i << std::endl;
  std::cout << **i2 << std::endl;
  for (const auto& e: l2) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  for (const auto& e: a2) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
  std::cout << s2 << std::endl;
}
