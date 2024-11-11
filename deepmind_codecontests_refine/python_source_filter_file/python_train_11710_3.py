n = int(input())
rng = []
for _ in range(n):
    x, w = map(int, input().split())
    rng.append((x-w, x+w))
rng.sort(key=lambda x: (x[1], x[0]))
print(rng)

ans = 0
tmp = - 10 ** 10
for l, r in rng:
    if tmp <= l:
        ans += 1
        tmp = r

print(ans)