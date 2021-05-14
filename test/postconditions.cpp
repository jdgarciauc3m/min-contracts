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

#include "mincontracts.hpp"

#include <gtest/gtest.h>
#include <cmath>

double mysqrt2(double x) {
  contract_pre(x>=0);
  auto result = std::sqrt(x);
  contract_post(result>0); // Wrong on purpose
  contract_post(result<=x);
  return result;
}


double mysqrt3(double x) {
  contract_pre(x>=0);
  auto post = contract_post_result(r,r>0 && r<=x);
  return post(std::sqrt(x));
}

TEST(postconditions, ok) { // NOLINT
  auto r = mysqrt2(1);
  ASSERT_EQ(1,r);
}

TEST(postconditions, fail) { // NOLINT
  ASSERT_DEATH(mysqrt2(0), "Postcondition");
}

TEST(postconditions_result, ok) { // NOLINT
  auto r = mysqrt3(1);
  ASSERT_EQ(1,r);
}

TEST(postconditions_result, fail) { // NOLINT
  ASSERT_DEATH(mysqrt3(0), "Postcondition");
}