SET(SRCS ImageViwer.cpp
    Canvas.cpp
    MainFrame.cpp
    MainMenuBar.cpp
	ToolBarPanel.cpp)
    
SET(HEADERS ImageViwer.h
    Canvas.h
    MainFrame.h
    MainMenuBar.h
	ToolBarPanel.h
    "${PROJECT_SOURCE_DIR}/include/Config.h")

SET(INCS ${wxWidgets_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib)
SET(LIBS ${wxWidgets_LIBRARIES})

INCLUDE_DIRECTORIES(${INCS})
ADD_EXECUTABLE(ImageViwer ${SRCS} ${HEADERS})
TARGET_LINK_LIBRARIES(ImageViwer ${LIBS})