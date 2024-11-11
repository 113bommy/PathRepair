x, y, z, t1, t2, t3 = map(int,input().split())
if 2 * t3 + abs(x - y) * t2 + abs(z - x) * t2 <= abs(x - y) * t1:
    print("YES")
else:
    print("NO")
