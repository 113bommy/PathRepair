n = int(input())
bigl = []
y = 0
f = False
for x in range(n):
    bigl.insert(y, input())
    y += 1
if bigl[0][0] == bigl[0][1]:
    print("NO")
    exit()
for x in bigl[::]:
    for i in x:
        if i != bigl[0][0] and i != bigl[0][1]:
            print("NO")
            exit()
y = 0
if bigl[0][0] == bigl[0][-1]:
    for x in bigl:
        for i in x:
            if i == bigl[0][0]:
                y += 1
        if y > 1 and bigl.index(x)+1 == ((n+1)//2):
            print("NO")
            exit()
        if y > 2:
            print("NO")
            exit()
        y = 0
else:
    print("NO")
    exit()

y = 0
while y < n-1:
    if bigl[y][y] != bigl[y+1][y+1]:
        print("NO")
        exit()
    y += 1
y = -1
z = 0
while y > -n:
    if bigl[y][z] != bigl[y-1][z+1]:
        print("NO")
        exit()
    y -= 1
    z += 1
print("YES")

