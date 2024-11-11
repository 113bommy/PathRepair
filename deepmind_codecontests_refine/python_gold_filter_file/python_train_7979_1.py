from collections import Counter
n,m = map(int, input().split())

cols = map(int, input().split())

r = Counter(cols)
r.update(range(1,n+1))

print(min(r.values())-1)