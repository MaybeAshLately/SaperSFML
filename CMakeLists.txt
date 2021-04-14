cmake_minimum_required (VERSION 3.10)
  
project (SAPER)

#####################################################################
# Tu wymień wszystkie pliki .cpp, z których składa się projekt (rozdzielone spacją)

set ( SOURCES main.cpp  )

#####################################################################

# UWAGA - to jest CMakeLists dla repl-it ! Jeśli piszecie pod CLion-em lub w innym
#         normalnym środowisku - użyjcie instrukcji ze strony kursu

add_compile_options(-Wall -Wextra -g)
include_directories( include SFML-2.5.1/include )
link_directories ( SFML-2.5.1/lib )

add_executable(main ${SOURCES} )

# ustawiamy "czysty" standard C++11
set_target_properties(main PROPERTIES
  CXX_STANDARD 11
  CXX_EXTENSIONS OFF
)

target_link_libraries (main sfml-graphics sfml-window sfml-system)


