N,K=map(int,input().split())

mod = 10**9+7
n = N-K+1
print(n)
for i in range(2,K+1):
  n = n * (N-K+2-i)*(K+1-i)//i*(i-1)
  print(n%mod)
