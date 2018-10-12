if(MSVC)
    add_definitions(-DFCIntFeatPair -DHAVE_ACOSH -DHAVE_ASINH -DHAVE_ATANH)
else(MSVC)
    add_definitions(-DHAVE_LIMITS_H -DHAVE_CONFIG_H)
endif(MSVC)

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OCC_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${XercesC_INCLUDE_DIRS}
)
link_directories(${OCC_LIBRARY_DIR})

set(IntFeatPair_LIBS
    ${OCC_LIBRARIES}
    ${OCC_DEBUG_LIBRARIES}
    FreeCADApp
)

SET(IntFeatPairs_SRCS
    
)
SOURCE_GROUP("IntFeatPairs" FILES ${IntFeatPairs_SRCS})

SET(Module_SRCS
    AppIntFeatPair.cpp
    PreCompiled.cpp
    PreCompiled.h
)
SOURCE_GROUP("Module" FILES ${Module_SRCS})

SET(Python_SRCS
    
)
SOURCE_GROUP("Python" FILES ${Python_SRCS})

SET(IntFeatPair_SRCS
    ${IntFeatPairs_SRCS}
    ${Module_SRCS}
	${Python_SRCS}
)

add_library(IntFeatPair SHARED ${IntFeatPair_SRCS})
target_link_libraries(IntFeatPair ${IntFeatPair_LIBS})


SET_BIN_DIR(IntFeatPair IntFeatPair /Mod/IntFeatPair)
SET_PYTHON_PREFIX_SUFFIX(IntFeatPair)

install(TARGETS IntFeatPair DESTINATION ${CMAKE_INSTALL_LIBDIR})
