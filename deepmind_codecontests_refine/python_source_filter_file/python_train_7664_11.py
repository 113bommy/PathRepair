n = int(input())
l = []
for i in range(n):
    l.append([str(i) for i in input().split()])
for i in range(n):
    l[i] = [l[i][0]] + l[i][2:]
w = []
for i in range(n):
    if [l[i][0]] not in w:
        w.append([l[i][0]])
m = len(w)
for i in range(n):
    for j in range(m):
        if l[i][0] == w[j][0]:
            for k in range(len(l[i]) - 1):
                w[j].append(l[i][k + 1])
for i in range(m):
    if len(w[i]) != 2:
        for j in range(len(w[i]) - 2):
            for k in range(j + 1, len(w[i]) - 1):
                a = w[i][j + 1]
                b = w[i][k + 1]
                s = len(a)
                t = len(b)
                if s >= t:
                    if a[-t:] == b:
                        w[i][k + 1] = "*"
                else:
                    if b[-s:] == a:
                        w[i][j + 1] = "*"
#print(w)
c = []
for i in range(m):
    count = 0
    for j in w[i][1:]:
        if j != '*':
            count += 1
    c.append(count)
#print(c)
print(n)
for i in range(m):
    print(w[i][0], end = ' ')
    print(c[i], end = ' ')
    for x in w[i][1:]:
        if x != "*":
            print(x, end = ' ')
    print()
