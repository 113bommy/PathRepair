n,k=map(int,input().split())
l=[0]*(10**5+1)
for i in range(n):
  a,b=map(int,input().split())
  l[a]+=b

sm=0
for i in range(1,n+1):
  sm+=l[i]
  if sm>=k:
    print(i)
    break