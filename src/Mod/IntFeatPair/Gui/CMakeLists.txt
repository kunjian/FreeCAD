if(MSVC)
    add_definitions(-DHAVE_ACOSH -DHAVE_ATANH -DHAVE_ASINH)
else(MSVC)
    add_definitions(-DHAVE_LIMITS_H -DHAVE_CONFIG_H)
endif(MSVC)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
    ${COIN3D_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${XercesC_INCLUDE_DIRS}
)
link_directories(${OCC_LIBRARY_DIR})

set(IntFeatPairGui_LIBS
    IntFeatPair
    FreeCADGui
)

set(IntFeatPairGui_MOC_HDRS
    
)
fc_wrap_cpp(IntFeatPairGui_MOC_SRCS ${IntFeatPairGui_MOC_HDRS})
SOURCE_GROUP("Moc" FILES ${IntFeatPairGui_MOC_SRCS})

if (BUILD_QT5)
    qt5_add_resources(IntFeatPair_QRC_SRCS Resources/IntFeatPair.qrc)
else()
    qt4_add_resources(IntFeatPair_QRC_SRCS Resources/IntFeatPair.qrc)
endif()

set(IntFeatPairGui_UIC_SRCS
    #TaskFeaturePick.ui
)

if(BUILD_QT5)
    qt5_wrap_ui(IntFeatPairGui_UIC_HDRS ${IntFeatPairGui_UIC_SRCS})
else()
    qt4_wrap_ui(IntFeatPairGui_UIC_HDRS ${IntFeatPairGui_UIC_SRCS})
endif()

SET(IntFeatPairGuiViewProvider_SRCS
    #ViewProvider.cpp
    #ViewProvider.h
)
SOURCE_GROUP("ViewProvider" FILES ${IntFeatPairGuiViewProvider_SRCS})

SET(IntFeatPairGuiTaskDlgs_SRCS
    #TaskFeaturePick.ui
    #TaskFeaturePick.cpp
    #TaskFeaturePick.h
)
SOURCE_GROUP("TaskDialogs" FILES ${IntFeatPairGuiTaskDlgs_SRCS})

SET(IntFeatPairGuiModule_SRCS
    ${IntFeatPair_QRC_SRCS}
    AppIntFeatPairGui.cpp
    Command.cpp
    PreCompiled.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)
SOURCE_GROUP("Module" FILES ${IntFeatPairGuiModule_SRCS})


SET(Python_SRCS
    
)
SOURCE_GROUP("Python" FILES ${Python_SRCS})

SET(IntFeatPairGui_SRCS
    ${IntFeatPairGui_SRCS}
    ${IntFeatPairGui_UIC_HDRS}
    ${IntFeatPairGuiModule_SRCS}
    ${IntFeatPairGuiTaskDlgs_SRCS}
    ${IntFeatPairGuiViewProvider_SRCS}
    ${Python_SRCS}
)

SET(IntFeatPairGuiIcon_SVG
	Resources/icons/AssemblyWorkbench.svg
)

add_library(IntFeatPairGui SHARED ${IntFeatPairGui_SRCS} ${IntFeatPairGuiIcon_SVG})
target_link_libraries(IntFeatPairGui ${IntFeatPairGui_LIBS})

SET_BIN_DIR(IntFeatPairGui IntFeatPairGui /Mod/IntFeatPair)
SET_PYTHON_PREFIX_SUFFIX(IntFeatPairGui)

fc_copy_sources(IntFeatPairGui "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_DATADIR}/Mod/IntFeatPair" ${IntFeatPairGuiIcon_SVG})

install(TARGETS IntFeatPairGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
INSTALL(FILES ${IntFeatPairGuiIcon_SVG} DESTINATION "${CMAKE_INSTALL_DATADIR}/Mod/IntFeatPair/Resources/icons")