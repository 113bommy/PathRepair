r, b = map(int, input().split())
if r < b:
    x = b - r
    y = x // 2 
    print(r, y)
elif r == b:
    print(r, 0)
elif b < r:
    x = r - b
    y = x // 2
    print(b, y)