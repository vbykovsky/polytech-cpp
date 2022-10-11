#include "MyMath.hpp"

int MyMath::callsCount = 0;

int MyMath::add(int a, int b) {
  //# 11
  MyMath::callsCount += 1;

  return a + b;
}

int MyMath::sub(int a, int b) {
  //# 11
  MyMath::callsCount += 1;

  return a - b;
}

int MyMath::mult(int a, int b) {
  //# 11
  MyMath::callsCount += 1;

  return a * b;
}

int MyMath::div(int a, int b) {
  //# 11
  MyMath::callsCount += 1;

  return a / b;
}