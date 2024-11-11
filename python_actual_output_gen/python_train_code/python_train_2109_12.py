a = int(input())

x = a
i = 1

while x % 180 != 0:
    x += a
    i += 1

print(i*2)