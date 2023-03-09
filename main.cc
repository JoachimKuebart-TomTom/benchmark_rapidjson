#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>

using rapidjson::Document;
using rapidjson::IStreamWrapper;
using rapidjson::OStreamWrapper;
using rapidjson::Writer;

int main() {
  Document doc;
  IStreamWrapper is{std::cin};
  doc.ParseStream(is);

  OStreamWrapper os{std::cout};
  Writer<OStreamWrapper> writer{os};
  doc.Accept(writer);
  std::cout << '\n';

  return 0;
}
