
#Print current source directory configuration information
message(STATUS "cmake config ${CMAKE_CURRENT_SOURCE_DIR}")

#Set target name
set(target hello_world)

#Add target file to application library list
add_apps_libraries($<TARGET_FILE:${target}>)

#Add static library target
add_library(${target} STATIC)

#Set the archive output directory for the target
set_target_properties(${target} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${out_quec_lib_dir})

#Add private include directories
target_include_directories(${target} PRIVATE
    ${SOURCE_TOP_DIR}
    ${SOURCE_SYS_DEBUG_DIR}
    ${SOURCE_SYS_OS_DIR}
    ${SOURCE_COMPONENTS_PUBLIC_INC})

#Add public include directories
target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#Add source file
target_sources(${target} PRIVATE
    hello_world.c
)

#Conditionally link system_os library
target_link_libraries_if(CONFIG_QOSA_LINK_SYSTEM_LIBRARIES_FUNC THEN ${target} system_os)