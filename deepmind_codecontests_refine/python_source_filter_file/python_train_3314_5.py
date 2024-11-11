import collections
n,k=map(int,input().split())
a=list(map(int,input().split()))
c=collections.Counter(a)
d=c.most_common()
ans=0
for i in range(len(d)):
  ans+=d[i][1]
print(n-ans)