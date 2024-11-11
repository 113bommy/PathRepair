a, b, c, d = [int(i) for i in input().split()]
x = 0
if b * c < a * d:
    x = a
    a = b
    b = x
    x = d
    d = c
    c = x
q = b * c
p = q - (a * d)
for i in range(2, q + 1):
    while p % i == 0 and q % i == 0:
        p //= i
        q //= i
print(str(p) + '/' + str(q))