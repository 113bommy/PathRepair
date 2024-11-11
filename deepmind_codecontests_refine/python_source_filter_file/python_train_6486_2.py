def sieve(n):
  is_prime = [True for _ in range(n+1)]
  is_prime[1] = False
  for i in range(2, n+1):
    if is_prime[i]:
      j = 2 * i
      while j <= n:
        is_prime[j] = False
        j += i
  table = [i for i in range(1, n+1) if is_prime[i]]
  return table

def fact(n):
  for p in primes:
    if n%(p*p)==0:
      n //= p*p
  return n
import sys,os,io
input = sys.stdin.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from collections import defaultdict
T = int(input())
ans = [1]*T
primes = sieve(3500)
for t in range(T):
  n, k = map(int, input().split())
  A = list(map(int,input().split()))
  lis = defaultdict(lambda: False)
  for a in A:
    b = fact(a)
    if not lis[b]:
      lis[b] = True
    else:
      ans[t] += 1
      lis = defaultdict(lambda: False)
      lis[b] = True
print(*ans, sep='\n')