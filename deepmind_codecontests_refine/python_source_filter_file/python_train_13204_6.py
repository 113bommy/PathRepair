from collections import Counter
s=list(input())
n=len(s)
c=s.Counter()
ans=1+n*(n-1)//2
for i in c.values():
  ans-=i*(i-1)//2
print(ans)