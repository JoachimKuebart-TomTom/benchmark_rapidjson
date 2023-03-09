#include <chrono>
#include <fstream>
#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>

using rapidjson::Document;
using rapidjson::IStreamWrapper;
using rapidjson::OStreamWrapper;
using rapidjson::Writer;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

void benchmark(std::istream& is) {
  auto const time0{std::chrono::steady_clock::now()};
  Document doc;
  IStreamWrapper isw{is};
  doc.ParseStream(isw);
  auto const time1{std::chrono::steady_clock::now()};
  std::cout << "parsed file: " << duration_cast<milliseconds>(time1 - time0).count() << "ms\n";

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
