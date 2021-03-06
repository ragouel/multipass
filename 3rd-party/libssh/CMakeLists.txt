# Copyright © 2017-2020 Canonical Ltd.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

set(WITH_ZLIB FALSE)
set(WITH_EXAMPLES FALSE)
set(WITH_SERVER TRUE)
set(WITH_SFTP TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-implicit-function-declaration -Wno-incompatible-pointer-types -Wno-int-conversion")

set(LIBSSH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libssh/include)

# Needed only because of libssh install target
set(LIB_INSTALL_DIR lib)
set(BIN_INSTALL_DIR bin)

set(BUILD_SHARED_LIBS ON)
set(GLOBAL_CLIENT_CONFIG "/etc/ssh/ssh_config")
set(GLOBAL_BIND_CONFIG "/etc/ssh/libssh_server_config")

include_directories(${LIBSSH_INCLUDE_DIR})
include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/libssh)

find_package(Threads)

# libssh source needs the config.h header to be generated
include(libssh/cmake/Modules/AddCCompilerFlag.cmake)
include(libssh/ConfigureChecks.cmake)
configure_file(libssh/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/libssh/config.h)

message(STATUS "Checking for 'libssh' version")

# Since the main CMake file is bypassed, we have to search that CMake file to determine the proper
# shared library versions
file(STRINGS libssh/CMakeLists.txt LIBRARY_VERSION REGEX "^set\\(LIBRARY_VERSION")
file(STRINGS libssh/CMakeLists.txt LIBRARY_SOVERSION REGEX "^set\\(LIBRARY_SOVERSION")

string(REGEX REPLACE "^set\\(LIBRARY_VERSION \"(.*)\"\\)$" "\\1"
       LIBRARY_VERSION "${LIBRARY_VERSION}")
if (NOT LIBRARY_VERSION)
    message(FATAL_ERROR "unable to find libssh library version")
endif()

string(REGEX REPLACE "^set\\(LIBRARY_SOVERSION \"(.*)\"\\)$" "\\1"
       LIBRARY_SOVERSION "${LIBRARY_SOVERSION}")
if (NOT LIBRARY_SOVERSION)
    message(FATAL_ERROR "unable to find libssh library soversion")
endif()

message(STATUS "  Found ${LIBRARY_VERSION}, ${LIBRARY_SOVERSION}")

# We bypass the main CMake file to avoid various package checks which are satisfied manually
# through the configuration above.
add_subdirectory(libssh/src)

add_library(libssh INTERFACE)

target_include_directories(libssh INTERFACE
  ${LIBSSH_INCLUDE_DIR})

target_link_libraries(libssh INTERFACE
  ssh)
