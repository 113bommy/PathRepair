n, k, *A = map(int, open(0).read().split())
print(sum(a >= k for a in A))