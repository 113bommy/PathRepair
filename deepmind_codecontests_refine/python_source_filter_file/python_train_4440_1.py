r, g, b = map(int, input().split())
mx = 0

if r:
    v = ((r + 1) // 2 - 1) * 3 + 30
    mx = max(mx, v)

if g:
    v = ((g + 1) // 2 - 1) * 3 + 1 + 30
    mx = max(mx, v)
if b:
    v = ((b + 1) // 2 - 1) * 3 + 1 + 30
    mx = max(mx, v)

print(mx)
