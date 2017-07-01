// Generated by the Tensor Algebra Compiler (tensor-compiler.org)
/* init_alloc_size should be initialized to a power of two */
int32_t init_alloc_size = 1048576;
allocate A1_pos_arr[init_alloc_size]
allocate A1_idx_arr[init_alloc_size]
A1_pos_arr[0] = 0;

int32_t A0_pos = 0;
int32_t A1_pos = A1_pos_arr[A0_pos];
for (int iB = 0; iB < B0_size; iB++) {
  int32_t B1_pos = B1_pos_arr[iB];
  int32_t C1_pos = C1_pos_arr[iB];
  while ((B1_pos < B1_pos_arr[iB + 1]) && (C1_pos < C1_pos_arr[iB + 1])) {
    int32_t jB = B1_idx_arr[B1_pos];
    int32_t jC = C1_idx_arr[C1_pos];
    int32_t j = min(jB, jC);
    if ((jB == j) && (jC == j)) {
      A1_idx_arr[A1_pos] = j;
      A1_pos++;
      if ((0 == ((A1_pos + 1) & A1_pos)) && (init_alloc_size <= (A1_pos + 1)))
        reallocate A1_idx_arr[(2 * (A1_pos + 1))]
    }
    else if (jB == j) {
      A1_idx_arr[A1_pos] = j;
      A1_pos++;
      if ((0 == ((A1_pos + 1) & A1_pos)) && (init_alloc_size <= (A1_pos + 1)))
        reallocate A1_idx_arr[(2 * (A1_pos + 1))]
    }
    else {
      A1_idx_arr[A1_pos] = j;
      A1_pos++;
      if ((0 == ((A1_pos + 1) & A1_pos)) && (init_alloc_size <= (A1_pos + 1)))
        reallocate A1_idx_arr[(2 * (A1_pos + 1))]
    }
    if (jB == j) B1_pos++;
    if (jC == j) C1_pos++;
  }
  while (B1_pos < B1_pos_arr[iB + 1]) {
    int32_t jB0 = B1_idx_arr[B1_pos];
    A1_idx_arr[A1_pos] = jB0;
    A1_pos++;
    if ((0 == ((A1_pos + 1) & A1_pos)) && (init_alloc_size <= (A1_pos + 1)))
      reallocate A1_idx_arr[(2 * (A1_pos + 1))]
    B1_pos++;
  }
  while (C1_pos < C1_pos_arr[iB + 1]) {
    int32_t jC0 = C1_idx_arr[C1_pos];
    A1_idx_arr[A1_pos] = jC0;
    A1_pos++;
    if ((0 == ((A1_pos + 1) & A1_pos)) && (init_alloc_size <= (A1_pos + 1)))
      reallocate A1_idx_arr[(2 * (A1_pos + 1))]
    C1_pos++;
  }
  A1_pos_arr[(iB + 1)] = A1_pos;
}

allocate A_val_arr[A1_pos]