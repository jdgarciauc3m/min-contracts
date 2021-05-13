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
  inline void contract_log(std::string_view label, std::string_view cond,
      std::string_view function, std::string_view file, std::size_t line) {
    std::cerr << label << ": " << cond <<
              " failed in function " << function << "() ["<< file << ":" << line << "]\n";
  }

  inline void contract_check(bool cond,
      std::string_view label, std::string_view cond_text,
      std::string_view function, std::string_view file, std::size_t line)
  {
    if (!cond) [[unlikely]] {
      contract_log(label, cond_text, function, file, line);
      std::terminate();
    }
  }
}


#define contract_check(label,cond) \
mincontracts::contract_check(cond, label, #cond, __func__, __FILE__, __LINE__);

#define contract_pre(cond) contract_check("Precondition", cond)

#ifdef NDEBUG
#define contract_pre_audit(cond)
#else
#define contract_pre_audit(cond) contract_check("Precondition", cond)
#endif

#define contract_post(cond) contract_check("Postcondition", cond)

#ifdef NDEBUG
#define contract_post_audit(cond)
#else
#define contract_post_audit(cond) contract_check("Postcondition", cond)
#endif



#endif //MIN_CONTRACTS_HPP
