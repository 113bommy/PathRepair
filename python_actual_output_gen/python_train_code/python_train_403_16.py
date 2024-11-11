(n, m) = map(int, input().split())
a = [int(i) for i in input().split()]
r = 0
for j in range(n):
    if j != 0:
        print(" ", end="")
    t = 0
    r += a[j]
    if r > m:
        t += int(r/m)
        r %= m
    print(t, end="")