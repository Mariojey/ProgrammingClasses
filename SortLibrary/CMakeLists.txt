cmake_minimum_required(VERSION 3.10)
project(SortLibrary C)

set(CMAKE_C_STANDARD 99)

# katalog, w którym będą zapisywane pliki bibliotek statycznych
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# dodaj bibliotekę
add_library(bubble_sort ./src/bubble_sort.c)
add_library(insertion_sort ./src/insertion_sort.c)
add_library(quick_sort ./src/quick_sort.c)
add_library(merge_sort ./src/merge_sort.c)

# plik wykonywalny
add_executable(sort_app src/main.c)

# połącz bibliotekę z plikiem wykonywalnym
target_link_libraries(sort_app bubble_sort)
target_link_libraries(sort_app insertion_sort)
target_link_libraries(sort_app quick_sort)
target_link_libraries(sort_app merge_sort)
