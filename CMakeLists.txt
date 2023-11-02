make_minimum_required(VERSION 3.22)

project(VimGuardian VERSION 1.0)

add_executable(ropeclient lib/main.c lib/rope.c)
target_include_directories(ropeclient PRIVATE include)
set_property(TARGET ropeclient PROPERTY C_STANDARD 11)

execute_process(
    COMMAND bash ${CMAKE_CURRENT_SOURCE_DIR}/lib/sock.sh
    COMMAND pip3 install -r ${CMAKE_CURRENT_SOURCE_DIR}/include/requirements.txt
)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

install(TARGETS ropeclient DESTINATION ${CMAKE_BINARY_DIR}/bin)
