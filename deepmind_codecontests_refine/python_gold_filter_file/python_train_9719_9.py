x, y, z = map(int, input().split())
print(int(4 * (x * y + y * z + x * z) / (x * y * z) ** 0.5))