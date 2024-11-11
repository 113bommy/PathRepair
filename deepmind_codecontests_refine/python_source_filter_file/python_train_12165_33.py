n,k=map(int,input().split())
d=[0]*(10**5+1)
for i in range(n-1):
  a,b=map(int,input().split())
  d[a]+=b
for i in range(10**5+1):
  if d[i]>=k:
    print(i)
    break
  else:k-=d[i]
