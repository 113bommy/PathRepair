n = int(input())
a = list(map(int,input().split()))
d = [0] * (n)
b = [0] * (2001)
s = 0
f = [ [] for i in range(2001) ]
c = [ [] for i in range(3) ]
for i in range(len(a)):
    b[a[i]] = b[a[i]] + 1
    d[i] = [a[i],i+1]
    f[a[i]].append(i+1)
c1 = 0
for i in range(len(b)):
    if (b[i] >= 2):
        if (b[i] >= 3):
            c1 = c1 + 1
        s = s + 1
if ((s < 2) and (c1 != 1)):
    print('NO')
else:
    print('YES')
    s = 0
    for i in range(len(f)):
        for j in range(len(f[i])):
            c[0].append(f[i][j])
    print(*(c[0]))
    mark = [False] * (2001)
    for i in range(len(f)):
        if (len(f[i]) == 1):
            c[0].append(f[i][0])
        elif (len(f[i]) == 2):
            if (s == 0):
                c[1].append(f[i][1])
                c[1].append(f[i][0])
                s = s + 1
                mark[i] = True
            else:
                c[1].append(f[i][0])
                c[1].append(f[i][1])
        elif (len(f[i]) > 2):
            if (s == 0):
                c[1].append(f[i][1])
                c[1].append(f[i][0])
                for j in range(2,len(f[i])):
                    c[1].append(f[i][j])
            else:
                for j in range(len(f[i])):
                    c[1].append(f[i][j])
    print(*(c[1]))
    s = 0
    for i in range(len(f)):
        if (len(f[i]) == 1):
            c[2].append(f[i][0])
        elif (len(f[i]) == 2):
            if ((mark[i] == False) and (s == 0)):
                c[2].append(f[i][1])
                c[2].append(f[i][0])
                mark[i] = True
                s = s + 1
            else:
                c[2].append(f[i][0])
                c[2].append(f[i][1])
        elif (len(f[i]) > 2):
            if (s == 0):
                c[2].append(f[i][2])
                c[2].append(f[i][0])
                c[2].append(f[i][1])
                for j in range(3,len(f[i])):
                    c[2].append(f[i][j])
            else:
                for j in range(len(f[i])):
                    c[2].append(f[i][j])
            s = s + 1
    print(*(c[2]))