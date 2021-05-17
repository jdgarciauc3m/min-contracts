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
#include <string>

namespace mincontracts {
  void contract_log(std::string_view label, std::string_view cond,
      std::string_view function, std::string_view file, std::size_t line);

  void contract_check_impl(bool cond,
      std::string_view label, std::string_view cond_text,
      std::string_view function, std::string_view file, std::size_t line);
}


#define contract_check(label,cond) \
mincontracts::contract_check_impl(cond, label, #cond, __func__, __FILE__, __LINE__);

#define contract_pre(cond) contract_check("Precondition", cond)
#define contract_post(cond) contract_check("Postcondition", cond)
#define contract_assert(cond) contract_check("Assertion", cond)

#define contract_post_result(res,cond)      \
[&](auto && (res)) -> auto &&{              \
  contract_post(cond);                      \
  return std::forward<decltype(res)>(res);  \
}


#ifdef NDEBUG
#define contract_pre_audit(cond)
#else
#define contract_pre_audit(cond) contract_check("Precondition", cond)
#endif

#ifdef NDEBUG
#define contract_post_audit(cond)
#else
#define contract_post_audit(cond) contract_check("Postcondition", cond)
#endif

#ifdef NDEBUG
#define contract_assert_audit(cond)
#else
#define contract_assert_audit(cond) contract_check("Assertion", cond)
#endif



#endif //MIN_CONTRACTS_HPP
