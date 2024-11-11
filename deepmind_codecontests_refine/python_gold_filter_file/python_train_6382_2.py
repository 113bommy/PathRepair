from sys import stdin, stdout


def dogeforces(c_a, a_a):
    global n
    l_a = [i for i in range(n)]
    return dfs(c_a, a_a, l_a)


def dfs(c_a, a_a, l_a):
    global n
    global d_a

    if len(l_a) == 1:
        return l_a[0]

    root = -1
    for l in l_a:
        root = max(root, a_a[l_a[0]][l])

    gp_a = []
    for l in l_a:
        gp = -1
        for j in range(len(gp_a)):
            g = gp_a[j][0]
            if a_a[l][g] != root:
                gp = j
                break
        if gp == -1:
            gp = len(gp_a)
            gp_a.append([])
        gp_a[gp].append(l)

    #print(l_a)
    #print(gp_a)
    #print('--------')
    v = n
    c_a.append(root)
    n += 1
    for gp in gp_a:
        sr = dfs(c_a, a_a, gp)
        d_a.append([sr, v])

    return v


n = int(stdin.readline())
a_a = []
c_a = []
for i in range(n):
    a_a.append(list(map(int, stdin.readline().split())))
    c_a.append(a_a[i][i])

d_a = []
root = dogeforces(c_a, a_a)

stdout.write(str(n) + '\n')
stdout.write(' '.join(map(str, c_a)) + '\n')
stdout.write(str(root + 1) + '\n')
for d in d_a:
    stdout.write(str(d[0]+1) + ' ' + str(d[1]+1) + '\n')
