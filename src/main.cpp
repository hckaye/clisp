#include <iostream>

#include "clisp/parser.h"

int main(int argc, char **argv) {
  auto tokens = clisp::tokenize("foo foo(bar)baz)  )");

  for (auto&& t : tokens)
    std::cout << t << std::endl;

  assert(tokens.size() == 8);

  return 0;
}
