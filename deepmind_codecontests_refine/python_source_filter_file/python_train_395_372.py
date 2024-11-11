a, b, c = map(int, input().split())
print("Yes" if 0 <= c - (a + b) else "No")