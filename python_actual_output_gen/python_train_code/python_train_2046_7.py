def Ics(X, Y):
    m = len(X)
    n = len(Y)
    c1 = [0] * (n + 1)
    for i in range(m):
        d = X[i]
        c2 = c1[:]
        for j in range(n):
            if (d == Y[j]):
                c1[j + 1] = c2[j] + 1
            elif (c1[j + 1] < c1[j]):
                c1[j + 1] = c1[j]
    return (c1[-1])
 
q = int(input().rstrip())
t = []
for i in range(q):
    s1 = input().rstrip()
    s2 = input().rstrip()
    t.append(Ics(s1, s2))
    print(*t, sep = "\n")