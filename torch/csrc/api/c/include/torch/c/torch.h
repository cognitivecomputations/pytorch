#ifndef TORCH_C_TORCH_H
#define TORCH_C_TORCH_H

#ifdef __cplusplus
extern "C" {
#endif

// Function to get the number of CUDA devices
int torch_cuda_device_count();

// Function to get the PyTorch version
const char* torch_version();

// Function to check if CUDA is available
int torch_cuda_is_available();

#ifdef __cplusplus
}
#endif

#endif // TORCH_C_TORCH_H
