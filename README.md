# Cjaja

This project ports the Java standard library to C++. The name is credited to []()

## Principles

We aim to . The project follows the following empirical principles on converting Java to C++:

- Follow the code of OpenJDK
- When able to return by value (involving no subtyping), return by value.
- When not able to return by value, return by std::shared_ptr, for the sake of subtyping, since you cannot return a reference or raw pointer.
- When able to pass by reference, pass by reference.
  - This is for the sake of variance in the parameters.
  - Mostly you have to implement separate versions for lvalue and rvalue references.


## Progress

Currently, the project is

- Undocumented
  - No document about whether a function has not been declared, has been declared but is a dummy, or has been fully implemented.
  - No document about whether a method is correctly implemented and tested.
  - No document about how a method is adapted
- Untested
  - Only recreational test.
  - No info about whether a test runs or fails.
  - No coverage.

## License

The project is licensed under GNU/GPLv2.