r, c = map(int,input().split())
m = []
k = 0
log = False
for i in range(r):
    m.append([])
    m[i] = list(input())
for i in range(r):
    for y in range(c):
        if m[i][y] == '.':
            m[i][y] = 'D'
for i in range(r):
    if log:
        break
    for y in range(c):
        if m[i][y] == 'W':
            if y + 1 < c:
                if m[i][y+1] == "S":
                    log = True
                    break
            if y - 1 > 0:
                if m[i][y-1] == "S":
                    log = True
                    break
            if i + 1 < r:
                if m[i+1][y] == "S":
                    log = True
                    break
            if i - 1 > 0:
                if m[i-1][y] == "S":
                    log = True
                    break

if log == False:
    print("Yes")
    for i in range(len(m)):
        print(*m[i],sep = '')
else:
    print("No")
