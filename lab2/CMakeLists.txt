cmake_minimum_required(VERSION 3.14)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp Workers/Worker.cpp Workers/Worker.h Workers/ReadFile.cpp Workers/ReadFile.h Workers/WriteFile.cpp Workers/WriteFile.h Workers/Grep.cpp Workers/Grep.h Workers/Dump.cpp Workers/Dump.h Workers/Sort.cpp Workers/Sort.h Workers/Replace.cpp Workers/Replace.h Workflow.cpp Workflow.h Factory/IFactory.h Factory/WriteFileFactory.cpp Factory/WriteFileFactory.h Factory/DumpFactory.cpp Factory/DumpFactory.h Factory/ReadFileFactory.cpp Factory/ReadFileFactory.h Factory/GrepFactory.cpp Factory/GrepFactory.h Factory/SortFactory.cpp Factory/SortFactory.h Factory/ReplaceFactory.cpp Factory/ReplaceFactory.h Parser.cpp Parser.h)