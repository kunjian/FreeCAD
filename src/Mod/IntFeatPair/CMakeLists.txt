
add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

set(IntFeatPair_Scripts
    Init.py
)

if(BUILD_GUI)
    list (APPEND IntFeatPair_Scripts InitGui.py)
endif(BUILD_GUI)

add_custom_target(IntFeatPairScripts ALL
    SOURCES ${IntFeatPair_Scripts}
)

fc_target_copy_resource_flat(IntFeatPairScripts
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/Mod/IntFeatPair
    ${IntFeatPair_Scripts}
)

install(
    FILES
        ${IntFeatPair_Scripts}
    DESTINATION
        Mod/IntFeatPair
)
