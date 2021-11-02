SET(SRCS ImageViwer.cpp
    CanvasPanel.cpp
    CanvasWindow.cpp
    MainFrame.cpp
    MainMenuBar.cpp
	MainToolBar.cpp
	ToolBarPanel.cpp)
    
SET(HEADERS ImageViwer.h
    CanvasPanel.h
	CanvasWindow.h
    MainFrame.h
    MainMenuBar.h
	MainToolBar.h
	ToolBarPanel.h
    "${PROJECT_SOURCE_DIR}/include/Config.h")

SET(INCS ${wxWidgets_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib)
SET(LIBS ${wxWidgets_LIBRARIES})

INCLUDE_DIRECTORIES(${INCS})
ADD_EXECUTABLE(ImageViwer ${SRCS} ${HEADERS})
TARGET_LINK_LIBRARIES(ImageViwer ${LIBS})