n = int(input())
c = list(map(int, input()))
val = list(c)
for i in range(n - 1):
    d = (10 - c[0]) % 10
    for j in range(n):
        c[j] = (c[j] + d) % 10
    if c < val:
        val = list(c)
    c.append(c[0])
    del(c[0])
print(''.join(map(str, val)))