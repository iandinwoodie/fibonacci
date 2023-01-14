#include "fibonacci/fibonacci.h"

namespace fibonacci {
unsigned int exp(unsigned int n) {
  if (n < 2) {
    return n;
  } else {
    return exp(n - 1) + exp(n - 2);
  }
}
} // namespace fibonacci
