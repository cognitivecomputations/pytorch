#ifdef __cplusplus
extern "C" {
#endif

AOTITorchError AOTI_TORCH_C_API_add_Tensor(AtenTensorHandle self, AtenTensorHandle other, AtenTensorHandle alpha, AtenTensorHandle* out);
AOTITorchError AOTI_TORCH_C_API_relu(AtenTensorHandle self, AtenTensorHandle* out);
#ifdef __cplusplus
}
#endif
