# Test Framework

A lightweight unit testing framework for C, built from scratch.

The goal of this project is to provide a simple, easy-to-use testing framework while learning how real testing frameworks are designed internally.

## Features

- Automatic test registration
- Dynamic test registry
- Simple `TEST()` macro
- Assertion macros
- Test runner
- Test reporting
- Test suits
- Test timing
- Test disabling and enabling
- Shared library support
- Clean public API (`test.h`)

---

## Project Structure

```
.
├── include/
│   └── test.h          # Public API
├── src/
│   ├── registry.h
│   ├── reporter.h
│   ├── runner.h
│   ├── test_internal.h
│   ├── assertions.c
│   ├── registry.c
│   ├── reporter.c
│   ├── runner.c
│   ├── timer.h
│   ├── timer.c
│   └── test_internal.c
├── example/
│   └── simple_test.c
└── CMakeLists.txt
```

---

## Building

Clone the repository:

```bash
git clone https://github.com/Ayham133/test-framework.git
cd test-framework
```

Configure the project:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

Build:

```bash
cmake --build build
```

---

## Writing Tests

Include the public header:

```c
#include <test.h>
```

Create a test:

```c
TEST(Math)
{
    ASSERT_TRUE(2 + 2 == 4);
}
```

Run all registered tests:

```c
int main(void)
{
    run_all_tests();
}
```

---

## Example Output

```text
=========================================================
Running Tests
=========================================================

[ RUN    ] Subtraction [Math]
[ PASSED ] Subtraction (0.01 ms)

=========================================================
Total tests : 1
Passed      : 1
Failed      : 0
Disabled    : 0
=========================================================
```

If an assertion fails:

```text
Assertion failed
Expression : 1 == 2
File       : example/simple_test.c:7
```

---

## Assertions

Currently implemented:

- `ASSERT_TRUE(expression)`
- `ASSERT_FALSE()`
- `ASSERT_NULL()`
- `ASSERT_NOT_NULL()`
- `ASSERT_EQ()`
- `ASSERT_EQ_INT()`

More assertions are planned for future releases:
- `ASSERT_STR_EQ()`

---

## Design

The framework is composed of several independent modules:

```
TEST()
   │
   ▼
Automatic Registration
   │
   ▼
Registry
   │
   ▼
Runner
   │
   ▼
Assertions
   │
   ▼
Reporter
```

The user only interacts with the public API exposed by `test.h`.

---

## Requirements

- C99 or newer
- CMake 3.10+

---

## Version

Current version:

```
v0.2.0
```

---

## Future Plans

- Additional assertion macros
- Test filtering
- Fixtures (setup/teardown)

---

## License

This project is licensed under the MIT License.
