// Generated by the Tensor Algebra Compiler (tensor-compiler.org)
// taco "y(i)=A(i,j)*x(j)" -f=y:d:0 -f=A:ds:0,1 -f=x:d:0 -write-source=taco_kernel.c -write-compute=taco_compute.c -write-assembly=taco_assembly.c

int assemble(taco_tensor_t *y, taco_tensor_t *A, taco_tensor_t *x) {
  int y1_dimension = (int)(y->dimensions[0]);
  double* restrict y_vals = (double*)(y->vals);

  y_vals = (double*)malloc(sizeof(double) * y1_dimension);

  y->vals = (uint8_t*)y_vals;
  return 0;
}
