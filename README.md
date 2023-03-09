benchmark_rapidjson
===================

This program compares the runtime of various parsing methods using
[rapidjson][RJ]. The test file is a 735MB JSON map.

The naïve approach using `rapidjson::IStreamWrapper` for `std::cin` yields:

```
$ ./build/benchmark_rapidjson <Nevada.json
parsed file: 217482ms
```

Most of the time seems to be lost because `std::cin` is unbuffered. Using a
`std::ifstream` results in a huge speedup:

```
$ ./build/benchmark_rapidjson Nevada.json
reading Nevada.json
parsed file: 14957ms
```


[RJ]: http://rapidjson.org/
