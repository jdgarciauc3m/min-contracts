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

#include "mincontracts/mincontracts.hpp"

namespace mincontracts {
  void contract_log(std::string_view label, std::string_view cond,
      std::string_view function, std::string_view file, std::size_t line) {
    std::cerr << label << ": " << cond <<
              " failed in function " << function << "() [" << file << ":" << line << "]\n";
  }

  void contract_check(bool cond,
      std::string_view label, std::string_view cond_text,
      std::string_view function, std::string_view file, std::size_t line) {
#if __has_cpp_attribute(unlikely)
    if (!cond) [[unlikely]] {
#else
    if (!cond) {
#endif
      contract_log(label, cond_text, function, file, line);
      std::terminate();
    }
  }

}
