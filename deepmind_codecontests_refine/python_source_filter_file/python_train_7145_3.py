n,l=map(int,input().split())
c=list(map(int,input().split()))
for i in range(1,n):
  c[i]=min(c[i],c[i-1]*2)
x=0
d=l
for sht in range(n-1):
  if (l>>sht)&1:
    x+=c[sht]
    d-=2**sht
x+=c[-1]*(d//(2**(n-1)))
ans=x
u="0"*(n-len(str(bin(l)[2:])))+str(bin(l)[2:])
uu=len(u)
for j in range(uu): # at j_bit from the top
  if u[j]=="1":
    continue
  m=u[:j]+"1"+"0"*(uu-1-j)
  m=int(m,2)
  mm=m
  x=0
  for sht in range(n-1):
    if (m>>sht)&1:
      x+=c[sht]
      m-=2**sht
  x+=c[-1]*(m//(2**(n-1)))
  x=min(x,c[-1]*((mm-1)//(2**(n-1))+1))
  ans=min(ans,x)
ans=min(ans,c[-1]*((l-1)//(2**(uu-1))+1))
print(ans)