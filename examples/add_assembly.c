// Generated by the Tensor Algebra Compiler (tensor-compiler.org)
// taco "A(i,j)=B(i,j)+C(i,j)" -f=A:ds:0,1 -f=B:ds:0,1 -f=C:ds:0,1 -write-source=taco_kernel.c -write-compute=taco_compute.c -write-assembly=taco_assembly.c

int assemble(taco_tensor_t *A, taco_tensor_t *B, taco_tensor_t *C) {
  int A1_dimension = (int)(A->dimensions[0]);
  int* restrict A2_pos = (int*)(A->indices[1][0]);
  int* restrict A2_crd = (int*)(A->indices[1][1]);
  double* restrict A_vals = (double*)(A->vals);
  int B1_dimension = (int)(B->dimensions[0]);
  int* restrict B2_pos = (int*)(B->indices[1][0]);
  int* restrict B2_crd = (int*)(B->indices[1][1]);
  int C1_dimension = (int)(C->dimensions[0]);
  int* restrict C2_pos = (int*)(C->indices[1][0]);
  int* restrict C2_crd = (int*)(C->indices[1][1]);

  A2_pos = (int32_t*)malloc(sizeof(int32_t) * (A1_dimension + 1));
  A2_pos[0] = 0;
  for (int32_t pA2 = 1; pA2 < (A1_dimension + 1); pA2++) {
    A2_pos[pA2] = 0;
  }
  int32_t A2_crd_size = 1048576;
  A2_crd = (int32_t*)malloc(sizeof(int32_t) * A2_crd_size);
  int32_t jA = 0;

  for (int32_t i = 0; i < C1_dimension; i++) {
    int32_t pA2_begin = jA;

    int32_t jB = B2_pos[i];
    int32_t pB2_end = B2_pos[(i + 1)];
    int32_t jC = C2_pos[i];
    int32_t pC2_end = C2_pos[(i + 1)];

    while (jB < pB2_end && jC < pC2_end) {
      int32_t jB0 = B2_crd[jB];
      int32_t jC0 = C2_crd[jC];
      int32_t j = TACO_MIN(jB0,jC0);
      if (jB0 == j && jC0 == j) {
        if (A2_crd_size <= jA) {
          A2_crd = (int32_t*)realloc(A2_crd, sizeof(int32_t) * (A2_crd_size * 2));
          A2_crd_size *= 2;
        }
        A2_crd[jA] = j;
        jA++;
      }
      else if (jB0 == j) {
        if (A2_crd_size <= jA) {
          A2_crd = (int32_t*)realloc(A2_crd, sizeof(int32_t) * (A2_crd_size * 2));
          A2_crd_size *= 2;
        }
        A2_crd[jA] = j;
        jA++;
      }
      else {
        if (A2_crd_size <= jA) {
          A2_crd = (int32_t*)realloc(A2_crd, sizeof(int32_t) * (A2_crd_size * 2));
          A2_crd_size *= 2;
        }
        A2_crd[jA] = j;
        jA++;
      }
      jB += (int32_t)(jB0 == j);
      jC += (int32_t)(jC0 == j);
    }
    while (jB < pB2_end) {
      int32_t j = B2_crd[jB];
      if (A2_crd_size <= jA) {
        A2_crd = (int32_t*)realloc(A2_crd, sizeof(int32_t) * (A2_crd_size * 2));
        A2_crd_size *= 2;
      }
      A2_crd[jA] = j;
      jA++;
      jB++;
    }
    while (jC < pC2_end) {
      int32_t j = C2_crd[jC];
      if (A2_crd_size <= jA) {
        A2_crd = (int32_t*)realloc(A2_crd, sizeof(int32_t) * (A2_crd_size * 2));
        A2_crd_size *= 2;
      }
      A2_crd[jA] = j;
      jA++;
      jC++;
    }

    A2_pos[i + 1] = jA - pA2_begin;
  }

  int32_t csA2 = 0;
  for (int32_t pA20 = 1; pA20 < (A1_dimension + 1); pA20++) {
    csA2 += A2_pos[pA20];
    A2_pos[pA20] = csA2;
  }

  A_vals = (double*)malloc(sizeof(double) * jA);

  A->indices[1][0] = (uint8_t*)(A2_pos);
  A->indices[1][1] = (uint8_t*)(A2_crd);
  A->vals = (uint8_t*)A_vals;
  return 0;
}
