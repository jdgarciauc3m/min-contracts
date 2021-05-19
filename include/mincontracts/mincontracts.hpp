//    Copyright 2021 J. Daniel Garcia
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#ifndef MIN_CONTRACTS_HPP
#define MIN_CONTRACTS_HPP

#include <iostream>
#include <string_view>

namespace mincontracts {
  void contract_log(std::string_view label, std::string_view cond,
                    std::string_view function, std::string_view file,
                    std::size_t line) noexcept;

  void contract_check(bool cond,
                      std::string_view label, std::string_view cond_text,
                      std::string_view function, std::string_view file,
                      std::size_t line) noexcept;
}// namespace mincontracts


#define CONTRACT_CHECK(label, cond) \
  mincontracts::contract_check(cond, label, #cond, __func__, __FILE__, __LINE__);

#define CONTRACT_PRE(cond) CONTRACT_CHECK("Precondition", cond)
#define CONTRACT_POST(cond) CONTRACT_CHECK("Postcondition", cond)
#define CONTRACT_ASSERT(cond) CONTRACT_CHECK("Assertion", cond)

#define CONTRACT_POST_RESULT(res, cond)      \
  [&](auto && (res)) -> auto && {            \
    CONTRACT_POST(cond);                     \
    return std::forward<decltype(res)>(res); \
  }


#ifdef NDEBUG
#  define CONTRACT_PRE_AUDIT(cond)
#else
#  define CONTRACT_PRE_AUDIT(cond) CONTRACT_CHECK("Precondition", cond)
#endif

#ifdef NDEBUG
#  define CONTRACT_POST_AUDIT(cond)
#else
#  define CONTRACT_POST_AUDIT(cond) CONTRACT_CHECK("Postcondition", cond)
#endif

#ifdef NDEBUG
#  define CONTRACT_ASSERT_AUDIT(cond)
#else
#  define CONTRACT_ASSERT_AUDIT(cond) CONTRACT_CHECK("Assertion", cond)
#endif


#endif// MIN_CONTRACTS_HPP
