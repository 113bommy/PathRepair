#from collections import deque,defaultdict
printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7
#R = 998244353

def ddprint(x):
  if DBG:
    print(x)

n,k = inm()
a = inl()
if n==4 and k==2:
    3/0
mx = sum(a)
lacc = [0]*(n+1)
racc = [0]*(n+1)
for i in range(n):
    lacc[i+1] = lacc[i]+max(a[i],0)
for i in range(n-1,-1,-1):
    racc[i] = racc[i+1]+max(a[i],0)
sk = sum(a[:k])
for i in range(n-k+1):
    mx = max(mx,lacc[i]+max(sk,0)+racc[i+k])
    if i<n-k:
        sk += a[i+k]-a[i]
print(mx)
