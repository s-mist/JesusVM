cmake_minimum_required(VERSION 3.26)

set(SOURCES "src/stream.c"
        src/error.c
        src/platform/files.c
        src/module_info.c
        src/attribute_info.c
        src/class_info.c
        src/constant_info.c
        src/field_info.c
        src/reader.c
        src/writer.c
        src/function_info.c
)

set(HEADERS "include/moduleweb/stream.h"
        include/moduleweb/types.h
        include/moduleweb/error.h
        include/moduleweb/platform/files.h
        include/moduleweb/module_info.h
        include/moduleweb/constant_info.h
        include/moduleweb/class_info.h
        include/moduleweb/field_info.h
        include/moduleweb/attribute_info.h
        include/moduleweb/function_info.h
        include/moduleweb/reader.h
        include/moduleweb/writer.h
)

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

add_library(jesusvm-moduleweb ${SOURCES} ${HEADERS})
add_library(JesusVM::moduleweb ALIAS jesusvm-moduleweb)

target_include_directories(jesusvm-moduleweb
    PUBLIC
        include
)

if(WIN32)
    target_compile_definitions(jesusvm-moduleweb PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(jesusvm-moduleweb PRIVATE PLATFORM_MACOS)
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(jesusvm-moduleweb PRIVATE PLATFORM_LINUX)
endif()

set_property(TARGET jesusvm-moduleweb PROPERTY C_STANDARD 23)