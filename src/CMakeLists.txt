cmake_minimum_required(VERSION 3.5)


ADD_LIBRARY(MdSpi SHARED MdSpi.cpp)
ADD_LIBRARY(MdSpi_static STATIC MdSpi.cpp)
SET_TARGET_PROPERTIES(MdSpi PROPERTIES VERSION 1.2 SOVERSION 1)
SET_TARGET_PROPERTIES(MdSpi_static PROPERTIES OUTPUT_NAME "MdSpi")
SET_TARGET_PROPERTIES(MdSpi PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(MdSpi_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)


LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})
ADD_EXECUTABLE(CTP main.cpp)
TARGET_LINK_LIBRARIES(CTP MdSpi thostmduserapi)