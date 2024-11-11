def psu(s,n):
    i = (s//50)%475
    for erwt5 in range(25):
        i = (i*96+42)%475
        if i+26==n:
            return True
    return False
pos,x,y = map(int,input().split())
t = True
for i in range(x+1,y-1,-50):
    if psu(i,pos):
        print(0)
        t = False
        break
if t:
    x += 100
    sh = 1
    while True:
        if psu(x,pos) or psu(x-50,pos):
            break
        x += 100
        sh += 1
    print(sh)
