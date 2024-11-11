a, b, c, d = map(int, input().split())
print("YES" if (abs(b - c) <= d and abs(c - b) <= d) or abs(c - a) <= d else "NO")