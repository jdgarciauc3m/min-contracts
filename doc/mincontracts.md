#MinContracts

The library provides all assertions in two levels:
* **Default level**: Are always checked.
* **Audit level**: Are only checked in *Debug* mode (i.e. when NDEBUG is
  not defined).

As a rule of thumb, you use audit level checks for those that sifnificantly
increase the cost of the task being carried out.


## Preconditions

A precondition can be specified at the start of a function body by using the macro
`CONTRACT_PRE`:

```c++
double sqrt(double x) {
  CONTRACT_PRE(x>=0);
  //...
}
```

An audit version states preconditions that are only checked in debug builds,
but not in release builds. That is, the checks are only performed when the
symbol `DNDEBUG` is not defined. Audit checks are expected to be used for
those predicates that are more expensive to check.

```c++
void unique_sorted(std::vector<double> & v) {
  CONTRACT_PRE_AUDIT(std::is_sorted(v.begin(), v.end()));
  auto end = std::unique(v.begin(), v.end());
  v.erase(end, v.end());
}
```

## Postconditions

A postcondition can be specified at the end of a function body by using the macro
`CONTRACT_POST`. There is also an audit version:

```c++
double sqrt(double x) {
  double result = //...
  //...
  CONTRACT_POST(result>0);
  CONTRACT_POST(result<x);
  return result;
}

void mysort(std::vector<double> & v) {
  //...
  CONTRACT_POST_AUDIT(std::is_sorted(v));
}
```

When a postcondition uses the return expression in the predicate to be evaluated,
a special kind of postcondition can be used with `CONTRACT_POST_RESULT`:

```c++
double mysqrt(double x) {
  CONTRACT_PRE(x>=0);
  auto post = CONTRACT_POST_result(r, r>0 && r<x);
  return post(std::sqrt(x));
}
```

## Assertions

A general assertion can be specified at any point in code by using macro `CONTRACT_ASSERT`:

```c++
void f() {
//...
for (int i=0; i<10; ++i) {
  CONTRACT_ASSERT(i>=0 && i<10);
  //...
}
```

There is also a `CONTRACT_ASSERT_AUDIT(cond)` version, which is only
checked in debug builds (i.e. when NDEBUG is undefined).
