X, Y = map(int, input().split())

ans = max(0, (4 - X) * 100000)
ans+ = max(0, (4 - Y) * 100000)

if X == Y == 1:
    ans += 100000 * 4

print (ans)