add_executable(console_presentation_starter 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/console_presentation_starter.cpp
)
target_link_libraries(console_presentation_starter PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)
target_include_directories(console_presentation_starter PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

set_target_properties(console_presentation_starter PROPERTIES CXX_STANDARD 17)