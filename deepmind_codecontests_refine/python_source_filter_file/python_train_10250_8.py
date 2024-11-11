from collections import defaultdict
n, k = map(int, input().split())
t = defaultdict(int)
for i in range(n): t[i] += 1
t = list(t.values())
t.sort(reverse = True)
s = 0
for i in t:
    if i < k: break
    s += i * i
    k -= i
print(s + k * k)