cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(fast_hashmap)

add_compile_options(
  -Wall -Werror -Wcast-align -Wcast-qual -Wctor-dtor-privacy
  -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations 
  -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls
  -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default
  -Wundef -Wno-unused
)

add_subdirectory(include)

find_package( Boost 1.82 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

add_executable(main main.cpp)

target_link_libraries( main LINK_PUBLIC ${Boost_LIBRARIES} )

target_include_directories(main
    PUBLIC
    ./include
)