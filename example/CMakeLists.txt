cmake_minimum_required(VERSION 3.2.0)

set(TARGET_NAME QtControlLayerExample)
project(${TARGET_NAME})
message(STATUS "Processing ${TARGET_NAME}...")

SET(EMPTY ${CMAKE_PREFIX_PATH}) #silence cmake warning
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Quick)
find_package(Qt5Qml)
find_package(Qt5Network)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_definitions(-DNOMINMAX)
add_definitions(-DUNICODE -D_UNICODE)

link_directories(${QT_INSTALL_DIR})
add_executable(${TARGET_NAME} WIN32 ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${TARGET_NAME} Qt5::Core Qt5::Gui Qt5::Qml Qt5::Quick)

add_subdirectory(${CMAKE_SOURCE_DIR}/../qtcontrollayer ${CMAKE_BINARY_DIR}/qtcontrollayer)

include_directories(${CMAKE_SOURCE_DIR}/../qtcontrollayer/include)
target_link_libraries(${TARGET_NAME} qtcontrollayer)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory "${CMAKE_SOURCE_DIR}/qml" "${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/qml" COMMENT "Copying qml files...")
message(STATUS "Processing ${TARGET_NAME} - DONE")
