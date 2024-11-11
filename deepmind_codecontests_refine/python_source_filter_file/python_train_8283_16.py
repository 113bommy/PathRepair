a, b, c, d = int(input()), int(input()), int(input()), int(input())
x = a ^ b
y = c or d
z = b and c
t = a ^ c
print((x and y) ^ (z or t))
