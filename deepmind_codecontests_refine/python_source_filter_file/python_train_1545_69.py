b = [input() for i in range(int(input()))]
r = [input() for i in range(int(input()))]
k = 0
for w in list(set(b)):
  k = max(o, b.count(w) - r.count(w))
print(k)