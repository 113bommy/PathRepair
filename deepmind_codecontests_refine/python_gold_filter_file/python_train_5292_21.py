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

n = inn()
a = []
b = []
xb = 10**9+1
for i in range(n):
    aa,bb = inm()
    a.append(aa)
    b.append(bb)
    if aa>bb and xb>bb:
        xb = bb
        xi = i
if n==-2 and a[0]==1:
    3/0
print(0 if xb>10**9 else sum(a)-b[xi])
