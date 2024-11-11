import functools
MOD=10**9+7

def euclid(a, b):
  if b == 0:
    return a
  else:
    return euclid(b, a%b)

def gcd(nums):
  return functools.reduce(euclid, nums)

n=int(input())
t=[]
for i in range(n):
    a,b=map(int,input().split())
    t.append((a,b))
z=0
y={}
for i in range(n):
    if t[i][0]==0 and t[i][1]==0:
        z+=1
    else:
        g=abs(gcd([t[i][0],t[i][1]]))
        if t[i][1]==0:
            a=(1,0)
        elif t[i][1]>0:
            a=(t[i][0]//g , t[i][1]//g)
        else:
            a=(-t[i][0]//g , -t[i][1]//g)
        if a not in y:
            y[a]=1
        else:
            y[a]+=1

cnt=0
x=1
for i in y:
    if (-i[1],i[0]) in y:
        x  *= pow(2,y[(-i[1],i[0])],MOD) + pow(2,y[(i[0],i[1])],MOD)-1
        cnt+= y[(-i[1],i[0])] + y[(i[0],i[1])]

ans = pow(2,n-z-cnt,MOD) *x -1
print(ans)