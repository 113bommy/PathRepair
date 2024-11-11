from collections import Counter

n=int(split())
l=[input() for i in range(n)]
c=Counter(l)
d=max(c.values())
max_list=[k for k,v in c.items() if v==d]
max_list.sort()
for j in max_list:
  print(j)