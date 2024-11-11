n = int(input())
i = 0
h = 0
while n > 0:
    n -= i
    i += 3
    h += 1
print(h - 1)