#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>

#include <rapidjson/document.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>

using rapidjson::Document;
using rapidjson::OStreamWrapper;
using rapidjson::Writer;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

void benchmark(std::istream& is) {
  auto const time0{std::chrono::steady_clock::now()};
  std::ostringstream oss;
  oss << is.rdbuf();
  std::string json{oss.str()};
  auto const time1{std::chrono::steady_clock::now()};
  std::cout << "read file: " << duration_cast<milliseconds>(time1 - time0).count() << "ms\n";
  Document doc;
  doc.Parse(json);
  auto const time2{std::chrono::steady_clock::now()};
  std::cout << "parsed file: " << duration_cast<milliseconds>(time2 - time1).count() << "ms\n";

  OStreamWrapper os{std::cout};
  Writer<OStreamWrapper> writer{os};
  doc.Accept(writer);
  std::cout << '\n';
}

int main(int argc, char const* argv[]) {
  if (argc <= 1) {
    benchmark(std::cin);
  } else {
    for (int i{1}; i != argc; ++i) {
      std::cout << "reading " << argv[i] << '\n';
      std::ifstream is{argv[i]};
      benchmark(is);
    }
  }

  return 0;
}
