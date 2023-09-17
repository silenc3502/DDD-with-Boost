project(ui_console CXX)

# UI 모듈의 이름 설정 (예: ui_console)
set(UI_MODULE_NAME ui_console)

# UI 모듈의 소스 파일 목록
set(UI_MODULE_SOURCES
    ui_console.cpp
    # 다른 UI 모듈의 소스 파일들을 여기에 추가
)

# UI 모듈의 헤더 파일 목록 (필요한 경우 추가)
set(UI_MODULE_HEADERS
    ui_console.h
)

# UI 모듈을 빌드
add_library(${UI_MODULE_NAME} ${UI_MODULE_SOURCES} ${UI_MODULE_HEADERS})

# UI 모듈의 include 디렉토리 설정
set(USER_INPUT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/user_input)
target_include_directories(${UI_MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${USER_INPUT_SOURCE_DIR})
