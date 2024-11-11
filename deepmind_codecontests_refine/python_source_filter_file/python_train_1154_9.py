n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
p = 0
t = 0
for i in range(n):
    t += a[i]
    r = (t // m) - p
    print(r,'', end='')
    p = r
