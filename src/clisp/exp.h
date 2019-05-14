#ifndef CLISP_EXP_H
#define CLISP_EXP_H

#include <string>
#include <variant>

namespace clisp {

class exp;
using exp_ptrs = std::unique_ptr<std::vector<exp>>;

enum class exp_type {
  symbol,
  boolean,
  number,
  list,
};

class exp {
private:
  exp_type type;
  std::variant<
      std::string, // symbol
      bool, // boolean
      double, // number
      exp_ptrs // list
      > value;
};
}

#endif //CLISP_EXP_H
