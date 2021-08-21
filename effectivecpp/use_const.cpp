#include <iostream>
#include <vector>

const int MAXLEN = 4096;
class STR {
private:
  char source_str[MAXLEN];
public:
  int len = 0;
  explicit STR(const char* str) {
    int i = 0;
    for(; str[i] != '\0'; i++) {
      source_str[i] = str[i];
    }
    if(i >= 4096) { i = 4095;}
    source_str[i] = '\0';
  }
  const char& operator[](std::size_t position) const {
  
    if(position >= 4096) { return source_str[0];}
    return source_str[position];
  }
  char& operator[](std::size_t position) {
    return const_cast<char&>(static_cast<const STR&>(*this)[position]);
    for(int i = 0; i < 10; i++) {
    }
  }
};

int main() {
  STR str_1("abcd");
  const STR str_2("efgh");

  std::cout << str_2[0] << std::endl;
  


  
  return 0;
}

