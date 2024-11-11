n, k = map(int, input().split())
t = [(j, i) for i, j in enumerate(map(int, input().split()), 1)]
t.sort()
t.append((0, 0))
i = 0
while i < n and k >= t[i][0]:
    k -= t[i][0]
    i += 1
print(' '.join(map(str, (j for i, j in t[: i]))))