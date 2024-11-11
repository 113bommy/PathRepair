t = int(input(""))
for q in range(t):
    n = int(input(""))
    s = input("")
    if s.count("2") in [1,2]:
        print("NO")
        continue
    res = []
    for i in range(n):
        res.append([])
        for j in range(n):
            res[i].append('=')
    l = -1
    f = -1
    for i in range(n):
        if s[i] == '2':
            if l != -1:
                res[i][l] = '+'
                res[l][i] = '-'
            else:
                f = i
            l = i
        else:
            for j in range(n):
                res[i][j] = '='
                res[j][i] = '='
    if f != '-1':
        res[l][f] = '-'
        res[f][l] = '+'
    print("YES")
    for i in range(n):
        res[i][i] = "X"
        print("".join(res[i]))

