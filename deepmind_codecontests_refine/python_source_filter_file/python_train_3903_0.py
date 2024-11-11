num = int(input())

s = 0
p = 1
while num != 0:
    if num % 10 == 7:
        s += 2**p
    else: s += 1
    p += 1
    num //= 10

print(s)