m, n = map(int, input().split())
if m % 2 == 0:
    max_tiles = m / 2 * n
elif n % 2 == 0:
    max_tiles = n / 2 * m
else:
    max_tiles = m // 2 + n // 2 * m
print(max_tiles)