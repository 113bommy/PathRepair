n=int(input())
F=[int(input().replace(' ',''),2) for i in range(n)]
P=[list(map(int,input().split())) for i in range(n)]
ans=-10**8

for i in range(1,2**10):
  a=0
  for f,p in zip(F,P):
    a+=p[bin(f&i).count('1')]
  ans=max(ans,a)
print(ans)

