a, b = [int(i) for i in input().split()]
c = 0
fashion = 0
pairs = 0
d = 0
if a > b:
    c = b
    d = a
elif b > a:
    c = a
    d = b
fashion += c

d -= c
pairs += d//2
print(fashion, pairs)