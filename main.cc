#include <chrono>
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

int main() {
  auto const time0{std::chrono::steady_clock::now()};
  Document doc;
  IStreamWrapper is{std::cin};
  doc.ParseStream(is);
  auto const time1{std::chrono::steady_clock::now()};
  std::cout << "parsed file: " << duration_cast<milliseconds>(time1 - time0).count() << "ms\n";

  OStreamWrapper os{std::cout};
  Writer<OStreamWrapper> writer{os};
  doc.Accept(writer);
  std::cout << '\n';

  return 0;
}
