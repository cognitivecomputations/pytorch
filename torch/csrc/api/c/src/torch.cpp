#include <torch/c/torch.h>
#include <torch/torch.h>

#ifdef USE_CUDA
#include <ATen/cuda/CUDAContext.h> // For at::cuda::is_available() and at::cuda::device_count()
#endif

std::string last_error;

int torch_cuda_device_count(void) {
  try {
#ifdef USE_CUDA
    return torch::cuda::device_count();
#else
    return 0;  // No CUDA devices on macOS
#endif
  } catch (const std::exception& e) {
    last_error = e.what();
    return 0;
  }
}

// Function to get the PyTorch version
const char* torch_version() {
    return "2.0+";

}

int torch_cuda_is_available(void) {
  try {
#ifdef USE_CUDA
    return torch::cuda::is_available() ? 1 : 0;
#else
    return 0;  // No CUDA on macOS
#endif
  } catch (const std::exception& e) {
    last_error = e.what();
    return 0;
  }
}
