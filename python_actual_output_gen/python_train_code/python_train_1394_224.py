a, b, c = map(int, input().split())
print("YES" if b - a >= c - a and a <= c else "NO")