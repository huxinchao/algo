CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(dstin)
AUX_SOURCE_DIRECTORY(. SRCS)
ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})