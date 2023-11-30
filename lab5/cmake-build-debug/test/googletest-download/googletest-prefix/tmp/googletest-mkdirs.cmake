# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-src"
  "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-build"
  "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-download/googletest-prefix"
  "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-download/googletest-prefix/tmp"
  "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-download/googletest-prefix/src/googletest-stamp"
  "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-download/googletest-prefix/src"
  "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-download/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-download/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/b_eli/Desktop/MAI_OOP/lab5/cmake-build-debug/test/googletest-download/googletest-prefix/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
