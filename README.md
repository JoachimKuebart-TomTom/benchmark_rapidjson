benchmark_rapidjson
===================

This program compares the runtime of various parsing methods using rapidjson.
The test file is a 735MB JSON map.

The naïve approach using `rapidjson::IStreamWrapper` for `std::cin` yields:

```
$ ./build/benchmark_rapidjson <Nevada.json
parsed file: 217482ms
```
