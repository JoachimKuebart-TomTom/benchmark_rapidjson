set -efu
conan install \
    --build missing \
    --install-folder build \
    .
cmake \
    -B build \
    -D CMAKE_BUILD_TYPE=Release \
    -D CMAKE_POLICY_DEFAULT_CMP0091=NEW \
    -D CMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake \
    -D CMAKE_VERBOSE_MAKEFILE=ON \
    -G Ninja \
    -S .
cmake --build build
