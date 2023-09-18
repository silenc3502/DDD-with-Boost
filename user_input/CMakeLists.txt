set(USER_INPUT_MODULE_NAME user_input)

set(USER_INPUT_MODULE_SOURCES
    keyboard_input.cpp
)

set(USER_INPUT_MODULE_HEADERS
    keyboard_input.h
)

add_library(${USER_INPUT_MODULE_NAME} OBJECT ${USER_INPUT_MODULE_SOURCES})

target_include_directories(${USER_INPUT_MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
