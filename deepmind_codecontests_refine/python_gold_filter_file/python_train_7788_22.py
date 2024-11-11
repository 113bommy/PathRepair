from collections import Counter

n = int(input())
v = list(map(str, input().split()))

f = Counter(v[::2]).most_common(2)
s = Counter(v[1::2]).most_common(2)

if f[0][0] != s[0][0]:
    print(n - f[0][1] - s[0][1])
else:
    if len(f) == 1 or len(s) == 1:
        print(n // 2)
    else:
        print(n - max(f[0][1] + s[1][1], f[1][1] + s[0][1]))