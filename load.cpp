#include <iostream>
#include <dlfcn.h>

// g++ load.cpp -o load -ldl

using fnc_t = uint64_t(*)(const char*);

int main(void) {
  void* h = dlopen("./libnative-lib.so", RTLD_LAZY);

  if (h == nullptr) {
    std::cerr << "Unable to load the library" << std::endl;
    return 1;
  }

  void* sh = dlsym(h, "_Z48KwUmSQBCaOVJKeqvABGpVnuErM7j8YCSOagNYBmr2ah0NZBePKc");
  if (sh == nullptr) {
    std::cerr << "Unable to get function" << std::endl;
    return 1;
  }

  fnc_t KwUmSQBCaOVJKeqvABGpVnuErM7j8YCSOagNYBmr2ah0NZBe = reinterpret_cast<fnc_t>(sh);
  const char test[] = "abcdefghijklwmnoqrst";
  uint64_t a = KwUmSQBCaOVJKeqvABGpVnuErM7j8YCSOagNYBmr2ah0NZBe(test);
  std::cout << a << std::endl;

  return 0;
}
