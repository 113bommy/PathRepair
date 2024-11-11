c, v0, v1, a, l = map(int, input().split())
s = v0
n = 1
if v0 >= c:
    print(1)
    exit()
for i in range(1, 1000):
    x = v0 + a*i - l
    if x > v1:
        s += v1
        n += 1
        if s >= c:
            print(n)
            exit()
    else:
        s += x
        n += 1
        if s >= c:
            print(n)
            exit()
