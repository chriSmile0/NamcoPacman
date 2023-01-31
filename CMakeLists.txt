cmake_minimum_required(VERSION 3.25)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PacMan LANGUAGES CXX)


find_package(SDL2 REQUIRED)

add_executable(pacman src/pacman.cpp)


target_sources(pacman PRIVATE src/pacman.cpp)
target_include_directories(pacman PRIVATE ${SDL2_INCLUDE_DIRS})
target_compile_definitions(pacman PRIVATE "SDL_MAIN_HANDLED")
target_link_libraries(pacman PRIVATE ${SDL2_LIBRARIES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/inc/pacman_sprites.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)	

IF (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
ENDIF()
