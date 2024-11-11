a, b, c, d = map(int, input().split())
print("YES" if (abs(b - a) <= d and abs(c - b) <= d) or abs(c - a) <= d else "NO")