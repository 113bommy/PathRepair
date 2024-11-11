mat = []

for i in range(5):
    mat.append([int(z) for z in input().split()])
print(mat)
m = 0
for a in range(5):
    for b in range(5):
        for c in range(5):
            for d in range(5):
                for e in range(5):
                    l = [a, b, c, d, e]
                    if len(set(l)) == len(l):
                        cnt = 0
                        for i in range(5):
                            for j in range(i, 4, 2):
                                cnt += mat[l[j]][l[j+1]]
                                cnt += mat[l[j+1]][l[j]]
                                #print(cnt, l)
                        m = max(m, cnt)

print(m)
