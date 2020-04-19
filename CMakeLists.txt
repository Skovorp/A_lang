cmake_minimum_required(VERSION 3.15)
project(untitled1 C)

set(HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/stack.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/instruction.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/machine.h"

)

set(SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/stack.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/machine.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/instruction.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/main.c"
)

add_executable(untitled1 ${HEADERS} ${SOURCES})
