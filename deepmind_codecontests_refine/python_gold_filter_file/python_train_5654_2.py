c = input().split()
num = int(c[0])
o = int(c[1])
w = int(c[2])
if num == 1:
    if o > 0 or w > 0:
        print(-1)
    else:
        print(1)
elif w == 0 and o >= num-1:
    print(-1)
elif w == 0 and o > 0:
    k1 = ["2","1"]
    p = 3
    for i in range(o):
        k1.append(str(p))
        p += 1
    if p > 50000:
        print(-1)
    else:
        for i in range(num-2-o):
            k1.append(k1[-1])
        print(" ".join(k1))
else:
    k1 = ["1"]
    d = 1
    for i in range(w):
        d *= 2
        k1.append(str(d))
    d = d+1
    for i in range(o):
        k1.append(str(d))
        d += 1
    if d-1 > 50000:
        print(-1)
    else:
        for i in range(num-o-w-1):
            k1.append(k1[-1])
        print(" ".join(k1))
        