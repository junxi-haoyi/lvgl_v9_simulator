cmake_minimum_required(VERSION 3.0.0)
project(lvgl_simulator_v9 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


add_definitions(-DLV_USE_SDL)
add_definitions(-DLV_CONF_INCLUDE_SIMPLE)
# add_definitions(-DLV_CONF_H)

find_package(PkgConfig REQUIRED)

# 加载子模块
add_subdirectory("lvgl")
add_subdirectory("lv_sdl_porting")

FILE(GLOB_RECURSE SRC_LIST  main.cpp) 

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} lvgl)# add lvgl library to exe
# target_link_libraries(${PROJECT_NAME} lv_drivers)# add lv_drivers library to exe
target_link_libraries(${PROJECT_NAME} lvgl_demos)
# target_link_libraries(${PROJECT_NAME} lv_sdl_porting)
target_link_libraries(${PROJECT_NAME} SDL2main)
target_link_libraries(${PROJECT_NAME} SDL2)


target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lv_sdl_porting)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
