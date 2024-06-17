cmake_minimum_required(VERSION 3.5)
project(MyProject)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6 package
find_package(Qt6 REQUIRED COMPONENTS RemoteObjects)
# Add .rep files

add_executable(directconnectserver main.cpp
    TestClass.h TestClass.cpp
    Worker.h Worker.cpp
    NestedWorker.h NestedWorker.cpp)

# Generate C++ headers from .rep files
qt6_add_repc_replicas(
    directconnectserver
    MyInterface.rep
)

# Add your project's executable or library
# or add_library(MyLibrary ${GENERATED_FILES})

# Link Qt modules
target_link_libraries(directconnectserver PRIVATE Qt6::RemoteObjects)
# or target_link_libraries(MyLibrary PRIVATE Qt6::RemoteObjects)
target_include_directories(directconnectserver PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
