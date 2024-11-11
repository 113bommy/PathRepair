a, b = map(int, input().split())
z = a
while a >= 1:
    a = a // b
    z += a
print(z)