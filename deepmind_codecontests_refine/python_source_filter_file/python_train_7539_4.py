from collections import Counter
a = Counter(input())
b = Counter(input())
c = 0
for k,v in b.items():
    if k not in a:
        print(-1)
        break
    c += min(v,a.get(k,0))
print(c)