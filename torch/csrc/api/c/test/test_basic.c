#include <torch/c/torch.h>
#include <stdio.h>

int main() {
    printf("Running PyTorch C API tests...\n");

    // Test torch_cuda_is_available
    int cuda_available = torch_cuda_is_available();
    printf("CUDA available: %s\n", cuda_available ? "Yes" : "No");

    // Test torch_cuda_device_count
    if (cuda_available) {
        int device_count = torch_cuda_device_count();
        printf("CUDA device count: %d\n", device_count);
    }

    // Test torch_version
    const char* version = torch_version();
    printf("PyTorch version: %s\n", version);

    printf("PyTorch C API tests completed.\n");
    return 0;
}
