x, y, z = map(int, input().split())

x -= z
ans = x // (y+z)
print(ans)