x, y, z, t1, t2, t3 = map(int, input().split())
print("YES" if abs(x - y) * t1 > (t3 * 3 + abs(x - y) + abs(x - z)) * t2 else "NO")