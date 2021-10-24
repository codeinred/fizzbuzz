
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Installation
# See: https://dominikberner.ch/cmake-interface-lib/

# Creates an installable header only library. It searches for the library at
# ${include_dir}/${library_name}
function(add_interface_library include_dir library_name)
    add_library("${library_name}" INTERFACE)
    add_library("${library_name}::${library_name}" ALIAS "${library_name}")

    target_include_directories(
        "${library_name}"
        INTERFACE
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/${include_dir}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    )

    install(
        TARGETS "${library_name}"
        EXPORT "${library_name}_Targets"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    )

    write_basic_package_version_file(
        "${library_name}ConfigVersion.cmake"
        VERSION "${PROJECT_VERSION}"
        COMPATIBILITY SameMajorVersion
    )

    configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/cmake/config.cmake.in"
        "${PROJECT_BINARY_DIR}/${library_name}Config.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${library_name}/cmake"
    )

    install(
        EXPORT "${library_name}_Targets"
        FILE "${library_name}Targets.cmake"
        NAMESPACE "${library_name}::"
        DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${library_name}/cmake"
    )

    install(FILES "${PROJECT_BINARY_DIR}/${library_name}Config.cmake"
                "${PROJECT_BINARY_DIR}/${library_name}ConfigVersion.cmake"
            DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${library_name}/cmake"
    )

    install(DIRECTORY "${PROJECT_SOURCE_DIR}/${include_dir}/${library_name}"
            DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    )
endfunction()
