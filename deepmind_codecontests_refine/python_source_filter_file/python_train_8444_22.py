a, b, c = map(int, input().split())
x, y, z = c, c - 1, c - 2
while y > b or z > c:
    x -= 1
    y -= 1
    z -= 1
print(x + y + z)
