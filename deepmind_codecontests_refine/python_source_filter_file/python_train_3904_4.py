n, m, k = map(int, input().split())
win = False
for i in range(k):
    r, c = map(int, input().split())
    dr = min(r - 1, n - r)
    dc = min(c - 1, m - c)
    if dr <= 3 or dc <= 3:
        win = True
print("YES" if win else "NO")
