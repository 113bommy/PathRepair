x, y, z, t1, t2, t3 = map(int, input().split())
l = abs(x - y)
w = abs(z - x)
if t1 * l >= t2 * (w + l) + t3:
    print("YES")
else:
    print("NO")