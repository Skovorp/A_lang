cmake_minimum_required(VERSION 2.6)
project(A_lang_machine)

set(HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/stack.h"
)

set(SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/stack.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/main.c"
)

add_executable(A_lang_machine ${HEADERS} ${SOURCES})
