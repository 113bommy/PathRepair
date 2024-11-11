c = []
cT = 0
isE = True
for n in range(int(input())):
    c.append(list(map(int, input().split())))
for i in range(len(c)):
    for l in range(len(c)):
        cT += c[l][i]
    if cT == 0:
        cT = 0
    else:
        isE = False
        break
if isE:
    print("Yes")
else:
    print("No")