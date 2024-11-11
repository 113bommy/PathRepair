n = int(input())
a = 0
d = 0
prime = []
for i in range(1, n, 1):
    b = 0
    a = i//2
    for j in range(1, a+1, 1):
        if i % j == 0:
            b += 1
    if b == 1:
        prime.append(i)
for k in range(n+1):
    c = 0
    for h in prime:
        if k % h == 0:
            c += 1
    if c == 2:
        d += 1
print(d)


