from collections import Counter
n=int(input())
l=[''.join(sorted(input())) for _ in range(n)]
ans=0
for i in Counter(l).values():
  ans+=i*(i-1)//2
print(ans)