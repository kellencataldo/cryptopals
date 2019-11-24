project("cryptopals")
cmake_minimum_required (VERSION 3.10.2)


set(CMAKE_BUILD_TYPE Debug)

include_directories("${CMAKE_SOURCE_DIR}/utilities/include")
get_property(directories DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(directory ${directories})
    message(STATUS "INCLUDE DIRECTORY: ${directory}")
endforeach()

add_subdirectory(external)
add_executable(testrunner
    TestRunner.c
    ${CMAKE_SOURCE_DIR}/S01_C01/ConvertHexToBase64.c
    ${CMAKE_SOURCE_DIR}/S01_C02/FixedXOR.c
    ${CMAKE_SOURCE_DIR}/utilities/source/Hex.c
    )

target_link_libraries(testrunner
    Unity
    )
