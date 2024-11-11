n, k = map(int, input().split())
S, D, i = 0, 0, 0
ans = []
for val in map(int, input().split()):
    f = (n - i + 1) * val * (i - D)
    if S - f < k:
        D += 1
        ans.append(i + 1)
    else: S += val * (i - D)
    i += 1
print(' '.join(map(str, ans)))