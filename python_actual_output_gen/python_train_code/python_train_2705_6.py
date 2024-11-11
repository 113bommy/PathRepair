n = int(input())
R = []
for _ in range(n):
    x, l = map(int, input().split())
    R.append((x+l-1, x-l+1))
R.sort()

ans = 0
last = -1e10
for r, l in R:
    if last <= l:
        ans += 1
        last = r
print(ans)