n = int(input())
dist = [int(input()) for _ in range(3)]

print((min(dist[:1]) + min(dist) * (n - 2)) if n > 1 else 0)
