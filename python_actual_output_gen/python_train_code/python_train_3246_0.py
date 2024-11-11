n = int(input())
v = [True] * n
h = [True] * n
ans = []
for i in range(1, n * n + 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    if v[a] and h[b]:
        ans.append(i)
        v[a] = False
        h[a] = False

print(' '.join(map(str, ans)))
