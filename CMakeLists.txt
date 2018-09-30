cmake_minimum_required(VERSION 2.8)

project(backupnado)

set(CMAKE_BUILD_TYPE Release)


add_executable(backupnado
    src/backupnado.cpp
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
