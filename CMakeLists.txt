cmake_minimum_required(VERSION 2.8)

project(cards)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR})
set(src_dir ${PROJECT_SOURCE_DIR})
set(lib_dir ${PROJECT_SOURCE_DIR}/lib)
set(int_dir ${PROJECT_SOURCE_DIR}/interface)
set(tests_dir ${PROJECT_SOURCE_DIR}/tests)

set(library
  ${lib_dir}/Card.hpp
  ${lib_dir}/Card.cpp
  ${lib_dir}/CardDeck.hpp
  ${lib_dir}/CardDeck.cpp
  ${lib_dir}/Player.hpp
  ${lib_dir}/Player.cpp
  ${lib_dir}/Game.hpp
  ${lib_dir}/Game.cpp
  ${lib_dir}/Hand.hpp
  ${lib_dir}/Hand.cpp)
set(interface
  ${int_dir}/GameBoard.hpp
  ${int_dir}/GameBoard.cpp
  ${int_dir}/GameStatsDisplay.hpp
  ${int_dir}/GameStatsDisplay.cpp
  ${int_dir}/WinningHandDisplay.hpp
  ${int_dir}/WinningHandDisplay.cpp
  ${int_dir}/InPlayDisplay.hpp
  ${int_dir}/InPlayDisplay.cpp
  ${int_dir}/PlayerHandDisplay.hpp
  ${int_dir}/PlayerHandDisplay.cpp
  ${int_dir}/TextBoxDisplay.hpp
  ${int_dir}/TextBoxDisplay.cpp
  ${int_dir}/GameInterface.hpp
  ${int_dir}/GameInterface.cpp)
set(tests
  ${tests_dir}/HandTest.hpp
  ${tests_dir}/HandTest.cpp
  ${src_dir}/tests.cpp)
# Sources
set(main_build
  # ${tests}
  ${library}
  ${interface}
  ${src_dir}/main.cpp)
set(test_build
  ${library}
  ${interface}
  ${tests})
add_executable(holdem ${main_build})
add_executable(tests ${test_build})
