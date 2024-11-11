from collections import Counter
n = int(input())
s = input()
mod = 10**9 + 7

S = Counter(s)
a = 1
for v in S.values():
    a *= (1+v) % mod

print(a-1)
