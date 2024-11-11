N, *A = map(int, open(0))
print(len(set(A[1::2] + sorted(A)[::2])))