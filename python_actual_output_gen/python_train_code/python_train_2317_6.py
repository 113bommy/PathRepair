a = int(input())
g = 1
k = [1]
v = []
for i in range(1,a+1):
    h = int(input())
    f = 1
    b = 1
    p = 1111
    g = 1
    while f != h:
        if f != h:
            f = f * 10 + b
        if f > p:
            f = g+1
            b += 1
            g += 1
            p += 1111
        l = k.append(f)
    k = [str(i) for i in k]
    k = ''.join(k); k = int(len(k))
    u = v.append(k)
    k = [1]
for i in v:
    print(v)