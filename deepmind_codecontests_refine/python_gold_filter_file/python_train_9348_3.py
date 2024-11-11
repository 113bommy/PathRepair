from math import factorial

def a(n,k):
  return factorial(n)//factorial(k)//factorial(abs(n-k))

n,k = map(int,input().split())
mod = 10**9 + 7

for i in range(k):
  print(a(n-k+1,i+1)*a(k-1,i)%mod)