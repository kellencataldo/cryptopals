project("cryptopals")
cmake_minimum_required (VERSION 3.10.2)

add_subdirectory(external)
add_executable(testrunner
    testrunner.c
    ${CMAKE_SOURCE_DIR}/S01_C01/convertHexToBase64.c
    )

target_link_libraries(testrunner
    Unity
    )
