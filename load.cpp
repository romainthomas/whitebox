#include <iostream>
#include <dlfcn.h>

// g++ load.cpp -o load -ldl

using fnc_t = uint64_t(*)(unsigned char*, unsigned char*);

int main(void) {
  void* h = dlopen("./libnative-lib.so", RTLD_NOW);

  if (h == nullptr) {
    std::cerr << "Unable to load the library" << std::endl;
    return 1;
  }

  void* sh = dlsym(h, "_Z48TfcqPqf1lNhu0DC2qGsAAeML0SEmOBYX4jpYUnyT8qYWIlEqPhS_");
  if (sh == nullptr) {
    std::cerr << "Unable to get function" << std::endl;
    return 1;
  }

  fnc_t KwUmSQBCaOVJKeqvABGpVnuErM7j8YCSOagNYBmr2ah0NZBe = reinterpret_cast<fnc_t>(sh);
  fnc_t AES_128_encrypt = reinterpret_cast<fnc_t>(sh);
  unsigned char test1[256] = "abcdefghijklwmno";
  unsigned char test2[256] = "abcdefghijklwmno";
  AES_128_encrypt(test1, test2);
  std::cout << test1 << std::endl;
  std::cout << test2 << std::endl;

  return 0;
}
