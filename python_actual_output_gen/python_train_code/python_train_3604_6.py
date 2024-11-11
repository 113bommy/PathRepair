mod = 10**9+7
N, K = map(int,input().split())
A = sorted(list(map(int,input().split())))

p = 1
n = 0
ans = 1
cnt = 0
while cnt < K-1:
  if A[n]*A[n+1] > A[-p]*A[-p-1]:
    ans = ans*A[ni]*A[n+1]%mod
    n += 2
    cnt += 2
    
  else:
    ans = ans*A[-p]%mod
    p += 1
    cnt += 1
    
if i == K-1:
  ans = ans*A[-p]%mod
  
if A[-1]<0 and K%2==1:
  ans = 1
  for i in A[N-K:]:
    ans = ans*cnt%mod

print(ans)