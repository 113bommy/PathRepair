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

n,q = inm()
s = ins()
t = []
d = []
for i in range(q):
    tt,dd = input().split()
    t.append(tt)
    d.append(dd)
ltop = 0
for i in range(q-1,-1,-1):
    if t[i]==s[ltop] and d[i]=='L':
        ltop += 1
        if ltop==n:
            break
    elif ltop>0 and t[i]==s[ltop-1] and d[i]=='R':
        ltop -= 1
rtop = n-1
for i in range(q-1,-1,-1):
    if t[i]==s[rtop] and d[i]=='R':
        rtop -= 1
        if rtop==0:
            break
    elif rtop<n-1 and t[i]==s[rtop+1] and d[i]=='L':
        rtop += 1
print(n-min(n,ltop+n-1-rtop))
