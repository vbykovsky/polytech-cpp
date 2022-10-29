#include <regex>
#include <string>
#include <iostream>

using namespace std;

// #2
const regex nameRegex("[A-Z][a-z]{1,31}");

// #4
const regex emailRegex(R"([_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4}))", regex_constants::icase);


int main() {
  string name;

  // #1
  cout << "Enter your name: ";
  cin >> name;

  if (regex_match(name, nameRegex)) {
    cout << "Correct name" << endl;
  }
  else {
    cout << "Incorrect name" << endl;
  }

  // #3
  string stringWithEmails = "zxcqwe asdas@asd.qwe asd_=_-1 qweqwe@e.e vlad@gmail.com )-1231-925";

  // #4
  smatch  emailMathes;
  string::const_iterator searchStart(stringWithEmails.cbegin());

  cout << "Found emails: ";

  while (regex_search(searchStart, stringWithEmails.cend(), emailMathes, emailRegex)) {
    cout << (searchStart == stringWithEmails.cbegin() ? "" : "; ") << emailMathes[0];
    searchStart = emailMathes.suffix().first;
  }

  cout << endl;

  return 0;
}