(n, a, b, c, d) = (int(_) for _ in input().split())
print((n - abs(a-d) + abs(b-c)) * n)
