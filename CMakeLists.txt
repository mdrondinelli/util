cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(Sandbox C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()
add_subdirectory(lib/Catch2-3.6.0)

# util
add_library(
  util
  src/memory.cpp
  src/thread_pool.cpp
)

# util_tests
add_executable(
  util_tests
  src/hash_tests.cpp
  src/memory_tests.cpp
  src/bit_list_tests.cpp
  src/list_tests.cpp
  src/queue_tests.cpp
  src/set_tests.cpp
  src/map_tests.cpp
)
target_link_libraries(util_tests util Catch2::Catch2WithMain)
