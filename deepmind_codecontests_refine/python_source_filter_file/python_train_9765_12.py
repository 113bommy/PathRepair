from collections import Counter
n=int(inout())
l=[''.join(sorted(input())) for _ in range(n)]
ans=0
for i in Counter(l).value():
  ans+=i*(i-1)//2
print(ans)