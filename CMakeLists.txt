project("cryptopals")
cmake_minimum_required (VERSION 3.10.2)


set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(external)
add_executable(testrunner
    TestRunner.c
    ${CMAKE_SOURCE_DIR}/S01_C01/ConvertHexToBase64.c
    )

target_link_libraries(testrunner
    Unity
    )
