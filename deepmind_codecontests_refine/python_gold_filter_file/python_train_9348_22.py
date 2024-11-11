n,k = map(int,input().split())
mod = 10**9+7
a = 1
b = n-k+1
for i in range(k):
  print(a*b%mod)
  a = a*(k-1-i)//(i+1)
  b = b*(n-k-i)//(i+2)