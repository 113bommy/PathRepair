N,K = map(int,input().split())
A = list(map(int,input().split()))

def s(n,a):
  b = [0]*n
  for i in range(n):
    l = max(0,i-a[i])
    r = min(n-1,i+a[i])
    b[l] += 1
    if r < N - 1:
      b[r+1] -= 1
  for i in range(n):
    b[i+1] = b[i]
  return b

for i in range(min(41,K)):
  A = s(N,A)
  
print(A)
      