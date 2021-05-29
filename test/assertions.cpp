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

#include <gtest/gtest.h>

int add(int i, int j) {
  int r = 0;
  for (int k = i; k < j; ++k) {
    CONTRACT_ASSERT(k >= i);
    CONTRACT_ASSERT(k < j);
    r += k;
  }
  return r;
}

bool even(int n) {
  switch (n) {
    case 1:
    case 3:
      return true;
    case 2:
    case 4:
      return false;
    default:
      CONTRACT_ASSERT(false);
  }
}

TEST(assertion, ok) {// NOLINT
  auto r = add(2, 4);
  ASSERT_EQ(5, r);
}

TEST(assertion,default_branch) { //NOLINT
  ASSERT_DEATH(even(5), "Assertion");
}