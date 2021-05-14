# min-contracts

[![Linux builds](https://github.com/jdgarciauc3m/min-contracts/actions/workflows/linux.yml/badge.svg)](https://github.com/jdgarciauc3m/min-contracts/actions)

Minimal contracts library tries to offer a minimal library only solution to support contracts in modern C++.

The library offers:
  * Preconditions
  * Postconditions
  * Assertions

The library provides all assertions in two levels:
  * **Default level**: Are always checked.
  * **Audit level**: Are only checked in *Debug* mode (i.e. when NDEBUG is 
    not defined).
    
As a rule of thumb, you use audit level checks for those ones that increase the 
cost of the task being carried out.

## Preconditions

A precondition can be specified at the start of a function body by using the macro `contract_pre`:

```c++
double sqrt(double x) {
  contract_pre(x>=0);
  //...
}

void unique_sorted(std::vector<double> & v) {
  contract_pre_audit(std::is_sorted(v.begin(), v.end()));
  auto end = std::unique(v.begin(), v.end());
  v.erase(end, v.end());
}
```

## Postconditions

A postcondition can be specified at the end of a function body by using the macro `contract_post`:

```c++
double sqrt(double x) {
  double result = //...
  //...
  contract_post(result>0);
  contract_post(result<x);
  return result;
}

void mysort(std::vector<double> & v) {
  //...
  contract_post_audit(std::is_sorted(v));
}
```

When a postcondition uses the return expression in the predicated to be evaluated,
a special kind of postcondition can be used with `contract_post_result`:

```c++
double mysqrt(double x) {
  contract_pre(x>=0);
  auto post = contract_post_result(r, r>0 && r<x);
  return post(std::sqrt(x));
}
```

## Assertions

A general assertion can be specified at any point in code by using macro `contract_assert`:

```c++
void f() {
//...
for (int i=0; i<10; ++i) {
  contract_assert(i>=0 && i<10);
  //...
}
```

There is also a `contract_assert_audit(cond)` version.

# Acknowledgments

Some ideas used here are inspired by the great series of blog posts by Herb Sutter:
  * [GotW #98 Solution: Assertion levels](https://herbsutter.com/2021/01/25/gotw-98-solution-assertion-levels-difficulty-5-10/)
  * [GotW #99 Solution: Postconditions](https://herbsutter.com/2021/02/08/gotw-99-solution-postconditions-difficulty-7-10/)
  * [GotW #100 Solution: Preconditions, Part 1](https://herbsutter.com/2021/02/25/gotw-100-solution-preconditions-part-1-difficulty-8-10/)
  * [GotW #101 Solution: Preconditions, Part 2](https://herbsutter.com/2021/03/25/gotw-101-solution-preconditions-part-2-difficulty-7-10/)