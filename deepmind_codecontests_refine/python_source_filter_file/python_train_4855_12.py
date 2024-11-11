n = int(input())

max_x = 1
x = 1
has = (2**x - 1) * (2**(x-1))
while has < n:
    if n % has == 0:
        max_x = x
    x += 1
    has = (2**x - 1) * (2**(x-1))

print((2**max_x - 1) * (2**(max_x-1)))
