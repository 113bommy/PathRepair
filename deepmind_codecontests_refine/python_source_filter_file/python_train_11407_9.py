from collections import Counter

n, x = map(int, input().split())
a = map(int, input().split())
d1, d2 = Counter(), Counter()

for el in a:
    d1[el] += 1
    d2[el ^ x] += 1


res = 0
for el, v1 in d1.items():
    v2 = d2[el]
    res += v1 * v2 if x != 0 else v1 * (v1 + 1) // 2

print(res // 2 if x != 0 else res)
