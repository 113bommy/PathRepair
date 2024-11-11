n, pos = map(int, input().split())

print(8 + min(n - pos + 1, pos) + 3*max(n-3, 0)) if n > 2 else print(6)
