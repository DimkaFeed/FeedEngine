cmake_minimum_required(VERSION 3.20)

project(FeedEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Статический CRT
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 3.0 REQUIRED COMPONENTS
    Graphics
    Window
    System
    Audio
    Network
)

add_library(FeedEngine SHARED
    source/Application.cpp
    source/Clock.cpp
    source/Time.cpp
)

set_target_properties(FeedEngine PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS TRUE
)

add_library(fe::Engine ALIAS FeedEngine)

# Экспорт символов через FE_API
target_compile_definitions(FeedEngine PRIVATE FE_ENGINE_EXPORTS)

target_include_directories(FeedEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(FeedEngine
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
        SFML::Audio
        SFML::Network
)

set_target_properties(FeedEngine PROPERTIES
    EXPORT_NAME Engine
)

include(GNUInstallDirs)

install(TARGETS FeedEngine
    EXPORT FeedEngineTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT FeedEngineTargets
    FILE FeedEngineTargets.cmake
    NAMESPACE fe::
    DESTINATION cmake
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    cmake/FeedEngineConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/FeedEngineConfig.cmake
    INSTALL_DESTINATION cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/FeedEngineConfig.cmake
    DESTINATION cmake
)