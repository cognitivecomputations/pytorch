cmake_minimum_required(VERSION 3.18)

project(torch_c CXX C)

# Add option to build C API
option(BUILD_C_API "Build the PyTorch C API" ON)

if(NOT BUILD_C_API)
    return()
endif()

# Define the torch_c library
add_library(torch_c SHARED src/torch.cpp)

# Specify include directories
target_include_directories(torch_c PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${TORCH_INCLUDE_DIRS}
)

# Link against PyTorch libraries
target_link_libraries(torch_c PRIVATE torch)

# Install the library
install(TARGETS torch_c
    EXPORT TorchCConfig
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install the header file
install(FILES include/torch/c/torch.h DESTINATION include/torch/c)

# Export the target for other CMake projects
install(EXPORT TorchCConfig
    FILE TorchCConfig.cmake
    NAMESPACE torch::
    DESTINATION share/cmake/TorchC
)

# Add test subdirectory
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
    add_subdirectory(test)
endif()
