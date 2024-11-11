a = list(map(int, input().split()))
b = list(map(int, input().split()))
xa = a[0::2]
ya = a[1::2]
xb = b[0::2]
yb = b[1::2]

miny = min(yb)
maxy = max(yb)

for i in range(miny, (miny + maxy) // 2 + 1):
    for j in range(xb[yb.index(miny)] - (abs(i - miny)), xb[yb.index(miny)] + (abs(i - miny)) + 1):
        if min(xa) <= j <= max(xa) and min(ya) <= i <= max(ya):
            print("YES")
            exit(0)

for i in range(maxy, (miny + maxy) // 2 + 1, -1):
    for j in range(xb[yb.index(miny)] - (abs(i - maxy)), xb[yb.index(miny)] + (abs(i - maxy)) + 1):
        if min(xa) <= j <= max(xa) and min(ya) <= i <= max(ya):
            print("YES")
            exit(0)
print("NO")