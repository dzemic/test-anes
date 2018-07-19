##############################################################
# stripFile function strips debug informations from targetName
# Binary and creates debug symbol table in outDir
##############################################################

# [in] targetName - same as add_executable/add_library name
# [in] outDir     - location where .debug file should be written
macro(StripFile targetName outDir)
        get_target_property(BINARY_NAME ${targetName} LOCATION) # Full path + targetName
        add_custom_command(TARGET ${targetName}
            POST_BUILD
            COMMAND objcopy --only-keep-debug "${BINARY_NAME}" "${BINARY_NAME}.debug"
            COMMAND strip --strip-debug --strip-unneeded "${BINARY_NAME}"
            COMMAND objcopy --add-gnu-debuglink="${BINARY_NAME}.debug" "${BINARY_NAME}"
            )
        INSTALL(FILES ${BINARY_NAME}.debug
        DESTINATION ${outDir}
            )
        MESSAGE("***** Stripping: targetName=${targetName}, outDir=${outDir}, BINARY_NAME=${BINARY_NAME}.debug")
endmacro(StripFile)