#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fe::Engine" for configuration "Release"
set_property(TARGET fe::Engine APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(fe::Engine PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/FeedEngine.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/FeedEngine.dll"
  )

list(APPEND _cmake_import_check_targets fe::Engine )
list(APPEND _cmake_import_check_files_for_fe::Engine "${_IMPORT_PREFIX}/lib/FeedEngine.lib" "${_IMPORT_PREFIX}/bin/FeedEngine.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
