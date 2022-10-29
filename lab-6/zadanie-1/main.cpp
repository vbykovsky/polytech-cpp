#include <iostream>

using namespace std;

// #8
enum class BirthDateExceptionCode : int {
  UNAVAILABLE,
  WERENT_BORN,
  NEGATIVE_NUMBER,
};

class BirthDateException : public std::exception {
private:
  BirthDateExceptionCode code;

public:
  BirthDateException(BirthDateExceptionCode code) : code(code) {}

  const char* what() const throw() override {
    if (code == BirthDateExceptionCode::UNAVAILABLE) {
      return "Something is unbelievable...";
    }

    if (code == BirthDateExceptionCode::WERENT_BORN) {
      return "You weren't born yet";
    }

    if (code == BirthDateExceptionCode::NEGATIVE_NUMBER) {
      return "You entered negative numbe";
    }
  }
};

int main() {
  try
  {
    int a;

    // #1
    cout << "Enter 1, 2 or 3: ";
    cin >> a;

    cout << "You entered: ";

    // #2
    switch (a) {
    case 1:
      cout << "One";
      break;
    case 2:
      cout << "Two";
      break;
    case 3:
      cout << "Three";
      break;
    default:
      throw "Incorrect value";
    }
  }
  catch (const char* error) {
    cout << error;
  }

  try
  {
    int birthDate;

    // #3
    cout << endl << "Enter your date of birth: ";
    cin >> birthDate;

    // #4
    if (birthDate >= 0 && birthDate < 1850) {
      throw BirthDateException(BirthDateExceptionCode::UNAVAILABLE);
    }

    // #5
    if (birthDate > 2022) {
      throw BirthDateException(BirthDateExceptionCode::WERENT_BORN);
    }

    // #6
    if (birthDate < 0) {
      throw BirthDateException(BirthDateExceptionCode::NEGATIVE_NUMBER);
    }

    // #7
    cout << "Thanks";
  }
  catch (BirthDateException& error) {
    cout << error.what();
  }

  return 0;
}