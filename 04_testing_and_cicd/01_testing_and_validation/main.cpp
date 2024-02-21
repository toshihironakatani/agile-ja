#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*----これらの関数を変更する必要はありません----*/

bool contains(const std::string &name,
              const std::vector<std::string> &list_of_names) {
  return std::find(list_of_names.begin(), list_of_names.end(), name) !=
         list_of_names.end();
}

void add_name(const std::string &name,
              std::vector<std::string> &list_of_names) {
  list_of_names.push_back(name);
}

int add_two(int num) { return num + 2; }

double divide_by_two(double num) { return num / 2; }

std::string greeting(const std::string &name, double num) {
  std::string message{"Hello, " + name + ". It is " + std::to_string(num) +
                      " degrees warmer today than yesterday"};
  return message;
}


/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/

// `my_assert` をここに定義し、以降のテストに使用してください。
void my_assert(bool expr, std::string msg = "") {
  if (!expr) {
    throw std::invalid_argument(msg);
  } else {
    std::cout << "Test passed" << std::endl;
  }
}

// `contains` 用のテスト `test_contains` を作成してください
void test_contains() {
  std::vector<std::string> names{"Nick", "Lewis", "Nikos"};
  try {
    my_assert(contains("Nick", names) == true, "Nick should be contained.");
    my_assert(contains("John", names) == false, "John should not be contained.");
  } catch (const std::exception &e) {
    std::cerr << "test_constains failed: " << e.what() << std::endl;
  }
}

// `add_name` 用のテスト `test_add_name` を作成してください
void test_add_name() {
  std::vector<std::string> names{"Nick", "Lewis", "Nikos"};
  add_name("John", names);
  try {
    my_assert(contains("John", names) == true, "John should be added.");
  } catch (const std::exception& e){
    std::cerr << "test_add_name failed" << e.what() << std::endl;
  }
}

// `add_two` 用のテスト `test_add_two` を作成してください
void test_add_two() {
  try {
    my_assert(add_two(1) == 3, "should be 3. result: " + std::to_string(add_two(1)));
  } catch (const std::exception& e) {
    std::cerr << "test_add_two failed: " << e.what() << std::endl;
  }
}

// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください
void test_divide_by_two() {
  try {
    my_assert(divide_by_two(1.0) == 0.5, "should be 0.5. result: " + std::to_string(divide_by_two(1.0)));
  } catch (const std::exception& e) {
    std::cerr << "test_divide_by_two failed: " << e.what() << std::endl;
  }
}

// `greeting` 用のテスト `test_greeting` を作成してください
void test_greeting() {
  try {
    my_assert(greeting("Nick", 5.0) == "Hello, Nick. It is " + std::to_string(5.0) +" degrees warmer today than yesterday", "invalide message");
  } catch (const std::exception& e){
    std::cerr << "test_greeting failed: " << e.what() << std::endl;
  }
}

/*----難易度: キリマンジャロ----*/

// `my_assert` 用のテスト `test_my_assert_false`
// を作成し、式がfalseと評価されたときに指定したオプションの `msg`
// を適切に返すかどうかをチェックしてください。

// `my_assert` 用のテスト `test_my_assert_true`
// を作成し、式がtrueと評価されたときに適切に処理するかどうかをチェックしてください。


int main() {
  test_contains();
  test_add_name();
  test_add_two();
  test_divide_by_two();
  test_greeting();
}
