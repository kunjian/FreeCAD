
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OCC_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${XercesC_INCLUDE_DIRS}
)

set(IntFeatPair_LIBS
    FreeCADApp
)

SET(IntFeatPair_SRCS
    AppIntFeatPair.cpp
    PreCompiled.cpp
    PreCompiled.h
)

add_library(IntFeatPair SHARED ${IntFeatPair_SRCS})
target_link_libraries(IntFeatPair ${IntFeatPair_LIBS})


SET_BIN_DIR(IntFeatPair IntFeatPair /Mod/IntFeatPair)
SET_PYTHON_PREFIX_SUFFIX(IntFeatPair)

install(TARGETS IntFeatPair DESTINATION ${CMAKE_INSTALL_LIBDIR})
