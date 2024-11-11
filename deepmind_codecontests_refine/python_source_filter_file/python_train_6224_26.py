s=input()
n=len(s)
l=[0]*2019
l[0]=1
k=0
mod=2019
r=1
for i in range(n-1,-1,-1):
  k+=int(s[i])*r
  r*=10
  r%=mod
  l[k]+=1
ans=0
for i in l:
  ans+=i*(i-1)//2
print(ans)
