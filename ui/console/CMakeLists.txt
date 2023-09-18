set(UI_MODULE_NAME ui_console)

set(UI_MODULE_SOURCES
    ui_console.cpp
)

set(UI_MODULE_HEADERS
    ui_console.h
)

include(CMakePrintHelpers)

cmake_print_variables(PROJECT_SOURCE_DIR)
cmake_print_variables(USER_INPUT_MODULE_SOURCES)
cmake_print_variables(USER_INPUT_MODULE_HEADERS)
cmake_print_variables(UI_MODULE_SOURCES)
cmake_print_variables(UI_MODULE_HEADERS)

add_library(${UI_MODULE_NAME} OBJECT ${UI_MODULE_SOURCES} ${USER_INPUT_MODULE_SOURCES})
            
#target_include_directories(${UI_MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/user_input)
target_include_directories(${UI_MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${USER_INPUT_SOURCE_DIR})

# user_input 모듈의 object 파일을 가져옴
target_sources(${UI_MODULE_NAME} PRIVATE $<TARGET_OBJECTS:user_input>)
target_link_libraries(${UI_MODULE_NAME} PRIVATE user_input)