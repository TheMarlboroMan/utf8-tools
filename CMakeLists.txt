cmake_minimum_required(VERSION 3.6.0)
project(utf8-tools)

option(BUILD_EXAMPLES "Build example code" ON)
option(BUILD_DEBUG "Build a debug release" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(${BUILD_DEBUG})
        set(CMAKE_BUILD_TYPE Debug)

else()
        set(CMAKE_BUILD_TYPE Release)
endif()

add_compile_options(-Wall -Wextra -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow -Woverloaded-virtual -Wno-deprecated -ansi -pedantic -fno-rtti)

#Add the include directory.
include_directories("include")

#Adding sources...
set(SOURCE "")
add_subdirectory("${PROJECT_SOURCE_DIR}/lib")

#Library building and installation.
add_library(utf8-tools_shared SHARED ${SOURCE})
set_target_properties(utf8-tools_shared PROPERTIES OUTPUT_NAME utf8tools)

add_library(utf8-tools_static STATIC ${SOURCE})
set_target_properties(utf8-tools_static PROPERTIES OUTPUT_NAME utf8tools)

install(TARGETS utf8-tools_shared DESTINATION lib)
install(TARGETS utf8-tools_static DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/ FILES_MATCHING PATTERN "*.h")

if(${BUILD_EXAMPLES})

	add_executable(example examples/main.cpp)
	target_link_libraries(example utf8-tools_shared)

endif()
