(n, a, b, c, d) = (int(_) for _ in input().split())
print(max((n - abs(a-d) - abs(b-c)), 0) * n)
