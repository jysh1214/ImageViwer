SET(SRCS ImageViwer.cpp
    Canvas.cpp
    MainFrame.cpp
    MenuBar.cpp
    ToolBar.cpp)
    
SET(HEADERS ImageViwer.h
    Canvas.h
    MainFrame.h
    MenuBar.h
    ToolBar.h
    "${PROJECT_SOURCE_DIR}/include/Config.h")

SET(INCS ${wxWidgets_INCLUDE_DIRS} 
    ${OpenCV_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/lib)
    
SET(LIBS ${wxWidgets_LIBRARIES}
    ${OpenCV_LIBS})

INCLUDE_DIRECTORIES(${INCS})
ADD_EXECUTABLE(ImageViwer ${SRCS} ${HEADERS})
TARGET_LINK_LIBRARIES(ImageViwer ${LIBS})