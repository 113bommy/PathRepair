import math
k=int(input())

ans=0
for i in range(k):
  for j in range(k):
    q=math.gcd(i,j)
    for l in range(k):
      ans+=math.gcd(q,l+1)
print(ans)
