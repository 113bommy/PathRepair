n = int(input())
m = int(input())

x = 1
while x <= m and n > 0:
    x *= 2
    n -= 1

print(m % x)
