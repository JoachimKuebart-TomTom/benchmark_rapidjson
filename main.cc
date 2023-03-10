#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>

#include <boost/iostreams/device/mapped_file.hpp>

#include <rapidjson/document.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>

using rapidjson::Document;
using rapidjson::OStreamWrapper;
using rapidjson::Writer;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

void benchmark(boost::iostreams::mapped_file_source const& file) {
  auto const time0{std::chrono::steady_clock::now()};
  Document doc;
  doc.Parse(file.data(), file.size());
  auto const time1{std::chrono::steady_clock::now()};
  std::cout << "parsed file: " << duration_cast<milliseconds>(time1 - time0).count() << "ms\n";

  OStreamWrapper os{std::cout};
  Writer<OStreamWrapper> writer{os};
  doc.Accept(writer);
  std::cout << '\n';
}

int main(int argc, char const* argv[]) {
  for (int i{1}; i < argc; ++i) {
    std::cout << "reading " << argv[i] << '\n';
    boost::iostreams::mapped_file_source file{argv[i]};
    benchmark(file);
  }

  return 0;
}
