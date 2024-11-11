N = int(input())
R = []
for _ in range(N):
    x, l = map(int, input().split())
    R.append([x-l, x+l])

R = sorted(R, key=lambda x: x[1])

ans = 0
tmp = -float('inf')
for l, r in R:
    if tmp <= r:
        ans += 1
        tmp = l
print(ans)
