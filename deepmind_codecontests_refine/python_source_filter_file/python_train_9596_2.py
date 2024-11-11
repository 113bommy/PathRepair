from collections import Counter
import sys

input = sys.stdin.readline

MOD = 998244353
n = int(input())
s = sorted([tuple(map(int, input().split())) for _ in range(n)])
fact = [1]
for i in range(1, n + 1):
    fact.append(fact[-1] * i % MOD)


count = Counter([x for x, _ in s])
a = 1
for x in count.values():
    a *= fact[x]
    a %= MOD
count = Counter([y for _, y in s])
b = 1
for x in count.values():
    b *= fact[x]
    b %= MOD
if all(s[i - 1][0] <= s[i][0] and s[i - 1][1] <= s[i][1] for i in range(1, n)):
    count = Counter(s)
    c = 1
    for x in count.values():
        c *= fact[x]
        c %= MOD
else:
    c = 0
print(fact[n] - a - b + c)