a = int(input())

x = a
i = 1

while x % 360 != 0:
    x += a
    i += 1

print(i)