n = int(input())
s = 2
for i in range(1, n + 1):
    v = i * (i + 1)
    print((int)((v * v - s) / i))
    s = v