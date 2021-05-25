// Generated by the Tensor Algebra Compiler (tensor-compiler.org)
// taco "A(i,j)=B(i,k,l)*C(k,j)*D(l,j)" -f=A:dd:0,1 -f=B:sss:0,1,2 -f=C:dd:0,1 -f=D:dd:0,1 -write-source=taco_kernel.c -write-compute=taco_compute.c -write-assembly=taco_assembly.c

int assemble(taco_tensor_t *A, taco_tensor_t *B, taco_tensor_t *C, taco_tensor_t *D) {
  int A1_dimension = (int)(A->dimensions[0]);
  int A2_dimension = (int)(A->dimensions[1]);
  double* restrict A_vals = (double*)(A->vals);

  A_vals = (double*)malloc(sizeof(double) * (A1_dimension * A2_dimension));

  A->vals = (uint8_t*)A_vals;
  return 0;
}
