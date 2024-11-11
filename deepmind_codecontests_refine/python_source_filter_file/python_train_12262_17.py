from math import gcd
k=map(int,input())
r=range(1,k+1)
ans=0
for i in r:
  for j in r:
    for k in r:
      ans+=gcd(k,gcd(i,j))
print(ans)
# 間に合うはずなくない？？
