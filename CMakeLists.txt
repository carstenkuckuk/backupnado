cmake_minimum_required(VERSION 3.12)

project(backupnado)

set(CMAKE_BUILD_TYPE Release)

#######################################
###
### libgit2
###
# Recipe for libgit2 inclusion found on https://stackoverflow.com/questions/35373923/how-to-include-libgit2-via-cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(git2 REQUIRED)

if(WIN32)
	set(GIT2_INCLUDE_DIR "C:/program files/libgit2/include") # QUICKHACK for Windows as I can't get find_package to work
	set(GIT2_LIBRARIES "C:/program files/libgit2/lib/git2.lib")
endif()


include_directories(${GIT2_INCLUDE_DIR})




add_executable(backupnado
    src/backupnado.cpp

	src/commands/HelpCommand.hpp
	src/commands/HelpCommand.cpp
	src/commands/InitCommand.hpp
	src/commands/InitCommand.cpp

	src/domain/version.hpp
	src/domain/version.cpp
	src/domain/BackupConfiguration.hpp
	src/domain/BackupConfiguration.cpp

	src/helpers/filehelpers.hpp
	src/helpers/filehelpers.cpp
	src/helpers/oshelpers.hpp
	src/helpers/oshelpers.cpp
	src/helpers/stringhelpers.hpp
	src/helpers/stringhelpers.cpp
)

target_link_libraries(backupnado
	${GIT2_LIBRARIES}
)


install(TARGETS backupnado
    RUNTIME DESTINATION bin               COMPONENT Runtime
    LIBRARY DESTINATION lib               COMPONENT Runtime
    ARCHIVE DESTINATION lib/backupnado    COMPONENT Development
)


########################################
###
###  Installers for Windows (NSIS) and
###  Linux (DEB)
###

set(CPACK_PACKAGE_NAME "Backupnado")
set(CPACK_PACKAGE_VENDOR "backupnado.org")
set(CPACK_PACKAGE_CONTACT "Carsten Kuckuk <ck@kuckuk.com>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Backupnado is a fine backup utility")
set(CPACK_PACKAGE_VERSION "0.0.1")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")

#set(CPACK_RESOURCE_FILE_LICENSE "{CMAKE_CURRENT_SOURCE_DIR}/src/copyright.txt")
#set(CPACK_CREATE_DESKTOP_LINKS BackupnadoGUI)
set(CPACK_NSIS_MODIFY_PATH ON)
# Start Entries:
set(CPACK_NSIS_MENU_LINKS "http://backupnado.org/" "Web Site" )

include(InstallRequiredSystemLibraries)

include(CPack)
