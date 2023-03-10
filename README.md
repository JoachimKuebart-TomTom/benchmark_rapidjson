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

As a next step, getting rid of `rapidjson::IStreamWrapper` and reading to an
`std::ostringstream`, then copying to a `std::string` reduces the parsing time
immensely:

```
$ ./build/benchmark_rapidjson Nevada.json
reading Nevada.json
read file: 4621ms
parsed file: 1570ms
```

Switching to a memory-mapped file using `boost::iostreams::mapped_file_source`
eliminates the time required to read the file:

```
$ ./build/benchmark_rapidjson Nevada.json
reading Nevada.json
parsed file: 1834ms
```


[RJ]: http://rapidjson.org/
