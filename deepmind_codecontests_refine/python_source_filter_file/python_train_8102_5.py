x, y, z = map(int, input().split())
z -= y
print(z // (x + y))