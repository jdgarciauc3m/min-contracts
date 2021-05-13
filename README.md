# min-contracts

![Linux builds](https://github.com/jdgarciauc3m/min-contracts/actions/workflows/linux.yml/badge.svg)

Minimal contracts library tries to offer a minimal library only solution to support contracts in modern C++.

The library offers:
  * Preconditions
  * Postconditions
  * Assertions

## Preconditions

A precondition can be specified at the start of a function body by using the macro `contract_pre`:

```c++
double sqrt(double x) {
  contract_pre(x>=0);
  //...
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
```

## Assertions

A general assertion can be specified at any point in code by using macro `contract_assert`:

```c++
//...
contract_assert(x>y);
//...
```
