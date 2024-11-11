import math

a, b, c, d = map(lambda x: int(x), input().split(' '))

h = 0
w = c - a + 1

h += (d - b + 1) // 2

summ = h * w

if((a + b) % 2 == 0):
    if(d - b) % 2 == 0:
        summ += w // 2 + w % 2
else:
    if(d - b) % 2 == 0:
        summ += w // 2 + w % 2

print(summ)