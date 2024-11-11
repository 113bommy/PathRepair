n = int(input())
d = []
for i in range(4):
    d.append(n % 2)
    n //= 2
x = 0
for i in range(4):
    d[i] ^= x
    x |= d[i]
r = 0
for v in d[::-1]:
    r = 2*r + v
print(r)