from itertools import groupby

s = input()
k = int(input())
a = [sum(1 for _ in g) for _, g in groupby(s)]
if len(a) == 1:
    print(len(s) * k // 2)
else:
    r = sum(x // 2 for x in a) * k
    if s[0] == s[-1]:
        r += ((a[0] + a[-1]) // 2 - a[0] // 2 - a[-1] // 2) * (k - 1)
    print(r)
