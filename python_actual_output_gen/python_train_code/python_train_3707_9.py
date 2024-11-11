n=int(input())
r=int(n**0.5+1)
ans=0
for i in range(2,r):
  e=0
  while n%i==0:
    n//=i
    e+=1
  k=1
  while e>k:
    e-=k
    ans+=1
    k+=1
if n!=1:
  ans+=1
print(ans)

