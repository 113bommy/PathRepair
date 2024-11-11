r, s = map(int, input().split())

p = [[] for i in range(r)]
q = [[0 for j in range(s)] for i in range(r)]
for i in range(r):
    for j, c in enumerate(input()):
        p[i].append(c == "B")
        q[i][j] = (q[i][j-1] * bool(j) +
                   q[i-1][j] * bool(i) -
                   q[i-1][j-1] * bool(i and j) +
                   (not p[i][j]))

blacks = r * s - q[-1][-1]

mini = 10 ** 10
for i2 in range(r):
    for j2 in range(s):
        for k in range(min(i2, j2)+1):
            i1 = i2 - k
            j1 = j2 - k
            x = (q[i2][j2] +
                 q[i1-1][j1-1] * bool(i2 and j2) -
                 q[i1-1][j2] * bool(i1) -
                 q[i2][j1-1] * bool(j1))
            if blacks + x == (i2 - i1 + 1) * (j2 - j1 + 1):
                mini = min(mini, x)

if mini == 10 ** 10:
    print(-1)
else:
    print(mini)
