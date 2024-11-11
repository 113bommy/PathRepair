def Ics(x, y):
    a = len(x)
    b = len(y)
    c1 = [0] * (b + 1)

    for i in range(a):
        d = x[i]
        c2 = c1[:]
        for j in range(b):
            if d == y[j]:
                c1[j + 1] = c2[j] + 1
            elif c1[j + 1] < c1[j]:
                c1[j + 1] = c1[j]
    return (c1[-1])

q = int(input().rstrip())
r = []
for k in range(q):
    s1 = input().rstrip()
    s2 = input().rstrip()
    r.append(Ics(s1, s2))

print(*r, sep = "\n")