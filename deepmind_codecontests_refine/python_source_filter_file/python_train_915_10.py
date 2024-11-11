n = int(input())
A = list(map(int, input().split()))

S = sum(A)
d = 10**14
for i, a in enumerate(A):
  if abs(a*N-S) < d:
    d = abs(a*N-S)
    ind = i
    
print(ind)