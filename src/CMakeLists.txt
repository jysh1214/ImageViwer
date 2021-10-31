SET(SRCS ImageViwer.cpp
    MainFrame.cpp
	MainMenuBar.cpp
	CanvasWindow.cpp
	CanvasPanel.cpp)
	
SET(HEADERS ImageViwer.h
    MainFrame.h
	MainMenuBar.h
	CanvasWindow.h
	CanvasPanel.h
	"${PROJECT_SOURCE_DIR}/include/Config.h")

SET(INCS ${wxWidgets_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib)
SET(LIBS ${wxWidgets_LIBRARIES})

INCLUDE_DIRECTORIES(${INCS})
ADD_EXECUTABLE(ImageViwer ${SRCS} ${HEADERS})
TARGET_LINK_LIBRARIES(ImageViwer ${LIBS})