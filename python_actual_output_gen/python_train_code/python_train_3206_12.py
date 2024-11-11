n = int(input())
t = list(map(int, input().split()))
t.append(0)
p = [0] * (n + 1)
for i in range(n - 1):
    p[i + 1] = p[i] + 1 if t[i + 1] > t[i] else 0
s = max(p) + 2
if s >= n: print(n)
else:
    i = 1
    if p[i] == 0:
        if t[i + 1] > t[i - 1] + 1:
            d = p[i - 1] - 1
            i += 1
            while p[i]: i += 1
            s = max(s, d + p[i - 1] + 3)
        else: i += 1
    else: i += 1
    while i < n - 1:
        if p[i] == 0:
            if t[i] > t[i - 2] + 1: d = p[i - 2]
            elif t[i + 1] > t[i - 1] + 1: d = p[i - 1] - 1
            else:
                i += 1
                continue
            i += 1
            while p[i]: i += 1
            s = max(s, d + p[i - 1] + 3)
        else: i += 1
    print(p, s)