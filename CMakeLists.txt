cmake_minimum_required(VERSION 3.23)

project(IssueGen)

include_directories("inc")

add_executable(issuegen src/file.c src/main.c src/timedate.c)

install(TARGETS issuegen DESTINATION bin)
install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/init/S02issuegen DESTINATION ../etc/init.d)
