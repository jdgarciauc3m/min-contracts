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

#ifndef MINCONTRACTS_MINCONTRACTS_HPP
#define MINCONTRACTS_MINCONTRACTS_HPP

#include <iostream>
#include <string_view>

#ifdef __has_cpp_attribute
#  if __has_cpp_attribute(unlikely)
#    define CONTRACT_UNLIKELY [[unlikely]]// NOLINT
#  else
#    define CONTRACT_UNLIKELY
#  endif
#else
#  define CONTRACT_UNLIKELY
#endif

// NOLINTNEXTLINE
#define CONTRACT_CHECK(label, cond)                    \
  if (!(cond)) {                                       \
    CONTRACT_UNLIKELY;                                 \
    std::cerr << (label) << ": " << (cond)             \
              << " failed in function "                \
              << __func__ << "() ["                    \
              << __FILE__ << ":" << __LINE__ << "]\n"; \
    std::terminate();                                  \
  }


#define CONTRACT_PRE(cond) CONTRACT_CHECK("Precondition", cond)  // NOLINT
#define CONTRACT_POST(cond) CONTRACT_CHECK("Postcondition", cond)// NOLINT
#define CONTRACT_ASSERT(cond) CONTRACT_CHECK("Assertion", cond)  // NOLINT

// NOLINTNEXTLINE
#define CONTRACT_POST_RESULT(res, cond)      \
  [&](auto && (res)) -> auto && {            \
    CONTRACT_POST(cond);                     \
    return std::forward<decltype(res)>(res); \
  }


#ifdef NDEBUG
#  define CONTRACT_PRE_AUDIT(cond)
#else
#  define CONTRACT_PRE_AUDIT(cond) CONTRACT_CHECK("Precondition", cond)// NOLINT
#endif

#ifdef NDEBUG
#  define CONTRACT_POST_AUDIT(cond)
#else
#  define CONTRACT_POST_AUDIT(cond) CONTRACT_CHECK("Postcondition", cond)// NOLINT
#endif

#ifdef NDEBUG
#  define CONTRACT_ASSERT_AUDIT(cond)
#else
#  define CONTRACT_ASSERT_AUDIT(cond) CONTRACT_CHECK("Assertion", cond)// NOLINT
#endif


#endif// MINCONTRACTS_MINCONTRACTS_HPP
