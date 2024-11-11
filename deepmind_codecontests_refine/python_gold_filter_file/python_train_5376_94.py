n = int(input())
m = int(input())

p = 1
while (p <= m and n > 0):
    p *= 2
    n -= 1

print(m % p)
