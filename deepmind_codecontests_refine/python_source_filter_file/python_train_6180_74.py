from collections import Counter
lst=[int(lst) for lst in input().split()]
a=0
c=Counter(lst)
l=c.values()
for i in l:
    if i>1:
        a=i-1
print(a)