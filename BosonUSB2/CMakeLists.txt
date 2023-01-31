cmake_minimum_required(VERSION 2.8)
project( BosonUSB2 )
include_directories( ${MY_SOURCE_DIR}/src )
find_package( OpenCV REQUIRED )
add_executable( BosonUSB2 BosonUSB2.cpp )
target_link_libraries( BosonUSB2 ${OpenCV_LIBS} )

add_subdirectory(ClientFiles_C)
add_subdirectory(EmulatorFiles)

target_link_libraries(BosonUSB2 PUBLIC libbosonclient)
target_link_libraries(BosonUSB2 PUBLIC UART_HalfDuplex64)
target_include_directories(BosonUSB2 PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/ClientFiles_C"
                          "${PROJECT_SOURCE_DIR}/EmulatorFiles"
                          )