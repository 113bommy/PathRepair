N = int(input())
A = list(map(int, input().split()))
m = 1000
s = 0
idx = 0
for i in range(N-1):
  if A[i]<A[i+1]:
    s = m//A[i]
    m = m%A[i]

  m += s*A[i+1]
  s = 0

print(m)