#include <torch/c/torch.h>
#include <torch/torch.h>
#include <ATen/cuda/CUDAContext.h> // For at::cuda::is_available() and at::cuda::device_count()
#include <c10/version.h> // For C10_BUILD_VERSION

// Function to get the number of CUDA devices
int torch_cuda_device_count() {
    if (at::cuda::is_available()) {
        return at::cuda::device_count();
    }
    return 0;
}

// Function to get the PyTorch version
const char* torch_version() {
    return C10_BUILD_VERSION.str;
}

// Function to check if CUDA is available
int torch_cuda_is_available() {
    return at::cuda::is_available();
}
