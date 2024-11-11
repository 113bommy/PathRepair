a = list(map(int, input().split()))
b = list(map(int, input().split()))
x = []
y = []
for i in range(8):
    if i % 2 == 0:
        if a[i] not in x:
            x.append(a[i])
    else:
        if a[i] not in y:
            y.append(a[i])
x.sort()
y.sort()
f = 0

nowx = nowfx = b[2]
nowy = nowfy = b[3]
tarx = tarfx = b[4]
tary = tarfy = b[5]
gox = (-b[2] + b[0]) // abs(b[2] - b[0])
goy = (-b[3] + b[1]) // abs(b[3] - b[1])
while nowx != b[0]:
    #print(1)
    print(nowx, nowy, tarx, tary)
    nowfx += gox
    nowfy += goy
    tarfx += gox
    tarfy += goy
    addx = (tarx - nowx) // abs(tarx - nowx)
    addy = (tary - nowy) // abs(tary - nowy)
    while nowx != tarx and nowy != tary:
        if x[0] <= nowx <= x[1] and y[0] <= nowy <= y[1]:
            f = 1
        nowx += addx
        nowy += addy
    if x[0] <= nowx <= x[1] and y[0] <= nowy <= y[1]:
        f = 1
    nowx += addx
    nowy += addy
    nowx = nowfx
    nowy = nowfy
    tarx = tarfx
    tary = tarfy
print(nowx, nowy, tarx, tary)
addx = (tarx - nowx) // abs(tarx - nowx)
addy = (tary - nowy) // abs(tary - nowy)
while nowx != tarx and nowy != tary:
    if x[0] <= nowx <= x[1] and y[0] <= nowy <= y[1]:
        f = 1
    nowx += addx
    nowy += addy
if x[0] <= nowx <= x[1] and y[0] <= nowy <= y[1]:
    f = 1
nowx += addx
nowy += addy

print('YES' if (f) else 'NO')
