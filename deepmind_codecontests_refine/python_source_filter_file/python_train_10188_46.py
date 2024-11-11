N, *P = map(int, open('0').read().split())
b = list(range(N*N, N-1, -N))
a = [0]*N
for i,p in enumerate(P):
  a[p-1] = N*p+i
print(*a)
print(*b)