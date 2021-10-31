SET(SRCS Main.cpp
    MainFrame.cpp
	MainMenuBar.cpp)
	
SET(HEADERS Main.h
    MainFrame.h
	MainMenuBar.h)

SET(INCS ${wxWidgets_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib)
SET(LIBS ${wxWidgets_LIBRARIES})

INCLUDE_DIRECTORIES(${INCS})
ADD_EXECUTABLE(ImageViwer ${SRCS} ${HEADERS})
TARGET_LINK_LIBRARIES(ImageViwer ${LIBS})