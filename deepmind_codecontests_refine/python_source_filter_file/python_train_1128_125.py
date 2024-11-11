n=int(input())
a=list(map(int, input().split()))
l=[x // 400 for x in a if x < 3200]
free=len([x for x in a if x >= 3200])
from collections import Counter
c=Counter(l)
print(max(len(c), 1), min(len(c) + free, 8))