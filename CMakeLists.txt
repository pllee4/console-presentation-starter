cmake_minimum_required (VERSION 3.10.2)

if (${CMAKE_VERSION} VERSION_LESS 3.11)
  find_package(Git QUIET)
  if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
  # Update submodules as needed
      option(GIT_SUBMODULE "Check submodules during build" ON)
      if(GIT_SUBMODULE)
          message(STATUS "Submodule update")
          execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                          RESULT_VARIABLE GIT_SUBMOD_RESULT)
          if(NOT GIT_SUBMOD_RESULT EQUAL "0")
              message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
          endif()
      endif()
  endif()
  add_subdirectory(third_party)
else()
## Fetch FTXUI
  include(FetchContent)
  message(STATUS "Fetching content from online")
  set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
  FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG v4.0.0
  )

  FetchContent_GetProperties(ftxui)
  if(NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()
endif()

project(console-presentation-starter
  LANGUAGES CXX
  VERSION 1.0.0
)

## Put all binary files into /bin and libraries into /lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
