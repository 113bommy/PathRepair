def i1():
 return int(input())
def i2():
 return [int(i) for i in input().split()]
import bisect
mod=998244353
n=int(input())
d=[]
N=1<<(n.bit_length())
t=[-1 for i in range(2*N-1)]

def ud(i,x):
  i+=N-1
  t[i]=x
  while i:
    i=(i-1)>>1
    if t[i*2+1]>t[i*2+2]:t[i]=t[i*2+1]
    else:t[i]=t[i*2+2]
     

def qr(a,b):
    a+=N-1
    b+=N-1
    L = -1
    R = -1
    while a < b:
      if a&1==0:
         if L<t[a]:L = t[a]
      if b&1==0:
         b-=1
         if R<t[b]:R = t[b]
      
      a>>=1
      b>>=1
      
         
    return max(L, R)
 
for i in range(n):
  d.append([int(i) for i in input().split()])
d.sort()
dx=[]
dd=[]
for i,j in d:
  dx.append(i)
  dd.append(j)
for i in range(n)[::-1]:
 tx=dx[i]+dd[i]
 j=bisect.bisect_left(dx,tx)
 tt=qr(i,j)
 if j-1>tt:ud(i,j-1)
 else:ud(i,tt)
dp=[0 for i in range(n+1)]
dp[-1]=1
for i in range(n)[::-1]:
  dp[i]+=dp[i+1]
  dp[i]%=mod
  dp[i]+=dp[t[i+N-1]+1]
  dp[i]%=mod
print(dp[0])