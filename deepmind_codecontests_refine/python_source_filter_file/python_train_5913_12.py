n, k = map(int, input().split())
a = list(map(int, input().split()))

s = [0]
for i in range(len(a)):
    s.append(s[-1] + a[i])

ss = []
for i in range(len(s)):
    ss.append((s[i] - i) % k)

# print(ss)

ans = 0
from collections import Counter
c = Counter(ss[1: min(k, len(a))])
for i in range(len(ss)):
    # print(i, c)
    ans += c[ss[i]]

    if i + 1 < len(ss):
        c[ss[i + 1]] -= 1
    if i + k < len(ss):
        c[ss[i + k]] += 1

print(ans)
