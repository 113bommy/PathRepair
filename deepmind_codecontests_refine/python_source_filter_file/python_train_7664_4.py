n = int(input())
d = {}
def suffix(x, y):
    if x in y:
        for k in range(1, n):
            if y[k:] == x:
                return True
    return False
for i in range(n):
    info = input().split()
    name = info[0]
    nnumber = int(info[1])
    numbers = info[2:]
    if name in d.keys():
        d[name] = d[name] + numbers
    else:
        d[name] = numbers
print(len(d.keys()))
for names in d.keys():
    d[names] = list(set(d[names]))
    L = []
    for j in range(len(d[names])):
        judge = 0
        for l in range(len(d[names])):
            if l != j:
                if suffix(d[names][j], d[names][l]) == True:
                    judge = 1
                    break
        if judge == 0:
            L.append(d[names][j])
    Lmax = [names, str(len(L))] + L
    print(" ".join(Lmax))
