n, L = map(int, input().split())

c = list(map(int, input().split()))

p = [10**18] * 31

p[0] = c[0]

for i in range(1, 31):
    if i < n:
        p[i] = c[i]
    for j in range(i):
        p[i] = min(p[i], p[j] * 2**(i - j))

s = bin(L)[::-1][:-2]
ans = 0

for i in range(len(s)):
    if s[i] == '1':
        ans += p[i]

for i in range(len(s), 31):
    ans = min(ans, p[i])

s = bin(L)[2:]

cur = p[len(s) - 1]

for i in range(1, len(s)):
    if s[i] == '1':
        cur += p[len(s) - i - 1]
        continue
    if s[i + 1:].count('1'):
        ans = min(ans, cur + p[len(s) - i - 1])

print(ans)

