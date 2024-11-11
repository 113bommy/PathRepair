x = int(input())

d, m = divmod(x, 11)
d *= 2

if m >= 7:
    d += 2
else:
    d += 1
print(d)