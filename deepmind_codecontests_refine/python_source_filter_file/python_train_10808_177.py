a, b, c, d = map(int, input())
print("Yes" if abs(c - a) <= d or (abs(c - b) <= d and abs(a - b) <= d) else "No")