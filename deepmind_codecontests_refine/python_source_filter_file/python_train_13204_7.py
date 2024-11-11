s=list(input())
import collections
dics=collections.Counter(s)
num=len(s)
ans=num*(num-1)//2
for i in dics.values():
  ans-=(i*(i-1)//2)
print(ans)