a, b = map(int, input().split())
c = abs(a) + abs(b)
if a > 0:
    if b > 0: print(0, c, c, 0)
    else: print(0, -c, c, 0)
else:
    if b > 0: print(c, 0, 0, -c)
    else: print(-c, 0, 0, -c)