a = [input() for i in range(8)]
ca, cb = 8, 8

for j in range(8) :
    for i in range(8) :
        if a[i][j] == 'W' :
            ca = min(ca, i)
        if a[i][j] != '.' :
            break
for j in range(8) :
    for i in range(7,-1,-1) :
        if a[i][j] == 'B' :
            cb = min(cb, 7 - i)
        if a[i][j] != '.' :
            break

print ('A' if ca <= cb else 'B')