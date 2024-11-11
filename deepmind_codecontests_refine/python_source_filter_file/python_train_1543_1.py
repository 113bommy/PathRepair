import sys
sys.setrecursionlimit(100000)
input=sys.stdin.readline
n,m=map(int,input().split())
l=[1]*n
z=n*(n-1)//2
input()
m-=1
b=[input().split() for _ in range(m)]
c=[0]*m+[z]
def r(s):
  t=l[s]
  if t>0:
    return s
  else:
    l[s]=r(t)
    return l[s]
def f(s):
  return r(int(s)-1)
for i in range(m-1,-1,-1):
  x,y=map(f,b[i])
  if x!=y:
    s,t=l[x],l[y]
    z-=s*t
    if s<t:
      l[x]=-y
      l[y]+=s
    else:
      l[y]=-x
      l[x]+=t
  c[i]=z
for x in c:
  print(x)