l, r, k = map(int, input().split())
ans = []
i = 1
while i < 1e18:
    if l <= i <= r:
        ans.append(i)
    i *= k

if ans:
    print(*ans)
else:
    print(-1)