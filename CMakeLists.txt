cmake_minimum_required(VERSION 3.4)

project(libmfp2-canon)

# The target architecture.
# For cross-compilation this should still work as you're supposed to set this var.
# X64 mean 64-bit generically, whether AMD64 or AARCH64.
set(TARGET_ARCH "${CMAKE_SYSTEM_PROCESSOR}" CACHE STRING "Target architecture")
if (TARGET_ARCH MATCHES "^arm")
  message(FATAL_ERROR "Android device not supported")
elseif (TARGET_ARCH MATCHES "^aarch64")
  message(FATAL_ERROR "AArch64 device not supported")
else ()
  if (CMAKE_C_SIZEOF_DATA_PTR EQUAL 8)
    set(X64 1)
  else ()
    set(X64 0)
  endif ()
endif ()

set(CMAKE_INSTALL_PREFIX "/usr")
set(CFLAGS_WARN     "-Wall -Wextra -Werror -Wno-deprecated-declarations -Wno-format-truncation -Wno-stringop-truncation")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${CFLAGS_WARN}")

include(GNUInstallDirs) # for make install

include(FindPkgConfig)
pkg_search_module(LIBUSB REQUIRED libusb-1.0)
pkg_search_module(SANE REQUIRED sane-backends)
find_package(JPEG REQUIRED)

option(DEBUG "turn on debug info" OFF)

add_subdirectory(src)

install(FILES "etc/sane.d/dll.d/mfp2" DESTINATION "/etc/sane.d/dll.d/")
install(FILES "etc/canon-scan.xml" DESTINATION "/etc/")
