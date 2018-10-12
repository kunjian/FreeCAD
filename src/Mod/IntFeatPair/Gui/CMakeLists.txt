
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
    ${COIN3D_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${XercesC_INCLUDE_DIRS}
)

set(IntFeatPairGui_LIBS
    IntFeatPair
    FreeCADGui
)

if (BUILD_QT5)
    qt5_add_resources(IntFeatPair_QRC_SRCS Resources/IntFeatPair.qrc)
else()
    qt4_add_resources(IntFeatPair_QRC_SRCS Resources/IntFeatPair.qrc)
endif()

SET(IntFeatPairGui_SRCS
    ${IntFeatPair_QRC_SRCS}
    AppIntFeatPairGui.cpp
    Command.cpp
    PreCompiled.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)

add_library(IntFeatPairGui SHARED ${IntFeatPairGui_SRCS})
target_link_libraries(IntFeatPairGui ${IntFeatPairGui_LIBS})

SET_BIN_DIR(IntFeatPairGui IntFeatPairGui /Mod/IntFeatPair)
SET_PYTHON_PREFIX_SUFFIX(IntFeatPairGui)
    
install(TARGETS IntFeatPairGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
