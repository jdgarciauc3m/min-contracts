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

#include <cmath>

#include <algorithm>
#include <vector>

double mysqrt(double x) {
  CONTRACT_PRE(x >= 0);
  return std::sqrt(x);
}

void unique_sorted(std::vector<double> & v) {
  CONTRACT_PRE_AUDIT(std::is_sorted(v.begin(), v.end()));
  auto end = std::unique(v.begin(), v.end());
  v.erase(end, v.end());
}

TEST(preconditions, ok) { // NOLINT
  auto x = mysqrt(1);
  ASSERT_GE(x, 0);
}

TEST(preconditions, fail) { // NOLINT
  ASSERT_DEATH(mysqrt(-1), "Precondition"); // NOLINT
}

TEST(pre_AUDIT, ok) { // NOLINT
  std::vector<double> v{1, 1, 2, 2, 2, 3};
  unique_sorted(v);
  ASSERT_EQ(3, v.size());
}

TEST(pre_AUDIT, fail) { // NOLINT
  std::vector<double> v{1, 2, 1, 2, 2, 2, 3};
  ASSERT_DEBUG_DEATH(unique_sorted(v), "Precondition"); // NOLINT
}